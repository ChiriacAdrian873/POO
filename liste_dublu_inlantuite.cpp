#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct nod
{
    int info;
    nod* urmator, * anterior;
};

nod* prim=NULL;

nod* cautare(nod* prim, int poz)
{
    int i=0;
    while(prim!=NULL && i<poz)
    {
        prim=prim->urmator;
        i++;
    }
    if(i==poz)
        return prim;
    else
        return NULL;
}

void inserare(nod*& prim, int inf)
{
    nod* elem=new nod;
    elem->info=inf;
    elem->anterior=NULL;
    elem->urmator=NULL;
    if(prim==NULL)
    {
        prim=elem;
    }
    else
    {
        nod* iter=prim;
        while(iter->urmator!=NULL)
            iter=iter->urmator;
        iter->urmator=elem;
        elem->anterior=iter;
    }
}

void stergere(nod* elem)
{
     cout<<"3"<<endl;elem->anterior->urmator=elem->urmator;
    cout<<"4"<<endl;elem->urmator->anterior=elem->anterior; cout<<"5"<<endl;
    //delete elem;
}

void stergerepoz(nod*& prim, int poz)
{
    if(prim==NULL) return;
    if(poz==0)
    {
        nod* sters=prim;
        prim=prim->urmator;
        prim->anterior=NULL;
        //delete sters;
        return;
    }
    cout<<"1"<<endl;nod* elem=cautare(prim, poz);
    cout<<"2"<<endl;stergere(elem);
}

void afisare(nod* prim)
{
    int i=0;
    while(prim!=NULL)
    {
        cout<<prim->info<<" se afla pe pozitia "<<i<<endl;
        prim=prim->urmator;
        i++;
    }
}

int main()
{
    int v1, optiune;
    do
    {
        cout<<"1. Inserare elemente"<<endl;
        cout<<"2. Stergere elemente"<<endl;
        cout<<"3. Cautare element"<<endl;
        cout<<"4. Afisare lista"<<endl;
        cout<<"5. Iesire"<<endl;
        cout<<"Alegeti o optiune: ";
        cin>>optiune;
        switch(optiune)
        {
        case 1:
            system("CLS");
            cout<<"Ce valoare doriti sa inserati? "; cin>>v1;
            inserare(prim, v1);
            system("CLS");
            afisare(prim);
            cout<<endl;
            break;
        case 2:
            system("CLS");
            afisare(prim);
            cout<<"Elementul de pe care pozitie doriti sa il stergeti? "; cin>>v1;
            stergerepoz(prim, v1);
            system("CLS");
            cout<<"Elementul a fost sters."<<endl;
            afisare(prim);
            cout<<endl;
            break;
        case 3:
            system("CLS");
            afisare(prim);
            cout<<"Elementul de pe care pozitie doriti sa il cautati? "; cin>>v1;
            system("CLS");
            cout<<"Elementul de pe pozitia "<<v1<<" are valoarea "<<cautare(prim, v1)->info<<endl;;
            break;
        case 4:
            system("CLS");
            afisare(prim);
            cout<<endl;
            break;
        case 5:
            return 0;
        default:
            cout<<"Nu este o optiune valida"<<endl;
        }
    }while(1);

    return 0;
}
