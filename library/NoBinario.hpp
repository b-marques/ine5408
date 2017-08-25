// Copyright Bruno Marques [2016.1]

#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <stdexcept>

//!  Classe do elemento da estrutura de dado: Arvore Binária.
/*!  Implementação do nó binário,
 *   realizada na disciplina de Estrutura de Dados - INE5408
 *   como trabalho prático do semestre.
 *   \author Bruno Marques do Nascimento
 *   \since 14/05/2016
 *   \version 1.0
 */
template <typename T>
class NoBinario {
 public:
//! Contrutor com argumentos.
/*! Sempre que usado, este construtor criará um 
 *  nó binário, que possuirá filhos nulos, e seu dado conforme
 *  valor passado por parâmetro,
 */
    NoBinario<T>(const T& dado);

//! Destrutor.
/*! Tem a função de destruir o nó binário.
 */
    virtual ~NoBinario();

//!  Função getDado, informa a posição de memória do dado do nó.
/*!  
 *   \return um ponteiro que informa a posição do dado do nó na memória.
 *   \sa NoBinario<T>(const T& dado)
 */
    T* getDado();

//!  Função getElementos, informa os elementos nó e seus filhos.
/*!  
 *   \return um vetor com os dados do nó pai e dos filhos.
 *   \sa NoBinario<T>(const T& dado)
 */
    std::vector< NoBinario<T>* > getElementos();

//!  Função getEsquerda, informa o ponteiro para o filho da esquerda.
/*!  
 *   \return um ponteiro que informa a posição do filho esquerdo na memória.
 *   \sa NoBinario<T>(const T& dado)
 */
    NoBinario<T>* getEsquerda();

//!  Função getDireita, informa o ponteiro para o filho da direita.
/*!  
 *   \return um ponteiro que informa a posição do filho direito na memória.
 *   \sa NoBinario<T>(const T& dado)
 */
    NoBinario<T>* getDireita();

//!  Função busca, busca por um dado em uma árvore binária.
/*!  
 *   \param dado o dado a ser localizado na árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o dado.
 *   \sa NoBinario<T>(const T& dado)
 */
    T* busca(const T& dado, NoBinario<T>* arv);

//!  Função inserir, insere um dado em uma árvore binária.
/*!  
 *   \param dado o dado a ser inserido na árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó inserido.
 *   \sa NoBinario<T>(const T& dado)
 */
    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv);

//!  Função remover, remove um dado em uma árvore binária.
/*!  
 *   \param dado o dado a ser removido da árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó removido.
 *   \sa NoBinario<T>(const T& dado)
 */
    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado);

//!  Função minimo, retorna o nó da árvore binária, com menor valor.
/*!  
 *   \param nodo o nó raiz da árvore.
 *   \return um ponteiro para o nó de menor valor.
 *   \sa NoBinario<T>(const T& dado)
 */
    NoBinario<T>* minimo(NoBinario<T>* nodo);

//!  Função preOrdem, algoritmo de percurso na árvore que passa pela raiz antes.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoBinario<T>(const T& dado)
 */
    void preOrdem(NoBinario<T>* nodo);

//!  Função emOrdem, algoritmo de percurso na árvore que passa primeiro pela
//!  subárvore esquerda depois pela raíz e por fim pela subárvore direita.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoBinario<T>(const T& dado)
 */
    void emOrdem(NoBinario<T>* nodo);

//!  Função posOrdem, algoritmo de percurso na árvore que passa primeiro pela
//!  subárvore esquerda depois pela subárvore direita e por fim pela raíz.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoBinario<T>(const T& dado)
 */
    void posOrdem(NoBinario<T>* nodo);

 private:
    T *dado_;  /*!< Ponteiro para o dado do nó */
    NoBinario<T> *esquerda_;  /*!< Ponteiro para o filho direito do nó */
    NoBinario<T> *direita_;   /*!< Ponteiro para o filho esquerdo do nó */
    std::vector<NoBinario<T>*> elementos_;  // Elementos acessados durante o
                                            //  percurso realizado.
};

template <typename T>
NoBinario<T>::NoBinario(const T &dado) : esquerda_{nullptr}, direita_{nullptr} {
    dado_ = new T(dado);
}

template <typename T>
NoBinario<T>::~NoBinario() {
    delete dado_;
}

template <typename T>
T* NoBinario<T>::getDado() {
    return dado_;
}

template <typename T>
std::vector< NoBinario<T>* > NoBinario<T>::getElementos() {
    return elementos_;
}

template <typename T>
NoBinario<T>* NoBinario<T>::getEsquerda() {
    return esquerda_;
}

template <typename T>
NoBinario<T>* NoBinario<T>::getDireita() {
    return direita_;
}

template <typename T>
T* NoBinario<T>::busca(const T& dado, NoBinario<T>* arv) {
    while (arv != nullptr && dado != *arv->getDado()) {
        if (dado < *arv->getDado()) {
            arv = arv->getEsquerda();
        } else {
            arv = arv->getDireita();
        }
    }

    if (arv == nullptr) {
        return nullptr;
        throw std::runtime_error("Dado não encontrado");
    } else {
        return arv->getDado();
    }
}

template <typename T>
NoBinario<T>* NoBinario<T>::inserir(const T& dado, NoBinario<T>* arv) {
    NoBinario<T>* novo;
    if (dado < *arv->getDado()) {
        if (arv->getEsquerda() == nullptr) {
            novo = new NoBinario<T>(dado);
            arv->esquerda_ = novo;
            return arv;
        } else {
            arv = inserir(dado, arv->getEsquerda());
            return arv;
        }
    } else {
        if (arv->getDireita() == nullptr) {
            novo = new NoBinario<T>(dado);
            arv->direita_ = novo;
            return arv;
        } else {
            arv = inserir(dado, arv->getDireita());
            return arv;
        }
    }
}

template <typename T>
NoBinario<T>* NoBinario<T>::remover(NoBinario<T>* arv, const T& dado) {
    NoBinario<T> *filho = nullptr;
    T tmp = 0;

    if (arv == nullptr) {
        return arv;
    }

    if (dado < *arv->getDado()) {
        arv->esquerda_ = remover(arv->getEsquerda(), dado);
        return arv;
    }

    if (dado > *arv->getDado()) {
        arv->direita_ = remover(((NoBinario<T>*)arv->getDireita()), dado);
        return arv;
    }

    // 2 filhos
    if (arv->getDireita() != nullptr && arv->getEsquerda() != nullptr) {
        tmp = *((minimo(((NoBinario<T>*)arv->getDireita())))->getDado());
        arv->dado_ = &tmp;
        arv->direita_ = remover(((NoBinario<T>*)arv->getDireita()),
                                                           *arv->getDado());
        return arv;
    }

    // 1 filho
    if (arv->getDireita() != nullptr) {
        filho = arv->getDireita();
        delete arv;
        return filho;
    }

    if (arv->getEsquerda() != nullptr) {
        filho = arv->getEsquerda();
        delete arv;
        return filho;
    }  else {
        delete arv;
        return nullptr;
    }
}

template <typename T>
NoBinario<T>* NoBinario<T>::minimo(NoBinario<T>* nodo) {
    if (nodo == nullptr) {
        return nullptr;
    }
    while (nodo->getEsquerda() != nullptr) {
        nodo = nodo->getEsquerda();
    }
    return nodo;
}

template <typename T>
void NoBinario<T>::preOrdem(NoBinario<T>* nodo) {
    if (nodo != nullptr) {
        elementos_.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
    }
}

template <typename T>
void NoBinario<T>::emOrdem(NoBinario<T>* nodo) {
    if (nodo != nullptr) {
        emOrdem(nodo->getEsquerda());
        elementos_.push_back(nodo);
        emOrdem(nodo->getDireita());
    }
}

template <typename T>
void NoBinario<T>::posOrdem(NoBinario<T>* nodo) {
    if (nodo != nullptr) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos_.push_back(nodo);
    }
}

#endif /* NO_BINARIO_HPP */

