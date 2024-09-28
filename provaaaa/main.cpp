#include <iostream>
#include "articoli.h"
#include "scontrino.h"
#include "gestisciCliente.h"
#include "clienti.h"

using namespace std;


int main()
{
    int num;
    GestisciClienti gc;
    int scelta;
    string nome;
    double prezzo;
    double quanti;


    do
    {
        
        cout << "\n1.seleziona il clliente su cui operare\n";
        cout << "2.visualizza scontrini cliente\n";
        cout << "3.calcola nuovo scontrino\n"; 
        cout << "4.registra nuovo cliente\n";
        cin >> scelta;

        switch (scelta)
        {
        case 1:
            gc.selezionaCliente();
            break;
        
        case 2:
            quanti = gc.checkIdClienti();
            break;

        case 3:
        {
            Scontrino sco;
            int sce;
            do
            {
                if ((gc.getIdCliente() < 0) || (gc.getIdCliente() > 100))
                {
                    cout<<"devi prima selezionare un cliente\n";
                    break;
                }
                else
                {
                    sco.leggiNumScontrino();//oltre che leggere il file, setta anche il membro numero nella classe scobntrino

                    cout << "inserisci nome articolo\n";
                    cin >> nome;

                    cout << "inserisci prezzo articolo\n";
                    cin >> prezzo;
                    
                    cout << "inserisci quantità venduta\n";
                    cin >> quanti;

                    Articoli art(nome, prezzo, quanti);
                    sco.setArticoli(art);

                    cout << "aggiungere altro prodotto? 1=si/ 0=no\n";
                    cin >> sce;

                    if (sce == 0)
                    {
                        sco.setTotale();
                        sco.getScontrino();
                        num = sco.getNumScontrino() + 1;
                        sco.aggiornaNumScontrino(num);
                        sco.setIdCliente(gc.getIdCliente());
                        sco.salvaScontrinoSuFile();
                    }
                }
                
            } while (sce != 0);
        }
        break;

        case 4 :
            gc.aggiungiCliente();

        break;

        default:
            cout << "scelta errata\n";
            break;
        }

    } while (scelta != 0);

    return 0;
}