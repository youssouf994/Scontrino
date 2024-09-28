#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>


#include "gestisciCliente.h"

using namespace std;


//costruttore 
GestisciClienti::GestisciClienti()
{

}

//controllo sia che non ci sia un id uguale nel file e sia inserisco il nuovo clliente nel db
int GestisciClienti::generaIdCliente()
{
    int idUprovvisorio;
    string appoggio, a2;
    size_t app;
    int idU, i = 0;
    bool pass;
    ifstream leggi("clienti.txt", ios::in);

    if (leggi.is_open())
    {
        do
        {
            pass = true;
            

            while (getline(leggi, appoggio))
            {
                idUprovvisorio = rand() % 101;
                app = appoggio.find(';');
                if (app != std::string::npos)
                {
                    a2 = appoggio.substr(0, app);
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

        } while (!pass);
    }
    else
    {
        i = 1;
    }

    leggi.close();

    return i;
}


int GestisciClienti::checkIdClienti()
{
    int id = 0, i = 0, pos;
    string idProvvisorio, appoggio;
    char appoggio2[400], a = ',';

    ifstream leggi("scontrini.txt", ios::in);

    while (getline(leggi, appoggio))
    {
        strcpy_s( appoggio2 , appoggio.c_str());
        pos = 0;
        idProvvisorio = "";
        for (i = 62; appoggio2[i]!=a; i++)
        {
            
               idProvvisorio = idProvvisorio + appoggio2[i];
             
        }
        id = stoi(idProvvisorio);
        
        if (id == this->idCliente)
        {
            cout << appoggio<<endl<<endl;

        }

    }
    leggi.close();

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
    ofstream scrivi("clienti.txt", ios::out | ios::app);

    scrivi << to_string(cli.getId()) + ", " + cli.getCognome() + ", " + cli.getNome() + ";\n";
    scrivi.close();

}

void GestisciClienti::selezionaCliente()
{
    int id;
   
 
    visualizzaClienti();
    cout << "inserisci l'id del cliente su cui vuoi l'avorare\n";
    cin >> id;
    setIdCliente(id);
    
}

void::GestisciClienti::visualizzaClienti()
{
    ifstream leggi("clienti.txt", ios::in);
    string app;

    cout << "ID CLIENTE | NOME | COGNOME" << endl;

    while (getline(leggi, app))
    {
        cout << app << endl;
    }
    leggi.close();
    cout << endl;
}