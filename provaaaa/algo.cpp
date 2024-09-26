#include <vector>
#include <string>
#include <fstream>
#include "lib.h"

using namespace std;

Scontrino::Scontrino()
{

}

void Scontrino::setNumScontrino(int num)
{
    this->num = num;
}


Articoli::Articoli()
{

}


Articoli::Articoli(string nome, double prezzo, double quanti)
{
    this->nome = nome;
    this->prezzo = prezzo;
    this->quanti = quanti;
}

void Scontrino::setArticoli(Articoli a)
{
    artic.push_back(a);
}

void Scontrino::setTotale()
{
    double quantiProv, totProv = 0;

    vector<Articoli>::iterator it = artic.begin();

    while (it != artic.end())
    {
        totProv = 0;
        quantiProv = 0;
        quantiProv = it->getQuanti();
        totProv = it->getPrezzo();
        totProv = totProv * quantiProv;

        this->prezzo = this->prezzo + totProv;

        it++;
    }
}

double Articoli::getQuanti()
{
    return this->quanti;
}

double Articoli::getPrezzo()
{
    return this->prezzo;
}


void Scontrino::getScontrino()
{
    cout << this->nomeAzienda << endl << "P. Iva: " << this->pIva << endl;
    cout << "scontrino n: " << this->num << endl;

    vector<Articoli>::iterator it = artic.begin();

    while (it != artic.end())
    {
        cout << it->toString() << endl;
        it++;
    }

    cout << "totale= " + to_string(this->prezzo) << endl;
}


string Articoli::toString()
{
    string riga;


    riga = this->nome + "   " + to_string(this->prezzo) + "    x" + to_string(this->quanti);

    return riga;
}


void Scontrino::aggiornaNumScontrino(int num)
{
    ofstream scrivi("salvaNumero.txt", ios::trunc | ios::out);
    string appoggio;

    if (scrivi.is_open())
    {
        appoggio = to_string(num);
        scrivi << appoggio;
        scrivi.close();
    }
    else
    {
        cout << "impossibile scrivere numero scontrino" << endl;
    }
}


void Scontrino::leggiNumScontrino()
{
    string letto, appoggio;

    fstream leggi("salvaNumero.txt", ios::in | ios::out);

    if (!leggi.is_open())
    {
        ofstream scrivi("salvaNumero.txt", ios::trunc | ios::out);

        if (scrivi.is_open())
        {

            scrivi << "1";
            this->num = 1;

        }
        scrivi.close();
    }

    else
    {
        while (getline(leggi, letto))
        {
            appoggio = letto;
            this->num = atoi(appoggio.c_str());
        }
        leggi.close();

    }
}

int Scontrino::getNumScontrino()
{
    return this->num;
}

void Scontrino::salvaScontrinoSuFile()
{
    ofstream scrivi("scontrini.txt", ios::out | ios::app);
    vector<Articoli>::iterator it = artic.begin();

    if (scrivi.is_open())
    {
        scrivi << this->nomeAzienda << "," << "P. Iva: " << this->pIva << ",";
        scrivi << "scontrino n: " << this->num << ",";
        scrivi << "Codice cliente: "<<idCliente << ",";

        while (it != artic.end())
        {
            scrivi << it->toString() <<",";
            it++;
        }
        scrivi << "totale= " + to_string(this->prezzo) << ";\n";
        
    }
    scrivi.close();
}

void Scontrino::leggiScontrino()
{

}

