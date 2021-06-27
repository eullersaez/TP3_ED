#include <iostream> //apenas para cin, cout, etc. TODOS os metodos de manipulacao da arvore foram implementados manualmentente, com base no que foi visto em aula!
#include <string>
#include "headers/no.h"
#include "headers/arvore.h"

int main(){

    char operacao;
    std::string s1, s2;                         
    int numero_de_palavras;                             
    int vetor_de_numeros_criptografados[20];
    std::string vetor_de_palavras[20];
    Arvore arvore;

    while (scanf("%c", &operacao) != EOF){                      //loop while checa operacao ate eof.
        switch (operacao){                                      //switch case para cada tipo de operacao entrada.
            case 'i':                                           //caso de insercao, le string e chama metodo insere para instancia 'arvore' do tipo Arvore implementado.
                std::cin>>s1; 
                arvore.insere(s1);
                break;
            case 's':                                           //caso substituicao, le strings e chama metodo substitui para instancia 'arvore' do tipo Arvore implementado.
                std::cin>>s1>>s2; 
                arvore.substitui(s1,s2);
                break;
            case 'e':                                           //caso encripta, le o numero de palavras a serem encriptadas, no primeiro loop for le cada string e armazena no vetor_de_palavras.
                std::cin>>numero_de_palavras;
                for(int i=0; i<numero_de_palavras;i++){
                    std::cin>>vetor_de_palavras[i];
                }
                for(int i = 0; i < numero_de_palavras; i++){    //segundo for chama metodo encripta para cada palavra armazenada pelo primeiro loop no vetor_de_palavras.
                    arvore.encripta(vetor_de_palavras[i]);
                }
                std::cout<<"\n";
                break;
            case 'd':                                           //caso desencripta, de modo semelhante ao caso encripta, le-se o numero de palavras que serao descriptadas e com um auxilio de um loop
                std::cin>>numero_de_palavras;                   //do tipo for armazena-se cada numero no vetor_de_numeros_criptografados.
                for(int i=0; i<numero_de_palavras;i++){
                    std::cin>>vetor_de_numeros_criptografados[i];
                }
                for(int i = 0; i < numero_de_palavras; i++){    //segundo loop chama metodo desencripta para cada numero armazenado pelo primeiro loop no vetor_de_numeros_criptografados.
                    arvore.desencripta(vetor_de_numeros_criptografados[i]);
                }
                std::cout<<"\n";
                break;
        }
    }    
    return 0;
}