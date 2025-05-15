#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct nod{
int cheie, init;
nod *fs, *fd;
};

void inserare(nod*& rad, int x)
{
    if(rad!=NULL)
    {
        if(rad->cheie==x)
            return;
        else
            if(rad->cheie>x)
                inserare(rad->fs, x);
            else
                inserare(rad->fd, x);
    }
    else
    {
        rad=new nod;
        rad->cheie=x;
        rad->fs=NULL;
        rad->fd=NULL;
        rad->init=1;
    }
}

void meniu(){
cout<<"1. Adaugare nod"<<endl;
cout<<"2. Parcurgere"<<endl;
cout<<"3. Iesire"<<endl;
}

void meniu2(){
cout<<"1. Inordine"<<endl;
cout<<"2. Preordine"<<endl;
cout<<"3. Postordine"<<endl;
cout<<"4. Iesire"<<endl;
}

void inordine(nod* x)
{
    if(x!=NULL)
    {
        inordine(x->fs);
        cout<<x->cheie<<" ";
        inordine(x->fd);
    }
}

void preordine(nod* x)
{
    if(x!=NULL)
    {
        cout<<x->cheie<<" ";
        preordine(x->fs);
        preordine(x->fd);
    }
}

void postordine(nod* x)
{
    if(x!=NULL)
    {
        postordine(x->fs);
        postordine(x->fd);
        cout<<x->cheie<<" ";
    }
}

int main(){
int v1, optiune, optiune2;
nod* rad;
cout<<"Introduceti cheia primului nod: "; cin>>v1;
rad=new nod; rad->cheie=v1; rad->fd=NULL; rad->fs=NULL; rad->init=1;
system("CLS");
do{
    meniu();
    cin>>optiune;
    switch(optiune){
    case 1:
        cout<<"Cheia nodului: "; cin>>v1;
        inserare(rad, v1);
        system("CLS");
        break;
    case 2:
        system("CLS");
        meniu2();
        cin>>optiune2;
        switch(optiune2)
        {
            case 1:
                system("CLS");
                inordine(rad); cout<<endl;
                break;
            case 2:
                system("CLS");
                preordine(rad); cout<<endl;
                break;
            case 3:
                system("CLS");
                postordine(rad); cout<<endl;
                break;
            case 4:
                system("CLS");
                break;
            default:
                cout<<"Nu este o optiune valida"<<endl;
                cin>>optiune2;
                break;
        }
        break;
    case 3:
        break;
    default:
        cout<<"Nu e o optiune valida."<<endl;
        cin>>optiune;
        break;
    }


}while(optiune!=3);

return 0;
}
