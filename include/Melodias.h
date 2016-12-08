//
//  Melodias.h
//  Exerc1
//
//  Created by Rondinele Prado on 07.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//

#ifndef Melodias_h
#define Melodias_h

#include "../MuM-master/MuMaterial.h"

#define C 60
#define D 62
#define E 64
#define F 65
#define G 67
#define A 69
#define H 71

#define is +1
#define es -1

#define _u +12
#define _d -12

class Melodias{
    
public:
    
    Melodias(){};
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a geração de uma melodia aleatoria dentro de uma determinada
     * tonalidade.
     *
     * \param tonalidade Tonalidade da melodia a ser gerada.
     * \param modo Modo da tonalidade a ser gerada.
     * \param num_notas Numero de notas a serem geradas
     * \param grau_liberdade Grau de liberdade dos saltos
     * \param max_amplitude Maxima distancia entre o centro tonal que a melodia pode alcancar
     *
     * \return MuMaterial contendo a sequencia de notas.
     */
    static MuMaterial melodiaTonalAleatoria(short tonalidade, short modo, short num_notas, short grau_liberdade, short max_amplitude);
    
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a geração de uma melodia aleatoria atonal
     *
     * \param altura_inicial altura da primeira e ultima notas
     * \param num_notas Numero de notas a serem geradas
     * \param grau_liberdade Grau de liberdade dos saltos
     * \param max_amplitude Maxima distancia entre o centro tonal que a melodia pode alcancar
     *
     * \return MuMaterial contendo a sequencia de notas.
     */
    static MuMaterial melodiaAtonalAleatoria(short altura_inicial, short num_notas, short grau_liberdade, short max_amplitude);
    
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a geração de uma escala maior ascendente sequida de sua
     * equivalente descendente
     *
     * \param tonalidade tonalidade da escala
     * \param duracao_notas duracao de cada nota
     *
     * \return MuMaterial contendo a sequencia de notas.
     */
    static MuMaterial EscalaMaiorAscendenteDescendente(short tonalidade, float duracao_notas);
    
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a variacao de uma melodia de forma aleatoria, gerando uma 
     * melodia diferente com a mesma estrutura rítmica.
     *
     * \param melodia Melodia a ser variada
     *
     * \return MuMaterial contendo a sequencia de notas.
     */
    static MuMaterial VariaMelodiaAleatoriamente(MuMaterial melodia);
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por criar um conjunto de n notas de mesma duracao baseado nas alturas contidas
     * no vetor passado como parametro
     *
     * \param alturas Vetor de alturas
     * \param duracao Duracao de cada nota
     * \param numNotas numero de notas no vetor
     *
     * \return MuMaterial contendo a sequencia de notas.
     */
    static MuMaterial criaMelodia(short* alturas, short duracao , short numNotas);
    
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por criar um conjunto de n notas baseado nas alturas e duracoes contidas
     * no vetor passado como parametro
     *
     * \param parametros Vetor de alturas
     *
     * \return MuMaterial contendo a sequencia de notas.
     */
    static MuMaterial criaMelodia(float* parametros);
    
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel imprimir as alturas de cada nota do mum
     *
     */
    static void printAlturas(MuMaterial notas){
        cout<< "\n";
        for (int i = 0; i < notas.NumberOfNotes(); i++) cout << "---";
        
        cout<< "\n";
        for (int i = 0; i< notas.NumberOfNotes(); i++) cout << notas.GetNote(i).Pitch() << " ";
        
        cout << "\n";
        for (int i = 0; i < notas.NumberOfNotes(); i++) cout << "---";
        cout << "\n";
    }
    
    //--------------------------------------------------------------------------------------------------
    /*!
     * Metodo responsavel por implementar a geração da melodia referente ao sujeito da Fuga em Do Maior
     * de O Cravo bem temperado I.
     *
     * \return MuMaterial contendo a sequencia de notas.
     */
    static MuMaterial wtkMelody(){
        
        MuMaterial material;
        MuNote note;
        note.SetInstr(2);
        note.SetDur(0.5);
        
        note.SetPitch(60);
        
        note.SetAmp(0.7);
        note.SetPitch(60);
        material.Append(0, note);
        note.SetPitch(62);
        material.Append(0, note);
        note.SetPitch(64);
        material.Append(0, note);
        note.SetPitch(65);
        note.SetDur(.75);
        material.Append(0, note);
        note.SetPitch(67);
        note.SetDur(.125);
        material.Append(0, note);
        note.SetPitch(65);
        material.Append(0, note);
        note.SetPitch(64);
        note.SetDur(.5);
        material.Append(0, note);
        note.SetPitch(69);
        note.SetDur(.5);
        material.Append(0, note);
        note.SetPitch(62);
        note.SetDur(.5);
        material.Append(0, note);
        note.SetPitch(67);
        note.SetDur(.75);
        material.Append(0, note);
        
        
        note.SetPitch(69);
        note.SetDur(.25);
        material.Append(0, note);
        note.SetPitch(67);
        material.Append(0, note);
        note.SetPitch(65);
        material.Append(0, note);
        note.SetPitch(64);
        material.Append(0, note);
        
        return material;
    }
};


#endif /* Melodias_h */
