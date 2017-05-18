/**
* @file emprestimo.h
* @author Felipe Medeiros 
* @version 1.0
*/

#include <iostream>
#include <fstream>
#include "../include/usuario.h"
#include "../include/lista.h"
#include "../include/livro.h"
#include "../include/data.h"

using namespace std;

#ifndef EMPRESTIMO_H    //uso do pré-processador
#define EMPRESTIMO_H    //definicao do identificador do cabeçalho

/**
* Classe responsavel por representar os emprestimos de livros
* realizados durante a execuçao do codigo.
*/
class Emprestimo{
    private:
        //Objetos da classe Data
        Data dataInicio,
             dataFim;
        //Objeto da classe livro
        livro book;
        //Objeto da classe usuario
        usuario user;
        //Variavel responsavel por apontar para o proximo emprestimo na lista
        Emprestimo *prox;

    public:
        
        /**
        * contrutor da classe Emprestimo no caso de nao haver parametros
        */
        Emprestimo();
        /**
        * contrutor da classe Emprestimo no caso de  haver outro objeto da classe Emprestimo como parametro
        */
        Emprestimo(const Emprestimo&);
        /**
        * contrutor da classe Emprestimo no caso de haver parametros
        */
        Emprestimo(Data dataInicio, Data dataFim, livro* book, usuario user);


        /**
        * funcao responsavel por retornar o valor de dataInicio
        */
        Data getDataInicio();
        /**
        * funcao responsavel por retornar o valor de dataInicio
        */
        Data getDataFim();
        /**
        * funcao responsavel por retornar o valor de dataFim
        */
        livro getBook();
        /**
        * funcao responsavel por retornar o valor de user
        */
        usuario getUser();
        /**
        * funcao responsavel por retornar o valor de book
        */
        string getNomeLivro();


        /**
        * Funcao responsavel por atualizar o valor de prox
        */
        void setProx(Emprestimo* e);
        /**
        * funcao responsavel por obter o valor de Prox
        */
        Emprestimo* obterProx();


        /**
        * funcao responsavel por alterar o valor de dataInicio
        */
        void setDataInicio(Data dataInicio);
        /**
        * funcao responsavel por alterar o valor de dataFim
        */
        void setDataFim(Data dataFim);
        /**
        * funcao responsavel por alterar o valor de book
        */
        void setBook(livro book);
        /**
        * funcao responsavel por alterar o valor de user
        */
        void setUser(usuario user);

		/**
        * sobrecarga do operador <<
        */
		friend ostream& operator << (ostream &o, Emprestimo const d);

};

/**
* funcao responsavel por criar um novo emprestimo
*/
Emprestimo criarEmprestimo(Data atual, Lista &biblioteca);

#endif
