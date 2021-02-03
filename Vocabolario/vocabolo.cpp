#include "vocabolo.h"

// costruttore classe con inizializzazione
Vocabolo::Vocabolo(string parola,string definizione)
{
    this->parola = parola;
    this->definizione = definizione;
}

//modifica  la parola
void Vocabolo :: setParola (string parola)
{
    this->parola = parola;
}

//modifica la definizione
void Vocabolo :: setDefin (string definizione)
{
    this->definizione = definizione;
}

// Ritorna La parola
string Vocabolo :: getParola()
{
    return parola;
}

// Ritorna La definizione
string Vocabolo :: getDefin()
{
    return definizione;
}

