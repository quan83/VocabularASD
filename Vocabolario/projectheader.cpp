#include "projectheader.h"
void firma ()
{
    cout << "\n\n\n\n\n";
    cout <<"\t***********************************************************\n";
    cout <<"\t*                                                         *\n";
    cout <<"\t*                  GESTIONE VOCABOLARIO                   *\n";
    cout <<"\t*             ESAME ALGORITMI E STRUTTURE DATI            *\n";
    cout <<"\t*              MATRICOLA  :  0124//000955                 *\n";
    cout <<"\t*                    QUINZIO ANTONIO                      *\n";
    cout <<"\t*                                                         *\n";
    cout <<"\t***********************************************************\n";
}

void sceltaVocabolario()
{
    cout << "\n\n\n\n\n";
    cout << "\t*******************************************" << endl;
    cout << "\t|                                         |" << endl;
    cout << "\t|                    MENU                 |" << endl;
    cout << "\t|                                         |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [1]        Vocabolario Hash           |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [2]        Vocabolario Red&Black      |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|  [ESC]       ESCI DAL PROGRAMMA         |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t        SCELTA:        ";



}
void opzioniH()
{
    cout << "\n\n";
    cout << "\t*******************************************" << endl;
    cout << "\t|                                         |" << endl;
    cout << "\t|             VOCABOLARIO HASH            |" << endl;
    cout << "\t|                                         |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [1]         INSERISCI                 |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [2]         CERCA                     |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [3]         ELIMINA PAROLA            |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [4]        STAMPA VOCABOLARIO         |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|  [<--]       RETURN SCELTA INIZIALE     |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t        SCELTA:        ";


}

void opzioniRB()
{
    cout << "\n\n";
    cout << "\t*******************************************" << endl;
    cout << "\t|                                         |" << endl;
    cout << "\t|          VOCABOLARIO RED & BLACK        |" << endl;
    cout << "\t|                                         |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [1]         INSERISCI                 |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [2]         CERCA                     |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [3]         ELIMINA PAROLA            |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [4]        STAMPA VOCABOLARIO         |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|   [5]        VERIFICA ALBERO-RB         |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t|  [<--]       RETURN SCELTA INIZIALE     |" << endl;
    cout << "\t*******************************************" << endl;
    cout << "\t        SCELTA:        ";
}

void buttContinue()
{
    cout << endl << endl << "\t PREMERE 'INVIO/ENTER' PER CONTINUARE";
    while ( _getch()!= 13); // Mentre è diverso dal Invio...
}
