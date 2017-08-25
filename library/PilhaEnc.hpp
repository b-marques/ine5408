// Copyright Bruno Marques <2016.1>

#include "ListaEnc.hpp"
#include "Elemento.hpp"

//!  Classe da estrutura de dado: Pilha Encadeada.
/*!  Implementação da estruturda de dado Pilha Encadeada,
 *   realizada na disciplina de Estrutura de Dados - INE5408
 *   como quinto trabalho prático do semestre.
 *   \author Bruno Marques do Nascimento
 *   \since 14/04/2016
 *   \version 1.0
 */
template<typename T>
class PilhaEnc :private ListaEnc<T>{
 public:
//! Contrutor padrão.
/*! Sempre que usado, este construtor criará uma 
 *  pilha encadeada de tamanho zero.
 */
    PilhaEnc();

//! Destrutor.
/*! Tem a função de destruir todos
 *  os nós da pilha encadeada.
 */
    ~PilhaEnc();

//!  Função empilha, insere um novo dado na pilha, e retorna vazio.
/*!  
 *   \param dado argumento do tipo T, que será empilhado.
 *   \sa PilhaEnc()
 */
    void empilha(const T& dado);

//!  Função desempilha, retira um dado da pilha, e retorna um tipo T.
/*!  
 *   \return o dado retirado da pilha do tipo T.
 *   \sa PilhaVazia() and PilhaEnc()
 */
    T desempilha();

//!  Função topo, informa o último valor inserido na pilha, do tipo T.
/*!
 *   \return o último dado empilhado na pilha, do tipo T.
 *   \sa PilhaVazia() and PilhaEnc()
 */ 
    T topo();

//!  Função limparPilha, remove todos os dados da pilha.
/*!
 *   \sa PilhaEnc()
 */ 
    void limparPilha();

//!  Função PilhaVazia, verifica se a pilha está vazia.
/*!
 *   \return um booleano, true se a pilha estiver vazia, caso contrário false.
 *   \sa PilhaEnc()
 */ 
    bool PilhaVazia();
};

template<typename T>
PilhaEnc<T>::PilhaEnc() :ListaEnc<T>::ListaEnc() {}

template<typename T>
PilhaEnc<T>::~PilhaEnc() {
    ListaEnc<T>::destroiLista();
}

template<typename T>
void PilhaEnc<T>::empilha(const T& dado) {
    ListaEnc<T>::adicionaNoInicio(dado);
}

template<typename T>
T PilhaEnc<T>::desempilha() {
    return ListaEnc<T>::retiraDoInicio();
}

template<typename T>
T PilhaEnc<T>::topo() {
    if (ListaEnc<T>::listaVazia()) {
        throw "ErroPilhaCheia";
    } else {
        return ListaEnc<T>::getHead()->getInfo();
    }
}

template<typename T>
void PilhaEnc<T>::limparPilha() {
    ListaEnc<T>::destroiLista();
}

template<typename T>
bool PilhaEnc<T>::PilhaVazia() {
    return ListaEnc<T>::listaVazia();
}
