//
//  arvore.h
//  Exerc1
//
//  Created by Rondinele Prado on 27.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//


#ifndef arvore_h
#define arvore_h

#include<cstddef>
#include <cstdlib>
#include <iostream>
#include "../include/Lista.h"

using namespace std;

template <class T>

class NohArvore{

private:
    T conteudo;
    NohArvore* pai;
    Lista<NohArvore*>* filhos;
    short profundidade;

public:
    
    NohArvore(T conteudo, short profundidade){
        
        this->conteudo = conteudo;
        pai = NULL;
        filhos = new Lista<NohArvore*>();
        this->profundidade = profundidade;
    }
    
    void remove(){
        //delete conteudo;
        //if(filhos != nullptr) delete filhos;
        if (pai != nullptr && pai->getFilhos() != nullptr) pai->getFilhos()->remove(this);
    }
    
    T getConteudo(){ return conteudo; }
    
    Lista<NohArvore*>* getFilhos(){ return filhos; }
    
    void setPai(NohArvore* pai){ this->pai = pai; }
    
    NohArvore* getPai(){ return pai; }
    
    short getProfundidade() { return profundidade; }
    
    void addFilho(T conteudo){
        NohArvore* filho = new NohArvore(conteudo, this->profundidade + 1);
        filho->setPai(this);
        filhos->adicionaInicio(filho);
    }
};


#endif /* arvore_h */
