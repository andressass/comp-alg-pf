//
//  Harmonia.cpp
//  TrabHarm
//
//  Created by Rondinele Prado on 01.11.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#include <stdio.h>
#include "../include/Harmonia.h"


//--------------------------------------------------------------------------------------------------
//
MuMaterial Harmonia::geraCampoHarmonico(short tonica, short modo){

    if (modo == 0) return geraCampoHarmonicoMaior(tonica);
    else return geraCampoHarmonicoMenor(tonica);

}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Harmonia::geraCampoHarmonicoMaior(short tonica){
    
    MuMaterial harmonia,
               triade;
    
    //Cria uma triade em C maior
    triade.MajorTriad(COMPASSO);
    
    //Transpoe a triade para a tonalidade da tonica
    triade.Transpose(tonica % 12);
    
    //Cria todas as triades do campo harmonico
    for(int i = 1; i < 8; i++){
        MuMaterial triade_aux = triade;
        
        triade_aux.DiatonicTranspose(tonica % 12, MAJOR_MODE, i, ASCENDING);
        
        //Adiciona a dominante ao VII grau
        if (i == 7) {
            MuNote dominante = triade_aux.GetFirstNote();
            dominante.SetPitch(dominante.Pitch()-4); //Dominante
            triade_aux.AddNote(dominante);
        }
        
        triade_aux.Transpose(-12);
            harmonia.Append(0, triade_aux, 0);
    }
    
    return harmonia;
    
}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Harmonia::geraCampoHarmonicoMenor(short tonica){
    
    MuMaterial harmonia;
    
    return harmonia;
    
}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Harmonia::escolheAcorde(MuMaterial notas, MuMaterial acordes){

    MuMaterial acorde_escolhido;
    MuNote nota;
    int quantidade_acordes = (int)acordes.Dur()/acordes.GetFirstNote().Dur();
    float ranking[quantidade_acordes];
    
    for (int i=0; i<quantidade_acordes; i++)
        ranking[i] = 0;
    
    //Percorre cada nota do conjunto
    for(int i = 0; i < notas.NumberOfNotes(); i++){
        nota = notas.GetNote(i);
        
        //Percorre cada possivel acorde
        for(int j = 0; j < quantidade_acordes; j++){
            MuMaterial acorde = acordes.GetNotesSoundingAt(0, j*2);
            //Percorre cada nota do acorde
            for(int k = 0; k < acorde.NumberOfNotes(); k++)
                //Se a nota estiver no acorde, aumenta o ranking do acorde no valor da duracao da nota
                //A nota com maior duracao tem mais peso na escolha.
                if(nota.Pitch() % 12 == acorde.GetNote(k).Pitch() % 12)
                    ranking[j] += nota.Dur();
        }
    }
    
    int maior_indice = 0;
    
    //Determina se hah algum acorde com ranking maior e, se tiver um empate, valoriza os graus I, IV e V
    for(int i = quantidade_acordes-1; i >= 0; i--)
        if(ranking[maior_indice] < ranking[i] ||
           (ranking[maior_indice] == ranking[i]
            && (i == 0 || i == 3 || i == 4)))
            maior_indice = i;
    
    //Pega notas do acorde que soa no tempo indicado pelo maior indice
    acorde_escolhido = acordes.GetNotesSoundingAt(0, maior_indice * 2);
    
    return acorde_escolhido;
}

//--------------------------------------------------------------------------------------------------
MuMaterial Harmonia::harmonizacaoMelodia(MuMaterial melodia, int tonalidade){
    
    MuMaterial  campo_harmonico,
                notas_compasso,
                harmonia;
    MuNote  tonica,
            nota;
    //int i = 0;
    float duracao = 0;
    
//    do{
//        i--;
//        
//        // Obtem a tonica da melodia para gerar os acordes possiveis da tonalidade
//        tonica = melodia.GetNote(melodia.NumberOfNotes()+i);
//        
//    }while(tonica.Amp() == 0);
    
    
    //Gera o campo harmonico maior da tonalidade
    campo_harmonico = geraCampoHarmonicoMaior(tonalidade);
    
    //Percorre a melodia
    for(int j = 0; j < melodia.NumberOfNotes(); j ++){
        
        nota = melodia.GetNote(j);
        
        notas_compasso.AddNote(nota);
        
        duracao += nota.Dur();
        
        if(duracao >= 2){
            duracao = 0;
            harmonia.Append(0, escolheAcorde(notas_compasso, campo_harmonico) , 0);
            notas_compasso.Clear();
        }
    }
    
    //melodia.Append(1, harmonia, 0);

    return harmonia;

}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Harmonia::inverteAcorde(MuMaterial acorde){
    
    //\TODO
    MuNote nota = acorde.GetFirstNote();
    acorde.RemoveNote(0);
    
    nota.SetPitch(nota.Pitch()+12);
    acorde.AddNote(nota);
    
    return acorde;
}


//--------------------------------------------------------------------------------------------------
//
MuMaterial Harmonia::inverteAcorde(MuMaterial acorde, MuNote nota){
    
    int i = 0;
    
    while (acorde.GetFirstNote().Pitch()%12 != nota.Pitch()%12 && i++ < acorde.NumberOfNotes())
        inverteAcorde(acorde);
    
    return acorde;
}
