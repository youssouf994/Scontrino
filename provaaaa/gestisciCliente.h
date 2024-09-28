#include <iostream>
#include <vector>
#include "scontrino.h"
#include "clienti.h"

using namespace std;

class GestisciClienti
{
    private:
        int idCliente=101;
        int generaIdCliente();
        void salvaCliente(Cliente cli);  
        
        

    public:
        GestisciClienti();
        int checkIdClienti();
        void aggiungiCliente();   
        void selezionaCliente();
        void setIdCliente(int idCliente);
        void visualizzaClienti();
        int getIdCliente();
};

#pragma once
