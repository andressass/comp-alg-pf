//
//  Fuga.cpp
//  Exerc1
//
//  Created by Rondinele Prado on 07.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#include "../include/Fuga.hpp"
#include "../include/Contraponto.h"

//--------------------------------------------------------------------------------------------------
//
MuMaterial Fuga::geraFuga(MuMaterial sujeito){
    
    MuMaterial fuga;
    
    fuga = geraExposicao(sujeito);
    
    fuga = geraDesenvolvimento(sujeito);

    //Finalizacao
    fuga.Append(0, sujeito, 0);
    aux.DiatonicTranspose(0, MAJOR_MODE, 5, ASCENDING);
    fuga.Append(1, aux, 0);
    aux.Clear();
    aux.Append(0, sujeito.GetNote(0));
    
    aux.Fit(sujeito.Dur());
    fuga.Append(2, aux, 0);
    
    return fuga;
}



//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por gerar uma transformacao equivalente ao indice passado como parametro.
 *
 * \param melodia_original MuMaterial contendo a melodia original
 * \param indice_transformacao indice da escolha da transformacao do sujeito
 *
 */
MuMaterial geraTransformacao(MuMaterial melodia_original, short indice_transformacao){
    
    MuMaterial transformacao = melodia_original;
    
    //Escolhe a transformacao que ira resultar no contrasujeito
    //TODO - PEDRO
    //1.Contraponto
    //2.Retro()
    //3.CyclePitch()
    //4. ...
    
    return transformacao;
}


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por gerar o contra-sujeito da fuga.
 *
 * \param sujeito MuMaterial contendo o sujeito da fuga
 * \param indice_transformacao indice da escolha da transformacao do sujeito
 *
 */
MuMaterial geraContraSujeito(MuMaterial sujeito, short indice_transformacao){
    
    //Escolhe a transformacao que ira resultar no contrasujeito
     return geraTransformacao(sujeito, indice_transformacao);
    
}


//--------------------------------------------------------------------------------------------------
//
MuMaterial Fuga::geraExposicao(MuMaterial sujeito){
    
    MuMaterial seq, aux;
    MuVoice voice;
    
    seq.AddVoices(2);
    
    //Obtemos o sujeito
    seq = sujeito;
    float dur_ultima_nota = sujeito.GetNote(sujeito.GetVoice(0).NumberOfNotes()-1).Dur();
    
    //Exposição
    
    //Voz 1
    aux = seq; //Sujeito
    
    //Escolha do contra-sujeitos------------
    
    //TODO - PEDRO - Escolhe aleatoriamente os indices
    
    //Invoca a funcao para gerar contra-sujeitos
    
    //Adiciona na variavel seq
    
    
    // OLD -----------------------------------
    aux.Retro(); //Contra-Sujeito 1
    seq.Append(0, aux, 0);
    
    
    aux.CycleRhythm((int)aux.NumberOfNotes() - 1); //Contra Sujeito 2
    //Contraponto* c = new Contraponto(sujeito);
    //int tessitura[] = TESSITURA_SOPRANO;
    //c->geraPrimeiraEspecie(tessitura);
    //aux = c->getContraponto();
    seq.Append(0, aux, 0);
    //----------------------------------------
    
    
    aux.Clear();
    aux = seq;
    //aux.Retro();
    //seq.Append(0, aux, 0);
    
    //Voz 2
    aux.Clear();
    aux = seq;
    aux.DiatonicTranspose(0, MAJOR_MODE, 5, ASCENDING);
    seq.Append(1, aux, 0);
    seq.Move(1, sujeito.Dur()- dur_ultima_nota); //Deslocamos para o final da exposição do sujeito pela voz 1
    
    //Voz 3
    aux.Clear();
    aux = seq;
    aux.Transpose(-12);
    seq.Append(2, aux, 0);
    seq.Move(2, 2 * (sujeito.Dur() - dur_ultima_nota));

    return seq;
}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Fuga::geraExposicao(MuMaterial sujeito){
    
    MuMaterial seq;
    
    //Obtemos o sujeito
    seq = sujeito;
    
    //Desenvolvimento
    MuMaterial aux = sujeito;
    aux.Fit(sujeito.Dur()*2);
    fuga.Append(0, aux, 0);
    aux.DiatonicTranspose(0, MAJOR_MODE, 5, ASCENDING);
    aux.Fit(sujeito.Dur()/2);
    fuga.Append(1, aux, 0);
    aux.Retro();
    fuga.Append(1, aux, 0);
    
    return seq;
}
