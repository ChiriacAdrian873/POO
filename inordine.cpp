#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct nod{
int cheie;
nod *fs, *fd;
};

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

int k=1, v1, optiune, optiune2, ok=0;
nod* iter;
nod* noduri[100];
noduri[0]=new nod;
cout<<"Introduceti cheia primului nod: "; cin>>v1; noduri[0]->cheie=v1;
system("CLS");
do{
    meniu();
    cin>>optiune;
    switch(optiune){
    case 1:
        iter=noduri[0];
        cout<<"Cheia nodului: "; cin>>v1;
        while(!ok)
        {
            if(v1<=iter->cheie)
            {
                if(iter->fs!=NULL)
                    iter=iter->fs;
                else
                {
                    noduri[k]=new nod; noduri[k]->cheie=v1; iter->fs=noduri[k]; k++; ok=1;
                }
            }
            else if(v1>=iter->cheie)
            {
                if(iter->fd!=NULL)
                    iter=iter->fd;
                else
                {
                    noduri[k]=new nod; noduri[k]->cheie=v1; iter->fd=noduri[k];  k++; ok=1;
                }
            }
        }
        ok=0;
        system("CLS");
        cout<<"Nodul cu cheia "<<v1<<" a fost introdus; este fiul nodului cu cheia "<<iter->cheie<<endl;
        break;
    case 2:
        meniu2();
        cin>>optiune2;
        switch(optiune2)
        {
            case 1:
                inordine(noduri[0]);
                break;
            case 2:
                preordine(noduri[0]);
                break;
            case 3:
                postordine(noduri[0]);
                break;
            case 4:
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
