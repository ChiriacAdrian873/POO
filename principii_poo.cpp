#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int id;
int nrAnimale=0, nrPesti=0, nrBroaste=0, nrHomari=0;

class Animal{
private:
    friend class Admin;
protected:
    string nume;
    float greutate;
public:
    Animal(string nume, float greutate)
    {
        this->nume=nume; this->greutate=greutate;
    }
    /*~Animal()
    {
        cout<<"Animalul a fost eliberat."<<endl;
    }*/
};

class Peste:public Animal{
private:
    friend class Admin;
protected:
    string speciePeste;
    int idAnimalp;
    string speciep;
public:
    Peste(string nume, float greutate, string speciePeste):Animal(nume, greutate)
    {
        this->speciePeste=speciePeste; this->idAnimalp=id; this->speciep="Peste";
        id++; nrAnimale++; nrPesti++;
    }
    ~Peste()
    {
        cout<<"Pestele a fost eliberat."<<endl;
        nrPesti--;
    }
    void afisare_p()
    {
        cout<<idAnimalp<<". Numele pestelui: "<<nume<<" Specia: "<<speciePeste<<" Greutatea: "<<greutate<<endl;
    }
    string get_speciep()
    {
        return speciep;
    }
};

class Broasca:public Animal{
private:
    friend class Admin;
protected:
    string specieBroasca;
    int idAnimalb;
    string specieb;
public:
    Broasca(string nume, float greutate, string specieBroasca):Animal(nume, greutate)
    {
        this->specieBroasca=specieBroasca; this->idAnimalb=id; this->specieb="Broasca";
        id++; nrAnimale++; nrBroaste++;
    }
    ~Broasca()
    {
        cout<<"Broasca a fost eliberata."<<endl;
        nrBroaste--;
    }
    void afisare_b()
    {
        cout<<idAnimalb<<". Numele broastei: "<<nume<<" Specia: "<<specieBroasca<<" Greutatea: "<<greutate<<endl;
    }
    string get_specieb()
    {
        return specieb;
    }
};

class Homar:public Animal{
private:
    friend class Admin;
protected:
    string specieHomar;
    int idAnimalh;
    string specieh;
public:
    Homar(string nume, float greutate, string specieHomar):Animal(nume, greutate)
    {
        this->specieHomar=specieHomar; this->idAnimalh=id; this->specieh="Homar";
        id++; nrAnimale++; nrHomari++;
    }
    ~Homar()
    {
        cout<<"Homarul a fost eliberat."<<endl;
        nrHomari--;
    }
    void afisare_h()
    {
        cout<<idAnimalh<<". Numele homarului: "<<nume<<" Specia: "<<specieHomar<<" Greutatea: "<<greutate<<endl;
    }
    string get_specieh()
    {
        return specieh;
    }
};




class Admin{
public:
    void afisareAcvariu(char v[20][58])
    {
        cout<<"----------------------------------------------------------"<<endl;
        for(int i=0; i<20; i++)
            {
                for(int j=0; j<58; j++)
                    cout<<v[i][j];
                cout<<endl;
            }
        cout<<"----------------------------------------------------------"<<endl;
    }
    void afisareAnimale(Peste* p[], Broasca* b[], Homar* h[])
    {
        if(nrAnimale==0)
            {
                cout<<"Nu exista nici un animal in acvariu!"<<endl;
                return;
            }
            if(nrPesti!=0)
            {
                cout<<"Pesti:"<<endl;
                for(int iter=1; iter<=nrPesti; iter++)
                    p[iter]->afisare_p();
            }
            if(nrBroaste!=0)
            {
                cout<<endl<<"Broaste:"<<endl;
                for(int iter=1; iter<=nrBroaste; iter++)
                    b[iter]->afisare_b();
            }
            if(nrHomari!=0)
            {
                cout<<endl<<"Homari:"<<endl;
                for(int iter=1; iter<=nrHomari; iter++)
                    h[iter]->afisare_h();
            }
    }
}admin;


void meniu()
{
    cout<<endl<<"1. Adaugati un animal"<<endl;
    cout<<endl<<"2. Eliberati un animal"<<endl;
    cout<<endl<<"3. Informatii animale"<<endl;
    cout<<endl<<"4. Iesire"<<endl;
    cout<<endl<<"Alegeti o operatie: ";
}

int main()
{
    int k;
    cout<<"Cate animale poate stoca acvariul? "; cin>>k;
    while(cin.fail())
    {
        cout<<endl<<"Nu este o valoare valida! Introduceti o alta valoare: "; cin.clear(); cin.ignore(100, '\n'); cin>>k;
    }
    system("CLS");
    const int n=k;
    Peste* pesti[n];
    Broasca* broaste[n];
    Homar* homari[n];
    int optiune, optiune2, v1, v2, indice;
    string vs1, vs2;
    char acvariu[20][58];
    for(int i=0; i<20; i++)
        {
            for(int j=0; j<58; j++)
                acvariu[i][j]=' ';
        }
    for(int i=0; i<20; i++)
    {
        acvariu[i][0]='|'; acvariu[i][57]='|';
    }

    do{
    admin.afisareAcvariu(acvariu);
    cout<<endl<<"Acvariul contine "<<nrAnimale<<" animale: "<<nrPesti<<" pesti, "<<nrBroaste<<" broaste si "<<nrHomari<<" homari."<<endl;
    cout<<"Id curent: "<<id<<endl;
    meniu();
    cin>>optiune;

    switch(optiune)
    {
        case 1:
            system("CLS");
            if(nrAnimale>=n)
            {
                cout<<"Acvariul este plin!"<<endl<<endl;
                break;
            }
            cout<<"1. Peste"<<endl<<"2. Broasca"<<endl<<"3. Homar"<<endl<<"Ce fel de animal doriti sa adaugati? ";
            cin>>optiune2;
            switch(optiune2)
            {
                case 1:
                cout<<endl<<"Introduceti numele pestelui: "; cin>>vs1;
                cout<<"Greutatea pestelui(kg): "; cin>>v1;
                cout<<"Si specia pestelui: "; cin>>vs2;
                pesti[nrPesti]=new Peste(vs1, v1, vs2);
                if(nrPesti<16)
                    {   acvariu[nrPesti+2][nrPesti*2%26+13-(nrPesti%2)*(nrPesti+17)%8+nrPesti%5]='<'; acvariu[nrPesti+2][nrPesti*2%26+13-(nrPesti%2)*(nrPesti+17)%8+2+nrPesti%5]='<'; acvariu[nrPesti+2][nrPesti*2%26+13-(nrPesti%2)*(nrPesti+17)%8+1+nrPesti%5]='>';  }
                system("CLS");
                break;

                case 2:
                cout<<endl<<"Introduceti numele broastei: "; cin>>vs1;
                cout<<"Greutatea broastei(kg): "; cin>>v1;
                cout<<"Si specia broastei: "; cin>>vs2;
                broaste[nrBroaste]=new Broasca(vs1, v1, vs2);
                if(nrBroaste<4)
                {    acvariu[19][nrBroaste*7%6+5+nrBroaste*10]='&'; acvariu[19][nrBroaste*7%6+6+nrBroaste*10]='>';   }
                system("CLS");
                break;

                case 3:
                cout<<endl<<"Introduceti numele homarului: "; cin>>vs1;
                cout<<"Greutatea homarului(kg): "; cin>>v1;
                cout<<"Si specia homarului: "; cin>>vs2;
                homari[nrHomari]=new Homar(vs1, v1, vs2);
                if(nrHomari<3)
                {
                    acvariu[17][nrHomari*7%6+8+nrHomari*15]='>'; acvariu[17][nrHomari*7%6+15+nrHomari*15]='>';
                    acvariu[17][nrHomari*7%6+9+nrHomari*15]='<';
                    acvariu[17][nrHomari*7%6+10+nrHomari*15]=','; acvariu[17][nrHomari*7%6+11+nrHomari*15]=','; acvariu[17][nrHomari*7%6+12+nrHomari*15]=','; acvariu[17][nrHomari*7%6+13+nrHomari*15]=','; acvariu[17][nrHomari*7%6+14+nrHomari*15]=',';
                    acvariu[17][nrHomari*7%6+16+nrHomari*15]='=';
                }
                system("CLS");
                break;

                default:
                    system("CLS");
                    cout<<endl<<"Nu este o optiune valida"<<endl<<endl;
                    if(cin.fail())
                    {   cin.clear(); cin.ignore(100, '\n');    }
            }
            break;

        case 2:
            system("CLS");
            if(nrAnimale==0)
            {
                cout<<"Acvariul este gol!"<<endl<<endl;
                break;
            }
            cout<<"1. Peste"<<endl<<"2. Broasca"<<endl<<"3. Homar"<<endl<<"Ce fel de animal doriti sa eliberati? ";
            cin>>optiune2;
            switch(optiune2)
            {
                case 1:
                for(int iter=1; iter<=nrPesti; iter++)
                {
                    if(pesti[iter]->get_speciep()=="Peste")
                        indice=iter;
                }
                delete pesti[indice];
                if(nrPesti>0)
                    {   acvariu[nrPesti+2][nrPesti*2%26+13-(nrPesti%2)*(nrPesti+17)%8+nrPesti%5]=' '; acvariu[nrPesti+2][nrPesti*2%26+13-(nrPesti%2)*(nrPesti+17)%8+2+nrPesti%5]=' '; acvariu[nrPesti+2][nrPesti*2%26+13-(nrPesti%2)*(nrPesti+17)%8+1+nrPesti%5]=' ';  }
                system("CLS");
                break;

                case 2:
                for(int iter=1; iter<=nrBroaste; iter++)
                {
                    if(broaste[iter]->get_specieb()=="Broasca")
                        indice=iter;
                }
                delete broaste[indice];
                if(nrBroaste>0)
                {    acvariu[19][nrBroaste*7%6+5+nrBroaste*10]=' '; acvariu[19][nrBroaste*7%6+6+nrBroaste*10]=' ';   }
                system("CLS");
                break;

                case 3:
                for(int iter=1; iter<=nrHomari; iter++)
                {
                    if(homari[iter]->get_specieh()=="Homar")
                        indice=iter;
                }
                delete homari[indice];
                if(nrHomari<3)
                {
                    acvariu[17][nrHomari*7%6+8+nrHomari*15]=' '; acvariu[17][nrHomari*7%6+15+nrHomari*15]=' ';
                    acvariu[17][nrHomari*7%6+9+nrHomari*15]=' ';
                    acvariu[17][nrHomari*7%6+10+nrHomari*15]=' '; acvariu[17][nrHomari*7%6+11+nrHomari*15]=' '; acvariu[17][nrHomari*7%6+12+nrHomari*15]=' '; acvariu[17][nrHomari*7%6+13+nrHomari*15]=' '; acvariu[17][nrHomari*7%6+14+nrHomari*15]=' ';
                    acvariu[17][nrHomari*7%6+16+nrHomari*15]=' ';
                }
                system("CLS");
                break;

                default:
                    system("CLS");
                    cout<<endl<<"Nu este o optiune valida"<<endl<<endl;
                    if(cin.fail())
                    {   cin.clear(); cin.ignore(100, '\n');    }
            }
            break;

        case 3:
            system("CLS");
            admin.afisareAnimale(pesti, broaste, homari);
            cout<<endl<<"Introduceti 0 pentru a reveni la meniu: "; cin>>v1;
            while(v1 || cin.fail())
            {
                system("CLS");
                cout<<endl<<"Introduceti 0 pentru a reveni la meniu"; cin>>v1;
            }
            system("CLS");
            break;

        case 4:
            return 0;
            break;

        default:
            system("CLS");
            cout<<endl<<"Nu este o optiune valida"<<endl<<endl;
            if(cin.fail())
            {   cin.clear(); cin.ignore(100, '\n');    }
    }
    }while(1);
    return 0;
}
