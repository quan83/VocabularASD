#include "vocabolariohash.h"


// class destructor
VocabolarioHash::~VocabolarioHash()
{
}

bool VocabolarioHash::Insert()
{
    string word;
    cout << endl << endl << endl;
    cout << "\tVocabolo da inserire : ";
    cout<<endl<<endl<<"\t";
    getline(cin,word);
    cout<<"\t_________________________________"<<endl;
    int k = hashu((char*)word.c_str(), DIM); // calcola l'hash della parola da inserire

    for(auto it = TableH[k].begin(); it!= TableH[k].end(); it++)
        if ( word==it->getParola())
        {
            cout << endl <<  "\tVocabolo gia presente";
            cout<<endl<<"\t_________________________________"<<endl;
            return false;
        }
    string defin;
    cout << endl << "\tInserisci la definizione : " ;
    cout<<endl<<endl<<"\t";
    getline (cin,defin);
    cout<<"\t_________________________________"<<endl;
    TableH[k].push_front(Vocabolo(word,defin));
    return true;

}


bool VocabolarioHash::Delete ()
{
    string word;
    cout << endl <<  "\tVocabolo da eliminare : ";
    cout<<endl<<endl<<"\t";
    getline(cin,word);
    cout<<"\t_________________________________"<<endl;
    int k = hashu((char*) word.c_str(), DIM); // calcola l'hash della parola da eliminare

    for(auto it = TableH[k].begin(); it!= TableH[k].end(); it++)
        if ( word==it->getParola())
        {
            TableH[k].erase(it);
            return true;
        }

    cout << endl <<"\tVocabolo Inesistente";
    cout<<endl<<"\t_________________________________"<<endl;
    return false;
}

bool VocabolarioHash::Search (list<string> &SameW)
{
    string word;
    cout << endl <<  "\tVocabolo da cercare : ";
    cout<<endl<<endl<<"\t";
    getline(cin,word);
    cout<<"\t_________________________________"<<endl;
    int k = hashu((char*)word.c_str() , DIM);

    string def;
    for (auto it = TableH[k].begin();it!= TableH[k].end();it++)
        if(word == it->getParola())
        {
            def = it->getDefin();
            cout << endl << "\tLa definizione della parola cercata e' : ";
            cout<<endl<<endl<<"\t"<< def;
            cout<<endl<<"\t_________________________________"<<endl;
            return true;
        }
    cout << endl <<"\tVocabolo non presente "<< endl;
    cout<<"\t_________________________________"<<endl;
    SameW = SimilWrd(word);
    return false;
}

list<string> VocabolarioHash::SimilWrd (string word)
{
    list <string> SameW;
    int x,y=(word.length())/2;
    string temp;

    for (int i = 0; i < DIM ; i++)
        for(auto it = TableH[i].begin(); it != TableH[i].end() ; it++)
        {
            temp= it->getParola();
            x = DistEdit(word,temp);
            if (x <= y)
                SameW.push_back(temp);
        }
    return SameW;
}


bool  VocabolarioHash::Print()
{
    bool check = false;
    int cont = 0;

    for (int i = 0 ; i < DIM ; i++)
        for(auto it = TableH[i].begin(); it!= TableH[i].end() ; it++)
        {
            cont++;
            if (cont == 1)
            {
                check=true;
                cout <<endl<<endl<<endl;
                cout  << "\tPAROLE CONTENUTE NEL VOCABOLARIO HASH :  ";
                cout <<endl<<endl<<endl;
            }
            cout << endl << "\tVOCABOLO :   " << it->getParola();
            cout <<endl << "\tDEFINIZIONE :   " << it->getDefin();
            cout << endl << "\tRIGA TABELLA HASH : " << i ;
            cout<<endl<<"\t_________________________________"<<endl;


        }
    return check;
}


int VocabolarioHash::hashu (char *v , int m)
{
    int h=0, a = 31415 , b = 27183;
    for ( ;*v!=0 ;v++, a= a*b%(m-1))
        h= (a * h + *v) % m;
    return (h<0)? (h+m) : h;
}




