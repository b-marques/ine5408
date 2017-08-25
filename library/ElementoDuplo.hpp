//  Copyright Bruno Marques <2016.1>

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

//!  Classe que representa um elemento em estrutura de dado.
/*!  Implementação de um elemento em estrutura de dado encadeada,
 *   realizada na disciplina de Estrutura de Dados - INE5408
 *   como parte da implementação dos trabalhos práticos do semestre.
 *   \author Bruno Marques do Nascimento
 *   \since 13/04/2016
 *   \version 1.0
 */
template<typename T>
class ElementoDuplo {
 private:
    T *info; /*!< Ponteiro para a informação do elemento*/
    ElementoDuplo<T>* _next; /*!< Ponteiro para o proximo elemento */
    ElementoDuplo<T>* _previous; /*!< Ponteiro para o elemento anterior */


 public:
//! Contrutor
/*! Sempre que usado, este construtor criará um 
 *  novo elemento com os dados pré-definidos e 
 *  o com o anterior e próximo elemento da estrutura.
 *	\param info dado do elemento
 *  \param next ponteiro para o próximo elemento.
 *  \param previous ponteiro para o elemento anterior.
 */
    ElementoDuplo(const T& info,
         ElementoDuplo<T>* next,
         ElementoDuplo<T>* previous);

//! Destrutor.
/*! Tem a função de destruir o
 *  elemento e seus dados
 */
	~ElementoDuplo();

//!  Função getProximo, informa a posição de memória do próximo elemento.
/*!  
 *   \return um ponteiro que informa a posição na memória do próximo elemento.
 */
	ElementoDuplo<T>* getProximo() const;

//!  Função getAnterior, informa a posição de memória do elemento anterior.
/*!  
 *   \return um ponteiro que informa a posição na memória do elemento anterior.
 */
	ElementoDuplo<T>* getAnterior() const;

//!  Função getInfo, informa o dado guardado pelo elemento.
/*!  
 *   \return o dado pertencente a este elemento.
 */
	T getInfo() const;

//!  Função setProximo, define quem será o próximo elemento da estrutura.
/*!  
 *   \param next o ponteiro para o próximo elemento.
 */
	void setProximo(ElementoDuplo<T>* next);

//!  Função setAnterior, define quem é o elemento anterior da estrutura.
/*!  
 *   \param previous o ponteiro para o elemento anterior.
 */
	void setAnterior(ElementoDuplo<T>* previous);
};

template<typename T>
ElementoDuplo<T>::ElementoDuplo(const T& info,
                  ElementoDuplo<T>* next,
                  ElementoDuplo<T>* previous)
                  :info(new T(info)),
                  _next(next),
                  _previous(previous) {}

template<typename T>
ElementoDuplo<T>::~ElementoDuplo() {
	delete info;
}

template<typename T>
ElementoDuplo<T>* ElementoDuplo<T>::getProximo() const {
	return _next;
}

template<typename T>
ElementoDuplo<T>* ElementoDuplo<T>::getAnterior() const {
	return _previous;
}

template<typename T>
T ElementoDuplo<T>::getInfo() const {
	return *info;
}

template<typename T>
void ElementoDuplo<T>::setProximo(ElementoDuplo<T>* next) {
	_next = next;
}

template<typename T>
void ElementoDuplo<T>::setAnterior(ElementoDuplo<T>* previous) {
	_previous = previous;
}

#endif
