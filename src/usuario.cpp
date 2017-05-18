/**
* @file usuario.cpp
* @author Felipe Medeiros 
* @version 1.0
*/


#include <iostream>
#include <fstream>
#include "../include/usuario.h"

using namespace std;
/**
* Contrutor da classe para o caso de não haver parametros
*/
usuario::usuario(){

    this->id = -1;
}
/**
* Contrutor da classe para o caso de haver parametros
*/
usuario::usuario(string nome, string endereco, int id){
    this->nome = nome;
    this->endereco = endereco;
    this->id = id;
}


/**
* @return String que contém o valor de nome
*/
string usuario::getNome(){return this->nome;}
/**
* @return String que contém o valor de endereco
*/
string usuario::getEndereco(){return this->endereco;}
/**
* @return inteiro que contém o valor de id
*/
int usuario::getId(){return this->id;}


/**
* @param nome String que contém o novo valor de nome
*/
void usuario::setNome(string nome){

    this->nome = nome;
}
/**
* @param endereco String que contém o novo valor de endereco
*/
void usuario::setEndereco(string endereco){

    this->endereco = endereco;
}
/**
* @param id inteiro que contém o novo valor de id
*/
void usuario::setId(int id){

    this->id = id;
}


/**
* @param out endereco de memoria de um stream de saida de dados
* @param u objeto da classe livro
*
* @return usuario de memoria para um stream de saida de dados
*/
istream& operator>> (istream &i, usuario &u){
    cout << "Nome: ";
	i >> u.nome;
	cout << "Endereco: ";
	i >> u.endereco;
	cout << "Id: ";
	i >> u.id;
	return i;
}

/**
* @param o endereco de memoria de um stream de entrada de dados
* @param u objeto da classe livro
*
* @return usuario de memoria para um stream de entrada de dados
*/
ostream& operator<< (ostream &o, usuario const u){
	o <<"Nome: "<< u.nome << endl <<"Endereco: "<< u.endereco << endl <<"Id: "<< u.id << endl;
	return o;
}
/**
* @param novo objeto da classe usuário
*/
void usuario::operator= (usuario novo){
    this->nome = novo.nome;
    this->endereco = novo.endereco;
    this->id = novo.id;
}

void cadastrarUsuario(){

    //objeto da classe usuario que recebe as informações
    usuario user;

    cout <<"Informe os dados do novo cliente:" << endl;
    cin >> user;

    ifstream recebe;
    ofstream escreve;

    string nome = user.getNome();

    recebe.open(nome);
    if(!recebe.is_open()){
        escreve.open(nome);
        escreve << user.getNome() << endl;
        escreve << user.getEndereco() << endl;
        escreve << user.getId() << endl;
        escreve.close();
    }
    else{
        cout << "Esse usuario já existe!" << endl;
        recebe.close();
    }
}

/**
* @param nome String que contem o nome de um usuário
*
* @return objeto da classe usuário
*/
usuario carregaUsuario(string nome){

    ifstream recebe;

    usuario user;
    string aux;
    int id;

    nome = nome + ".txt";
    recebe.open(nome);

    if(recebe.is_open()){
        recebe>>aux;
        user.setNome(aux);
        recebe>>aux;
        user.setEndereco(aux);
        recebe>>id;
        user.setId(id);

        recebe.close();
    }
    return user;
}


