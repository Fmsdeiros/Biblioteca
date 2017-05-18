/**
* @file lista.h
* @author Felipe Medeiros 
* @version 1.0
*/

#include <iostream>
#include <string>
#include "../include/livro.h"

using namespace std;

#ifndef LISTA_H	//uso do pré-processador
#define LISTA_H	//definicao do identificador do cabeçalho

/**
* Classe responsavel por criar a lista de livros do sistema
*/
class Lista{
private:
	//primeiro elemento da lista
	livro* cabeca;
	//ultimo elemento da lista
	livro* cauda;

public:
	/**
	* Construtor da classe no caso de nao haver parametros
	*/
	Lista();

	/**
	* Construtor da classe no caso de haver parametro
	*/
	Lista(livro l);

	/**
	* Checa se a lista esta ou nao vazia
	*/
	bool listaVazia();
	/**
	* Printa todos os elementos da lista na tela
	*/
	void exibir();
	/**
	* Insere um livro no inicio da lista
	*/
	void inserirInicio(livro bk);
	/**
	* Insere um livro no final da lista
	*/
	void inserirFinal(livro bk);
	/**
	* Retorna o tamanho da lista
	*/
	int tamanho();
	/**
	* Busca por um livro na lista
	*/
	livro* buscaLivro(string titulo);
	/**
	* Remove um livro da lista
	*/
	void remover(string titulo);
	/**
	* Atualiza o txt que contem todos os elementos da lista
	*/
    void attListaTxt();
};
/**
* carrega a lista com os elementos presentes no txt
*/
Lista carregaLista_Livro();

#endif
