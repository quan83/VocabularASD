#include "nodorb.h"

// Costruttore Default
nodoRb::nodoRb()
{
    this->isred = false;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

//Costruttore NIL

nodoRb::nodoRb(string word)
{
    this->isred = false;
    this->setParola (word);
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

//COSTRUTTORE CON PARAMETRI
nodoRb::nodoRb(string word,string def)
{
    this->isred = true;
    this->setParola (word);
    this->setDefin (def);
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

// DISTRUTTORE NODO
nodoRb::~nodoRb()
{
}

//METODI


void nodoRb::setColor (bool color)
{
        if (this == nullptr)
            return;
        else
            this->isred = color;
}


void nodoRb::setRight(nodoRb* des)
{
    this->right = des;
    if(des != nullptr)
        des->parent = this;
}

void nodoRb::setLeft(nodoRb* sin)
{
    this->left = sin;
    if(sin != nullptr)
        sin->parent = this;
}
void nodoRb::setParent(nodoRb* parent)
{
        this->parent = parent;
}

bool nodoRb::checkRed()
{
    if (this==nullptr)
        return false;
    else
        return this->isred;
}



nodoRb* nodoRb::getLeft()
{
    return this->left;
}

nodoRb* nodoRb::getRight()
{
    return this->right;
}

nodoRb* nodoRb::getParent()
{
    return this->parent;
}


