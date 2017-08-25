// Copyright Bruno Marques [2016.1]

//!  Classe da estrutura de dado: Fila.
/*!  Implementação da estruturda de dado Fila,
 *	 realizada na disciplina de Estrutura de Dados - INE5408
 *	 como segundo trabalho prático do semestre.
 * 	 \author Bruno Marques do Nascimento
 * 	 \since 01/04/2016
 * 	 \version 1.0
 */
template <typename T>
class Fila {
 private:
    int primeiro = 0;  /*!< Valor da posição do primeiro elemento da Fila */
    int ultimo_ = -1;  /*!< Valor da posição do último elemento da Fila */
    int maxFila = 100;  /*!< Tamanho máximo que a fila deve assumir */
    int numeroItens = 0;  /*!< Número de itens presente na Fila */ 
    T* dados;  /*!< Ponteiro para o array de T */

 public:
//!  Contrutor padrão.
/*!  Sempre que usado, este construtor criará uma 
 * 	 fila, com tamanho definido pela variável maxFila.
 */
	Fila() {
		dados = new T[maxFila];
	}

//!  Contrutor com paramêtro.
/*!  Sempre que usado, este construtor criará uma 
 * 	 fila, com tamanho definido pela variável inteira "tam".
 */
	Fila<T>(int tam): maxFila(tam) {
		dados = new T[maxFila];
	}

//!  Função inclui, realiza a inserção de um novo dado na fila, e retorna vazio.
/*!  
 *	 \param dado argumento do tipo T, que será adicionado na fila.
 *	 \sa filaCheia() and Fila()
 */
	void inclui(T dado) {
		if (filaCheia()) {
			throw "Erro Fila Cheia";
		} else {
			++ultimo_;
			if (ultimo_ == maxFila) {
				ultimo_ = 0;
				dados[ultimo_] = dado;
			} else {
				dados[ultimo_] = dado;
			}
			++numeroItens;
		}
	}

//!  Função retira, realiza a retirada de um dado da fila, e retorna um tipo T.
/*!  
 *	 \return o dado retirado da fila do tipo T.
 *	 \sa filaVazia() and Fila()
 */
	T retira() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			T temp = dados[primeiro];
			++primeiro;
			if (primeiro == maxFila) {
				primeiro = 0;
			}
			--numeroItens;
			return temp;
		}
	}

//!  Função ultimo, informa o último dado inserido na fila, do tipo T.
/*!
 *	 \return o último dado adicionado na fila, do tipo T.
 *	 \sa filaVazia() and Fila()
 */	
	T ultimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return dados[ultimo_];
		}
	}

//!  Função getUltimo, informa a posição no array do último dado inserido.
/*!
 *	 \return um inteiro referente a posição do último dado inserido na fila.
 *	 \sa filaVazia() and Fila()
 */	
	int getUltimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return numeroItens - 1;  // return ultimo_;
		}
	}

//!  Função filaCheia, verifica se a fila está cheia.
/*!
 *	 \return um booleano, true se a fila estiver cheia, caso contrário false.
 *	 \sa Fila()
 */	
	bool filaCheia() {
		return numeroItens == maxFila;
	}

//!  Função filaVazia, verifica se a fila está vazia.
/*!
 *	 \return um booleano, true se a fila estiver vazia, caso contrário false.
 *	 \sa Fila()
 */	
	bool filaVazia() {
		return numeroItens == 0;
	}
//!  Função inicializarFila, remove todos os dados da fila.
/*!
 *	 \sa Fila() and filaVazia()
 */	
	void inicializaFila() {
		if (filaVazia()) {
           throw "Erro Fila Vazia";
    	} else {
    	    ultimo_ = -1;
    		primeiro = 0;
    		numeroItens = 0;
    	}
	}
};

// Copyright Bruno Marques <2016.1>
template <typename T>
class Fila {
 private:
 	int maxFila = 100;
 	int ultimo_ = -1;
 	T* dados;

 public:
	Fila() {
		dados = new T[maxFila];
	}

	Fila<T>(int tam): maxFila(tam) {
		dados = new T[maxFila];
	}

	void inclui(T dado) {
		if (filaCheia()) {
			throw "Erro Fila Cheia";
		} else {
			++ultimo_;
			dados[ultimo_] = dado;
		}
	}

	T retira() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			T temp = dados[0];
			int i;
			--ultimo_;
			for (i = 0; i < ultimo_; i++) {
				dados[i] = dados[i+1];
			}
			return temp;
		}
	}

	T ultimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return dados[ultimo_];
		}
	}

	int getUltimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return ultimo_;
		}
	}
	
	bool filaCheia();
	bool filaVazia();
	void inicializaFila();
};



---------------------------------------------------
SEM COMENTÁRIO
---------------------------------------------------

// Copyright Bruno Marques [2016.1]
template <typename T>
class Fila {
 private:
    int primeiro = 0;
    int ultimo_ = -1;
    int maxFila = 100;
    int numeroItens = 0;
    T* dados;

 public:
	Fila() {
		dados = new T[maxFila];
	}

	Fila<T>(int tam): maxFila(tam) {
		dados = new T[maxFila];
	}

	void inclui(T dado) {
		if (filaCheia()) {
			throw "Erro Fila Cheia";
		} else {
			++ultimo_;
			if (ultimo_ == maxFila) {
				ultimo_ = 0;
				dados[ultimo_] = dado;
			} else {
				dados[ultimo_] = dado;
			}
			++numeroItens;
		}
	}

	T retira() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			T temp = dados[primeiro];
			++primeiro;
			if (primeiro == maxFila) {
				primeiro = 0;
			}
			--numeroItens;
			return temp;
		}
	}

	T ultimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return dados[ultimo_];
		}
	}

	int getUltimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return numeroItens - 1;  // return ultimo_;
		}
	}

	bool filaCheia() {
		return numeroItens == maxFila;
	}

	bool filaVazia() {
		return numeroItens == 0;
	}

	void inicializaFila() {
		if (filaVazia()) {
           throw "Erro Fila Vazia";
    	} else {
    	    ultimo_ = -1;
    		primeiro = 0;
    		numeroItens = 0;
    	}
	}
};

// Copyright Bruno Marques <2016.1>
template <typename T>
class Fila {
 private:
 	int maxFila = 100;
 	int ultimo_ = -1;
 	T* dados;

 public:
	Fila() {
		dados = new T[maxFila];
	}

	Fila<T>(int tam): maxFila(tam) {
		dados = new T[maxFila];
	}

	void inclui(T dado) {
		if (filaCheia()) {
			throw "Erro Fila Cheia";
		} else {
			++ultimo_;
			dados[ultimo_] = dado;
		}
	}

	T retira() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			T temp = dados[0];
			int i;
			--ultimo_;
			for (i = 0; i < ultimo_; i++) {
				dados[i] = dados[i+1];
			}
			return temp;
		}
	}

	T ultimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return dados[ultimo_];
		}
	}

	int getUltimo() {
		if (filaVazia()) {
			throw "Erro Fila Vazia";
		} else {
			return ultimo_;
		}
	}
	
	bool filaCheia();
	bool filaVazia();
	void inicializaFila();
};

