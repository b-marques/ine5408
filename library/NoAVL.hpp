// Copyright Bruno Marques Do Nascimento <2016.1>

#ifndef NO_AVL_HPP
#define NO_AVL_HPP
#include <vector>
#include <algorithm>

template <typename T>
//!  Classe do elemento da estrutura de dado: Arvore AVL.
/*!  Implementação do nó AVL,
 *   realizada na disciplina de Estrutura de Dados - INE5408
 *   como trabalho prático do semestre.
 *   \author Bruno Marques do Nascimento
 *   \since 09/06/2016
 *   \version 1.0
 */
class NoAVL  {
 public:
//! Contrutor com argumentos.
/*! Sempre que usado, este construtor criará um 
 *  nó AVL, que possuirá filhos nulos, e seu dado conforme
 *  valor passado por parâmetro, além de altura 1;
 */
    explicit NoAVL(const T& data);

//! Destrutor.
/*! Tem a função de destruir o nó AVL.
 */
    virtual ~NoAVL();

//!  Função getAltura, informa a altura do nó.
/*!  
 *   \return um inteiro que informa a altura do nó.
 *   \sa NoAVL<T>(const T& data)
 */
    int getAltura();

//!  Função getElementos, informa os elementos nó e seus filhos.
/*!  
 *   \return um vetor com os dados do nó pai e dos filhos.
 *   \sa NoAVL<T>(const T& data)
 */
    std::vector<NoAVL<T>*> getElementos();

//!  Função getEsquerda, informa o ponteiro para o filho da esquerda.
/*!  
 *   \return um ponteiro que informa a posição do filho esquerdo na memória.
 *   \sa NoAVL<T>(const T& data)
 */
    NoAVL<T>* getEsquerda();

//!  Função getDireita, informa o ponteiro para o filho da direita.
/*!  
 *   \return um ponteiro que informa a posição do filho direito na memória.
 *   \sa NoAVL<T>(const T& data)
 */
    NoAVL<T>* getDireita();

//!  Função inserir, insere um dado em uma árvore AVL.
/*!  
 *   \param dado o dado a ser inserido na árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó inserido.
 *   \sa NoAVL<T>(const T& data)
 */
    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv);

//!  Função remover, remove um dado em uma árvore AVL.
/*!  
 *   \param dado o dado a ser removido da árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó removido.
 *   \sa NoAVL<T>(const T& data)
 */
    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado);

//!  Função minimo, retorna o nó da árvore AVL, com menor valor.
/*!  
 *   \param nodo o nó raiz da árvore.
 *   \return um ponteiro para o nó de menor valor.
 *   \sa NoAVL<T>(const T& data)
 */
    NoAVL<T>* minimo(NoAVL<T>* nodo);

//!  Função getDado, informa a posição de memória do dado do nó.
/*!  
 *   \return um ponteiro que informa a posição do dado do nó na memória.
 *   \sa NoAVL<T>(const T& data)
 */
    T* getDado();

//!  Função busca, busca por um dado em uma árvore AVL.
/*!  
 *   \param dado o dado a ser localizado na árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o dado.
 *   \sa NoAVL<T>(const T& data)
 */
    T* busca(const T& dado, NoAVL<T>* arv);

//!  Função preOrdem, algoritmo de percurso na árvore que passa pela raiz antes.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoAVL<T>(const T& data)
 */
    void preOrdem(NoAVL<T>* nodo);

//!  Função emOrdem, algoritmo de percurso na árvore que passa primeiro pela
//!  subárvore esquerda depois pela raíz e por fim pela subárvore direita.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoAVL<T>(const T& data)
 */
    void emOrdem(NoAVL<T>* nodo);

//!  Função posOrdem, algoritmo de percurso na árvore que passa primeiro pela
//!  subárvore esquerda depois pela subárvore direita e por fim pela raíz.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoAVL<T>(const T& data)
 */
    void posOrdem(NoAVL<T>* nodo);

//!  Função alturaAVL, informa a altura do nó.
/*!  
 *   \param nodo nó que se deseja saber a altura.
 *   \return um inteiro que informa a altura do nó.
 *   \sa NoAVL<T>(const T& data)
 */
    int alturaAVL(NoAVL<T> *nodo);

//!  Função simp_roda_esq, realiza uma rotação simples para direita.
/*!  
 *   \param y o nó raiz da rotação.
 *   \return um ponteiro para o nó raiz ao final da rotação.
 *   \sa NoAVL<T>(const T& data)
 */
    NoAVL<T>* simp_roda_esq(NoAVL<T>* y);

//!  Função simp_roda_dir, realiza uma rotação simples para esquerda.
/*!  
 *   \param x o nó raiz da rotação.
 *   \return um ponteiro para o nó raiz ao final da rotação.
 *   \sa NoAVL<T>(const T& data)
 */
    NoAVL<T>* simp_roda_dir(NoAVL<T>* x);

//!  Função getEquilibrio, calcula a diferença das alturas dos nós filhos.
/*!  
 *   \param nodo o nó pai.
 *   \return um inteiro que informa a diferença das alturas dos nós filhos.
 *   \sa NoAVL<T>(const T& data)
 */
    int getEquilibrio(NoAVL<T>* nodo);
 private:
    int altura;  /*!< Inteiro que indica a altura do nó */
    T* dado;  /*!< Ponteiro para o dado do nó */
    NoAVL<T>* esquerda;  /*!< Ponteiro para o filho esquerdo do nó */
    NoAVL<T>* direita;  /*!< Ponteiro para o filho direito do nó */
    std::vector<NoAVL<T>* > elementos; /*!Elementos acessados durante o
                                        * percurso realizado. */
};

template <typename T>
NoAVL<T>::NoAVL(const T& data): altura{1}, esquerda{nullptr}, direita{nullptr} {
    dado = new T(data);
}

template <typename T>
NoAVL<T>::~NoAVL<T>(const T& data) {
    delete dado;
}

template <typename T>
int NoAVL<T>::getAltura() {
    return altura - 1;
}

template <typename T>
std::vector<NoAVL<T>*> NoAVL<T>::getElementos() {
    return elementos;
}

template <typename T>
NoAVL<T>* NoAVL<T>::getEsquerda() {
    return esquerda;
}

template <typename T>
NoAVL<T>* NoAVL<T>::getDireita() {
    return direita;
}

template <typename T>
NoAVL<T>* NoAVL<T>::inserir(const T& dado, NoAVL<T>* arv) {
    if (arv == nullptr) {
        arv = new NoAVL<T>(dado);
        return arv;
    }
    if (dado < *arv->dado) {
        arv->esquerda = inserir(dado, arv->esquerda);
    } else {
        arv->direita = inserir(dado, arv->direita);
    }

    arv->altura = std::max(alturaAVL(arv->esquerda), alturaAVL(arv->direita))+1;

    int equilibrio = getEquilibrio(arv);


    // Caso Esquerda-Esquerda
    if (equilibrio > 1 && dado < *arv->esquerda->getDado()) {
        return simp_roda_esq(arv);
    }

    // Caso Esquerda-Direita
    if (equilibrio > 1 && dado > *arv->esquerda->getDado()) {
        arv->esquerda = simp_roda_dir(arv->esquerda);
        return simp_roda_esq(arv);
    }

    // Caso Direita-Direita
    if (equilibrio < -1 && dado > *arv->direita->getDado()) {
        return simp_roda_dir(arv);
    }

    // Caso Direita-Esquerda
    if (equilibrio < -1 && dado < *arv->direita->getDado()) {
        arv->direita = simp_roda_esq(arv->direita);
        return simp_roda_dir(arv);
    }

    return arv;
}

template <typename T>
NoAVL<T>* NoAVL<T>::remover(NoAVL<T>* arv, const T& dado) {
    if (arv == nullptr) {
        return arv;
    }

    if (dado < *arv->getDado()) {
        arv->esquerda = remover(arv->esquerda, dado);

    } else if (dado > *arv->getDado()) {
        arv->direita = remover(arv->direita, dado);

    } else {

        NoAVL<T>* aux;
        if (arv->esquerda != nullptr && arv->direita != nullptr) {
            aux = minimo(arv->direita);
            *arv->dado = *aux->dado;
            arv->direita = remover(arv->direita, *arv->dado);

        } else if (arv->esquerda == nullptr) {
            aux = arv->direita;
            delete arv;
            return aux;
        } else {
            NoAVL<T>* aux = arv->esquerda;
            delete arv;
            return aux;
        }
    }

    arv->altura = std::max(alturaAVL(arv->esquerda), alturaAVL(arv->direita))+1;

    int equilibrio = getEquilibrio(arv);


    // Caso Esquerda-Esquerda
    if (equilibrio > 1 && getEquilibrio(arv->esquerda) >= 0) {
        return simp_roda_esq(arv);
    }

    // Caso Esquerda-Direita
    if (equilibrio > 1 && getEquilibrio(arv->esquerda) < 0) {
        arv->esquerda = simp_roda_dir(arv->esquerda);
        return simp_roda_esq(arv);
    }

    // Caso Direita-Direita
    if (equilibrio < -1 && getEquilibrio(arv->direita) <= 0) {
        return simp_roda_dir(arv);
    }

    // Caso Direita-Esquerda
    if (equilibrio < -1 && getEquilibrio(arv->direita) > 0) {
        arv->direita = simp_roda_esq(arv->direita);
        return simp_roda_dir(arv);
    }

    return arv;
}

template <typename T>
NoAVL<T>* NoAVL<T>::minimo(NoAVL<T>* nodo) {
    while (nodo->esquerda != nullptr) {
        nodo = nodo->esquerda;
    }
    return nodo;
}

template <typename T>
T* NoAVL<T>::getDado() {
    return dado;
}

template <typename T>
T* NoAVL<T>::busca(const T& dado, NoAVL<T>* arv) {
    while (arv != nullptr && dado != *arv->getDado()) {
        if (dado < *arv->getDado()) {
            arv = arv->getEsquerda();
        } else {
            arv = arv->getDireita();
        }
    }

    if (arv == nullptr) {
        throw std::runtime_error("Dado não encontrado");
    } else {
        return arv->getDado();
    }
}

template <typename T>
void NoAVL<T>::preOrdem(NoAVL<T>* nodo) {
    if (nodo != nullptr) {
        elementos.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
    }
}

template <typename T>
void NoAVL<T>::emOrdem(NoAVL<T>* nodo) {
    if (nodo != nullptr) {
        emOrdem(nodo->getEsquerda());
        elementos.push_back(nodo);
        emOrdem(nodo->getDireita());
    }
}

template <typename T>
void NoAVL<T>::posOrdem(NoAVL<T>* nodo) {
    if (nodo != nullptr) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos.push_back(nodo);
    }
}

template <typename T>
int NoAVL<T>::alturaAVL(NoAVL<T> *subarvore) {
    if (subarvore == nullptr) {
        return 0;
    } else {
        return subarvore->altura;
    }
}
/*
                y      (Rotação a esquerda)      x
               / \     Right Rotation           / \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3
                        (Rotação a direita)
*/

template <typename T>
NoAVL<T>* NoAVL<T>::simp_roda_esq(NoAVL<T>* y) {
    NoAVL<T>* x = y->esquerda;
    NoAVL<T>* T2 = x->direita;
    // Rotaciona
    x->direita = y;
    y->esquerda =  T2;

    //  Atualiza altura
    y->altura = std::max(alturaAVL(y->esquerda), alturaAVL(y->direita))+1;
    x->altura = std::max(alturaAVL(x->esquerda), alturaAVL(x->direita))+1;
    // Retorna nova raiz
    return x;
}

template <typename T>
NoAVL<T>* NoAVL<T>::simp_roda_dir(NoAVL<T>* x) {
    NoAVL<T>* y = x->direita;
    NoAVL<T>* T2 = y->esquerda;
    // Rotaciona
    y->esquerda = x;
    x->direita = T2;

    //  Atualiza altura
    x->altura = std::max(alturaAVL(x->esquerda), alturaAVL(x->direita))+1;
    y->altura = std::max(alturaAVL(y->esquerda), alturaAVL(y->direita))+1;

    // Retorna nova raíz
    return y;
}

template <typename T>
int NoAVL<T>::getEquilibrio(NoAVL<T>* nodo) {
    if (nodo == nullptr) {
        return 0;
    } else {
        int equilibrio = alturaAVL(nodo->esquerda) - alturaAVL(nodo->direita);
        return equilibrio;
    }
}


#endif /* NO_AVL_HPP */
