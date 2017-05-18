/**
* @file listaEmprestimo.h
* @author Felipe Medeiros 
* @version 1.0
*/


#include <iostream>
#include <string>
#include "../include/emprestimo.h"

using namespace std;

#ifndef LISTAEMPRESTIMO_H	//uso do pré-processador
#define LISTAEMPRESTIMO_H	//definicao do identificador do cabeçalho

class ListaEmp{
private:
	//primeiro elemento da lista
	Emprestimo* cabeca; 
	//ultimo elemento da lista
	Emprestimo* cauda;

public:
	/**
	* Construtor da classe
	*/
	ListaEmp();
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
	void inserirInicio(Emprestimo bk);
	/**
	* Insere um livro no final da lista
	*/
	void inserirFinal(Emprestimo bk);
	/**
	* Retorna o tamanho da lista
	*/
	int tamanho();
	/**
	* Busca por um emprestimo na lista e o retorna
	*/
	Emprestimo* buscaEmprestimo(string titulo);
	/**
	* Procura por emprestimos atrasados
	*/
	void buscaAtraso(Data);
	/**
	* Devolve um livro que estava emprestado
	*/
	livro devolucao(string titulo);
	/**
	* Atualiza o txt que contem os elementos da lista de Emprestimos
	*/
	void attListaTxt();

};
/**
* Carrega a lista de emprestimos usando os elementos de um txt 
*/
ListaEmp carregaLista_Emprestimo();

#endif

