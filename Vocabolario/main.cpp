#include "projectheader.h"
#include "absvocabolario.h"
#include "vocabolariohash.h"
#include "nodorb.h"
#include "vocabolariorbtree.h"

/************************************************************************
*               Quinzio Antonio  - Matricola 0124/955                   *
*           ----------------TRACCIA 1 -------------------               *
* 1. Costruire un vocabolario V utilizzando un Hash Table con il metodo *
* della concatenazione, che abbia le seguenti funzioni:                 *
* – Inserimento del termine                                             *
* – Cancellazione                                                       *
* – Ricerca del termine. In caso di fallimento deve restituire una      *
*   lista delle parole pi´u prossime, utilizzando un approccio basato   *
*   sulla Distanza di editing.                                          *
*                                                                       *
* 2. Costruire un vocabolario V', utilizzando un albero RED BLACK che   *
* abbia le stesse funzioni, dell’ esercizio precedente.                 *
*                                                                       *
* Nell’ implementazione di entrambi i quesiti si faccia uso delle Classi*
* Astratte.                                                             *
*************************************************************************
*/


int main()
{
    int scelta,scelta2 ;
    list <string> sameW;  // Lista di appoggio per le parole simili
    VocabolarioHash *V ; // vocabolario hash
    VocabolarioRbTree *V_perm; // vocabolario RB
    firma();
    buttContinue();

    while(scelta != 27)//TASTO ESC
    {
        scelta2 = 0 ;
        system("CLS");
        sceltaVocabolario();//stampa il menu di scelta del tipo del vocabolario sullo schermo
        switch(scelta = _getch())
        {
            case '1' : //Vocabolario Hash

                V = new VocabolarioHash;
                while(scelta2 != 8 ) //TASTO BACKSPACE
                {
                    system("CLS");
                    opzioniH();  // Stampa opzioni vocabolario hash
                    switch(scelta2 = _getch())
                    {
                        // INSERISCI PAROLA;
                        case '1' :
                        system("CLS");
                        if(V->Insert())   // SE RIESCE A INSERIRE
                         {
                            cout<< endl<<endl<<endl<<"\tVOCABOLO INSERITO CORRETTAMENTE";
                            cout<<endl<<"\t_________________________________"<<endl;
                         }
                        buttContinue();
                        break;


                         // CERCA PAROLA;
                        case '2' :
                        system("CLS");
                        if (!V->Search(sameW) && sameW.begin() != sameW.end())
                        {
                            cout << endl << "\tFORSE CERCAVI  : ";
                            cout << endl<<endl;
                            for (auto it = sameW.begin();it!= sameW.end();it++)
                                cout<<"\t"<< *it << endl;
                            cout<<"\t_________________________________"<<endl;
                        }
                        buttContinue();
                        break;

                        case '3' : // ELIMINA PAROLA
                        system("CLS");
                        if(V->Delete())
                        {
                            cout<<endl<<endl<<endl<<"\tVOCABOLO ELIMINATO CORRETTAMENTE";
                            cout<<endl<<"\t_________________________________"<<endl;
                        }
                        buttContinue();
                        break;

                        case '4' : //STAMPA VOCABOLARIO
                        system("CLS");
                        if (!V->Print())
                        {
                            cout <<endl<<endl<<endl<< "\tVOCABOLARIO VUOTO";
                            cout<<endl<<"\t_________________________________"<<endl;

                        }
                        buttContinue();
                        break;




                        default :
                        break;



                    }
                }
                delete V;
                break;
            case '2' ://Vcocabolario Rb
                V_perm = new VocabolarioRbTree;
                while (scelta2 != 8) //TASTO BACKSPACE O ESC
                {
                    system("CLS");
                    opzioniRB();  // stampa opzioni vocabolario RB
                    scelta2 = _getch() ;
                    switch(scelta2)
                    {
                        case '1' : // INSERISCI PAROLA;
                        system("CLS");
                        if(V_perm->Insert())
                        {
                            cout<< endl<<endl<<endl<<"\tVOCABOLO INSERITO CORRETTAMENTE";
                            cout<<endl<<"\t_________________________________"<<endl;
                        }
                        buttContinue();
                        break;

                        case '2' : // CERCA PAROLA;
                        system("CLS");
                        if (!V_perm->Search(sameW) && sameW.begin() != sameW.end())
                        {
                            cout << endl << "\tFORSE CERCAVI  : ";
                            cout << endl<<endl;
                            for (auto it = sameW.begin();it!= sameW.end();it++)
                                cout<<"\t" << *it << endl;
                            cout<<endl<<"\t_________________________________"<<endl;

                        }
                        buttContinue();
                        break;

                        case '3' : // ELIMINA PAROLA
                        system("CLS");
                        if(V_perm->Delete())
                        {
                            cout<< endl <<"\tVOCABOLO ELIMINATO CORRETTAMENTE";
                            cout<<endl<<"\t_________________________________"<<endl;
                        }
                        buttContinue();
                        break;


                        case '4' : //STAMPA VOCABOLARIO
                        system("CLS");
                        if (!V_perm->Print())
                        {
                            cout <<endl<<endl<<endl<< "\tVOCABOLARIO VUOTO";
                            cout<<endl<<"\t_________________________________"<<endl;

                        }
                        buttContinue();
                        break;

                        case '5' : //STAMPA ALBERO BINARIO
                        system("CLS");

                        if (!V_perm->PrintRB())
                        {
                            cout <<endl<<endl<<endl<< "\tALBERO VUOTO";
                            cout<<endl<<"\t_________________________________"<<endl;

                        }
                        buttContinue();
                        break;

                        default :
                        break;
                    }
                }
                delete V_perm;
                break;
        }

    }

    return EXIT_SUCCESS;
}
