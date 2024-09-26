#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>


#include "lib.h"

using namespace std;

GestisciClienti::GestisciClienti()
{

}


int GestisciClienti::generaIdCliente()
{
    int idUprovvisorio = rand()%100;
    int appoggio;
    ifstream leggi("clienti.txt", ios::in);

    while (!leggi.eof())
    {
        while ( (appoggio= leggi.get()) != ' ')
        {

        }
    }
    return idU;
}

int GestisciClienti::checkIdClienti()
{
    int id = 0, i = 0, pos;
    string idC, appoggio, appoggio2;

    ifstream leggi("scontrini.txt", ios::in);

    while (getline(leggi, appoggio))
    {
        i++;
        if (i == 3)
        {
            pos = appoggio.find(":") + 1;
            appoggio = appoggio.substr(pos);
            cout << appoggio;
            // id = atoi(appoggio2);
        }
    }
    return id;
}

void GestisciClienti::setIdCliente(int idCliente)
{
    this->idCliente = idCliente;
}

int GestisciClienti::getIdCliente()
{
    return this->idCliente;
}

void GestisciClienti::aggiungiCliente()
{
    string nome, cognome;
    int idU=0;

    cout << "inserire nome cliente\n";
    cin >> nome;

    cout << "inserire cognome cliente\n";
    cin >> cognome;

    //funzione genera id

    Cliente cliente(idU, nome, cognome);
    salvaCliente(cliente);
}

void GestisciClienti::salvaCliente(Cliente cli)
{
    ofstream scrivi("clienti.txt", ios :: out | ios :: app);

    scrivi << cli.getId() + ", " + cli.getCognome() + ", " + to_string(cli.getId()) + ";\n";
    scrivi.close();

}

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
