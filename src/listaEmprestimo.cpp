/**
* @file listaEmprestimo.cpp
* @author Felipe Medeiros
* @version 1.0
*/


#include <iostream>
#include <fstream>
#include <string>
#include "../include/listaEmprestimo.h"

using namespace std;

/**
* Contrutor da classe
*/
ListaEmp::ListaEmp(){
	cabeca = NULL;
	cauda = NULL;
}
/**
* @return booleano que informa se a lista está ou nao vazia
*/
bool ListaEmp::listaVazia(){

	return (cabeca == NULL);
}
/**
*
*/
void ListaEmp::exibir(){
	cout << "\nImprimindo todos os emprestimos..." << endl;
    //aponta para o inicio da lista
	Emprestimo* primario = cabeca;

	if(listaVazia())
		cout << "Não existem emprestimos cadastrados." << endl;
	else{
		while(primario){
	 		cout << *primario << endl;
			primario = primario->obterProx();
		}
	}
}
/**
* @param bk Objeto da classe emprestimo que será inserido na lista de emprestimos
*/
void ListaEmp::inserirInicio(Emprestimo bk){
    //auxiliar que recebe o emprestimo
	Emprestimo* primario = new Emprestimo(bk);

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
* @param bk Objeto da classe emprestimo que será inserido na lista de emprestimos
*/
void ListaEmp::inserirFinal(Emprestimo bk){
    //auxiliar que recebe o emprestimo
	Emprestimo* primario = new Emprestimo(bk);

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
* @return inteiro com o tamanho da lista
*/
int ListaEmp::tamanho(){
	if(listaVazia()){
		return 0;
	}

	Emprestimo* primario = cabeca;
	int tam = 0;

	do{
		primario = primario->obterProx();
		tam++;
	}
	while(primario);

	return tam;
}
/**
* @param titulo String que contem o nome de um livro que está emprestado
*
* @return retorna o emprestimo que contem o livro
*/
Emprestimo* ListaEmp::buscaEmprestimo(string titulo){
    //aponta para o inicio da lista
	Emprestimo* primario = cabeca;
    //no caso de nao encontrar o emprestimo, é retornado um emprestimo vazio    
	Emprestimo* vazio = new Emprestimo();
	while(primario){
		if(primario->getNomeLivro() == titulo)
			return primario;
		primario = primario->obterProx();
	}
	return vazio;
}
/**
* @param atual objeto da classe Data que contem o a data do dia atual
*/
void ListaEmp::buscaAtraso(Data atual){
    //informa se há algum emprestimo atrasado
    bool atrasou = false;
    //informa se um emprestimo está atrasdo
    bool atrasado;
    //recebe a data de devolucao do emprestimo
    Data validade;
    //aponta para o inicio da lista
    Emprestimo* primario = cabeca;

    cout << "procurando emprestimos atrasados..." << endl;
    while(primario){

        validade = primario->getDataFim();
        atrasado = atual.compara(validade);

        if(atrasado){
            atrasou = true;
            cout << *primario << endl;
        }
        primario = primario->obterProx();
    }
    if(!atrasou){
        cout << "Nao existem emprestimos atrasados! " << endl;
    }
}
void ListaEmp::attListaTxt(){

    ofstream escreve;

    escreve.open("emprestimos.txt");
    //aponta para o inicio da lista
    Emprestimo* primario = cabeca;
    //objeto da classe data auxiliar
    Data date;
    //objeto da classe usuario auxiliar
    usuario user;
    //objeto da classe livro auxiliar
    livro book;
    int cont = 0;

	if(!listaVazia()){
		while(primario){
            cont++;
            date = primario->getDataInicio();
            escreve << date.getDia() << endl;
            escreve << date.getMes() << endl;
            escreve << date.getAno() << endl;

            date = primario->getDataFim();
			escreve << date.getDia() << endl;
            escreve << date.getMes() << endl;
            escreve << date.getAno() << endl;

            book = primario->getBook();
            escreve << book.getTitulo() << endl;
            escreve << book.getAutor() << endl;
			escreve << book.getEditora() << endl;
			escreve << book.getAno() << endl;

			user = primario->getUser();
            escreve << user.getNome() << endl;
            escreve << user.getEndereco() << endl;
            escreve << user.getId() << endl;

			primario = primario->obterProx();
		}
	}
	escreve.close();

	escreve.open("emprestimosNum.txt");
	escreve << cont;
	escreve.close();
}
/**
* @param titulo String que contém o titulo de um livro que será retirado da lista de Emprestimos
*
* @return objeto da classe livro que foi retirado da lista
*/
livro ListaEmp::devolucao(string titulo){
    livro book;
	if(!listaVazia()){

        //recebe o objeto da classe emprestimo que deve ser deletado
		Emprestimo* deleta = buscaEmprestimo(titulo);
        //Objeto usado para saber se deleta está ou nao vazio
		Emprestimo* vazio = new Emprestimo();
        //Aponta para o inicio da lista
		Emprestimo* primario = cabeca;
        //objeto que está seguindo primario porém 1 posiçao atrás dele na lista
        Emprestimo* secundario = NULL;

		if(deleta != vazio){
			while(primario != NULL){
				if(primario->getNomeLivro() == titulo){
					book = primario->getBook();
                    break;
				}
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
	return book;
}
/**
* @retun objeto da classe ListaEmp que contem todos os emprestimos do sistema
*/
ListaEmp carregaLista_Emprestimo(){

    ifstream recebe;

    //lista que será carregada com os emprestimos
    ListaEmp nova;
    //varavel auxiliar para incluir elementos na lista
    Emprestimo emp;
    //variavel auxiliar para incluir um objeto da classe livro em emp
    livro book;
    //variavel auxiliar para incluir um objeto da classe user em emp
    usuario user;
    //conta quantos emprestimos foram inseridos na lista
    int cont = 0;
    //recebe a quantidade de emprestimso salvos no txt
        quant;
    //string auxiliar
    string aux;
    //vetor de inteiros auxiliar
    int auxInt[3];

    recebe.open("emprestimosNum.txt");
    if(recebe.is_open()){

        recebe >> quant;
        recebe.close();

        recebe.open("emprestimos.txt");
        while(cont < quant){
            cont ++;
            recebe >> auxInt[0];
            recebe >> auxInt[1];
            recebe >> auxInt[2];
            Data primaria(auxInt[0], auxInt[1], auxInt[2]);
            emp.setDataInicio(primaria);

            recebe >> auxInt[0];
            recebe >> auxInt[1];
            recebe >> auxInt[2];
            Data secundaria(auxInt[0], auxInt[1], auxInt[2]);
            emp.setDataFim(secundaria);

            recebe >> aux;
            book.setTitulo(aux);
            recebe >> aux;
            book.setAutor(aux);
            recebe >> aux;
            book.setEditora(aux);
            recebe >> auxInt[0];
            book.setAno(auxInt[0]);
            emp.setBook(book);

            recebe >> aux;
            user.setNome(aux);
            recebe >> aux;
            user.setEndereco(aux);
            recebe >> auxInt[0];
            user.setId(auxInt[0]);
            emp.setUser(user);


            Emprestimo* pronto = new Emprestimo(emp);
            nova.inserirInicio(*pronto);
        }
        recebe.close();
    }
    return nova;
}

