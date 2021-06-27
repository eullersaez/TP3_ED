#ifndef ARVORE_H
#define ARVORE_H
#include <string>
#include "no.h"

class Arvore{
    private:
        No *raiz;                                               //atributo unico ponteiro do tipo No que sera raiz e demais metodos implementados (explicados detalhadamente em "arvore.cpp").
        void insere_recursivo(No* &p, std::string );            
        void remove_recursivo(No* &p, std::string );
        void remove(std:: string );
        void antecessor(No* q, No* &r);

    public:
        Arvore();
        void insere(std::string );
        void substitui(std::string , std::string );
        void pre_ordem_encripta(No * , std::string , int * );
        void pre_ordem_desencripta(No * , int , int * );
        void encripta(std::string );
        void desencripta(int );
};

#endif