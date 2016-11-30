//
//  Harmonia.h
//  TrabHarm
//
//  Created by Rondinele Prado on 01.11.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#ifndef Harmonia_h
#define Harmonia_h

#include "../MuM-master/MuMaterial.h"

#define COMPASSO 2

class Harmonia {
    
private:
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a geração de uma sequencia de acordes que representam as
     * triades do campo harmonico maior referente à tonalidade desejada.
     *
     * \param tonica Tonica do campo harmonico.
     *
     * \return MuMaterial contendo o conjunto de triades
     */
    static MuMaterial geraCampoHarmonicoMaior(short tonica);
    
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a geração de uma sequencia de acordes que representam as
     * triades do campo harmonico menor referente à tonalidade desejada
     *
     * \param tonica Tonica do campo harmonico.
     *
     * \return MuMaterial contendo o conjunto de triades
     */
    static MuMaterial geraCampoHarmonicoMenor(short tonica);
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por estimar o melhor acorde de acordo com o conjunto de notas recebidas
     *
     * \param notas Notas a serem utilizadas para a escolha de um acorde.
     * \param acordes Conjunto de acordes possiveis
     *
     * \return MuMaterial contendo o acorde escolhido
     */
    static MuMaterial escolheAcorde(MuMaterial notas, MuMaterial acordes);
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por inverter um acorde, fazendo com que a nota mais grave se torne a mais 
     * aguda
     *
     * \param acorde Acorde a ser invertido
     *
     * \return MuMaterial contendo o acorde escolhido
     */
    static MuMaterial inverteAcorde(MuMaterial acorde);
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por inverter um acorde de forma que o baixo seja a nota passada como parametro
     *
     * \param acorde Acorde a ser invertido
     * \param nota Nota a ser o baixo do acorde
     *
     * \return MuMaterial contendo o acorde escolhido
     */
    static MuMaterial inverteAcorde(MuMaterial acorde, MuNote nota);
    
public:
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a geração de uma sequencia de acordes que representam as 
     * triades do campo harmonico da tonalidade desejada.
     *
     * \param tonica Tonica do campo harmonico.
     * \param modo Modo da tonalidade.
     *
     * \return MuMaterial contendo o conjunto de triades
     */
    static MuMaterial geraCampoHarmonico(short tonica, short modo);
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a harmonizacao de uma melodia
     *
     * \param melodia Melodia a ser harmonizada
     *
     * \return MuMaterial contendo o conjunto de triades
     */
    static MuMaterial harmonizacaoMelodia(MuMaterial melodia, int tonalidade);

};


#endif /* Harmonia_h */
