#include <iostream>
#include <string>
using namespace std;

class Animal{
protected:
    string nume;
    string rasa;
    int varsta;
    string culoare_ochi;
    int greutate;

public:
    Animal(string nume, int varsta, string rasa, int greutate, string culoare_ochi)
    {
        this->nume=nume;
        this->varsta=varsta;
        this->rasa=rasa;
        this->greutate=greutate;
        this->culoare_ochi=culoare_ochi;
    }
    void afisare_detalii()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Rasa:"<<rasa<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<endl;
    }
};

class Pasare:public Animal{
private:
    int lungime_aripi;
    string culoare_pene;
public:
    Pasare(string nume, int varsta, string rasa, int greutate, string culoare_ochi, int lungime_aripi, string culoare_pene):Animal(nume, varsta, rasa, greutate, culoare_ochi)
    {
        this->lungime_aripi=lungime_aripi;
        this->culoare_pene=culoare_pene;
    }
    void afisare_pasare()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Rasa:"<<rasa<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<" Lungime aripi:"<<lungime_aripi<<" Culoare pene:"<<culoare_pene<<endl;
    }
};

class Caine:public Animal{
private:
    string culoare_blana;
    string rasa_caine;
    string culoare_zgarda;
public:
    Caine(string nume, int varsta, string rasa, int greutate, string culoare_ochi, string culoare_blana, string rasa_caine, string culoare_zgarda):Animal(nume, varsta, rasa, greutate, culoare_ochi)
    {
        this->culoare_blana=culoare_blana;
        this->rasa_caine=rasa_caine;
        this->culoare_zgarda=culoare_zgarda;
    }
    void afisare_caine()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Rasa:"<<rasa<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<" Culoare blana:"<<culoare_blana<<" Rasa cainelui:"<<rasa_caine<<" Culoarea zgarzii:"<<culoare_zgarda<<endl;
    }
};

class Peste:public Animal{
private:
    string culoare_solzi;
    string tip_apa;
public:
    Peste(string nume, int varsta, string rasa, int greutate, string culoare_ochi, string culoare_solzi, string tip_apa):Animal(nume, varsta, rasa, greutate, culoare_ochi)
    {
        this->culoare_solzi=culoare_solzi;
        this->tip_apa=tip_apa;
    }
    void afisare_peste()
    {
        cout<<"Nume:"<<nume<<" Varsta:"<<varsta<<" Rasa:"<<rasa<<" Greutate:"<<greutate<<" Culoare ochi:"<<culoare_ochi<<" Culoare solzi:"<<culoare_solzi<<" Traieste in apa "<<tip_apa<<endl;
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

    Pasare *pasari(p);
    Caine *caini;
    Peste *pesti;

    for(i=0; i<p; i++)
    {
        string nume; int varsta; string rasa; string culoare_ochi; int greutate; int lungime_aripi; string culoare_pene;
        cin>>nume>>varsta>>rasa>>culoare_ochi>>greutate>>lungime_aripi>>culoare_pene;
        pasari(i)=new Pasare(nume, varsta, rasa, greutate, culoare_ochi, lungime_aripi, culoare_pene);
    }
    for(i=0; i<p; i++)
    {
        pasari(i)->afisare_pasare;
    }
    return 0;
}
