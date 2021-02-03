#ifndef NODORB_H_INCLUDED
#define NODORB_H_INCLUDED
#include "projectheader.h"
#include "vocabolo.h"
/*****************************************************************
La classe NodoRb è una classe che eredita attributi dalla classe
Vocabolo , quindi ogni nodo contiene due attributi stringa : parola
 e definizione

Ha in aggiunta i seguenti attributi :
nodoRb *left, *right, *parent puntatori ad altri nodi
bool isred;

Ha i seguenti metodi :

bool checkRed();	     :  ritorna il colore del nodo
void setColor (bool )    :  setta il colore del nodo
void setRight(nodoRb* )  :  setta il nodo destro
void setLeft(nodoRb* )   :  setta il nodo sinistro
void setParent(nodoRb*)  :  setta il nodo padre
nodoRb* getLeft()        :  ritorna il puntatore al nodo sinistro
nodoRb* getRight()       :  ritorna il puntatore al nodo destro
nodoRb* getParent()      :  ritorna il puntatore al nodo padre

******************************************************************
*/
class nodoRb : public Vocabolo
{
	public:
		// class constructor
		nodoRb();
		nodoRb(string word,string def);
		nodoRb(string word);

		// class destructor
		~nodoRb();
		bool checkRed();	            // ritorna il colore del nodo
        void setColor (bool color);     // setta il colore del nodo
		void setRight(nodoRb* des);    // setta il nodo destro
		void setLeft(nodoRb* sin);    // setta il nodo sinistro
		void setParent(nodoRb* parent);    // setta il nodo padre
		nodoRb* getLeft();              // ritorna il puntatore al nodo sinistro
		nodoRb* getRight();             // ritorna il puntatore al nodo destro
		nodoRb* getParent();            // ritorna il puntatore al nodo padre


	private:
        nodoRb *left, *right, *parent;  // puntatori al padre, e figli
        bool isred;                     // var.booleana per il colore

};


#endif
