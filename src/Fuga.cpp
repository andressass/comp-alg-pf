//
//  Fuga.cpp
//  Exerc1
//
//  Created by Rondinele Prado on 07.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#include "../include/Fuga.h"
#include "../include/Contraponto.h"
#include "../include/Melodias.h"

//--------------------------------------------------------------------------------------------------
//
MuMaterial Fuga::geraFuga(){
    
    MuMaterial fuga;
    MuMaterial aux = sujeito;
    
    fuga = geraExposicao(sujeito);
    
    fuga = geraDesenvolvimento(sujeito, fuga);
    
    //Finalizacao
    fuga.Append(0, sujeito, 0);
    aux.DiatonicTranspose(0, MAJOR_MODE, 5, ASCENDING);
    fuga.Append(1, aux, 0);
    aux.Clear();
    aux.Append(0, sujeito.GetNote(0));
    aux.Transpose(-12);
    
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
    
    switch(indice_transformacao)
    {
            //Caso 1 Aplica a funcao Retro ao sujeito
        case 1:
            transformacao.Retro();
            break;
            //Caso 2 Aplica a funcao CyclePitch ao sujeito, todas as notas serao iguais as suas precedentes
        case 2:
            transformacao.CycleRhythm((int)transformacao.NumberOfNotes() - 1);
            break;
            //caso 5 quando o contrasujeito1 passar pelo Caso 2 todas as notas do contrasujeito 2 serao as precedentes de suas 				precedentes
        case 5:
            transformacao.CycleRhythm((int)transformacao.NumberOfNotes() - 2);
            break;
            //Repete o primeiro caso por conta de peculiaridades do codigo
        case 6:
            transformacao.Retro();
            break;
            //Caso default, mais provavel , chama a classe que cria contraponto criada no segundo trabalho da materia
        default:
            Contraponto* c = new Contraponto(melodia_original);
            int tessitura[] = TESSITURA_SOPRANO;
            c->geraPrimeiraEspecie(tessitura);
            transformacao = c->getContraponto();
            
            if (transformacao.NumberOfNotes() == 0){
                transformacao = melodia_original;
                transformacao.Retro();
            }
            break;
    }
    
    return transformacao;
}


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por gerar o primeiro contra-sujeito da fuga.
 *
 * \param sujeito MuMaterial contendo o sujeito da fuga
 * \param indice_transformacao indice da escolha da transformacao do sujeito
 *
 */
MuMaterial geraContraSujeito1(MuMaterial sujeito, short indice_transformacao){
    
    //Escolhe a transformacao que ira resultar no contrasujeito
    return geraTransformacao(sujeito, indice_transformacao);
    
}
//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por gerar o segundo contra-sujeito da fuga.
 *
 * \param sujeito MuMaterial contendo o sujeito da fuga
 * \param indice_transformacao indice da escolha da transformacao do sujeito
 *
 */
MuMaterial geraContraSujeito2(MuMaterial sujeito, short indice_transformacao){
    //Parametro feito para evitar que o primeiro contra sujeito seja igual ao segundo
    short ind2;
    //Sequencia de 'if's para garantir que o primeiro contra sujeito seja igual ao segundo
    if (indice_transformacao == 1){
        ind2=Between(2,4);
    }
    if (indice_transformacao == 2){
        ind2=Between(3,6);
    }
    else{
        ind2=Between(1,4);
    }
    
    //Escolhe a transformacao que ira resultar no contrasujeito
    return geraTransformacao(sujeito, ind2);
    
}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Fuga::geraExposicao(MuMaterial sujeito){
    
    MuMaterial seq, aux;
    MuVoice voice;
    short indice_transformacao;
    
    seq.AddVoices(2);
    
    //Obtemos o sujeito
    seq = sujeito;
    float dur_ultima_nota = sujeito.GetNote(sujeito.GetVoice(0).NumberOfNotes()-1).Dur();
    
    //Exposição
    
    //Voz 1
    aux = seq; //Sujeito
    
    //Escolha do contra-sujeitos------------
    
    //escolhe aleatoriamente a mudanca que sera feita no sujeito para criar o contrasujeito1
    indice_transformacao=Between(1, 4);
    //Invoca a funcao para gerar o primeiro contra-sujeito
    while(contra_sujeito_1.Dur() == 0) contra_sujeito_1 = geraContraSujeito1(aux, indice_transformacao);
    seq.Append(0, contra_sujeito_1, 0);
    //Invoca a funcao para gerar o segundo contra-sujeito
    while(contra_sujeito_2.Dur() == 0) contra_sujeito_2 = geraContraSujeito2(aux, indice_transformacao);
    seq.Append(0, contra_sujeito_2, 0);
    
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
/*!
 * Metodo responsavel por ajustar o tamanho de todas as vozes para terem o mesmo tamanho que a maior voz
 *
 * \param mat MuMaterial contendo um material com as vozes jah geradas
 *
 */
MuMaterial ajustaTamanhoVozes(MuMaterial mat){
    
    //Obtem a melodia original
    MuMaterial seq = mat;
    
    int maior_voz = 0;
    
    for(int i = 1; i < 3; i ++) {
        if(seq.GetVoice(i).Dur() > seq.GetVoice(maior_voz).Dur()){
            maior_voz = i;
        }
    }
    
    MuMaterial mat_voz_menor,
    mat_preenchimento,
    notas_aux;
    
    float tamanho_preenchimento;
    
    MuNote nota, pausa;
    
    //Seta a amplitude da nota para que ela seja uma pausa
    pausa.SetAmp(0);
    
    int j;
    
    for(int i = 0; i < 3; i++){
        if(i != maior_voz){
            
            //Obtem a voz a ser prolongada
            mat_voz_menor = seq.GetVoice(i);
            
            //A duracao que falta para a menor voz ter o tamanho da maior voz
            tamanho_preenchimento = seq.GetVoice(maior_voz).Dur() - mat_voz_menor.Dur();
            
            //Escolhe um numero aleatorio que vai servir para determinar qual serah a transformacao no desenvolvimento
            int opcao = 100;//Between(0, 100);
            
            if (opcao < 10){
                //Se opcao igual a 0, a voz serah preenchida com pausas ateh ter o mesmo tamanho da maior voz.
                mat_preenchimento.Clear();
                
                pausa.SetDur(tamanho_preenchimento);
                
                //Insere a pausa no material que preencherah a voz menor
                mat_preenchimento.Append(0, pausa);
                
                //Anexa na voz menor
                seq.Append(i, mat_preenchimento, 0);
            }
            
            //Se opcao igual a 1, a voz serah preenchida com sua propria melodia retrogradada ateh ter o mesmo tamanho da maior voz.
            else {
                //Obtem as ultimas notas da voz a ser prolongada de modo que a duracao do material que as contem seja a que falta para preencher esta voz
                mat_preenchimento = mat_voz_menor;
                
                //Retrograda o material de preenchimento
                mat_preenchimento.Retro();
                
                j = 0;
                
                notas_aux.Clear();
                
                //Anexa em uma voz auxiliar ateh que a sua duracao seja igual ah duracao que falta
                do{
                    notas_aux.AddNote(mat_preenchimento.GetNote(j++));
                    //printf("While: duracao Voz %d: %f\n, durNota: %f\n", i, notas_aux.Dur(), mat_preenchimento.GetNote(j).Dur());
                }while(notas_aux.Dur() < tamanho_preenchimento);
                
                //Se a duracao da voz auxiliar for maior que a duracao que falta
                if(notas_aux.Dur() > tamanho_preenchimento){
                    //Eh pq a duracao da ultima nota da voz auxiliar eh maior do que devia, entao
                    
                    //Obtem a ultima nota
                    nota = notas_aux.GetNote(notas_aux.NumberOfNotes()-1);
                    
                    //Reduz a duracao para a correta
                    nota.SetDur(notas_aux.GetNote(notas_aux.NumberOfNotes()-1).Dur() - (notas_aux.Dur() - tamanho_preenchimento));
                    
                    //Remove a ultima nota que tem duracao errada
                    notas_aux.RemoveNote(notas_aux.NumberOfNotes()-1);
                    
                    //Seta a ultima nota com a duracao correta
                    notas_aux.AddNote(nota);
                }
                
                seq.Append(i, notas_aux, 0);
                
            }
        }
    }
    
    //for(int i = 0; i < 3; i++) printf("duracao Voz %d: %f\n", i, seq.GetVoice(i).Dur());
    
    return seq;
}

//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por desenvolver um material
 *
 * \param mat MuMaterial contendo um material
 *
 */
MuMaterial desenvolveMaterial(MuMaterial mat){
    
    MuMaterial seq,
    aux = mat;
    
    //Escolhe um numero aleatorio que vai servir para determinar qual serah a transformacao no desenvolvimento
    int opcao = Between(0, 100);
    
    if (opcao < 50) aux = Melodias::VariaMelodiaAleatoriamente(mat);
    
    aux.Fit(mat.Dur()*2);
    seq.Append(0, aux, 0);
    aux.DiatonicTranspose(0, MAJOR_MODE, 5, ASCENDING);
    seq.Append(1, aux, 0);
    aux.Fit(mat.Dur()/2);
    seq.Append(2, aux, 0);
    aux.Retro();
    seq.Append(2, aux, 0);
    
    return seq;
}

//--------------------------------------------------------------------------------------------------
//
MuMaterial Fuga::geraDesenvolvimento(MuMaterial sujeito, MuMaterial mat_exposicao){
    
    //Obtemos o sujeito
    MuMaterial seq = mat_exposicao,
    aux = sujeito;
    
    //Desenvolvimento
    for(int i = 0; i < 3; i++){
        seq.Append(i, desenvolveMaterial(sujeito), i);
        seq.Append(i, desenvolveMaterial(contra_sujeito_1), i);
        seq.Append(i, desenvolveMaterial(contra_sujeito_2), i);
    }
    
    //    for(int i = 0; i < 3; i++){
    //        seq.Append(i, desenvolveMaterial(Melodias::VariaMelodiaAleatoriamente(sujeito)), i);
    //        seq.Append(i, desenvolveMaterial(Melodias::VariaMelodiaAleatoriamente(contra_sujeito_1)), i);
    //        seq.Append(i, desenvolveMaterial(Melodias::VariaMelodiaAleatoriamente(contra_sujeito_2)), i);
    //    }
    
    //Ajusta tamanho das vozes para entrarem na Finalizacao juntas
    seq = ajustaTamanhoVozes(seq);
    
    return seq;
}
