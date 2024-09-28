#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Articoli
{
private:
    string nome;
    double prezzo;
    double quanti;

public:
    Articoli();
    Articoli(string nome, double prezzo, double quanti);
    double getPrezzo();
    double getQuanti();
    string toString();

};


#pragma once

