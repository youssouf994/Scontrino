#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>


#include "clienti.h"

using namespace std;


Cliente::Cliente()
{

}

Cliente::Cliente(int idCliente, string nome, string cognome)
{
    this->idCliente = idCliente;
    this->nome = nome;
    this->cognome = cognome;
}

string Cliente::getNome()
{
    return nome;
}


string Cliente::getCognome()
{
    return cognome;
}


int Cliente::getId()
{
    return idCliente;
}
