//
//  Contraponto.h
//  Exerc1
//
//  Created by Rondinele Prado on 27.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#ifndef Contraponto_h
#define Contraponto_h

#include "../MuM-master/MuMaterial.h"
#include "../include/Arvore.h"

#define TESSITURA_SOPRANO {60,79}
#define TESSITURA_CONTRALTO {55,72}
#define TESSITURA_TENOR {47,67}
#define TESSITURA_BAIXO {40,60}

class Contraponto{
    
private:
    
    MuMaterial cantusFirmus;
    MuMaterial contraponto;
    
public:
    
    Contraponto(MuMaterial cantusFirmus){
        this->cantusFirmus = cantusFirmus;
    }
    
    Contraponto(short* cantusFirmus, short numNotas){
        setCantusFirmus(cantusFirmus, numNotas);
    }
    
    MuMaterial getCantusFirmus(){ return cantusFirmus; }
    
    MuMaterial getContraponto(){ return contraponto; }
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por gerar um contraponto de primeira espécie para a melodia contida no 
     * cantusFirmus.
     *
     * \param tessitura Tessitura da regiao vocal a ser utilizada no contraponto
     */
    void geraPrimeiraEspecie(int* tessitura);
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por setar o cantus firmus à partir de um muMaterial contendo as notas.
     *
     * \param cantusFirmus Cantus fimus a ser utilizado
     */
    void setCantusFirmus(MuMaterial cantusFirmus){ this->cantusFirmus = cantusFirmus; }
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por setar o cantus firmus à partir de uma lista de alturas (short)
     *
     * \param cantusFirmus Lista de alturas das notas do cantus firmus
     * \param numNotas numero de notas no vetor
     */
    void setCantusFirmus(short* cantusFirmus, short numNotas);
    
private:
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por calcular o conjunto de notas que formará o cantus firmus à partir de uma
     * nota inicial contida no argumento noh. O método atua de forma recursiva, buscando as possíveis
     * alturas de cada nota do contraponto em relação ao cantus firmus configurado na classe.
     * O resultado será gravado atributo "contraponto" da classe contraponto.
     *
     * \param notasTessitura Notas da tessitura da regiao vocal a ser utilizada no contraponto
     * \param noh noh a ser tomado como base para o calculo das proximas notas
     */
    int calculaNotasPrimeiraEspecie(MuMaterial notasTessitura, NohArvore<MuNote>* noh);
    
    //--------------------------------------------------------------------------------------------------
    /* Metodo aplica regras harmonicas do contraponto de primeira especie. Na primeira especie, somente
     * sao permitidos, alem do unissono e oitava, intervalos harmonicos de 3m, 3M, 5J, 6m e 6M.
     *
     *  \param notas Notas a serem filtradas
     *  \param noh Noh atual
     */
    void filtroHarmonicoPrimeiraEspecie(MuMaterial *notas, NohArvore<MuNote>* noh);
    
    //--------------------------------------------------------------------------------------------------
    /* Metodo aplica regras melodicas do contraponto de primeira especie. Na primeira especie, somente
     * sao permitidos os intervalos melodicos de 2m, 2M, 3m, 3M, 4J, 5J, 6m ascendente, e 8J.
     *
     *  \param notas Notas a serem filtradas
     *  \param noh Noh atual
     */
    void filtroMelodicoPrimeiraEspecie(MuMaterial *notas, NohArvore<MuNote>* noh);
};


#endif /* Contraponto_h */
