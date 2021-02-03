#ifndef VOCABOLARIOBTREE_H_INCLUDED
#define VOCABOLARIOBTREE_H_INCLUDED
#include "projectheader.h"
#include "absvocabolario.h"
#include "nodorb.h"

/*******************************************************************
La classe VocabolarioRbTree è una classe che eredita alcuni metodi
virtuali da implementare , dalla classe AbsVocabolario.

Come Attributo ha :
nodoRb *radice   che è un puntatore a un oggetto della classe nodoRb

Ha i seguenti metodi pubblici :

        I primi sono ereditati dalla classe AbsVocabolario
        e implementati secondo le caratteristiche della classe
        VocabolarioRbTree

bool Insert()   Inserisce i nodi nell'albero
bool Delete ()  Elimina i nodi dall'albero
bool Search ( list<string> &) Cerca un nodo altrimenti restituisce
                              una lista di stringhe simili a quella
                              contenuta nel nodo

list<string> SimilWrd (string ) Nel caso fallisce la ricerca restituisce
                                una lista di stringhe simili a quella
                                cercata , calcolata con la distanza di
                                editing
bool Print()            Stampa tutti le informazioni dei nodi presenti

inoltre in aggiunta ha :
bool PrintRB()         Stampa i nodi in formato albero

Inoltre ha altri metodi privati in quanto non utilizzati esternamente
alla classe  , questi sono :

nodoRb* minimo (nodoRb* )
nodoRb* successore (nodoRb* )
nodoRb* RbDelete (nodoRb* )
oid leftRotate (nodoRb* )
void rightRotate (nodoRb* )
void fixRbInsert (nodoRb* )
void fixRbDelete (nodoRb* )
void inorder_Dist (int , string , list<string> & , nodoRb* )
void print_inorder (nodoRb*)
void print_rb(nodoRb* nodo)
void del_postorder (nodoRb* )

********************************************************************
*/
class VocabolarioRbTree : public AbsVocabolario
{
	public:
		VocabolarioRbTree();  // class constructor
		~VocabolarioRbTree() ; // class destructor

		bool Insert();
		bool Delete ();
		bool Search ( list<string> &);
		list<string> SimilWrd (string );
		bool Print();
		bool PrintRB();





	private:
        nodoRb* radice;

        nodoRb* minimo (nodoRb* );
        nodoRb* successore (nodoRb* );
        nodoRb* RbDelete (nodoRb* );
        void leftRotate (nodoRb* );
        void rightRotate (nodoRb* );
        void fixRbInsert (nodoRb* );
        void fixRbDelete (nodoRb* );
        void inorder_Dist (int , string , list<string> & , nodoRb* );
        void print_inorder (nodoRb*);
        void print_rb(nodoRb* nodo);
        void del_postorder (nodoRb* );
};
#endif // ABSVOCABOLARIO_H_INCLUDED

