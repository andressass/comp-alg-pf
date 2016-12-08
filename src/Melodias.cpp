//
//  Melodias.cpp
//  Exerc1
//
//  Created by Rondinele Prado on 01.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//
//--------------------------------------------------------------------------------------------------
#include "../include/Melodias.h"
#include <math.h>

short escolhe(short* vetor){
    
    return vetor[rand()%(sizeof(vetor)/sizeof(*vetor))];
}


//--------------------------------------------------------------------------------------------------
//
MuMaterial Melodias::melodiaTonalAleatoria(short tonalidade, short modo, short num_notas,
                                           short grau_liberdade, short max_amplitude){
    MuMaterial seq, nota_tr;
    int ampl_saltos = grau_liberdade;
    
    //Nota fundamental
    MuNote note;
    note.SetInstr(1);
    note.SetDur(1);
    note.SetPitch(tonalidade);
    note.SetAmp(.5);
    
    //Melodia responsavel por guardar a nota atual a ser transposta
    nota_tr.Append(0,note);
    
    //Resultado recebe como primeira nota a tonica
    seq.Append(0, note);
    
    //Geramos uma semente aleatoria
    srand((unsigned)time(NULL));
    
    short grau = 0;
    
    for(int i = 0; i < num_notas - 2; i++)
    {
        
        //Calculamos a amplitude maxima do salto baseado nos pesos
        int aleatorio = rand()%101;
        if(aleatorio < 10)  ampl_saltos = fminf(4, grau_liberdade); //10% de chance
        if(aleatorio >= 10 && aleatorio <= 15) ampl_saltos = fminf(6, grau_liberdade); //5% de chance
        else ampl_saltos = fminf(4, grau_liberdade); //85% de chance
        
        //Distribuimos a altura da nota de acordo com o grau de liberdade
        grau = abs(Between(grau-ampl_saltos, grau+ampl_saltos)%max_amplitude);
        
        nota_tr.Clear();
        nota_tr.Append(0,note);
        
        //Transpomos a nota
        nota_tr.DiatonicTranspose(0, MAJOR_MODE, grau, ASCENDING);
        
        //Colocamos a distribuicao do tempo com 10% de chance de alteracao
        aleatorio = rand()%101;
        float duracao;
        
        //Calculamos a duracao da nota
        if(aleatorio < 20) duracao = 1; //20% de chance
        if(aleatorio >= 20 && aleatorio <= 30) duracao = .25; //10% de chance
        else duracao = .5; //60% de chance
        
        nota_tr.Fit(duracao);
        seq.Append(0, nota_tr, 0);
    }
    //Nota final
    note.SetDur(2);
    seq.Append(0, note);
    
    return seq;
}


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por implementar a geração de uma melodia aleatoria atonal
 *
 * \param altura_inicial altura da primeira e ultima notas
 * \param num_notas Numero de notas a serem geradas
 * \param grau_liberdade Grau de liberdade dos saltos
 * \param max_amplitude Maxima distancia entre o centro tonal que a melodia pode alcancar
 *
 * \return MuMaterial contendo a sequencia de notas.
 */
MuMaterial Melodias::melodiaAtonalAleatoria(short altura_inicial, short num_notas, short grau_liberdade, short max_amplitude){
    
    
    MuMaterial seq, nota_tr;
    int ampl_saltos = grau_liberdade;
    
    //Nota fundamental
    MuNote note;
    note.SetInstr(1);
    note.SetDur(1);
    note.SetPitch(altura_inicial);
    note.SetAmp(.5);
    
    //Melodia responsavel por guardar a nota atual a ser transposta
    nota_tr.Append(0,note);
    
    //Resultado recebe como primeira nota a tonica
    seq.Append(0, note);
    
    //Geramos uma semente aleatoria
    srand((unsigned)time(NULL));
    
    short grau = 0;
    
    for(int i = 0; i < num_notas - 2; i++)
    {
        
        //Calculamos a amplitude maxima do salto baseado nos pesos
        int aleatorio = rand()%101;
        if(aleatorio < 10)  ampl_saltos = fminf(4, grau_liberdade); //10% de chance
        if(aleatorio >= 10 && aleatorio <= 15) ampl_saltos = fminf(6, grau_liberdade); //5% de chance
        else ampl_saltos = fminf(4, grau_liberdade); //85% de chance
        
        //Distribuimos a altura da nota de acordo com o grau de liberdade
        grau = abs(Between(grau-ampl_saltos, grau+ampl_saltos)%max_amplitude);
        
        nota_tr.Clear();
        nota_tr.Append(0,note);
        
        //Transpomos a nota
        nota_tr.Transpose(grau);
        
        //Colocamos a distribuicao do tempo com 10% de chance de alteracao
        aleatorio = rand()%101;
        float duracao;
        
        //Calculamos a duracao da nota
        if(aleatorio < 10) duracao = 1; //10% de chance
        if(aleatorio >= 10 && aleatorio <= 15) duracao = .25; //5% de chance
        else duracao = .5; //85% de chance
        
        nota_tr.Fit(duracao);
        seq.Append(0, nota_tr, 0);
    }
    //Nota final
    note.SetDur(2);
    seq.Append(0, note);
    
    return seq;
    
}


//--------------------------------------------------------------------------------------------------
//
MuMaterial Melodias::EscalaMaiorAscendenteDescendente(short tonalidade, float duracao_notas){
    
    MuMaterial seq;
    
    //Geramos a escala maior
    seq.MajorScale(duracao_notas);
    
    //Obtemos a primeira nota e traspomos uma oitava (fechar escala)
    MuNote n = seq.GetNote(0);
    MuMaterial aux;
    aux.Append(0, n);
    aux.Transpose(12);
    seq.Append(0, aux, 0);
    
    //Criamos a escala descendente (retrograda da ascendente)
    MuMaterial retro = seq;
    retro.Retro();
    seq.Append(0, retro , 0);
    
    //Passamos para a tonalidade desejada
    seq.Transpose(tonalidade);
    
    return seq;
}


//--------------------------------------------------------------------------------------------------
MuMaterial decaiRitmo(MuMaterial melodia){
    
    MuMaterial seq;
    for (int i = 0; i < melodia.NumberOfNotes() - 1; i+=2) {
        MuNote notaReduzida  = melodia.GetNote(i); //Primeira nota
        MuNote notaAumentada = melodia.GetNote(i+1); //Segunda nota
        
        //Aumenta a extensao da segunda na nota em metade do valor de duracao da primeira
        notaAumentada.SetDur(notaReduzida.Dur()/2 + notaAumentada.Dur());
        //Reduz a duracao da nota pela metade
        notaReduzida.SetDur(notaReduzida.Dur()/2);
        
        seq.Append(0, notaReduzida);
        seq.Append(0, notaAumentada);
    }
    return seq;
}


//--------------------------------------------------------------------------------------------------
//
MuMaterial Melodias::VariaMelodiaAleatoriamente(MuMaterial melodia){
    MuMaterial seq = melodia;
    
    int op1 = Between(0, 100);
//    int op3 = Between(0, 100);
//    int op2 = Between(0, 100);
//    int op4 = Between(0, 100);
//    
//    short transp[] = {-4, 5}; //Transposicoes possiveis (4 desc ou 5 asc)
    
    //Escolhemos algumas transformacoes de acordo com a probabilidade do operador
    //Variacao ritmica
    if (op1 > 50) seq.CycleRhythm(0, Between(2, (int) seq.NumberOfNotes()-2));
    if (op1 < 10) seq = decaiRitmo(seq);
    
//    //Variacao melodica
//    if (op2 > 50) seq.DiatonicTranspose(0, MAJOR_MODE, transp[Between(0, 1)], ASCENDING);
//    if (op3 > 40) seq.Retro();
//    
//    //Remove as ultimas notas e dobra a duracao
//    if (op4 > 80){
//        int numberOfNotes = (int) seq.NumberOfNotes();
//        
//        for (int i = 0; i < numberOfNotes/2; i++) seq.RemoveNote((--numberOfNotes) - i);
//        seq.Fit(seq.Dur()*2);
//    }
//    
//    //Remove as primeiras notas e dobra a duracao
//    if (op4 < 20){
//        int numberOfNotes = (int) seq.NumberOfNotes();
//        
//        for (int i = 0; i < numberOfNotes/2; i++) seq.RemoveNote(0);
//        seq.Fit(seq.Dur()*2);
//    }
    
    return seq;
}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Melodias::criaMelodia(short* alturas, short duracao, short numNotas)
{
    MuMaterial melodia;
    MuNote nota;
    
    nota.SetDur(duracao);
    nota.SetAmp(.5);
    
    for(int i = 0; i < numNotas; i++){
        nota.SetPitch(alturas[i]);
        melodia.Append(0, nota);
    }
    return melodia;
}


//--------------------------------------------------------------------------------------------------
//
MuMaterial Melodias::criaMelodia(float* parametros)
{
    MuMaterial melodia;
    MuNote nota;
    nota.SetAmp(.5);
    
    for(int i = 0; parametros[i] > 0; i+=2){
        nota.SetPitch(parametros[i]);
        nota.SetDur(parametros[i+1]);
        melodia.Append(0, nota);
    }
    return melodia;
}

