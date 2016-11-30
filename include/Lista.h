//
//  Lista.h
//  Exerc1
//
//  Created by Rondinele Prado on 27.09.16.
//  Copyright © 2016 Rondinele Prado. All rights reserved.
//


#ifndef lista_h
#define lista_h

#include<cstddef>
#include <cstdlib>
#include <list>
#include <iostream>

using namespace std;

template <class T>

class NohLista{
    
private:
    T conteudo;
    NohLista* anterior = nullptr;
    NohLista* proximo = nullptr;
    
public:
    
    NohLista(T conteudo, NohLista* anterior, NohLista* proximo){
        
        this->conteudo = conteudo;
        this->anterior = anterior;
        this->proximo = proximo;
    }
    
    ~NohLista(){
        delete conteudo;
        if (anterior != nullptr)
            anterior->setProximo(proximo);
        if (proximo != nullptr)
            proximo->setAnterior(anterior);
        
    }
    
    T getConteudo(){ return conteudo; }
    void setConteudo(T conteudo){ this->conteudo = conteudo; }
    
    NohLista* getAnterior() { return  anterior; }
    NohLista* getProximo() { return  proximo; }
    void setProximo(NohLista* proximo) { this->proximo = proximo; }
    void setAnterior(NohLista* anterior) { this->anterior = anterior; }
    
    bool
    isEqual(T conteudo)
    { return this->getConteudo() == conteudo;}
    
};

template <class L>
class Lista{
    
private:
    int tamanho;
    NohLista<L>* inicio;
    
public:
    
    Lista(){
        tamanho = 0;
        inicio = nullptr;
    }
    
    ~Lista(){
        NohLista<L>* i = inicio;
        while (i != nullptr) {
            NohLista<L>* j = i;
            i = i->getProximo();
            delete j;
        }
          
    }
    
    int getTamanho(){return tamanho;}
    L getPrimeiro(){return inicio->getConteudo();}
    
    void remove(L conteudo){
        for (NohLista<L>* i = inicio ; i != nullptr; i = i->getProximo()) {
            if (i->isEqual(conteudo)){
                if (i == inicio) inicio = i->getProximo();
                delete i;
                tamanho --;
            }
        }
    }
    
    void adicionaInicio(L conteudo){
        NohLista<L>* noh = new NohLista<L>(conteudo, nullptr, inicio);
        if(inicio != nullptr) inicio->setAnterior(noh);
        inicio = noh;
        tamanho++;
    }
    
    void embaralha(){
        if (inicio == nullptr) return;
        for (int k = 0; k < rand()%33; k++)
            for (NohLista<L>* i = inicio ; i != nullptr; i = i->getProximo())
                for (NohLista<L>* j = inicio->getProximo() ; j != nullptr; j = j->getProximo()) {
                    if(rand()%101 > 25){
                        L tempCont = i->getConteudo();
                        i->setConteudo(j->getConteudo());
                        j->setConteudo(tempCont);
                    }
                }
    }
};

#endif /* lista_h */
