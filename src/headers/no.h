#ifndef NO_H
#define NO_H
#include <string>

class No{                   //classe base para a criacao da arvore.
    private:
        std::string chave;
        No *esq;
        No *dir;
    public:
        No();               //construtor.
    friend class Arvore;    //fazendo ser friend de Arvore para que ela possa acessar seus atributos privados.
};

#endif