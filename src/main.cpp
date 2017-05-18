W/**
* @file main.cpp
* @author Felipe Medeiros
* @version 1.0
*
* @section DESCRIPTION
*
* sistema que simula o funcionamento de uma biblioteca.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "../include/lista.h"
#include "../include/menu.h"
#include "../include/emprestimo.h"
#include "../include/listaEmprestimo.h"

using namespace std;

/**
* Funcao responsavel por checar se os arquivos necessarios
* para o funcionamento do código já existem.
*/
int primeiroAcesso();

int main(){
    // Objeto da classe livro
    livro book;
    // Objeto da classe Lista
    Lista lst;
    // Objeto da classe listaEmp
	ListaEmp lstEmp;
    // Objeto da classe data
	Data atual;

    //inteiro responsavel por receber as entradas do usuário
	int funcao,
        criador;
    //string responsavel por guardar informaçoes
	string nome;

    //define a data atual
	cout << "Informe a data atual: \n";
	cin >> atual;

    //checa se os arquivos necessarios ja existem
    criador = primeiroAcesso();

    //carrega os dados das listas do sistema
    if(criador != 2 && criador != 3)
        lst = carregaLista_Livro();
	if(criador != 1 && criador != 3)
        lstEmp = carregaLista_Emprestimo();

	do{
         //recebe a escolha do usuário
        cout << "\n\n";
		funcao = menuOpc(atual);
        cout << "\n\n";
		switch(funcao){
			case 1:
                //cria um livro e coloca ele na lista
                lst.inserirFinal(criaLivro());
				break;

			case 2:
                //printa todos os livros da lista
			    lst.exibir();
				break;

            case 3:
                //procura por um livro na lista através de seu titulo
                livro *bkat;

                cout << "Insira o titulo do livro: ";
                cin >> nome;
                bkat = lst.buscaLivro(nome);
                if(bkat->getAno() == -1){
                    cout << "Livro nao cadastrado!" << endl;
                }
                else{
                    cout << *bkat;
                }
                break;

            case 4:
                //cadastra um novo usuário
                cadastrarUsuario();
                break;

            case 5:
                //Cria um emprestimo
            	lstEmp.inserirFinal(criarEmprestimo(atual,lst));
            	break;

            case 6:
                cout << "Informe o nome do livro que deseja devolver: ";
                cin >> nome;

                //Devolve um livro emprestado
                book = lstEmp.devolucao(nome);

                if(book.getAno() == -1){
                    cout << "Esse livro nao esta na lista de livros emprestados." << endl;
                }
                else{
                    lst.inserirFinal(book);
                    cout << "Livro devolvido com sucesso!" << endl;
                }
                break;

            case 7:
                //procura os emprestimos que já passaram da data de devolução
                lstEmp.buscaAtraso(atual);
                break;

            case 8:
                //mostra todos os emprestimos ativos no momento
                lstEmp.exibir();
                break;

			case 9:
                //altera a data atual
				cout << "Informe a data autal: " << endl;
                cin >> atual;
                cout << "Data alterada com sucesso!" <<endl;
				break;

		}
	}while(funcao != 0);


    //salva as listas do sistema antes de fechar o sistema
    if(lst.listaVazia()){
        remove("livros.txt");
        remove("livrosNum.txt");
    }
    else{
        lst.attListaTxt();
    }

    if(lstEmp.listaVazia()){
        remove("emprestimos.txt");
        remove("emprestimosNum.txt");
    }
    else{
        lstEmp.attListaTxt();
    }

	return 0;
}




int primeiroAcesso(){
    int k;
    ifstream recebe;
    ofstream escreve;

    recebe.open("livrosNum.txt");
    if(!recebe.is_open()){
        recebe.close();
        escreve.open("livrosNum.txt");
        escreve << 0;
        escreve.close();
    }

    recebe.open("emprestimosNum.txt");
    if(!recebe.is_open()){
        recebe.close();
        escreve.open("emprestimosNum.txt");
        escreve << 0;
        escreve.close();
    }

    recebe.open("emprestimos.txt");
    if(!recebe.is_open()){
        k = 1;
        recebe.close();
        escreve.open("emprestimos.txt");
        escreve << "";
        escreve.close();
    }
    recebe.open("livros.txt");
    if(!recebe.is_open()){
        if(k == 0)
            k = 2;
        else
            k = 3;
        recebe.close();
        escreve.open("livros.txt");
        escreve << "";
        escreve.close();
    }

    return k;
}
