//
//  Fuga.hpp
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
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por gerar a exposicao da fuga
     *
     * \param sujeito MuMaterial contendo o sujeito da fuga
     *
     */
    static MuMaterial geraExposicao(MuMaterial sujeito);
    
public:
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por gerar o desenvolvimento da fuga
     *
     * \param sujeito MuMaterial contendo o sujeito da fuga
     *
     */
    static MuMaterial geraDesenvolvimento(MuMaterial sujeito);
    
public:
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por gerar uma fuga a partir de um sujeito
     *
     * \param sujeito MuMaterial contendo o sujeito da fuga
     *
     */
    static MuMaterial geraFuga(MuMaterial sujeito);
    
};


#endif /* Fuga_h */
