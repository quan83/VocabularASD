#include "vocabolariorbtree.h"

//COSTRUTTORE DELLA CLASSE
VocabolarioRbTree::VocabolarioRbTree()
{
    radice = nullptr;
}

//DISTRUTTORE
VocabolarioRbTree::~VocabolarioRbTree()
{
	del_postorder(radice);
}


///METODI

nodoRb* VocabolarioRbTree::successore (nodoRb* x)
{
    //CASO 1  : ESISTE FIGLIO DESTRO
    if ( x->getRight() != nullptr)
    {
        x = x->getRight();
        // il successore è il minimo
        // del sottoalbero destro di x
        while(x->getLeft() != nullptr)
            x = x->getLeft();
        return x;
    }

    nodoRb* y = x->getParent();
    //CASO 2-3  : NON ESISTE FIGLIO DESTRO DI X ,
    //           X FIGLIO SINISTRO
    // il successore è il padre di X

    //             NON ESISTE FIGLIO DESTRO DI X,
    //             X FIGLIO DESTRO
    // il successore è l'ultimo antenato per il
    // quale X si trova nel suo sottoalbero sinistro
    while (y != nullptr && x == y->getLeft())
        {
            x=y;
            y = y->getParent() ;
        }
    return y;
}

void VocabolarioRbTree::leftRotate (nodoRb* x)
{
    if (x->getRight() == nullptr)
        return;
    nodoRb* y;  // nodo di appoggio
    y = x->getRight();    // y diventa figlio destro di x
    x->setRight(y->getLeft()); // Imoosto il figlio sinistro di y  come figlio destro di x
    y->setParent(x->getParent());
    if(x->getParent() == nullptr)
        radice = y;
    else
    {
        if (x->getParent()->getLeft()== x)
            x->getParent()->setLeft(y);
        else
            x->getParent()->setRight(y);
    }
     y->setLeft(x);
     x=y;
}


void VocabolarioRbTree::rightRotate (nodoRb* x)
{
    if (x->getLeft() == nullptr)
        return;
    nodoRb* y;  // nodo di appoggio
    y = x->getLeft();    // y diventa figlio destro di x
    x->setLeft(y->getRight()); // Imoosto il figlio sinistro di y  come figlio destro di x
    //y->setLeft(x);
    y->setParent(x->getParent());
    if(x->getParent() == nullptr)
        radice = y;
    else
    {
        if (x->getParent()->getRight()== x)
            x->getParent()->setRight(y);
        else
            x->getParent()->setLeft(y);
    }
     y->setRight(x);
     x=y;
}



bool VocabolarioRbTree::Insert()
{
    string word ;
    bool check = false;
    cout << endl << "\tVocabolo da inserire : ";
    cout<<endl<<endl<<"\t";
    getline(cin,word);
    cout<<"\t_________________________________"<<endl;
    nodoRb* x;  // nodo di appoggio per la ricerca nell'albero
    nodoRb* y; // padre di x
    x = radice;
    y = nullptr;
    //ricerca posizione da inserire
    while ( x!= nullptr)
    {
        if( word == x->getParola() )
        {
            cout << endl <<  "\tVocabolo gia presente";
            cout<<endl<<"\t_________________________________"<<endl;
            return check;
        }
        // altrimenti si muove nel figlio sinistro se la parola è piu piccola
        // o viceversa nel figlio destro
        y = x;
        x = (x->getParola() > word)?  x->getLeft()  : x->getRight();
    }
    //altrimenti inserisce la parola
    check  = true; // AVVISO CHE LA PAROLA SARA INSERITA
    string def;
    cout << endl << "\tInserisci la definizione : ";
    cout<<endl<<endl<<"\t";
    getline (cin,def);
    cout<<"\t_________________________________"<<endl;
    x = new nodoRb(word,def); //inizializzo il nuovo nodo come  RED

    if (y == nullptr)  // SE NON CE NESSUN NODO NELL'ALBERO
        radice = x; // la radice punterà al nuovo nodo creato

    else  // ALTRIMENTI SI POSIZIONA NELLA FOGLIA GIUSTA
        {
            if ( word < y->getParola())
            y->setLeft(x);
            else
            y->setRight(x);
        }

     if (check)  // SE IL NODO E' STATO INSERITO
        fixRbInsert(x); //SI RIBILANCIA l'ALBERO
    return check;

}


void VocabolarioRbTree::fixRbInsert(nodoRb* x)
{
    nodoRb* p;// PADRE DI X
    nodoRb* n; // NONNO DI X
    nodoRb* z; // ZIO DI X
    while (x!= nullptr)
    {
        // RIMPOSTO AD OGNI ITERAZIONE
        // PADRE
        p  = x->getParent();

        //NONNO
        n = ( p != nullptr)? p->getParent() : nullptr;

        //ZIO
        if (n == nullptr)
            z = nullptr;
        else
        z =  (p == n->getLeft()) ? n->getRight() : n->getLeft();

            // CASO 1 PRIMO NODO A ESSER INSERITO
        if ( p == nullptr)
        {
            x->setColor(false) ;         // X DIVENTA NERO
            x = nullptr; // si esce dal while
        }

        // CASO 2 PADRE DI X NERO  - NESSUN VINCOLO VIOLATO
        else if(p->checkRed()== false)
            x = nullptr;

        else if (z!= nullptr)
        {
            if(z->checkRed())
             {
                //CASO 3  :  PADRE ROSSO , ZIO ROSSO ,x ROSSO
                 p->setColor(false); //COLORO IL PADRE NERO
                 z->setColor(false);// COLORO LO ZIO NERO
                if (n != nullptr)
                    n->setColor(true); // COLORO IL NONNO ROSSO
                x = n;// SPOSTIAMO IL PROBLEMA + IN ALTO
             }
            // CASO 4
            // p FIGLIO SINISTRO DI N
            // p NERO , z ESISTE ED é NERO , x ROSSO
            // 2 SOTTO CASI , x FIGLIO DESTRO OR x FIGLIO SINISTRO
            else
            {
                // 4.a X FIGLIO DESTRO
                if (x==p->getRight() &&  p == n->getLeft())
                {
                    leftRotate(p);
                    x = p;
                }
                // 4.b X FIGLIO SINISTRO
                else if (x==p->getLeft() && p == n->getRight())
                {
                    rightRotate(p);
                    x = p;
                }
                // CASO 5
                // p ROSSO , z NERO  , x ROSSO
                // 2 SOTTO CASI ,
                else
                {   //5.a x figlio sinistro di p , p FIGLIO SINISTRO DI N
                    if (x==p->getLeft() && p == n->getLeft())
                        rightRotate(n);
                    else if ( x==p->getRight() && p == n->getRight())
                        leftRotate(n);
                p->setColor(false); // coloro p di nero
                n->setColor(true); // coloro n di rosso
                x = nullptr;
                }
            }
        }

        // CASO 4 e 5 CON ZIO NULLPTR QUINDI NERO
        // UGUALI AI PRECEDENTI MA SI EVITA CONTROLLO
        else
        {
            if (x==p->getRight() &&  p == n->getLeft())
            {
                leftRotate(p);
                x = p;
            }
            else if (x==p->getLeft() && p == n->getRight())
            {
                rightRotate(p);
                x = p;
            }
            else
            {
                if (x==p->getLeft() && p == n->getLeft())
                    rightRotate(n);
                else if ( x==p->getRight() && p == n->getRight())
                        leftRotate(n);

                p->setColor(false); // coloro p di nero
                n->setColor(true); // coloro n di rosso
                x = nullptr;
            }

        }
    }
}



bool VocabolarioRbTree::Delete ()
{
    bool check = false;
    string word ;
    nodoRb* z = radice; // per la ricerca
    nodoRb* y; //nodo da eliminare

    // Inseriamo vocabolo da eliminare
    cout << endl <<  "\tVocabolo da eliminare : ";
    cout<<endl<<endl<<"\t";
    getline(cin,word);
    cout<<"\t_________________________________"<<endl;


    // FASE 1 : RICERCA DELLA PAROLA NELL' ALBERO
    while( z != nullptr && z->getParola() != word)
        z = (z->getParola() > word)?  z->getLeft()  : z->getRight();

    if ( z == nullptr) // nel caso non viene trovata
    {
        cout << endl <<"\tVocabolo Inesistente";
        cout<<endl<<"\t_________________________________"<<endl;
        return check;
    }
    check=true;  // parola trovata  = z
    //se la parola trovata è nella  radice e la radice non ha figli
    if (z == radice && (z->getRight()==nullptr && z->getLeft()== nullptr))
    {
        delete z;
        radice = nullptr;
        return check;

    }
    //altrimenti verifichiamo quale nodo effettivamente va eliminato
    y = RbDelete(z);
    delete y; //deallochiamo il nodo da eliminare
    return check;
}

nodoRb* VocabolarioRbTree::RbDelete (nodoRb* z)
{
    nodoRb* y;
    nodoRb* x;
    nodoRb* temp =  nullptr;
    // COME PRIMO PASSAGGIO CONTROLLIAMO SE
    if (z->getLeft()== nullptr || z->getRight() == nullptr) // CASO 1 AL + UN FIGLIO
            y=z; // Il nodo da eliminare è esattamente z
    else
        y = successore(z); // CASO2   -   2 FIGLI
        // Il nodo da eliminare è il suo successore


    // Adesso Impostiamo il nodo X che serve a ribilanciare successivamente
    // l'albero :

    if (y->getLeft() != nullptr)
        x=y->getLeft(); //

    else if (y->getRight()!= nullptr) // VICEVERSA , DESTRO
        x=y->getRight();

    else    // Y NON HA FIGLI
                x = new nodoRb("NIL");


    if (y->getParent() == nullptr) // SE IL PADRE è NULLPTR
       {
            radice = x; // X è La radice
            x->setParent(nullptr);
       }
           //ALTRIMENTI EFFETTUIAMO LO SHORTCUT
    else
    {
        if (y == y->getParent()->getLeft())
            y->getParent()->setLeft(x);
        else
            y->getParent()->setRight(x);
    }

            // sostituiamo le chiavi
    if (y!= z)
    {
        z->setParola(y->getParola());
        z->setDefin(y->getDefin());
    }
    if (x->getParola()=="NIL")  // se il nodo di appoggio é stato creato
      temp = x; // ce lo copiamo in un nodo temp


    if (y->checkRed()== false)  // se il nodo da eliminare é nero
        fixRbDelete (x);        // Ribilanciamo l'albero RB

    if (temp != nullptr) // elimino il nodo di appoggio creato in precedenza
    {                     // effettuando uno shortcut dal padre
        if (temp == temp->getParent()->getLeft())
            temp->getParent()->setLeft(nullptr);

        else
            temp->getParent()->setRight(nullptr);

        delete temp; // il nodo temp viene deallocato
    }


    return y;
}

void VocabolarioRbTree::fixRbDelete (nodoRb* x)
{
    nodoRb* brother;
    while (x != radice && x->checkRed()== false)
    {

            if (x == x->getParent()->getLeft()) // CASI (1-3)A x Figlio sinistro
            {
                brother = x->getParent()->getRight();  // fratello figlio destro
                if(brother->checkRed())
                {      //  CASO 1.a  --> il fratello di x è rosso
                    x->getParent()->setColor(true);  // il padre di x è rosso
                    brother->setColor(false); //  il fratello di x diventa nero
                    leftRotate(x->getParent()); //padre(x) effettua una rotazione a sin
                    brother = x->getParent()->getRight(); // reimposto w come fratello di x
                }


                if ( brother->getLeft()->checkRed()== false && brother->getRight()->checkRed() == false)
                {   //CASO 2.a  --> il fratello di x è NERO e ha FIGLI NERI
                    brother->setColor(true);  // fratello di x diventa rosso
                    x = x->getParent(); //spostiamo il problema più in alto
                }

                else
                {
                    if (brother->getRight()->checkRed() == false) //
                    { //CASO 3.a  --> fratello di x è nero e ha il figlio sinistro rosso
                        brother->getLeft()->setColor(false); //il figlio sinistro diventa nero
                        brother->setColor(true); // e il fratello diventa rosso
                        rightRotate(brother); // effettuiamo una rotazione a destra
                        brother = x->getParent()->getRight(); // reimpostiamo il fratello
                        // e ci portiamo nel caso 4
                    }// CASO 4.a
                    brother->setColor(x->getParent()->checkRed()); // settiamo lo stesso colore del padre di x
                    brother->getParent()->setColor(false);  // il padre del fratello diventa nero
                    brother->getRight()->setColor(false); // il figlio destro diventa nero
                    leftRotate(x->getParent()); // effettuiamo una rotazione a sinistra
                    x = radice; // e settiamo x = alla radice e si esce dal while
                }

            }
            else  // CASI (1-3)B x Figlio destro
                 // simmetrici ai precedenti
            {
                brother = x->getParent()->getLeft();
                if(brother->checkRed())
                {   //  CASO 1.b
                    x->getParent()->setColor(true);
                    brother->setColor(false);
                    rightRotate(x->getParent());
                    brother= x->getParent()->getLeft();
                }
                if ( brother->getLeft()->checkRed()== false && brother->getRight()->checkRed()== false)
                { // CASO 2.b
                    brother->setColor(true);
                    x = x->getParent();
                }
                else
                {

                    if (brother->getLeft()->checkRed() == false)
                    { //CASO 3.b
                        brother->getRight()->setColor(false);
                        brother->setColor(true);
                        leftRotate(brother);
                        brother = x->getParent()->getLeft();
                    }// CASO 4.b
                    brother->setColor(x->getParent()->checkRed());
                    x->getParent()->setColor(false);
                    brother->getLeft()->setColor(false);
                    rightRotate(x->getParent());
                    x = radice;
                }

            }

    }
    x->setColor(false); // x viene colorato di nero
}


bool VocabolarioRbTree::Search ( list<string> &SameW)
{
    string word ;
    cout << endl <<  "\t\tVocabolo da cercare : ";
    cout<<endl<<endl<<"\t";
    getline(cin,word);
    cout<<"\t_________________________________"<<endl;
    nodoRb* z = radice; // per la ricerca

    // FASE 1 : RICERCA DELLA PAROLA NELL' ALBERO
    while( z != nullptr && z->getParola() != word)
        z = (z->getParola() > word)?  z->getLeft()  : z->getRight();

    if ( z == nullptr) // nel caso non viene trovata
    {
        cout << endl <<  "\t\tVocabolo non presente " << endl ;
        cout<<"\t_________________________________"<<endl;
        SameW = SimilWrd(word);
        return false;
    }
    string def = z->getDefin();
    cout << endl <<"\tLa definizione della parola cercata e' : "<< endl;
    cout<<"\t" << def << endl;
    cout<<"\t_________________________________"<<endl;
    return true;
}


list<string> VocabolarioRbTree::SimilWrd (string word)
{
    list <string> SameW;
    int y=(word.length())/2;
    inorder_Dist(y,word,SameW,radice);
    return SameW;
}

void VocabolarioRbTree::inorder_Dist (int y , string word,list<string>  &SameW , nodoRb* nodo)
{
    if(nodo == nullptr)
        return;
    inorder_Dist(y , word ,SameW , nodo->getLeft());
    string temp = nodo->getParola();
    int x = DistEdit(word,temp);
    if (x<=y)
        SameW.push_back(temp);
    inorder_Dist(y , word , SameW,nodo->getRight());
    return;
}

bool VocabolarioRbTree::PrintRB()
{
    if (radice == nullptr)
        return false;
    else
    {
        cout <<endl<<endl<<endl;
        cout  << "\t\tVISTA ALBERO RB";
        cout <<endl<<endl<<endl;
        print_rb(radice);
    }
    return true;
}

void VocabolarioRbTree::print_inorder(nodoRb* nodo)
{
    if(nodo == nullptr)
        return;
    print_inorder(nodo->getLeft());
    cout <<endl << "\tVOCABOLO :   " << nodo->getParola();
    cout <<endl << "\tDEFINIZIONE:   " << nodo->getDefin();
    cout<<endl<<"\t_________________________________"<<endl;
    print_inorder(nodo->getRight());
}

bool VocabolarioRbTree::Print()
{
    if (radice == nullptr)
        return false;
    else
     {
        cout <<endl<<endl<<endl;
        cout  << "\t\tPAROLE CONTENUTE NEL VOCABOLARIO RED&BLACK ";
        cout <<endl<<endl<<endl;
        print_inorder(radice);
     }
    return true;
}
void VocabolarioRbTree::print_rb(nodoRb* nodo)
{
    if ( nodo == nullptr)
        return;

    string s1,s2,s3;
    s1 = "\t";
    s2 = "              ";
    nodoRb* temp = nullptr;
    temp = nodo->getParent();
    while (temp != nullptr)
    {
            temp = temp->getParent();
            s1 += s2;
    }
    s3 = s1 + s2;
    print_rb(nodo->getRight());

    if(nodo->getRight() == nullptr)
    {
        cout <<endl<<endl;
        cout <<endl<<s3 + "NIL";
        cout<<endl<<s3 + "PADRE : ";
        cout << nodo->getParola();
        cout <<endl<<s3 + "Colore : ";
        cout<< "NERO";
        cout<<endl;
    }

    cout <<endl<<endl;
    cout <<endl<<s1 + nodo->getParola();
    if (nodo->getParent()!= nullptr)
    {
        cout<<endl<<s1 + "PADRE : ";
        cout << nodo->getParent()->getParola();
    }
    else
        cout<<endl<<s1 + "RADICE";
    cout <<endl<<s1 + "Colore : ";
    if (nodo->checkRed())
        cout <<"ROSSO"<<endl;
    else
        cout <<"NERO"<<endl;

    if(nodo->getLeft() == nullptr)
    {
        cout <<endl<<endl;
        cout <<endl<<s3 + "NIL";
        cout<<endl<<s3 + "PADRE : ";
        cout << nodo->getParola();
        cout <<endl<<s3 + "Colore : ";
        cout<< "NERO"<<endl;
    }
    print_rb(nodo->getLeft());
}



 void VocabolarioRbTree::del_postorder (nodoRb* nodo)
{

    if(nodo == nullptr)
        return;
    del_postorder(nodo->getLeft());
    del_postorder(nodo->getRight());
    delete nodo;
}

