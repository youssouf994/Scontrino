#include <iostream>
#include <vector>
#include "clienti.h"
#include "articoli.h"

using namespace std;

class Scontrino
{
private:
    string nomeAzienda = "Youss_Byte";
    string pIva = "0015248745";
    int num;
    double prezzo;
    vector<Articoli> artic;
    int idCliente;


public:
    Scontrino();
    void setArticoli(Articoli a);
    void getScontrino();
    void setTotale();
    void aggiornaNumScontrino(int num);
    void setNumScontrino(int num);
    int getNumScontrino();
    void leggiNumScontrino();
    void salvaScontrinoSuFile();
    //void leggiScontrino();
    void setIdCliente(int id);
};
#pragma once
