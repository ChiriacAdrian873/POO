#include <iostream>
#include <string>
using namespace std;

int nr_pasari, nr_caini, nr_pesti;

class Animal{
protected:
    string nume;
    int varsta;
    string culoare_ochi;
    float greutate;

public:
    Animal(string nume, int varsta, float greutate, string culoare_ochi)
    {
        this->nume=nume;
        this->varsta=varsta;
        this->greutate=greutate;
        this->culoare_ochi=culoare_ochi;
    }
    void afisare_detalii()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<endl;
    }
};

class Pasare:public Animal{
private:
    int lungime_aripi;
    string culoare_pene;
public:
    Pasare(string nume, int varsta, float greutate, string culoare_ochi, int lungime_aripi, string culoare_pene):Animal(nume, varsta, greutate, culoare_ochi)
    {
        this->lungime_aripi=lungime_aripi;
        this->culoare_pene=culoare_pene;
        nr_pasari++;
    }
    void afisare_pasare()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<" Lungime aripi:"<<lungime_aripi<<" Culoare pene:"<<culoare_pene<<endl;
    }
};

class Caine:public Animal{
private:
    string culoare_blana;
    string rasa_caine;
    string culoare_zgarda;
public:
    Caine(string nume, int varsta, float greutate, string culoare_ochi, string culoare_blana, string rasa_caine, string culoare_zgarda):Animal(nume, varsta, greutate, culoare_ochi)
    {
        this->culoare_blana=culoare_blana;
        this->rasa_caine=rasa_caine;
        this->culoare_zgarda=culoare_zgarda;
        nr_caini++;
    }
    void afisare_caine()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<" Culoare blana:"<<culoare_blana<<" Rasa cainelui:"<<rasa_caine<<" Culoarea zgarzii:"<<culoare_zgarda<<endl;
    }
};

class Peste:public Animal{
private:
    string culoare_solzi;
    string tip_apa;
public:
    Peste(string nume, int varsta, float greutate, string culoare_ochi, string culoare_solzi, string tip_apa):Animal(nume, varsta, greutate, culoare_ochi)
    {
        this->culoare_solzi=culoare_solzi;
        this->tip_apa=tip_apa;
        nr_pesti++;
    }
    void afisare_peste()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<" Culoare solzi:"<<culoare_solzi<<" Traieste in apa "<<tip_apa<<endl;
    }
};

int main()
{
    int i, k;
    cout<<"Cate animale sunt in zoo?"<<endl;
    cin>>k;
    const int n=k; //nr animale total
    cout<<"Cate pasari sunt in zoo?"<<endl;
    cin>>k;
    const int p=k;
    cout<<"Cati caini sunt in zoo?"<<endl;
    cin>>k;
    const int c=k;
    cout<<"Cati pesti sunt in zoo?"<<endl;
    cin>>k;
    const int ps=k;

    Pasare* pasari[p];
    Caine* caini[c];
    Peste* pesti[ps];

    for(i=0; i<p; i++)
    {
        string nume; int varsta;; string culoare_ochi; float greutate; int lungime_aripi; string culoare_pene;
        cout<<endl<<"Introduceti informatii pentru pasarea numarul "<<nr_pasari+1<<endl;
        cout<<"Numele pasarii:"; cin>>nume;
        cout<<"Varsta pasarii(ani):"; cin>>varsta;
        cout<<"Culoarea ochilor:"; cin>>culoare_ochi;
        cout<<"Greutatea pasarii(kg):"; cin>>greutate;
        cout<<"Lungimea aripilor(cm):"; cin>>lungime_aripi;
        cout<<"Culoarea penelor:"; cin>>culoare_pene;
        pasari[i]=new Pasare(nume, varsta, greutate, culoare_ochi, lungime_aripi, culoare_pene);
    }
    for(i=0; i<p; i++)
    {
        pasari[i]->afisare_pasare();
    }

    for(i=0; i<c; i++)
    {
        string nume; int varsta;; string culoare_ochi; float greutate; string culoare_blana; string rasa_caine; string culoare_zgarda;
        cout<<endl<<"Introduceti informatii pentru cainele numarul "<<nr_caini+1<<endl;
        cout<<"Numele cainelui:"; cin>>nume;
        cout<<"Varsta cainelui(ani):"; cin>>varsta;
        cout<<"Culoarea ochilor:"; cin>>culoare_ochi;
        cout<<"Greutatea cainelui(kg):"; cin>>greutate;
        cout<<"Culoarea blanii:"; cin>>culoare_blana;
        cout<<"Culoarea zgarzii:"; cin>>culoare_zgarda;
        cout<<"Rasa cainelui:"; cin>>rasa_caine;
        caini[i]=new Caine(nume, varsta, greutate, culoare_ochi, culoare_blana, rasa_caine, culoare_zgarda);
    }
    for(i=0; i<c; i++)
    {
        caini[i]->afisare_caine();
    }

    for(i=0; i<ps; i++)
    {
        string nume; int varsta;; string culoare_ochi; float greutate; string culoare_solzi; string tip_apa;
        cout<<endl<<"Introduceti informatii pentru pestele numarul "<<nr_pesti+1<<endl;
        cout<<"Numele pestelui:"; cin>>nume;
        cout<<"Varsta pestelui(ani):"; cin>>varsta;
        cout<<"Culoarea ochilor:"; cin>>culoare_ochi;
        cout<<"Greutatea pestelui(kg):"; cin>>greutate;
        cout<<"Culoare solzilor:"; cin>>culoare_solzi;
        cout<<"Tipul de apa in care traieste:"; cin>>tip_apa;
        pesti[i]=new Peste(nume, varsta, greutate, culoare_ochi, culoare_solzi, tip_apa);
    }
    for(i=0; i<ps; i++)
    {
        pesti[i]->afisare_peste();
    }
    return 0;
}
