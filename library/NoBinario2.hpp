// Copyright Bruno Marques [2016.1]

#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>
#include <stdexcept>

template <typename T>
class NoBinario {
 protected:
    T *dado_;
    NoBinario<T> *esquerda_;
    NoBinario<T> *direita_;
    std::vector<NoBinario<T>*> elementos_;  //!< Elementos acessados durante
                                           // o percurso realizado

 public:
    NoBinario<T>(const T& dado);
    virtual ~NoBinario();
    T* getDado();
    std::vector< NoBinario<T>* > getElementos();
    NoBinario<T>* getEsquerda();
    NoBinario<T>* getDireita();
    T* busca(const T& dado, NoBinario<T>* arv);
    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv);
    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado);
    NoBinario<T>* minimo(NoBinario<T>* nodo);
    void preOrdem(NoBinario<T>* nodo);
    void emOrdem(NoBinario<T>* nodo);
    void posOrdem(NoBinario<T>* nodo);
};

template <typename T>
NoBinario<T>::NoBinario(const T &dado) {
	dado_ = new T(dado);
	esquerda_ = nullptr;
	direita_ = nullptr;
}

template <typename T>
NoBinario<T>::~NoBinario() {}

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
	while (arv != nullptr && *arv->getDado() != dado) {
		if (dado > *arv->getDado()) {
			arv = arv->getDireita();
		} else {
			arv = arv->getEsquerda();
		}
	}

	if (arv == nullptr) {
		throw std::runtime_error("Dado não encontrado");
	}

	return arv->getDado();
}

template <typename T>
NoBinario<T>* NoBinario<T>::inserir(const T& dado, NoBinario<T>* arv) {
	NoBinario<T>* novo;
	if (dado < *arv->getDado()) {
		if (arv->getEsquerda() == nullptr) {
			novo = new NoBinario<T>(dado);
			arv->esquerda_ = novo;
		} else {
			arv = inserir(dado, arv->getEsquerda());
		}
	} else {
		if ( arv->getDireita() == nullptr ) {
			novo = new NoBinario<T>(dado);
			arv->direita_ = novo;
		} else {
			arv = inserir(dado, arv->getDireita());
		}
	}
	return arv;
}

template <typename T>
NoBinario<T>* NoBinario<T>::remover(NoBinario<T>* arv, const T& dado) {
	NoBinario<T> *filho;
	NoBinario<T> *tmp;

	if (arv == nullptr) {
		return arv;
	} else {
		if (dado < *arv->getDado()) {
			arv->esquerda_ = remover(arv->getEsquerda(), dado);
			return arv;
		} else {
			if (dado > *arv->getDado()) {
				arv->direita_ = remover(((NoBinario<T>*)arv->getDireita()),
				                                                          dado);
				return arv;
			} else {
				if (arv->getDireita() != nullptr &&
				                    arv->getEsquerda() != nullptr) {  // 2 filhos
					tmp = minimo(((NoBinario<T>*)arv->getDireita()));
					arv->dado_ = tmp->getDado();
					arv->direita_ = remover(((NoBinario<T>*)arv->getDireita()),
					                                            *arv->getDado());
					return arv;
				} else {  // 1 filho
					tmp = arv;
					if (arv->getDireita() != nullptr) {
						filho = arv->getDireita();
						return filho;
					} else {
						if (arv->getEsquerda() != nullptr) {
							filho = arv->getEsquerda();
							return filho;
						} else {
							delete arv;
							return nullptr;
						}
					}
				}
			}
		}
	}
}

template <typename T>
NoBinario<T>* NoBinario<T>::minimo(NoBinario<T>* nodo) {
	if (nodo == nullptr) {
		return nullptr;
	}
	while (nodo->getEsquerda()) {
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
