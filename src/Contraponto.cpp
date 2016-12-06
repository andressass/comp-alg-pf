//
//  Contraponto.cpp
//  Exerc1
//
//  Created by Rondinele Prado on 27.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#include "../include/Contraponto.h"
#include "../include/Melodias.h"
#include <math.h>

#define DUR_FINALIS 2.2

//--------------------------------------------------------------------------------------------------
/* Metodo que retorna o numero de semitons relativos entre duas alturas absolutas
 */
int getIntervalo(MuNote nota1, MuNote nota2){
    
    return abs(nota1.Pitch()%12 - nota2.Pitch()%12);
}

//--------------------------------------------------------------------------------------------------
/* Metodo que  gera todas as provaveis notas no intervalo da tessitura de acordo com a tonica
 *
 * \param tessitura Vetor contendo o maximo e o minimo da tessitura
 * \return Conjunto de notas da tessitura
 */
MuMaterial geraNotasTessitura(int* tessitura){
    MuMaterial notas, muMatNota;
    MuNote nota;
    
    nota.SetPitch(tessitura[0]); //Primeira nota da tessitura
    //nota.SetDur(1);
    nota.SetAmp(.5);
    muMatNota.Append(0, nota);
    int i = 2;
    
    do {
        //Adiciona a nota atual
        notas.AddNote(muMatNota.GetNote(0));
        //Transpoe a nota de um grau
        muMatNota.Clear();
        muMatNota.Append(0, nota);
        muMatNota.DiatonicTranspose(0, MAJOR_MODE, i++, ASCENDING);
    }
    //Enquanto nao atingirmos a maior altura da tessitura
    while (muMatNota.GetNote(0).Pitch() <= tessitura[1]);
    
    return notas;
}

//--------------------------------------------------------------------------------------------------
/* Metodo que escolhe uma nota de altura multipla da nota passada como parametro na regiao da
 * tessitura
 *
 *  \param notasTessitura Conjunto de notas da tessitura
 *  \return Nota equivalente
 */
MuMaterial obtemNotaTessitura(MuMaterial* notasTessitura, MuNote nota){
    MuMaterial notas;
    
    //Percorremos cada uma das notas da tessitura
    for (int i = 0; i < notasTessitura->NumberOfNotes(); i++)
        //Se a nota for equivalente
        if (nota.Pitch() % 12 == notasTessitura->GetNote(i).Pitch() % 12)
            notas.AddNote(notasTessitura->GetNote(i));
    
    //Retornamos uma nota arbitraria, dentre as equivalentes
    return notas;
}

//--------------------------------------------------------------------------------------------------
//
void Contraponto::geraPrimeiraEspecie(int* tessitura){
    
    //Escolher-se-a arbitrariamente a primeira nota
    MuNote tonica = cantusFirmus.GetNote(0);
    MuMaterial matTonica;
    matTonica.AddNote(tonica);
    
    //Geramos as possiveis notas de acordo com a tessitura
    MuMaterial notasTessitura = geraNotasTessitura(tessitura);
    
    //Cria-se o noh raiz com a nota escolhida
    tonica = matTonica.GetNote(0);
    
    //Obtemos as possiveis alturas iniciais na regiao da tessitura
    matTonica = obtemNotaTessitura(&notasTessitura, tonica);
    
    //Cria o noh
    NohArvore<MuNote>* noh = new NohArvore<MuNote>(tonica, 0);
    
    //Enquanto nao encontramos um resultado, tentamos todas as notas
    // iniciais possiveis
    do{
        if (matTonica.NumberOfNotes() == 0) return;
        int noteNumber = Between(0,(int) matTonica.NumberOfNotes()-1);
        tonica = matTonica.GetNote(noteNumber);
        noh = new NohArvore<MuNote>(tonica, 0);
        matTonica.RemoveNote(noteNumber);
    
    }
    //Calculamos as demais notas baseado na primeira nota escolhida
    while (calculaNotasPrimeiraEspecie(notasTessitura, noh) == 0);
    
    contraponto.Retro(); //Invertemos, pois as notas sao adicionadas ao contrario
}


//--------------------------------------------------------------------------------------------------
//
int Contraponto::calculaNotasPrimeiraEspecie(MuMaterial notasTessitura, NohArvore<MuNote>* noh){
    
    cout << "===============" << "\n";
    cout << "Noh: " << noh << "\n";
    cout << "Profundidade: " << noh->getProfundidade() << "\n";
    cout << "Nota: " << noh->getConteudo().Pitch() << "\n";
    cout << "===============" << "\n";
    
    //Se chegamos na penultima nota
    if (noh->getProfundidade() ==  cantusFirmus.GetVoice(0).NumberOfNotes() - 2){
        //Se a penultima nota for a sensivel
        if((noh->getConteudo().Pitch() % 12 == (cantusFirmus.GetNote(0).Pitch() + 11 )% 12 ||
            noh->getConteudo().Pitch() % 12 == (cantusFirmus.GetNote(0).Pitch() + 10 )% 12)){
            
            
            //Fazemos a verificacao do setimo grau (se eh a sensivel)
            MuNote nota = noh->getConteudo();
            
            //Verifica se é a sensivel, se nao adiciona um semitom
            if ( //Verificamos a relacao de semitom entre a sensivel e tonica
                nota.Pitch() % 12 == (cantusFirmus.GetNote(0).Pitch() + 10 )% 12 &&
                //Vericamos a relacao entre a tonica e o segundo grau
                getIntervalo(cantusFirmus.GetNote(cantusFirmus.NumberOfNotes()-2),
                             cantusFirmus.GetNote(cantusFirmus.NumberOfNotes()-1)) != 1
                )
                nota.SetPitch(nota.Pitch() + 1);
            
            //Adicionamos a finalis
            MuNote finalis = nota;
            finalis.SetPitch(finalis.Pitch() + 1);
            if(getIntervalo(cantusFirmus.GetNote(0), finalis) != 0) finalis.SetPitch(finalis.Pitch() + 1);
            
            finalis.SetDur(cantusFirmus.GetNote(noh->getProfundidade() + 1 ).Dur());
            contraponto.Append(0, finalis);
            
            //Adicionamos a sensivel
            nota.SetDur(cantusFirmus.GetNote(noh->getProfundidade()).Dur());
            contraponto.Append(0, nota);
            
            //Retorno positivo
            return 1;
        }
        else {
            //Deleta o noh e volta ao pai
            noh->remove();
            return 0;
        }
    }
    
    //Obtemos o conjunto possível de notas
    MuMaterial notasPotenciais = notasTessitura;
    
    //Filtramos de acordo com as regras do contraponto
    filtroHarmonicoPrimeiraEspecie(&notasPotenciais, noh);
    filtroMelodicoPrimeiraEspecie(&notasPotenciais, noh);
    
    cout << "===============" << "\n";
    cout << "Filhos\n";
    //Adicionamos as notas ao pai
    for (int i = 0; i < notasPotenciais.NumberOfNotes(); i++){
        MuNote filho = notasPotenciais.GetNote(i);
        noh->addFilho(filho);
        
        
        cout << filho.Pitch() << " ";
    }
    cout << "\n===============" << "\n";
    int resultado = 0;
    
    //Obtemos os filhos
    Lista<NohArvore<MuNote>*>* filhos = noh->getFilhos();
    
    while(resultado == 0){
        
        //Se o noh nao possui mais filhos, deletamos o noh e voltamos um passo
        if (filhos->getTamanho() == 0) {
            noh->remove();
            return 0;
        }
        
        //Escolhemos um filho qualquer e fazemos a recursao
        filhos->embaralha();
        
        resultado = calculaNotasPrimeiraEspecie(notasTessitura, filhos->getPrimeiro());
        
        
        
        //Se o retorno foi positivo (1), adicionamos a nota atual e retornamos
        if (resultado == 1) {
            MuNote n = noh->getConteudo();
            n.SetDur(cantusFirmus.GetNote(noh->getProfundidade()).Dur()); //Duracao da nota
            contraponto.Append(0, n);
            return 1;
        }
    }
    return 0;
}


//--------------------------------------------------------------------------------------------------
//
void Contraponto::filtroHarmonicoPrimeiraEspecie(MuMaterial *notas, NohArvore<MuNote>* noh){
    
    
    MuNote notaCantusFirmusAtual = cantusFirmus.GetNote(noh->getProfundidade());
    MuNote notaCantusFirmusProx = cantusFirmus.GetNote(noh->getProfundidade()+1);
    bool restricaoQuinta = false,
    restricaoOitava = false,
    restricaoTerca = false,
    restricaoSexta = false;
    
    //Verifica se o intervalo anterior é uma quinta ou oitava justa
    if (noh->getProfundidade() > 0){
        //Obtemos as notas anteriores
        MuNote notaContrapontoAtual = noh->getConteudo();
        
        //Verificamos os intervalos
        int intervaloAnt = getIntervalo(notaCantusFirmusProx, notaContrapontoAtual);
        restricaoQuinta = intervaloAnt == 7;
        restricaoOitava = intervaloAnt == 0;
    }
    
    //Verificamos os intervalos de terca e sexta (max 3 repeticoes)
    if(noh->getProfundidade() > 2){
        restricaoTerca = true;
        restricaoSexta = true;
        int profundidade = noh->getProfundidade();
        NohArvore<MuNote>* nohAnt = noh;
        
        //Verificamos cada um dos tres niveis anteriores
        for (int i = 0; i < 3; i++){
            
            //Se nao for uma terca
            if (getIntervalo(nohAnt->getConteudo(), cantusFirmus.GetNote(profundidade)) != 3 &&
                getIntervalo(nohAnt->getConteudo(), cantusFirmus.GetNote(profundidade)) != 4)
                restricaoTerca = false;
            
            //Se nao for uma sexta
            if (getIntervalo(nohAnt->getConteudo(), cantusFirmus.GetNote(profundidade)) != 8 &&
                getIntervalo(nohAnt->getConteudo(), cantusFirmus.GetNote(profundidade)) != 9)
                restricaoSexta = false;
            nohAnt = nohAnt->getPai();
            profundidade--;
        }
    }
    
    
    //Checamos os intervalos harmonicos possiveis
    int i = 0;
    do{
        MuNote notaProx = notas->GetNote(i);
        
        //Checa o intervalo hamonico
        int intervalo = getIntervalo(notaCantusFirmusProx, notaProx);
        if(
           !(intervalo == 3 || //Se o intervalo for de terca menor
             intervalo == 4 || //terca maior
             (intervalo == 7 && !restricaoQuinta) || //quinta justa
             intervalo == 8 || //Sexta menor
             intervalo == 9 || //Sexta maior
             (intervalo == 0 && !restricaoOitava)) //Oitava
           ){
            notas->RemoveNote(i);
            i--;
        }
        else{
            //Elimina cruzamento de vozes
            //Se a nota anterior do contraponto for mais alta que a atual do cantus firmus
            //Evitamos o uníssono
            //So aceitamos notas mais altas
            
            if(noh->getConteudo().Pitch() >= notaCantusFirmusAtual.Pitch()){
               if(notaProx.Pitch() <= notaCantusFirmusProx.Pitch()){
                    notas->RemoveNote(i);
                    i--;
               }
            }
            //Se nao, so aceitamos mais baixas
            else {
                if (notaProx.Pitch() >= notaCantusFirmusProx.Pitch()){
                    notas->RemoveNote(i);
                    i--;
                }
            }
        }
        i++;
    } while (i < notas->NumberOfNotes());
}


//--------------------------------------------------------------------------------------------------
/* Metodo aplica regras melodicas do contraponto de primeira especie. Na primeira especie, somente
 * sao permitidos os intervalos melodicos de 2m, 2M, 3m, 3M, 4J, 5J, 6m ascendente, e 8J.
 *
 *  \param notas Notas a serem filtradas
 *  \param noh Noh atual
 */
void Contraponto::filtroMelodicoPrimeiraEspecie(MuMaterial *notas, NohArvore<MuNote>* noh){
    
    
    //Se houver uma nota anterior
    if (noh->getPai() != nullptr){
        
        MuNote notaAtual = noh->getConteudo();
        
        //Checamos os intervalos harmonicos possiveis
        for (int i = 0; i < notas->NumberOfNotes(); i++){
            MuNote notaProx = notas->GetNote(i);
            
            //Checa o intervalo hamonico
            bool ascendente = notaProx.Pitch() - notaAtual.Pitch() > 0;
            int intervalo = abs(notaAtual.Pitch() - notaProx.Pitch());
            
            if(
               !(intervalo == 1 || //Se o intervalo for de segunda menor
                 intervalo == 2 || //segunda maior
                 intervalo == 3 || //terca menor
                 intervalo == 4 || //terca maior
                 intervalo == 5 || //terca maior
                 intervalo == 7 || //quinta justa
                 (intervalo == 8 && ascendente) || //Sexta menor ascendente
                 intervalo == 0) //Oitava
               ){
                notas->RemoveNote(i);
                i--;
            }
        }
    }
}


//--------------------------------------------------------------------------------------------------
//
void Contraponto::setCantusFirmus(short* cantusFirmus, short numNotas){
    MuMaterial cantus = Melodias::criaMelodia(cantusFirmus, 1, numNotas);
    
    MuNote nota = cantus.GetNote(cantus.NumberOfNotes()-1);
    MuNote nota2 = cantus.GetNote(cantus.NumberOfNotes()-2);
    
    //nota.SetDur(nota.Dur() * DUR_FINALIS);
    //nota2.SetDur(nota2.Dur() * 2);
    
    cantus.RemoveNote(cantus.NumberOfNotes()-1);
    cantus.RemoveNote(cantus.NumberOfNotes()-1);
    
    cantus.Append(0, nota2);
    cantus.Append(0, nota);
    
    this->cantusFirmus = cantus;
}
