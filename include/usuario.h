/**
* @file usuario.h
* @author Felipe Medeiros 
* @version 1.0
*/


#include <iostream>
#include <string>

using namespace std;

#ifndef USUARIO_H   //uso do pré-processador
#define USUARIO_H   //definicao do identificador do cabeçalho
/**
* Classe que represeta os usuários da biblioteca
*/
class usuario{
    private:
        //strings que contém os dados do usuário
        string nome,
               endereco;
        //inteiro que contém o id do usuário
        int id;

    public:
        /**
        * Contrutor da classe para o caso de não haver parametros
        */
        usuario();
        /**
        * Contrutor da classe para o caso de haver parametros
        */
        usuario(string nome, string endereco, int id);


        /**
        * Funcao que retorna o valor de nome
        */
        string getNome();
        /**
        * Funcao que retorna o valor de endereco
        */
        string getEndereco();
        /**
        * Funcao que retorna o valor de id
        */
        int getId();

        /**
        * Funcao que define o valor de nome
        */
        void setNome(string nome);
        /**
        * Funcao que define o valor de endereco
        */
        void setEndereco(string endereco);
        /**
        * Funcao que define o valor de id
        */
        void setId(int id);

        /**
        * sobrecarga do operador =
        */
        void operator= (usuario novo);
        /**
        * sobrecarga do operador >>
        */
        friend istream& operator >> (istream &i, usuario &u);
        /**
        * sobrecarga do operador <<
        */
        friend ostream& operator << (ostream &o, usuario const u);

};

/**
* Funcao que cadastra usuário no sistema 
*/
void cadastrarUsuario();
/**
* funcao que carrega um usuario e retorna ele
*/
usuario carregaUsuario(string nome);

#endif
