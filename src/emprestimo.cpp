/**
* @file emprestimo.cpp
* @author Felipe Medeiros 
* @version 1.0
*/

#include <iostream>
#include <fstream>
#include <string>
#include "../include/emprestimo.h"

using namespace std;

/**
* contrutor da classe Emprestimo no caso de nao haver parametros
*/
Emprestimo::Emprestimo(){}
/**
* contrutor da classe Emprestimo no caso de  haver outro objeto da classe Emprestimo como parametro
*/
Emprestimo::Emprestimo(const Emprestimo& Novo){
    this->dataInicio = Novo.dataInicio;
    this->dataFim = Novo.dataFim;
    this->book = Novo.book;
    this->user = Novo.user;
    this->prox = NULL;
}
/**
* contrutor da classe Emprestimo no caso de haver parametros
*/
Emprestimo::Emprestimo(Data dataInicio, Data dataFim, livro* book, usuario user){
    this->dataInicio = dataInicio;
    this->dataFim = dataFim;
    this->book = *book;
    this->user = user;
    this->prox = NULL;
}

/**
* @return o objeto dataInicio
*/
Data Emprestimo::getDataInicio(){return this->dataInicio;}
/**
* @return o objeto dataFim
*/
Data Emprestimo::getDataFim(){return this->dataFim;}
/**
* @return o objeto book
*/
livro Emprestimo::getBook(){return this->book;}
/**
* @return o objeto user
*/
usuario Emprestimo::getUser(){return this->user;}
/**
* @return o nome do livro que esta dentro do objeto book
*/
string Emprestimo::getNomeLivro(){return this->book.getTitulo();}


/**
* @param dataInicio Objeto da classe Data que recebera um novo valor
*/
void Emprestimo::setDataInicio(Data dataInicio){this->dataInicio = dataInicio;}
/**
* @param dataInicio Objeto da classe Data que recebera um novo valor
*/
void Emprestimo::setDataFim(Data dataFim){this->dataFim = dataFim;}
/**
* @param dataInicio Objeto da classe livro que recebera um novo valor
*/
void Emprestimo::setBook(livro book){this->book = book;}
/**
* @param dataInicio Objeto da classe usuario que recebera um novo valor
*/
void Emprestimo::setUser(usuario user){this->user = user;}


/**
* @param e Objeto da classe Emprestimo que irá ser usado para mudar o valor de Prox
*/
void Emprestimo::setProx(Emprestimo* e){prox = e;}
/**
* @return Objeto da classe Emprestimo
*/
Emprestimo* Emprestimo::obterProx(){return prox;}


/**
* @param o endereco de memoria de um stream de saida de dados
* @param e objeto da classe Emprestimo
*
* @return endereço de memoria para um stream de saida de dados
*/
ostream& operator << (ostream &o, Emprestimo const e){
    o << "Data que foi realizado: " << e.dataInicio << endl << "Data de devolucao: " << e.dataFim << endl << e.book << e.user;
    return o;
}

/**
* @param atual       objeto da classe Data que contem a data do dia em que o sistema está
* @param biblioteca  endereco de memoria de um objeto da classe lista que contem todos os livros do sistema
*
* @return objeto da classe Emprestimo
*/
Emprestimo criarEmprestimo(Data atual, Lista &biblioteca){

    ifstream recebe;
    ofstream escreve;

    //objeto da classe usuario auxiliar
    usuario user;
    //objeto da classe livro auxiliar
    livro* book = new livro();
    //objeto da classe data auxiliar
    Data final;

    //string auxiliar
    string nome;
    //inteiro auxiliar
    int valor;
    //booleano que informa se as informaçoes sao validas
    bool sair = false;

    while(!sair){
        cout << "Informe o nome do usuario: ";
        cin >> nome;
        recebe.open(nome);
        if(!recebe.is_open()){
            cout << "\nEsse usuario nao existe!" << endl;
        }
        else{
            recebe >> nome;
            user.setNome(nome);
            recebe >> nome;
            user.setEndereco(nome);
            recebe >> valor;
            user.setId(valor);
            recebe.close();
            sair = true;
        }
    }
    sair = false;

    cout << "Data atual: " << atual << endl;
    cout << "Informe a data de devolucao: " << endl;
    cin >> final;

    while(!sair){
        cout << "Informe o nome do livro: ";
        cin >> nome;
        book = biblioteca.buscaLivro(nome);
        if(book->getAno() == -1){
            cout << "Nao temos esse livro no estoque!" << endl;
        }
        else{
            biblioteca.remover(nome);
            sair = true;
        }
    }

    Emprestimo novo(atual,final,book,user);

    cout << "Emprestimo realizado com sucesso!" << endl;

    return novo;
}
