#ifndef VOCABOLO_H_INCLUDED
#define VOCABOLO_H_INCLUDED
#include "projectheader.h"

/*****************************************************************
La classe Vocabolo  ha i seguenti attributi :

string parola
string definizione

ed i seguenti metodi :

void setParola (string )  modifica  l'attributo parola cambiandolo
                        con una stringa fornita come parametro
void setDefin (string )  modifica  l'attributo definizione cambiandolo
                        con una stringa fornita come parametro
string getParola ()      Ritorna l'attributo parola
string getDefin()       Ritorna l'attributo definizione

******************************************************************
*/
class Vocabolo
{
    public:

        Vocabolo(string parola , string definizione);  // Costruttore con inizializzazione
		Vocabolo(){};  // Costruttore  di default
		~Vocabolo(){};   // distruttore

		void setParola (string parola); //modifica  la parola
		void setDefin (string definizione); //modifica la definizione
		string getParola (); // Ritorna La parola
		string getDefin(); // Ritorna La definiziione

	private:
         string parola;
         string definizione;

};
#endif
