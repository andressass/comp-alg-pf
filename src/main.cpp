//
//  main.cpp
//  Exerc1
//
//  Created by Rondinele Prado on 07.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#include <iostream>
#include "../MuM-master/MuMaterial.h"
#include "../include/Harmonia.h"
#include "../include/Orquestra.h"
#include "../include/Fuga.h"
#include "../include/Melodias.h"
#include <signal.h>
#include <unistd.h>


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por criar um processo que tocarah a sequencia com o csound e outro que
 * encerrara os processos csound e o atual.
 *
 * \param seq Sequencia a ser executada
 */
void playAndExit(MuMaterial seq){
    
    int pid = fork();
    
    //Processo filho toca
    if(pid == 0) {
        seq.PlaybackWithCsound("csd/out");
    }
    
    //Processo pai aquarda encerramento
    else {
        sleep(1);
        cout << endl;
        cout << "Pressione \"Enter\" para encerrar...";
        cout << "\n";
        getchar();
        system("killall -9 csound");
    }
    exit(0);
}


//--------------------------------------------------------------------------------------------------
//
int main(int argc, const char * argv[]) {
    MuInit();
    MuMaterial melodia, seq, aux;
    
    //Melodia carregada do arquivo partitura para um objeto MuMaterial
    melodia.LoadScore("csd/m3.sco");
    
    //float parametros[] = {G is, .5, A is, .25, G is, .25, F is, .25, G is, .25, F _u, .5, C is _u, .5,
    //G is, .5, F is, .25, F, .25, F is, .5, D is _u, .5, F , .5, C is _u, .5, D is, .5, C _u, .5, C is, .5 }; int numNotas = 17; //WTK3
    //short cantusFirmus[] = {60, 64, 62, 60, 65, 64, 67, 65, 64, 62, 60}; int numNotas = 11; int transp = 2;
    //float parametros[] = {60, 2, 64, 2, 65, 2, 67 ,2 , 64, 2, 69, 2, 67, 2, 64, 2, 65, 2, 64, 2, 62, 2, 60, 2}; int numNotas = 12;
    //short cantusFirmus[] = {G _d, C, H _d, G _d, C, E, D, G, E, C, D, H _d, A _d, G _d}; int numNotas = 14; int transp = 5;
    //short cantusFirmus[] = {A _d, C, H _d, C, D, E, C, H _d, A _d}; int numNotas = 9; int transp = 6;
    
    
    float parametros[] = {E, .5, E, .5, F, .5, G, .5, G, .5, F, .5, E, .5, D, .5, C, .5, C, .5, D, .5, E, .5, E, .75, D, .25, D, 1, E, .5, E, .5, F, .5, G, .5, G, .5, F, .5, E, .5, D, .5, C, .5, C, .5, D, .5, E, .5, D, .75, C, .25, C, 1, D, 1, E, .5, C, .5, D, .5, E, .25, F, .25, E, .5, C,.5, D, .5, E, .25, F, .25, E, .5, D, .5, C, .5, D, .5, G _d, .5, E, .5, E, .5, E, .5, F, .5, G, .5, G, .5, F, .5, E, .5, D, .5, C, .5, C, .5, D, .5, E, .5, D, .75, C, .25, C, 1, -1};
    
//    
//    float parametros[] = {C, .25, C, .5, E, .25, G, .25, E, .5, C, .25, D, 1, F, 1 ,
//                          H _d, .25, H _d, .5, D, .25, F, .25, D, .5, H _d, .25, C, 1, E, 1,
//                        C, .25, C, .5, E, .25, G, .25, E, .5, C, .25, D, 1, F, 1 ,
//                        H _d, .25, H _d, .5, D, .25, F, .25, D, .5, H _d, .25, C, 1, E, 1
//    };
//    
//    int numNotas = 16*2;
    
    melodia = Melodias::criaMelodia(parametros);
    //cout << melodia.Csd();
    melodia.Fit(30);
    
    seq = melodia;
    
    Fuga *fuga = new Fuga(seq);
    
    seq = fuga->geraFuga();
    
    //seq.Append(3, Harmonia::harmonizacaoMelodia(seq, 0), 0);
    
    //seq.Fit(150);
    
    //seq.SetAmp(3, 0.5);
    
    //seq.Transpose(-12);
    seq.Transpose(2, -12);
    
    Orquestra::setOrgao(&seq, 0);
    Orquestra::setOrgao(&seq, 1);
    Orquestra::setOrgao(&seq, 2);
    seq.SetAmp(2, 500);

    
    //Carrega a orquestra
    seq.LoadOrchestra("inst/pers1.orc.txt");
    seq.LoadFunctionTables("inst/pers1tables.tbl.txt");
    seq.SetInstrument(0, 5);
    seq.SetInstrument(1, 4);
    seq.SetInstrument(2, 3);

    seq.Score("csd/part");
    seq.Orchestra("csd/orq");
    
    playAndExit(seq);
}
