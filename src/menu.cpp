/**
* @file menu.cpp
* @author Felipe Medeiros 
* @version 1.0
*/

#include <iostream>
#include "../include/menu.h"

using namespace std;

/**
* @param atual Objet da classe Data que contém a data atual
*
* @return inteiro com a escolha do usuário
*/
int menuOpc(Data atual){
	//recebe a escolha do usuario
	int escolha;
	//checa se a escolha foi valida
	bool sair = false;

	do{
		cout << "Data: " << atual << endl;
		cout << "(1) - Cadastrar livro."  << endl;
		cout << "(2) - exibir todos os livros." << endl;
		cout << "(3) - Buscar livro."  << endl;
		cout << "(4) - Cadastrar usuario." << endl;
		cout << "(5) - Realizar emprestimo." << endl;
		cout << "(6) - Devolver livro." << endl;
		cout << "(7) - Procurar emprestimos atrasados" << endl;
		cout << "(8) - exibir todos os emprestimos." << endl;
		cout << "(9) - Alterar data atual." << endl;
		cout << "(0) - Sair." << endl;
		cout << "Escolha: ";
		cin >> escolha;
        if(escolha >= 0 && escolha <= 9){
            return escolha;
        }
        else{
            cout << "valor invalido!" << endl;
            cout << "\n\n\n";
        }

	}while(!sair);
	return 0;
}
