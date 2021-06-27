#include "headers/arvore.h"
#include "headers/no.h"
#include <string>
#include <iostream>

Arvore::Arvore(){                                                   //construtor vazio.
    this->raiz = nullptr;
}

void Arvore::insere_recursivo(No* &p, std::string _chave){          //recebe um no e uma chave.
    if(p==nullptr){                                                 //checa se o no eh nulo, se for aloca espaco na memoria e seta sua chave como a string passada na chamada do metodo.
        p = new No();
        p->chave = _chave;
    }else{                                                          //caso nao seja, vai recursivamente caminhar pela arvore seguindo a regra de ordenacao das chaves, ate encontrar no nulo
        if(_chave < p->chave){                                      //e no caso entrar na condicao de parada (inserindo o no propriamente dito).
            insere_recursivo(p->esq, _chave);
        }else{
            insere_recursivo(p->dir, _chave);
        }
    }
}

void Arvore::insere(std::string chave){                             //recebe a chave a ser inserida e chama insere_recursivo partindo da raiz.
    insere_recursivo(raiz, chave);
}

void Arvore::antecessor(No* q, No* &r){                             //recebe o no a se retirar e o seu no antecessor(assume que eh seu no esquerdo).
    if(r->dir != nullptr){                                          //checa se o no assumido como antecessor nao possui no a sua direita, pois caso tenha, o no assumido inicialmente           
        antecessor(q, r->dir);                                      //como antecessor nao o eh de fato. entao checa-se recursivamente ate que seja o caso, ou seja, teremos de fato o no
        return;                                                     //antecessor de q.
    }
    q->chave = r->chave;                                            //troca-se a chave de p, logo em seguida q recebe r, r recebe seu no a esquerda e deleta-se q, terminando assim a remocao.
    q = r;
    r = r->esq;
    free(q);
}

void Arvore::remove_recursivo(No* &no, std::string chave){          //recebe-se um no de partida e uma chave a ser removida da arvore.
    No *aux;
    if (no == NULL) {
        throw("Item nao está presente");                            //checa se no esta na arvore.
    }
    if(chave < no->chave){                                          //procura pelo no recursivamente seguindo a regra de ordenacao da arvore.
        return remove_recursivo(no->esq, chave);
    }else if(chave > no->chave){
        return remove_recursivo(no->dir, chave);
    }else{                                                          //else eh executado quando se acha o no.
        if(no->dir == nullptr){                                     //se no da direita eh nulo, substitui pelo no da esquerda e apaga-se o no.
            aux = no;
            no = no->esq;
            free(aux);
        }else if(no->esq == nullptr){                               //se no da esquerda eh nulo, substitui pelo no da direita e apaga-se o no.
            aux = no;
            no = no->dir;
            free(aux);
        }else{                                                      //se no tem dois filhos, substitui pelo antecessor chamando metodo antecessor.
            antecessor(no, no->esq);
        }
    }
}

void Arvore::remove(std:: string s1){                               //recebe chave a ser removida e chama remove_recursivo passando a raiz da arvore como parametro e a chave a ser removida.
    
    return remove_recursivo(raiz, s1);
}

void Arvore::substitui(std::string s1, std::string s2){             //recebe duas strings, chama remove para a primeira e insere para a segunda.
    remove(s1);
    insere(s2);
}

void Arvore::pre_ordem_encripta(No *no, std::string a, int *i){     //recebe no inicial, string e um iterador ponteiro inteiro e faz o caminhamento pre ordem na arvore.
    if (no != nullptr){                                             //condicao de parada quando o no eh nulo.
        if (a == no->chave){                                        //se a string for igual a chave do no, imprime-se a sua posicao, ou seja, o iterador.
            std::cout<< *i <<" ";
        }
        (*i)++;                                                     //itera i e chama-se a si proprio recursivamente para continuar o caminhamento por toda a arvore.
        pre_ordem_encripta(no->esq, a, i);
        pre_ordem_encripta(no->dir, a, i);
    }
}

void Arvore::encripta(std::string s1){                              //recebe uma string, comeca o iterador em 1 e chama pre_ordem_encripta comecando na raiz, procurando a string e passando i
    int i = 1;                                                      //por referencia. ou seja, imprime-se a posicao da string na arvore levando em conta seu caminhamento pre ordem.
    pre_ordem_encripta(raiz, s1, &i);
}

void Arvore::pre_ordem_desencripta(No *no, int posicao, int *i){    //similar ao metodo pre_ordem_encripta, mas agora se recebe um inteiro onde antes se recebia uma string e percorre-se a
    if (no != nullptr){                                             //arvore pelo caminhamento pre ordem. quando a posicao do iterador i for igual ao inteiro posicao, imprime-se a chave do no
        if (posicao == *i){                                         //que esta nessa posicao.
            std::cout<< no->chave <<" ";
        }
        (*i)++;
        pre_ordem_desencripta(no->esq, posicao, i);
        pre_ordem_desencripta(no->dir, posicao, i);
    }
}

void Arvore::desencripta(int posicao){                             //recebe um inteiro, comeca o iterador em 1 e chama pre_ordem_desencripta comecando na raiz, procurando a posicao e passando i
    int i = 1;                                                     //por referencia. ou seja, imprime-se a chave do no na arvore levando em conta sua posicao no caminhamento pre ordem.
    pre_ordem_desencripta(raiz,posicao, &i);
}