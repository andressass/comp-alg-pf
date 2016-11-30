//
//  Orquestra.h
//  Trab1
//
//  Created by Rondinele Prado on 11.10.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#ifndef Orquestra_h
#define Orquestra_h

#include <MuMaterial.h>

class Orquestra {
    
    
public:
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo rsponsavel por setar o bloco de paramtros necessarios para a execucao da flauta em cada
     * uma das notas do instrumento.
     *
     * \param material Material com as notas a serem setadas
     * \param numVoz numero da voz
     */
    static void setFlauta(MuMaterial* material, short numVoz){
        
        MuMaterial aux;
        MuParamBlock params;
        
        for (int i = 0; i < material->GetVoice(numVoz).NumberOfNotes(); i++){
            MuNote nota = material->GetVoice(numVoz).GetNote(i);
            
            params.Clear();
            params.AddParam(0.9 + nota.Pitch()/1000.0f); //Pressure
            params.AddParam(.036); //Breath
            params.AddParam(.4); //Fb1
            params.AddParam(.4); //Fb2
            
            nota.SetParams(params);
            nota.SetAmp(2000);
            aux.AddNote(nota);
        }
        
        material->SetVoice(numVoz, aux, 0);
    }
    
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo rsponsavel por setar o bloco de paramtros necessarios para a execucao da flauta em cada
     * uma das notas do instrumento.
     *
     * \param material Material com as notas a serem setadas
     * \param numVoz numero da voz
     */
    static void setClarineta(MuMaterial* material, short numVoz){
        
        MuMaterial aux;
        MuParamBlock params;
        
        for (int i = 0; i < material->GetVoice(numVoz).NumberOfNotes(); i++){
            MuNote nota = material->GetVoice(numVoz).GetNote(i);
            
            params.Clear();
            params.AddParam(1.5 + nota.Pitch()/300.0f); //Pressure
            params.AddParam(1000); //Filter
            params.AddParam(.2); //Embrochure
            params.AddParam(1); //Reedtable
            
            nota.SetParams(params);
            nota.SetAmp(1700);
            aux.AddNote(nota);
        }
        
        material->SetVoice(numVoz, aux, 0);
    }
};


#endif /* Orquestra_h */
