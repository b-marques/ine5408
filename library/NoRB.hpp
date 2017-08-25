// Copyright Bruno Marques Do Nascimento <2016.1>

#ifndef NO_RB_HPP
#define NO_RB_HPP

#include <vector>

#define RB_RUBRO true
#define RB_NEGRO false

template <typename T>
//!  Classe do elemento da estrutura de dado: Arvore Red-Black.
/*!  Implementação do nó RB,
 *   realizada na disciplina de Estrutura de Dados - INE5408
 *   como trabalho prático do semestre.
 *   \author Bruno Marques do Nascimento
 *   \since 29/06/2016
 *   \version 1.0
 */
class NoRB {
 private:
    T* dado;    //!< Atributo onde é guardado o valor representado pelo nó
    NoRB<T>* esquerda;  //!< Atributo que aponta para menor nó descendente
    NoRB<T>* direita;   //!< Atributo que aponta para maior nó descendente
    NoRB<T>* pai;       //!< Atributo que aponta para nó ascendente
    bool cor;           //!< Atributo que indica a cor do nó
    std::vector<NoRB<T>*> elementos;  // Elementos acessados durante o
                                            // percurso realizado.

 public:
//! Contrutor com argumentos.
/*! Sempre que usado, este construtor criará um 
 *  nó RB, que possuirá filhos nulos, e seu dado conforme
 *  valor passado por parâmetro;
 */
    explicit NoRB(const T& dado);

//! Destrutor.
/*! Tem a função de destruir o nó RB.
 */
    virtual ~NoRB();

//!  Função getPai, informa o ponteiro para o pai do nó.
/*!  
 *   \return um ponteiro que informa a posição do pai na memória.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* getPai();

//!  Função getCor, informa a cor do nó.
/*!  
 *   \param nodo o nó que se quer saber a cor;
 *   \return um inteiro que informa a cor do nó.
 *   \sa NoRB<T>(const T& data)
 */
    bool getCor(NoRB<T>* nodo);

//!  Função getElementos, informa os elementos nó e seus filhos.
/*!  
 *   \return um vetor com os dados do nó pai e dos filhos.
 *   \sa NoRB<T>(const T& data)
 */
    std::vector<NoRB<T>*> getElementos();

//!  Função getEsquerda, informa o ponteiro para o filho da esquerda.
/*!  
 *   \return um ponteiro que informa a posição do filho esquerdo na memória.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* getEsquerda();

//!  Função getDireita, informa o ponteiro para o filho da direita.
/*!  
 *   \return um ponteiro que informa a posição do filho direito na memória.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* getDireita();

//!  Função inserir, insere um dado em uma árvore RB.
/*!  
 *   \param dado o dado a ser inserido na árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó inserido.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* inserir(const T& dado, NoRB<T>* arv);

//!  Função remover, remove um dado em uma árvore RB.
/*!  
 *   \param dado o dado a ser removido da árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó removido.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* remover(NoRB<T>* arv, const T& dado);

//!  Função minimo, retorna o nó da árvore RB, com menor valor.
/*!  
 *   \param nodo o nó raiz da árvore.
 *   \return um ponteiro para o nó de menor valor.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* minimo(NoRB<T>* nodo);

//!  Função getDado, informa a posição de memória do dado do nó.
/*!  
 *   \return um ponteiro que informa a posição do dado do nó na memória.
 *   \sa NoRB<T>(const T& data)
 */
    T* getDado();

//!  Função busca, busca por um dado em uma árvore RB.
/*!  
 *   \param dado o dado a ser localizado na árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o dado.
 *   \sa NoRB<T>(const T& data)
 */
    T* busca(const T& dado, NoRB<T>* arv);

//!  Função preOrdem, algoritmo de percurso na árvore que passa pela raiz antes.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoRB<T>(const T& data)
 */
    void preOrdem(NoRB<T>* nodo);

//!  Função emOrdem, algoritmo de percurso na árvore que passa primeiro pela
//!  subárvore esquerda depois pela raíz e por fim pela subárvore direita.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoRB<T>(const T& data)
 */
    void emOrdem(NoRB<T>* nodo);

//!  Função posOrdem, algoritmo de percurso na árvore que passa primeiro pela
//!  subárvore esquerda depois pela subárvore direita e por fim pela raíz.
/*!  
 *   \param nodo nó que representa a raiz da árvore.
 *   \sa NoRB<T>(const T& data)
 */
    void posOrdem(NoRB<T>* nodo);

//!  Função roda_esq, realiza uma rotação simples para esquerda.
/*!  
 *   \param nodo o nó raiz da rotação.
 *   \return um ponteiro para o nó raiz ao final da rotação.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* roda_esq(NoRB<T>* nodo);

//!  Função roda_dir, realiza uma rotação simples para direita.
/*!  
 *   \param nodo o nó raiz da rotação.
 *   \return um ponteiro para o nó raiz ao final da rotação.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* roda_dir(NoRB<T>* nodo);

//!  Função roda_dupla_esq, realiza uma rotação dupla para esquerda.
/*!  
 *   \param nodo o nó raiz da rotação.
 *   \return um ponteiro para o nó raiz ao final da rotação.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* roda_dupla_esq(NoRB<T>* nodo);

//!  Função roda_dupla_dir, realiza uma rotação dupla para direita.
/*!  
 *   \param nodo o nó raiz da rotação.
 *   \return um ponteiro para o nó raiz ao final da rotação.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* roda_dupla_dir(NoRB<T>* nodo);

//!  Função insercaoBinaria, insere um dado em uma árvore binaria.
/*!  
 *   \param dado o dado a ser inserido na árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó inserido.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* insercaoBinaria(const T& key, NoRB<T>* node);

//!  Função passoCE_esq, realiza passos especificos.
/*!  
 *   \param atual o nó atual.
 *   \param pai o nó pai.
 *   \param avo o nó avo. 
 *   \return um ponteiro para o nó atual.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* passoCE_esq(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo);

//!  Função passoCE_dir, realiza passos especificos.
/*!  
 *   \param atual o nó atual.
 *   \param pai o nó pai.
 *   \param avo o nó avo. 
 *   \return um ponteiro para o nó atual.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* passoCE_dir(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo);

//!  Função passoCED, realiza passos especificos.
/*!  
 *   \param w o nó atual.
 *   \param raiz o nó raiz. 
 *   \return um ponteiro para o nó atual.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* passoCED(NoRB<T>* w, NoRB<T>* raiz);

//!  Função passoCED_esq, realiza passos especificos.
/*!  
 *   \param w o nó atual.
 *   \param raiz o nó raiz. 
 *   \return um ponteiro para o nó atual.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* passoCED_esq(NoRB<T>* w, NoRB<T>* raiz);

//!  Função passoCED_dir, realiza passos especificos.
/*!  
 *   \param w o nó atual.
 *   \param raiz o nó raiz. 
 *   \return um ponteiro para o nó atual.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* passoCED_dir(NoRB<T>* w, NoRB<T>* raiz);

//!  Função remocaoBinaria, remove um dado em uma árvore binária.
/*!  
 *   \param dado o dado a ser removido da árvore.
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para o nó removido.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* remocaoBinaria(NoRB<T>* arv, const T& dado);

//!  Função fixViolacao, arruma a violação das propriedades da Arv. Red-Black.
/*!  
 *   \param arv o nó raiz da árvore.
 *   \return um ponteiro para a raiz da arv arrumada.
 *   \sa NoRB<T>(const T& data)
 */
    NoRB<T>* fixViolacao(NoRB<T>* arv);
};

template <typename T>
NoRB<T>::NoRB(const T& dado) : esquerda{nullptr}, direita{nullptr},
                                           pai{nullptr}, cor{RB_NEGRO} {
    this->dado = new T(dado);
}

template <typename T>
NoRB<T>::~NoRB() {
    delete dado;
    delete esquerda;
    delete direita;
}

template <typename T>
NoRB<T>* NoRB<T>::getPai() {
    return pai;
}

template <typename T>
bool NoRB<T>::getCor(NoRB<T>* node) {
    if (node != nullptr) {
        return node->cor;
    } else {
        return RB_NEGRO;
    }
}

template <typename T>
std::vector<NoRB<T>*> NoRB<T>::getElementos() {
    return elementos;
}

template <typename T>
NoRB<T>* NoRB<T>::getEsquerda() {
    return esquerda;
}

template <typename T>
NoRB<T>* NoRB<T>::getDireita() {
    return direita;
}

template <typename T>
NoRB<T>* NoRB<T>::inserir(const T& dado, NoRB<T>* arv) {
    arv = insercaoBinaria(dado, arv);
    return fixViolacao(arv);
}

template <typename T>
NoRB<T>* NoRB<T>::fixViolacao(NoRB<T>* arv) {
    if (getCor(arv->direita) == RB_RUBRO) {
        if (getCor(arv->direita->direita) == RB_RUBRO) {
            return roda_dir(arv);
        }
        if (getCor(arv->direita->esquerda) == RB_RUBRO) {
            return roda_dupla_dir(arv);
        }
    }
    if (getCor(arv->esquerda) == RB_RUBRO) {
        if (getCor(arv->esquerda->esquerda) == RB_RUBRO) {
            return roda_esq(arv);
        }
        if (getCor(arv->esquerda->direita) == RB_RUBRO) {
            return roda_dupla_esq(arv);
        }
    }

    return arv;
}

template <typename T>
NoRB<T>* NoRB<T>::remover(NoRB<T>* arv, const T& dado) {
    if (arv == nullptr) {
        throw "Dado Nao Encontrado";
    }
    if (dado < *arv->dado) {
        arv->esquerda = remover(arv->esquerda, dado);
    } else if (dado > *arv->dado) {
        arv->direita = remover(arv->direita, dado);
    } else if (arv->esquerda != nullptr && arv->direita != nullptr) {
        *arv->dado = *minimo(arv->direita)->dado;
        arv->direita = remover(arv->direita, *arv->dado);
    } else if (arv->esquerda == nullptr && arv->direita == nullptr) {
        delete arv;
        return nullptr;
    } else {
        NoRB* temp = arv;
        if(arv->esquerda != nullptr)
            arv = arv->esquerda;
        else
            arv = arv->direita;
        arv->pai = temp->pai;
        temp->esquerda = nullptr;
        temp->direita = nullptr;
        delete temp;
        return arv;
    }

    return fixViolacao(arv);
}

template <typename T>
NoRB<T>* NoRB<T>::minimo(NoRB<T>* nodo) {
    while (nodo->esquerda != nullptr) {
        nodo = nodo->esquerda;
    }
    return nodo;
}

template <typename T>
T* NoRB<T>::getDado() {
    return dado;
}

template <typename T>
T* NoRB<T>::busca(const T& dado, NoRB<T>* arv) {
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
void NoRB<T>::preOrdem(NoRB<T>* nodo) {
    if (nodo != nullptr) {
        elementos.push_back(nodo);
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
    }
}

template <typename T>
void NoRB<T>::emOrdem(NoRB<T>* nodo) {
    if (nodo != nullptr) {
        emOrdem(nodo->getEsquerda());
        elementos.push_back(nodo);
        emOrdem(nodo->getDireita());
    }
}

template <typename T>
void NoRB<T>::posOrdem(NoRB<T>* nodo) {
    if (nodo != nullptr) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        elementos.push_back(nodo);
    }
}

template <typename T>
NoRB<T>* NoRB<T>::roda_esq(NoRB<T>* arv) {
    NoRB<T> *raiz;
    raiz = arv->esquerda;
    arv->esquerda = raiz->direita;
    raiz->direita = arv;

    raiz->pai = arv->pai;
    arv->pai = raiz;
    if (arv->esquerda != nullptr) {
        arv->esquerda->pai = arv;
    }

    NoRB<T>* aux = raiz->direita;
    if (getCor(aux->direita) == RB_RUBRO) {
        if(raiz->pai != nullptr) {
            raiz->cor = RB_RUBRO;
        } else {
            raiz->cor = RB_NEGRO;
        }
        raiz->esquerda->cor = RB_NEGRO;
        raiz->direita->cor = RB_NEGRO;

    } else {
        raiz->cor = RB_NEGRO;
        aux->cor = RB_RUBRO;
    }
    return raiz;
}

template <typename T>
NoRB<T>* NoRB<T>::roda_dir(NoRB<T>* arv) {
    NoRB<T> *raiz;
    raiz = arv->direita;
    arv->direita = raiz->esquerda;
    raiz->esquerda = arv;

    raiz->pai = arv->pai;
    arv->pai = raiz;
    if (arv->direita != nullptr) {
        arv->direita->pai = arv;
    }

    NoRB<T>* aux = raiz->esquerda;
    if (getCor(aux->esquerda) == RB_RUBRO) {
        if(raiz->pai != nullptr) {
            raiz->cor = RB_RUBRO;
        } else {
            raiz->cor = RB_NEGRO;
        }
        raiz->esquerda->cor = RB_NEGRO;
        raiz->direita->cor = RB_NEGRO;

    } else {
        raiz->cor = RB_NEGRO;
        aux->cor = RB_RUBRO;
    }
    return raiz;
}

template <typename T>
NoRB<T>* NoRB<T>::roda_dupla_dir(NoRB<T>* arv) {
    arv->direita = roda_esq(arv->direita);
    return roda_dir(arv);
}

template <typename T>
NoRB<T>* NoRB<T>::roda_dupla_esq(NoRB<T>* arv) {
    arv->esquerda = roda_dir(arv->esquerda);
    return roda_esq(arv);
}

template <typename T>
NoRB<T>* NoRB<T>::passoCE_esq(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo) {
    NoRB<T>* tio = avo->direita;
    if (getCor(tio) == RB_RUBRO) {
        pai->cor = RB_NEGRO;
        avo->cor = RB_RUBRO;
        tio->cor = RB_NEGRO;
        atual = avo;
    } else {
        if (pai->direita == atual) {
            roda_esq(pai);
            atual = atual->esquerda;
        }
        pai->cor = RB_NEGRO;
        avo->cor = RB_RUBRO;
        roda_dir(avo);
    }
    return atual;
}

template <typename T>
NoRB<T>* NoRB<T>::passoCE_dir(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo) {
    NoRB<T>* tio = avo->esquerda;
    if (getCor(tio) == RB_RUBRO) {
        pai->cor = RB_NEGRO;
        avo->cor = RB_RUBRO;
        tio->cor = RB_NEGRO;
        atual = avo;
    } else {
        if (pai->esquerda == atual) {
            roda_dir(pai);
            atual = atual->direita;
        }
        pai->cor = RB_NEGRO;
        avo->cor = RB_RUBRO;
        roda_esq(avo);
    }
    return atual;
}

template <typename T>
NoRB<T>* NoRB<T>::insercaoBinaria(const T& dado, NoRB<T>* arv) {
    if (dado < *arv->dado) {
        if (arv->esquerda == nullptr) {
            arv->esquerda = new NoRB<T>(dado);
            arv->esquerda->pai = arv;
            arv->esquerda->cor = RB_RUBRO;
        } else {
            arv->esquerda = inserir(dado, arv->esquerda);
        }
    } else {
        if (arv->direita == nullptr) {
            arv->direita = new NoRB<T>(dado);
            arv->direita->pai = arv;
            arv->direita->cor = RB_RUBRO;
        } else {
            arv->direita = inserir(dado, arv->direita);
        }
    }
    return arv;
}

template <typename T>
NoRB<T>* NoRB<T>::passoCED(NoRB<T>* w, NoRB<T>* raiz) {
    while (w != raiz) {                             //  Cond. de término
        if (w == w->pai->esquerda) {
            w = passoCED_esq(w, raiz);              //  Esquerda
        } else {
            w = passoCED_dir(w, raiz);              //  Direita
        }
    }
    return w;
}

template <typename T>
NoRB<T>* NoRB<T>::passoCED_esq(NoRB<T>* w, NoRB<T>* raiz) {
    NoRB<T>* y;
    y = w->pai->direita;                                //  Irmão da direita
    if (getCor(y) == RB_RUBRO) {
        y->cor = RB_NEGRO;                              //  Caso 1
        w->pai->cor = RB_RUBRO;                         //  Caso 1
        roda_esq(w->pai);                               //  Caso 1
        y = w->pai->direita;                            //  Reseta Caso 1
    }
    if (getCor(y->esquerda) == RB_NEGRO && getCor(y->direita) == RB_NEGRO) {
        y->cor = RB_RUBRO;                              //  Caso 2
        w = w->pai;                                     //  Sobe Caso 2
    } else {
        if (getCor(y->direita) == RB_NEGRO) {
            y->esquerda->cor = RB_NEGRO;                //  Caso 3
            y->cor = RB_RUBRO;                          //  Caso 3
            roda_dir(y);                                //  Caso 3
            y = w->pai->direita;                        //  Caso 3
        }
        y->cor = getCor(w->pai);                           //  Caso 4
        w->pai->cor = RB_NEGRO;                         //  Caso 4
        y->direita->cor = RB_NEGRO;                     //  Caso 4
        roda_esq(w->pai);                               //  Caso 4
        w = raiz;                                       //  Caso 4
    }
    return w;
}

template <typename T>
NoRB<T>* NoRB<T>::passoCED_dir(NoRB<T>* w, NoRB<T>* raiz) {
    NoRB<T>* y;
    y = w->pai->esquerda;                               //  Irmão da direita
    if (getCor(y) == RB_RUBRO) {
        y->cor = RB_NEGRO;                              //  Caso 1
        w->pai->cor = RB_RUBRO;                         //  Caso 1
        roda_dir(w->pai);                               //  Caso 1
        y = w->pai->esquerda;                           //  Reseta Caso 1
    }
    if (getCor(y->direita) == RB_NEGRO && getCor(y->esquerda) == RB_NEGRO) {
        y->cor = RB_RUBRO;                              //  Caso 2
        w = w->pai;                                     //  Sobe Caso 2
    } else {
        if (getCor(y->esquerda) == RB_NEGRO) {
            y->direita->cor = RB_NEGRO;                 //  Caso 3
            y->cor = RB_RUBRO;                          //  Caso 3
            roda_esq(y);                                //  Caso 3
            y = w->pai->esquerda;                       //  Caso 3
        }
        y->cor = w->pai->cor;                           //  Caso 4
        w->pai->cor = RB_NEGRO;                         //  Caso 4
        y->esquerda->cor = RB_NEGRO;                    //  Caso 4
        roda_dir(w->pai);                               //  Caso 4
        w = raiz;                                       //  Caso 4
    }
    return w;
}

template <typename T>
NoRB<T>* NoRB<T>::remocaoBinaria(NoRB<T>* arv, const T& dado) {
    if (arv == nullptr) {
        return arv;
    }
    if (dado < *(arv->getDado())) {
        arv->esquerda = remover(arv->getEsquerda(), dado);
        return arv;
    }
    if (dado > *(arv->getDado())) {
        arv->direita = remover(arv->getDireita(), dado);
        return arv;
    }
    if (arv->getDireita() != nullptr && arv->getEsquerda() != nullptr) {
        NoRB<T>* tmp = minimo(arv->getDireita());
        arv->dado = tmp->getDado();
        arv->direita = remover(arv->getDireita(), *(arv->dado));
        return arv;
    }
    if (arv->getDireita() != nullptr) {
        NoRB<T>* filho = (arv->getDireita());
        return filho;
    } else if (arv->getEsquerda() != nullptr) {
        NoRB<T>* filho = (arv->getEsquerda());
        return filho;
    } else {
        delete arv;
        return nullptr;
    }
}

#endif /* NO_RB_HPP */
