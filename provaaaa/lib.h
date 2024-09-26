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
    void leggiScontrino();
};

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

class GestisciClienti
{
    private:
        int idCliente;
        vector<Scontrino> vScontrini;
        vector<Cliente> vClienti;
        

    public:
        GestisciClienti();
        int generaIdCliente();
        int checkIdClienti();
        int getIdCliente();
        void setIdCliente(int idCliente);
        void aggiungiCliente();
        void salvaCliente(Cliente cli);
}; 



#pragma once

