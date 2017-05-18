/**
* @file data.h
* @author Felipe Medeiros
* @version 1.0
*/

#include <iostream>

using namespace std;

#ifndef DATA_H	//uso do pré-processador
#define DATA_H	//definicao do identificador do cabeçalho

/**
* Classe responsavel por conter as datas do sistema
*
* Usada com frequencia para definir o dia atual e o dia em que
* livros emprestados devem ser devolvidos
*/
class Data{
	private:
		//valores privados responsaveis por definir a data
		int dia,mes,ano;
	public:
		/**
		*Construtor da classe no caso de nao haver parametros
		*/
		Data();
		/**
		*Construtor da classe no caso de haver parametros
		*/
		Data(int dia, int mes, int ano);
		//funcao que retorna o valor de dia
		int getDia();
		//funcao que retorna o valor de mes
        int getMes();
        //funcao que retorna o valor de ano
        int getAno();
        //Sobrecarga do operador =
        void operator = (Data nova);
        //Sobrecarga do operador >>
		friend istream& operator >> (istream &i, Data &d);
		//Sobrecarga do operador <<
		friend ostream& operator << (ostream &o, Data const d);
		//Compara datas
		bool compara(Data date);
};

#endif // DATA_H
