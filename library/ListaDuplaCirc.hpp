//  Copyright Bruno Marques <2016.1>

#include "ElementoDuplo.hpp"

//!  Classe da estrutura de dado: lista circular duplamente encadeada.
/*!  Implementação da estruturda de dado lista circular duplamente encadeada,
 *   realizada na disciplina de Estrutura de Dados - INE5408
 *   como trabalho prático do semestre.
 *   \author Bruno Marques do Nascimento
 *   \since 27/04/2016
 *   \version 1.0
 */
template<typename T>
class ListaDuplaCirc {
 private:
    ElementoDuplo<T>* head;  /*!< Ponteiro para o primeiro elemento */

    int size;  /*!< Inteiro que guarda o tamanho da estrutura */

 public:
//! Contrutor padrão.
/*! Sempre que usado, este construtor criará uma 
 *  lista circular duplamente encadeada de tamanho zero,
 *  e com o ponteiro "head" sendo um ponteiro nulo.
 */
	ListaDuplaCirc();

//! Destrutor.
/*! Tem a função de destruir todos
 *  os nós da lista circular duplamente encadeada.
 */
	~ListaDuplaCirc();

//!  Função adicionaNoInicioDuplo, insere um dado no inicio da estrutura.
/*!  
 *   \param dado argumento do tipo T, que será adicionado na estrutura.
 *   \sa ListaDuplaCirc()
 */
	void adicionaNoInicioDuplo(const T& dado);

//!  Função retiraDoInicioDuplo, retira o dado da posição inicial da estrutura.
/*!  
 *   \return o dado retirado da estrutura do tipo T.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	T retiraDoInicioDuplo();

//!  Função eliminaDoInicioDuplo, elimina o dado do inicio da estrutura.
/*!  
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	void eliminaDoInicioDuplo();

//!  Função adicionaNaPosicaoDuplo, insere um dado na posicao definida.
/*!  
 *   \param dado argumento do tipo T, que será adicionado na estrutura.
 *   \param pos posição de inserção desejada
 *   \sa ListaDuplaCirc()
 */
	void adicionaNaPosicaoDuplo(const T& dado, int pos);

//!  Função posicaoDuplo, informa a posição de um dado na estrutura.
/*!  
 *   \param dado argumento do tipo T, que será procurado na estrutura.
 *   \return um inteiro que informa a posição do dado na estrutura.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	int posicaoDuplo(const T& dado) const;

//!  Função posicaoMemDuplo, retorna a posição de memória do dado na estrutura.
/*!  
 *   \param dado argumento do tipo T, que será procurado na estrutura.
 *   \return um ponteiro que informa a posição do dado na memória.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	T* posicaoMemDuplo(const T& dado) const;

//!  Função contemDuplo, informa a presença de um dado na estrutura.
/*!  
 *   \param dado argumento do tipo T, que será procurado na estrutura.
 *   \return um boolean que informa a presença do dado na estrutura.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	bool contemDuplo(const T& dado);

//!  Função retiraDaPosicaoDuplo, retira um dado de uma posição escolhida.
/*!  
 *   \param pos posição de retirada de um dado.
 *   \return o dado retirado da estrutura do tipo T.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	T retiraDaPosicaoDuplo(int pos);

//!  Função adicionaDuplo, insere um novo dado no fim da estrutura.
/*!  
 *   \param dado argumento do tipo T, que será adicionado na estrutura.
 *   \sa ListaDuplaCirc()
 */
	void adicionaDuplo(const T& dado);

//!  Função retiraDuplo, retira um dado do final da estrutura.
/*!  
 *   \return o dado retirado da estrutura do tipo T.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	T retiraDuplo();

//!  Função retiraEspecificoDuplo, retira um dado específico da estrutura.
/*!  
 *   \param dado argumento do tipo T, que será retirado da estrutura.
 *   \return o dado retirado da lista circular duplamente encadeada do tipo T.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	T retiraEspecificoDuplo(const T& dado);

//!  Função mostra, mostra o dado que está na posição informada.
/*!  
 *   \param pos posição do dado na estrutura.
 *   \return um dado T do elemento na posição escolhida.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	T mostra(int pos);

//!  Função adicionaEmOrdem insere o dado na estrutura em ordem crescente.
/*!  
 *   \param dado argumento do tipo T, que será adicionado na estrutura.
 *   \sa ListaEnc()
 */
	void adicionaEmOrdem(const T& data);

//!  Função verUltimo, retorna a posição do ultimo elemento da estrutura.
/*!  
 *   \return um inteiro com a posição do último elemento.
 *   \sa listaVazia() and ListaDuplaCirc()
 */
	int verUltimo();

//!  Função listaVazia, informa se a estrutura está vazia
/*!  
 *   \return um boolean que informa se a estrutura está vazia ou não.
 */
	bool listaVazia() const;

//!  Função igual, informa se os dados são iguais.
/*!  
 *   \param dado1 argumento do tipo T, que será comparado com dado2.
 *   \param dado2 argumento do tipo T, que será comparado com dado1.
 *   \return um boolean que informa se dado1 é igual ao dado2.
 */
	bool igual(T dado1, T dado2) const;

//!  Função maior, informa se um dado é maior que o outro.
/*!  
 *   \param dado1 argumento do tipo T, que será comparado com dado2.
 *   \param dado2 argumento do tipo T, que será comparado com dado1.
 *   \return um boolean que informa se dado1 é maior que dado2.
 */
	bool maior(T dado1, T dado2);

//!  Função menor, informa se um dado é menor que o outro.
/*!  
 *   \param dado1 argumento do tipo T, que será comparado com dado2.
 *   \param dado2 argumento do tipo T, que será comparado com dado1.
 *   \return um boolean que informa se dado1 é menor que dado2.
 */
	bool menor(T dado1, T dado2);

//!  Função destroiListaDuplo, zera a estrutura descartando seus dados.
/*!  
 */
	void destroiListaDuplo();

//!  Função getHead, retorna o ponteiro que aponta para primeiro elemento.
/*!  
 *   \return um ponteiro que aponta para o primeiro elemento.
 */
	ElementoDuplo<T>* getHead();

//!  Função getSize, informa o tamanho da estrutura.
/*!  
 *   \return um inteiro que informa o tamanho da estrutura.
 */
	int getSize();
};

template<typename T>
ListaDuplaCirc<T>::ListaDuplaCirc() {
	size = 0;
	head = nullptr;
}

template<typename T>
ListaDuplaCirc<T>::~ListaDuplaCirc() {
	destroiListaDuplo();
}

template<typename T>
void ListaDuplaCirc<T>::adicionaNoInicioDuplo(const T& dado) {
	ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, head, nullptr);
	if (novo == nullptr) {
		throw "ErroListaCheia";
	} else {
		if (listaVazia()) {
			head = novo;
			novo->setAnterior(novo);
			novo->setProximo(novo);
			++size;
		} else {
			novo->setAnterior(head->getAnterior());
			novo->setProximo(head);
			head->setAnterior(novo);
			head = novo;
			++size;
		}
	}
}

template<typename T>
T ListaDuplaCirc<T>::retiraDoInicioDuplo() {
	if (listaVazia()) {
		throw "ErroListaVazia";
	} else {
		T info = head->getInfo();
		ElementoDuplo<T>* aux = head;
		// head->getProximo->setAnterior(head->getAnterior());
		head->getProximo() -> setAnterior(head->getAnterior());
		head->getAnterior() -> setProximo(head->getProximo());
		head = head->getProximo();
		delete aux;
		--size;
		return info;
	}
}

template<typename T>
void ListaDuplaCirc<T>::eliminaDoInicioDuplo() {
	if (listaVazia()) {
		throw "ErroListaVazia";
	} else {
		ElementoDuplo<T>* aux = head;
		// head->getProximo->setAnterior(head->getAnterior());
		head->getProximo() -> setAnterior(head->getAnterior());
		head->getAnterior() -> setProximo(head->getProximo());
		head = head->getProximo();
		--size;
		delete aux;
	}
}

template<typename T>
void ListaDuplaCirc<T>::adicionaNaPosicaoDuplo(const T& dado, int pos) {
	if (pos < 0 || pos > size) {
		throw "PosiçãoInválida";
	} else {
		if (pos == 0) {
			adicionaNoInicioDuplo(dado);
			return;
		} else {
			ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, head, head);
			if (novo == nullptr) {
				throw "ErroListaCheia";
			} else {
				ElementoDuplo<T>* anterior = head;
				for (int i = 0; i < pos - 1; ++i) {
					anterior = anterior->getProximo();
				}
				if (pos == size) {
					anterior->setProximo(novo);
					novo->setAnterior(anterior);
					novo->setProximo(head);
					++size;
				} else {
					novo->setProximo(anterior->getProximo());
					novo->setAnterior(anterior);
					anterior->setProximo(novo);
					novo->getProximo()-> setAnterior(novo);
					++size;
				}
			}
		}
	}
}

template<typename T>
int ListaDuplaCirc<T>::posicaoDuplo(const T& dado) const {
	if (listaVazia()) {
		throw "ErroListaVazia";
	} else {
		ElementoDuplo<T>* aux = head;
		for (int i = 0; i < size; ++i) {
			if (igual(dado, (aux->getInfo()))) {
				return i;
			}
			aux = aux->getProximo();
		}
		throw "ErroNãoContem";
	}
}

template<typename T>
T* ListaDuplaCirc<T>::posicaoMemDuplo(const T& dado) const {
	if (listaVazia()) {
		throw "ErroListaVazia";
	} else {
		ElementoDuplo<T>* aux = head;
		for (int i = 0; i < size; ++i) {
			if (igual(dado, aux->getInfo())) {
				return aux;
			}
			aux = aux->getProximo();
		}
		throw "ErroNãoContem";
	}
}

template<typename T>
bool ListaDuplaCirc<T>::contemDuplo(const T& dado) {
	if (listaVazia()) {
		throw "ErroListaVazia";
	} else {
		ElementoDuplo<T>* aux = head;
		for (int i = 0; i < size; ++i) {
			if (igual(dado, aux->getInfo())) {
				return true;
			}
			aux = aux->getProximo();
		}
		return false;
	}
}

template<typename T>
T ListaDuplaCirc<T>::retiraDaPosicaoDuplo(int pos) {
	if (listaVazia()) {
		throw "ErroListaVazia";
	} else {
		if (pos > size-1 || pos < 0) {
			throw "ErroPosição";
		} else {
			if (pos == 0) {
				return retiraDoInicioDuplo();
			} else {
				ElementoDuplo<T>* anterior = head;
				ElementoDuplo<T>* eliminar;
				for (int i = 0; i < pos-1; ++i) {
					anterior = anterior->getProximo();
				}
				eliminar = anterior->getProximo();
				anterior->setProximo(eliminar->getProximo());
				--size;
				T dado = eliminar->getInfo();
				delete eliminar;
				return dado;
			}
		}
	}
}

template<typename T>
void ListaDuplaCirc<T>::adicionaDuplo(const T& dado) {
	adicionaNaPosicaoDuplo(dado, size);
}

template<typename T>
T ListaDuplaCirc<T>::retiraDuplo() {
	return retiraDaPosicaoDuplo(size-1);
}

template<typename T>
T ListaDuplaCirc<T>::retiraEspecificoDuplo(const T& dado) {
	return retiraDaPosicaoDuplo(posicaoDuplo(dado));
}

template<typename T>
T ListaDuplaCirc<T>::mostra(int pos) {
	if (listaVazia()) {
		throw "ErroListaVazia";
	} else {
		if (pos > size-1 || pos < 0) {
			throw "ErroPosição";
		} else {
			ElementoDuplo<T>* anterior = head;
			for (int i = 0; i < pos-1; i++) {
				anterior = anterior->getProximo();
			}
			return anterior->getInfo();
		}
	}
}

template<typename T>
void ListaDuplaCirc<T>::adicionaEmOrdem(const T& data) {
	ElementoDuplo<T>* anterior = head;
	int posicao = 0;
    while (posicao < size && maior(data, anterior->getInfo())) {
    	    anterior = anterior->getProximo();
    	    ++posicao;
    }
    ElementoDuplo<T>* novo = new ElementoDuplo<T>(data, nullptr, nullptr);
    if (posicao == 0) {
        adicionaNoInicioDuplo(data);
    } else {
        novo -> setProximo(anterior->getProximo());
        novo -> setAnterior(anterior);
	    anterior->setProximo(novo);
	    novo->getProximo()->setAnterior(novo);
	    ++size;
    }
}

template<typename T>
int ListaDuplaCirc<T>::verUltimo() {
		if (listaVazia()) {
			throw "ErroListaVazia";
		} else {
			ElementoDuplo<T>* aux = head;
			int ultimo = 0;
			while (aux->getProximo() != nullptr) {
				aux = aux->getProximo();
				++ultimo;
			}
			return ultimo;
		}
	}

template<typename T>
bool ListaDuplaCirc<T>::listaVazia() const {
	return size == 0;
}

template<typename T>
bool ListaDuplaCirc<T>::igual(T dado1, T dado2) const {
	return dado1 == dado2;
}

template<typename T>
bool ListaDuplaCirc<T>::maior(T dado1, T dado2) {
	return dado1 > dado2;
}

template<typename T>
bool ListaDuplaCirc<T>::menor(T dado1, T dado2) {
	return dado1 < dado2;
}

template<typename T>
void ListaDuplaCirc<T>::destroiListaDuplo() {
	ElementoDuplo<T>* temp;
	while (size > 0) {
		temp = head->getProximo();
		delete head;
		head = temp;
		--size;
	}
}

template<typename T>
ElementoDuplo<T>* ListaDuplaCirc<T>::getHead() {
	return head;
}

template<typename T>
int ListaDuplaCirc<T>::getSize() {
	return size;
}
