/**
* @file data.cpp
* @author Felipe Medeiros
* @version 1.0
*/

#include <iostream>
#include <fstream>
#include "../include/data.h"

using namespace std;

//Construtor da classe data no caso de nao haver parametros
Data::Data(){}
//Construtor da classe data no caso de haver parametros
Data::Data(int dia, int mes, int ano){
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

/**
* @return valor de dia
*/
int Data::getDia(){return this->dia;}
/**
* @return valor de mes
*/
int Data::getMes(){return this->mes;}
/**
* @return valor de ano
*/
int Data::getAno(){return this->ano;}

/**
* @param i endereco de memoria de um stream de entrada de dados
* @param d endereco de memoria de um objeto da classe data
*
* @return endereço de memoria para um stream de entrada de dados
*/
istream& operator>> (istream &i, Data &d){
	cout << "Dia:";
	i >> d.dia;
	cout << "Mes:";
	i >> d.mes;
	cout << "Ano:";
	i >> d.ano;
	return i;
}

/**
* @param o endereco de memoria de um stream de saida de dados
* @param d objeto da classe data
*
* @return endereço de memoria para um stream de saida de dados
*/
ostream& operator<< (ostream &o, Data const d){
	o << d.dia << "/" << d.mes << "/" << d.ano;
	return o;
}

/**
* @param nova objeto da classe Data
*
*/
void Data::operator= (Data nova){
    this->dia = nova.dia;
    this->mes = nova.mes;
    this->ano = nova.ano;
}

/**
* @param atual objeto da classe Data
*
* @return booleano que informa se data é maior que date
*/
bool Data::compara(Data date){
    if(this->ano > date.ano){
        return 1;
    }
    if(this->ano < date.ano){
        return 0;
    }
    if(this->mes > date.mes){
        return 1;
    }
    if(this->mes < date.mes){
        return 0;
    }
    if(this->dia > date.dia){
        return 1;
    }
    if(this->dia < date.dia){
        return 0;
    }

    return 0;
}
