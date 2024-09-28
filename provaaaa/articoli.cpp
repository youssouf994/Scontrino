#include <vector>
#include <string>
#include <fstream>
#include "articoli.h"

using namespace std;




Articoli::Articoli()
{

}


Articoli::Articoli(string nome, double prezzo, double quanti)
{
    this->nome = nome;
    this->prezzo = prezzo;
    this->quanti = quanti;
}



double Articoli::getQuanti()
{
    return this->quanti;
}

double Articoli::getPrezzo()
{
    return this->prezzo;
}




string Articoli::toString()
{
    string riga;


    riga = this->nome + "   \n" + to_string(this->prezzo) + "    x\n" + to_string(this->quanti)+"\n";

    return riga;
}



