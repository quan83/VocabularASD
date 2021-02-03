#ifndef VOCABOLARIOHASH_H_INCLUDED
#define VOCABOLARIOHASH_H_INCLUDED
#include "projectheader.h"
#include "absvocabolario.h"
#include "vocabolo.h"

/*******************************************************************
La classe VocabolarioHash è una classe che eredita alcuni metodi
virtuali da implementare , dalla classe AbsVocabolario.

Come Attributi ha :
static const int DIM :   che è un variabile statica che serve a
                        definire la dimensione massima della Tabella
                        Hash

list<Vocabolo> TableH[DIM] :  che è una lista gestita dalla stl
                               ( Standard Template List) di un array
                               di oggetti costituiti dalla classe
                               Vocabolo , e che forma la Tabella
                               hash


Ha i seguenti metodi pubblici :

        I primi sono ereditati dalla classe AbsVocabolario
        e implementati secondo le caratteristiche della tabella hash

b
Ha i seguenti metodi privati :

int hashu (char *v , int M)  : che ritorna una chiave hash universale
********************************************************************
*/

class VocabolarioHash : public AbsVocabolario
{
	public:
		// class constructor
		VocabolarioHash(){};
		// class destructor
		~VocabolarioHash();

  	    bool Insert();
		bool Delete ();
		bool Search (list<string> &SameW);
		list<string> SimilWrd (string word);
		bool Print();


    private:
        static const int DIM = 383;
        list<Vocabolo> TableH[DIM];
        int hashu (char *v , int M);
};
#endif // ABSVOCABOLARIO_H_INCLUDED
