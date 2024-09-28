#include <iostream>
#include <vector>

using namespace std;

class Cliente
{
private:
    int idCliente;
    string nome;
    string cognome;

public:
    Cliente();
    Cliente(int idCliente, string nome, string cognome);
    string getNome();
    string getCognome();
    int getId();

};
#pragma once
