//
//  Fuga.h
//  Exerc1
//
//  Created by Rondinele Prado on 07.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#ifndef Fuga_h
#define Fuga_h

#include "../MuM-master/MuMaterial.h"

using namespace std;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
/*!
 * Classe responsavel por implementar os metodos relacionados a geracao e manipulacao de melodias
 * seguindo os padroes de composicao da fuga
 
 * \author Rondinele Prado
 */
class Fuga {
    
private:
    
    MuMaterial sujeito;
    MuMaterial contra_sujeito_1;
    MuMaterial contra_sujeito_2;
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por gerar a exposicao da fuga
     *
     * \param sujeito MuMaterial contendo o sujeito da fuga
     *
     */
    MuMaterial geraExposicao(MuMaterial sujeito);
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por gerar o desenvolvimento da fuga
     *
     * \param sujeito MuMaterial contendo o sujeito da fuga
     * \param mat_exposicao MuMaterial contendo o material com a exposicao jah gerada
     *
     */
    MuMaterial geraDesenvolvimento(MuMaterial sujeito, MuMaterial mat_exposicao);
    
public:
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo construtor de objetos da classe fuga
     *
     * \param sujeito MuMaterial contendo o sujeito da fuga
     *
     */
    Fuga(MuMaterial sujeito){
        this->sujeito = sujeito;
    }
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por gerar uma fuga a partir de um sujeito
     *
     *
     */
    MuMaterial geraFuga();
    
};


#endif /* Fuga_h */
