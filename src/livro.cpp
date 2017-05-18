/**
* @file livro.cpp
* @author Felipe Medeiros 
* @version 1.0
*/

#include <iostream>
#include <fstream>
#include "../include/livro.h"

using namespace std;

/**
* Construtor para o caso de nao haver parametros
*/
livro::livro(){this->ano = -1;}
/**
* Construtor para o caso de receber outro objeto da classe livro como parametro
*/
livro::livro(const livro& novo){
    this->titulo = novo.titulo;
    this->autor = novo.autor;
    this->editora = novo.editora;
    this->ano = novo.ano;
    this->prox = NULL;
}
/**
* Construtor para o caso de receber os parametros normais
*/
livro::livro(std::string titulo, std::string autor, std::string editora, int ano){
	this->titulo = titulo;
	this->autor = autor;
	this->editora = editora;
	this->ano = ano;
	this->prox = NULL;
}


/**
* @return valor de titulo
*/
std::string livro::getTitulo(){return this->titulo;}
/**
* @return valor de autor
*/
std::string livro::getAutor(){return this->autor;}
/**
* @return valor de editora
*/
std::string livro::getEditora(){return this->editora;}
/**
* @return valor de ano
*/
int livro::getAno(){return this->ano;}


/**
* @param titulo String que contém o novo valor de titulo
*/
void livro::setTitulo(std::string titulo){this->titulo = titulo;}
/**
* @param autor String que contém o novo valor de autor
*/
void livro::setAutor(std::string autor){this->autor = autor;}
/**
* @param editora String que contém o novo valor de editora
*/
void livro::setEditora(std::string editora){this->editora = editora;}
/**
* @param ano inteiro que contém o novo valor de ano
*/
void livro::setAno(int ano){this->ano = ano;}


/**
* @param l novo valor de prox
*/
void livro::setProx(livro* l){prox = l;}
/**
* @return o valor de prox
*/
livro* livro::obterProx(){return prox;}


/**
* @param out endereco de memoria de um stream de saida de dados
* @param l objeto da classe livro
*
* @return endereço de memoria para um stream de saida de dados
*/
ostream& operator<< (ostream &out, livro const l){
	out <<"Titulo: "<< l.titulo << endl <<"Autor: "<< l.autor << endl <<"Editora: "<< l.editora << endl <<"Ano: "<< l.ano << endl;
	return out;
}
/**
* @param i endereco de memoria de um stream de entrada de dados
* @param l objeto da classe livro
*
* @return endereço de memoria para um stream de entrada de dados
*/
istream& operator>> (istream &i, livro &l){
	cout << "Titulo: ";
	i >> l.titulo;
	cout << "Autor: ";
	i >> l.autor;
	cout << "Editora: ";
	i >> l.editora;
	cout << "Ano: ";
	i >> l.ano;

	return i;
}
/**
* @param novo Objeto da classe livro
*/
void livro::operator= (livro novo){
    this->titulo = novo.titulo;
    this->autor = novo.autor;
    this->editora = novo.editora;
    this->ano = novo.ano;
}


/**
* @return objeto da classe livro
*/
livro criaLivro(){

    ofstream escreve;
    //recebe as informações que serao salvas no objeto que esta sendo criado
    livro novo;
    cout << "Cadastrando um novo livro: " << endl;
    cin >> novo;
    cin.ignore();
    escreve.open("livros.txt", fstream::app);
    escreve << novo.getTitulo() << endl;
    escreve << novo.getAutor() << endl;
    escreve << novo.getEditora() << endl;
    escreve << novo.getAno() << endl;
    escreve.close();

    return novo;
}