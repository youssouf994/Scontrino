#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>


#include "lib.h"

using namespace std;

//costruttore 
GestisciClienti::GestisciClienti()
{

}

//controllo sia che non ci sia un id uguale nel file e sia inserisco il nuovo clliente nel db
int GestisciClienti::generaIdCliente()
{
    int idUprovvisorio ;
    string appoggio, a2;
    size_t app;
    int idU, i=0;
    bool pass;
    ifstream leggi("clienti.txt", ios::in);

    if (leggi.is_open())
    {
        do
        {
            pass = true;
            idUprovvisorio = rand() % 100;

            while (getline(leggi, appoggio))
            {
                app = appoggio.find(';');
                if (app != std::string::npos)
                {
                    a2=appoggio.substr(0, app);
                    idU = stoi(a2);
                    if (idU == idUprovvisorio)
                    {
                        pass = false;
                        break;
                    }
                    else
                    {
                        i = idUprovvisorio;
                    }
                }
            }

        } while (!true);
    }
    else
    {
        i=1;
    }

    leggi.close();

    return i;
}


int GestisciClienti::checkIdClienti()
{
    int id = 0, i = 0, pos;
    string idC, appoggio, appoggio2;

    ifstream leggi("scontrini.txt", ios::in);

    while (getline(leggi, appoggio))
    {
        
        pos = appoggio.find(":") + 1;
        appoggio = appoggio.substr(pos);
        cout << appoggio;
        // id = atoi(appoggio2);
        
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
    int idU;

    cout << "inserire nome cliente\n";
    cin >> nome;

    cout << "inserire cognome cliente\n";
    cin >> cognome;

    idU = generaIdCliente();

    Cliente cliente(idU, nome, cognome);
    salvaCliente(cliente);
}

void GestisciClienti::salvaCliente(Cliente cli)
{
    ofstream scrivi("clienti.txt", ios :: out | ios :: app);

    scrivi << to_string(cli.getId()) + ", " + cli.getCognome() + ", " + cli.getNome() + ";\n";
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
