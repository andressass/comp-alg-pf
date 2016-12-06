//
//  Fuga.cpp
//  Exerc1
//
//  Created by Rondinele Prado on 07.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#include "../include/Fuga.h"
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
                
                if (transformacao.NumberOfNotes() == 0) cout << "\nContraponto vazio\n";
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
	seq.Append(0, geraContraSujeito1(aux, indice_transformacao), 0);
	//Invoca a funcao para gerar o segundo contra-sujeito
	seq.Append(0, geraContraSujeito2(aux, indice_transformacao), 0);
    
    
    //Adiciona na variavel seq
    
    
    // OLD -----------------------------------
    //aux.Retro(); //Contra-Sujeito 1
    //seq.Append(0, aux, 0);
    
    
    //aux.CycleRhythm((int)aux.NumberOfNotes() - 1); //Contra Sujeito 2
    //Contraponto* c = new Contraponto(sujeito);
    //int tessitura[] = TESSITURA_SOPRANO;
    //c->geraPrimeiraEspecie(tessitura);
    //aux = c->getContraponto();
    //seq.Append(0, aux, 0);
    //----------------------------------------
    
    
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
