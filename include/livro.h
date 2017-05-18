/**
* @file livro.h
* @author Felipe Medeiros 
* @version 1.0
*/


#include <string>

using namespace std;

#ifndef LIVRO_H	//uso do pré-processador
#define LIVRO_H	//definicao do identificador do cabeçalho

/**
* Classe que representa os livros do sistema
*/
class livro{
	private:
		//strings que contem as informaçoes do livro
		string titulo,
				autor,
				editora;
		//inteiro que contem o ano de publicacao
		int ano;

		//objeto da classe livro que aponta para o proximo livro na lista de livros
		livro *prox;

	public:
		/**
		* Contrutor para o caso de nao haver parametros
		*/
		livro();
		/**
		* Contrutor para o caso de receber como parametro outro objeto da classe livro
		*/
		livro(const livro&);
		/**
		* Contrutor para o caso de receber os parametros normais
		*/
		livro(string titulo, string autor, string editora, int ano);


		/**
		* Funcao que retorna o valor de titulo
		*/
		string getTitulo();
		/**
		* Funcao que retorna o valor de autor
		*/
		string getAutor();
		/**
		* Funcao que retorna o valor de editora
		*/
		string getEditora();
		/**
		* Funcao que retorna o valor de ano
		*/
		int getAno();


		/**
		* retorna o valor de titulo
		*/
		void setTitulo(string titulo);
		/**
		* retorna o valor de Autor
		*/
		void setAutor(string autor);
		/**
		* retorna o valor de editora
		*/
		void setEditora(string editora );
		/**
		* retorna o valor de ano
		*/
		void setAno(int ano);


		/**
		* Funcao responsavel por atualizar o valor de prox
		*/
		void setProx(livro* l);
		/**
		* Funcao responsavel por retornar o valor de prox
		*/
		livro* obterProx();


		/**
		* sobrecarga do operador =
		*/
		void operator= (livro novo);
		/**
		* sobrecarga do operador >>
		*/
		friend istream& operator >> (istream &i, livro &d);
		/**
		* Sobrecarga do operador <<
		*/
		friend ostream& operator << (ostream &out, livro const l);
};

/**
* Cria um novo objeto da classe livro e o retorna
*/

livro criaLivro();


#endif // DATA_H
