/**
* @file lista.cpp
* @author Felipe Medeiros
* @version 1.0
*/
#include <iostream>
#include <fstream>
#include <string>
#include "../include/lista.h"

using namespace std;

/**
* Construtor da classe no caso de não haver parametros
*/
Lista::Lista(){
	cabeca = NULL;
	cauda = NULL;
}
/**
* Construtor da classe no caso de não haver parametro
*/
Lista::Lista(livro l){
	cabeca = new livro(l);
	cauda = cabeca;
}
/**
* @return retorna um booleano que diz se a lista está vazia
*/
bool Lista::listaVazia(){

	return (cabeca == NULL);
}

void Lista::exibir(){
	cout << "\nImprimindo todos os livros..." << endl;
	//aponta para o inicio da lista
	livro* primario = cabeca;

	if(listaVazia())
		cout << "Não existem livros cadastrados." << endl;
	else{
		while(primario){
			cout << *primario << endl;
			primario = primario->obterProx();
		}
	}
}
/**
* @param bk objeto da classe livro que será inserido na lista
*/
void Lista::inserirInicio(livro bk){
	//recebe o objeto que será inserido
	livro* primario = new livro(bk);

	if(listaVazia()){
		cabeca = primario;
		cauda = primario;
	}
	else
	{
		primario->setProx(cabeca);
		cabeca = primario;
	}
}
/**
* @param bk objeto da classe livro que será inserido no final da lista
*/
void Lista::inserirFinal(livro bk){
	//recebe o objeto que será inserido
	livro* primario = new livro(bk);

	if(listaVazia()){
		cabeca = primario;
		cauda = primario;
	}
	else{
		cauda->setProx(primario);
		cauda = primario;
	}
}
/**
* @return inteiro que contém o tamanho da lista
*/
int Lista::tamanho(){
	if(listaVazia()){
		return 0;
	}
	//aponta para o inicio da lista
	livro* primario = cabeca;
	int tam = 0;

	do{
		primario = primario->obterProx();
		tam++;
	}
	while(primario);

	return tam;
}
/**
* @param titulo string que contém o nome de um livro que será procurado na lista
*
* @return um objeto da classe livro
*/
livro* Lista::buscaLivro(string titulo){
	//aponta para o inicio da lista
	livro* primario = cabeca;
	//objeto que vazio que será retornado no caso de não de nao existr o que foi procurado
	livro* vazio = new livro();
	while(primario){
		if(primario->getTitulo() == titulo)
			return primario;
		primario = primario->obterProx();
	}
	return vazio;
}
/**
* @param titulo string que contém o nome de um livro que será retirado da lista
*/
void Lista::remover(string titulo){
	if(!listaVazia()){
		//recebe o objeto que deve ser deletado
		livro* deleta = buscaLivro(titulo);
		//recebe um objeto vazio
		livro* vazio = new livro();
		//aponta para o inicio da lista
		livro* primario = cabeca;
		//recebe NULL
		livro* secundario = NULL;

		if(deleta != vazio){
			while(primario != NULL){
				if(primario->getTitulo() == titulo)
					break;

				secundario = primario;
				primario = primario->obterProx();
			}	
			if(secundario == NULL){
				cabeca = primario->obterProx();
			}
			else if(primario != NULL){
				secundario->setProx(primario->obterProx());
			}
		}

	}
}
/**
* atualiza a o arquivo txt de lista
*/
void Lista::attListaTxt(){

    ofstream escreve;
    //contador
    int k = 0;

    escreve.open("livros.txt");

    //aponta para o inicio da lista
    livro* primario = cabeca;

	if(!listaVazia()){
		while(primario){
			escreve << primario->getTitulo() << endl;
			escreve << primario->getAutor() << endl;
			escreve << primario->getEditora() << endl;
			escreve << primario->getAno() << endl;
			primario = primario->obterProx();
			k++;
		}
	}
	escreve.close();

	escreve.open("livrosNum.txt");
	escreve << k;
	escreve.close();
}
/**
* @return um objeto da classe lista carregado com todos os livros
*/
Lista carregaLista_Livro(){

    ifstream recebe;

    //lista que será carregada com livros
    Lista nova;
    //objeto do tipo livro que recebe os dados
    livro book;
    //string auxiliar
    string aux;

    //inteiro auxiliar
    int auxInt,
    //recebe a quantidade de livros salvos
        quant,
    //conta quantos livros foram inseridos
        cont = 0;

    recebe.open("livrosNum.txt");
    if(recebe.is_open()){
        recebe >> quant;
        recebe.close();

        recebe.open("livros.txt");
        if(recebe.is_open()){
            do{
                cont++;
                recebe >> aux;
                book.setTitulo(aux);
                recebe >> aux;
                book.setAutor(aux);
                recebe >> aux;
                book.setEditora(aux);
                recebe >> auxInt;
                book.setAno(auxInt);
                nova.inserirInicio(book);
            }while(cont < quant);
        }
    }
    recebe.close();
    return nova;
}
