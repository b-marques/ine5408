// Copyright Bruno Marques [2016.1]

//!  Classe da estrutura de dado: Pilha.
/*!  Implementação da estruturda de dado Pilha,
 *	 realizada na disciplina de Estrutura de Dados - INE5408
 *	 como primeiro trabalho prático do semestre.
 * 	 \author Bruno Marques do Nascimento
 * 	 \since 30/03/2016
 * 	 \version 1.0
 */
template<typename T>
class Pilha {
 private:
    int MAXPILHA = 100;  /*!<Tamanho máximo que a pilha deve assumir */
	T *dados;  /*!< Ponteiro para o array de T */
	int topo_ = -1;	/*!< Variável que aponta para o último elemento da pilha */

 public:
//!  Contrutor padrão.
/*!  Sempre que usado, este construtor criará uma 
 * 	 pilha, com tamanho definido pela variável MAXPILHA.
 */
    Pilha() {
        dados = new T[MAXPILHA];
    }

//!  Contrutor com paramêtro.
/*!  Sempre que usado, este construtor criará uma 
 * 	 pilha, com tamanho definido pela variável inteira "t".
 */
    Pilha<T>(int t): MAXPILHA(t) {
        dados = new T[MAXPILHA];
    }

//!  Função empilha, insere um novo dado na pilha, e retorna vazio.
/*!  
 *	 \param dado argumento do tipo T, que será empilhado.
 *	 \sa PilhaCheia() and Pilha()
 */
	void empilha(T dado) {
	    if (PilhaCheia()) {
	        throw "Erro Pilha Cheia";
	    } else {
	        ++topo_;
	        dados[topo_] = dado;
	    }
	}

//!  Função desempilha, retira um dado da pilha, e retorna um tipo T.
/*!  
 *	 \return o dado retirado da pilha do tipo T.
 *	 \sa PilhaVazia() and Pilha()
 */
	T desempilha() {
	    if (PilhaVazia()) {
	        throw "Erro Pilha Vazia";
	    } else {
	        --topo_;
	        return dados[topo_ + 1];
	    }
	}

//!  Função topo, informa o último valor inserido na pilha, do tipo T.
/*!
 *	 \return o último dado empilhado na pilha, do tipo T.
 *	 \sa PilhaVazia() and Pilha()
 */	
	T topo() {
	    if (PilhaVazia()) {
	        throw "Erro Pilha Vazia";
	    } else {
	        return dados[topo_];
	    }
	}

//!  Função getPosTopo, informa a posição no array do último dado inserido.
/*!
 *	 \return um inteiro referente a posição do último dado inserido na pilha.
 *	 \sa PilhaVazia() and Pilha()
 */	
	int getPosTopo() {
	    if (PilhaVazia()) {
	        throw "Erro Pilha Vazia";
	    } else {
	    return topo_;
	    }
	}

//!  Função limparPilha, remove todos os dados da pilha.
/*!
 *	 \sa Pilha()
 */	
	void limparPilha() {
        topo_ = -1;
	}

//!  Função PilhaVazia, verifica se a pilha está vazia.
/*!
 *	 \return um booleano, true se a pilha estiver vazia, caso contrário false.
 *	 \sa Pilha()
 */	
	bool PilhaVazia() {
	    return topo_ == -1;
	}

//!  Função PilhaCheia, verifica se a pilha está cheia.
/*!
 *	 \return um booleano, true se a pilha estiver cheia, caso contrário false.
 *	 \sa Pilha()
 */	
	bool PilhaCheia() {
		return topo_ == (MAXPILHA - 1);
    }
};


--

// Copyright Bruno Marques [2016.1]
template<typename T>
class Pilha {
 private:
    int MAXPILHA = 100;
	T *dados;
	int topo_ = -1;

 public:
    Pilha() {
        dados = new T[MAXPILHA];
    }

    Pilha<T>(int t): MAXPILHA(t) {
        dados = new T[MAXPILHA];
    }

	void empilha(T dado) {
	    if (PilhaCheia()) {
	        throw "Erro Pilha Cheia";
	    } else {
	        ++topo_;
	        dados[topo_] = dado;
	    }
	}

	T desempilha() {
	    if (PilhaVazia()) {
	        throw "Erro Pilha Vazia";
	    } else {
	        --topo_;
	        return dados[topo_ + 1];
	    }
	}

	T topo() {
	    if (PilhaVazia()) {
	        throw "Erro Pilha Vazia";
	    } else {
	        return dados[topo_];
	    }
	}

	int getPosTopo() {
	    if (PilhaVazia()) {
	        throw "Erro Pilha Vazia";
	    } else {
	    return topo_;
	    }
	}

	void limparPilha() {
        topo_ = -1;
	}

	bool PilhaVazia() {
	    if (topo_ == -1) {
	        return true;
	    } else {
	        return false;
	    }
	}

	bool PilhaCheia() {
	    if (topo_ == (MAXPILHA - 1)) {
	        return true;
	    } else {
	        return false;
	    }
    }
};
