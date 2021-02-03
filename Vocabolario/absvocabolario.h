#ifndef ABSVOCABOLARIO_H_INCLUDED
#define ABSVOCABOLARIO_H_INCLUDED
#include "projectheader.h"

/*****************************************************************
La classe AbsVocabolario è una classe Astratta in quanto ha dei
metodi virtuali

Ha i seguenti metodi :

int DistEdit(string , string) : il quale restituisce la distanza
                                di editing tra due stringhe

int GetMin (int , int , int ) : il quale resituisce il minimo fra
                                 tre valori

I metodi virtuali da implementare sono :
virtual bool Insert()
virtual bool Delete ()
virtual bool Search ( list<string> & )
virtual list<string> SimilWrd (string )
virtual bool Print()

******************************************************************
*/
class AbsVocabolario
{
	public:


		virtual bool Insert()= 0;
		virtual bool Delete () = 0;
		virtual bool Search ( list<string> & )=0;
		virtual list<string> SimilWrd (string )=0;
		virtual bool Print()=0;
	    int DistEdit(string , string);
	    int GetMin (int , int , int );

};
#endif // ABSVOCABOLARIO_H_INCLUDED

