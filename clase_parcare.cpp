#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

void maximizeWindow(){
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

int nrVehicule;

void convertire(string& s)  //pt transformarea in majuscule a literelor din nr inmatriculare
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='a' && s[i]<='z')
            s[i]=s[i]-32;
    }
}

void infrum(string& s)  //transforma in majuscula datele vehiculelor
{
    s[0]=toupper(s[0]);
}

struct vehicul
{
    string nrInmat, numeProp, marca, model, culoare;
    int id;
    vehicul* link;
};

vehicul* p=NULL;

void vehiculNou(vehicul*& p, string nrI, int idV)
{
    string nP, m, mdl, cul;
    vehicul* x=new vehicul;
    cout<<endl<<"Acest vehicul nu este salvat in baza de date!"<<endl;
    cout<<endl<<"Introduceti numele proprietarului: "; cin>>nP; infrum(nP);
    cout<<endl<<"Marca vehiculului: "; cin>>m; infrum(m);
    cout<<endl<<"Modelul: "; cin>>mdl; infrum(mdl);
    cout<<endl<<"Si culoarea: "; cin>>cul; infrum(cul);
    x->id=idV; x->nrInmat=nrI;
    x->numeProp=nP; x->marca=m; x->model=mdl; x->culoare=cul;
    x->link=NULL;
    if(p==NULL)
        p=x;
    else
    {
        vehicul* iter=p;
        while(iter->link!=NULL)
            iter=iter->link;
        iter->link=x;
    }
    nrVehicule++;
}

int verificaExistenta(vehicul*& p, string nrI) //returneaza 0 daca nu este deja salvat
{
    if(p==NULL)
        return 0;
    else
    {
        vehicul *iter=p;
        while(iter->link!=NULL)
        {
            if(iter->nrInmat==nrI)
                return 1;
        }
        return 0;
    }
}

int nrOcupate, nrGoale;

void meniu()
{
    cout<<endl<<"1. Creare bilet parcare"<<endl;
    cout<<endl<<"2. Oprire bilet parcare"<<endl;
    cout<<endl<<"3. Verificare status loc parcare"<<endl;
    cout<<endl<<"4. Vizualizare istoric loc parcare"<<endl;
    cout<<endl<<"5. Vizualizare vehicule salvate"<<endl;
    cout<<endl<<"6. Iesire"<<endl;
    cout<<endl<<"Alegeti o operatie: ";
}



class LocParcare
{
private:
    friend class Admin;
protected:
    string istoric[5]={"-","-","-","-","-"};
    string nrInmatriculare;
    int idParcare, oraIntrare, minIntrare, oraIesire, minIesire, tarif;
public:
    LocParcare(string nrInmatriculare, int idParcare, int oraIntrare, int minIntrare, int oraIesire, int minIesire, int tarif)
    {
        this->nrInmatriculare=nrInmatriculare; this->idParcare=idParcare; this->oraIntrare=oraIntrare; this->minIntrare=minIntrare; this->oraIesire=oraIesire; this->minIesire=minIesire; this->tarif=tarif;
    }
    void afisare_detalii()
    {
        if(oraIntrare!=-1)
            cout<<endl<<"Locul cu id "<<idParcare<<" si tarif de "<<tarif<<"RON/ora este ocupat de catre vehiculul cu numarul de inmatriculare "<<nrInmatriculare<<", parcat la ora "<<setfill('0')<<setw(2)<<oraIntrare<<":"<<setfill('0')<<setw(2)<<minIntrare<<"."<<endl;
        else
            cout<<endl<<"Locul cu id "<<idParcare<<" este liber"<<endl;
    }
    int calc_timp_ocupat()
    {
        int minute_ocupat=(oraIesire*60+minIesire)-(oraIntrare*60+minIntrare);
        return minute_ocupat/60+1;
    }
    string get_nrInmatriculare()
    {
        return nrInmatriculare;
    }
};

class Admin
{
public:
    void afisareVehicule(vehicul*& p)
    {
        if(p==NULL)
        {
            cout<<endl<<"Nu exista nici un vehicul salvat!"; return;
        }
        else
        {
            vehicul* iter=p;
            cout<<iter->id<<": "<<iter->nrInmat<<", "<<iter->numeProp<<", "<<iter->marca<<" "<<iter->model<<" "<<", "<<iter->culoare<<endl;
            while(iter->link!=NULL)
            {
                cout<<iter->id<<": "<<iter->nrInmat<<", "<<iter->numeProp<<", "<<iter->marca<<" "<<iter->model<<" "<<iter->culoare<<endl;
            }
        }
    }
    void afisareParcare(LocParcare* l[], int n)
    {
        /*for(int i=1; i<=n/2+n%2; i++)
        {
            if(i<=n/2)
            {
                if(l[i]->get_nrInmatriculare()!="gol")
                    cout<<setfill(' ')<<setw(2)<<i<<": "<<l[i]->get_nrInmatriculare()<<"                      "<<n/2+n%2+i<<": "<<l[n/2+n%2+i]->get_nrInmatriculare()<<endl;
                else
                    cout<<setfill(' ')<<setw(2)<<i<<": "<<l[i]->get_nrInmatriculare()<<"                         "<<n/2+n%2+i<<": "<<l[n/2+n%2+i]->get_nrInmatriculare()<<endl;
            }
            else
                cout<<setfill(' ')<<setw(2)<<i<<": "<<l[i]->get_nrInmatriculare()<<endl;
        }*/  //aliniere pe doua coloane
        int i=1;
        while(i<=n)
        {
            for(int j=1; j<=6; j++)
            {
                if(i<n+1)
                {
                    if(l[i]->get_nrInmatriculare()!="gol")
                        cout<<setfill(' ')<<setw(2)<<i<<": "<<l[i]->get_nrInmatriculare()<<"         ";
                    else
                        cout<<setfill(' ')<<setw(2)<<i<<": "<<l[i]->get_nrInmatriculare()<<"            ";
                    i++;
                }
            }
            cout<<endl;
        }

    }
    void eliberare_loc(LocParcare& l)
    {
        l.nrInmatriculare="gol";
        l.oraIntrare=-1;
        l.minIntrare=-1;
        l.tarif=-1;
    }
    void vizualizare_istoric(LocParcare& l)
    {
        cout<<endl<<"Istoric locului cu id "<<l.idParcare<<": "<<endl;
        for(int i=0; i<5; i++)
        {
            cout<<i+1<<":"<<l.istoric[i]<<endl;
        }
    }
    void actualizare_istoric(LocParcare& l, string nrInRecent)
    {
        for(int i=4; i>0; i--)
            {
                l.istoric[i]=l.istoric[i-1];
            }
        l.istoric[0]=nrInRecent;
    }
    void modifica_numar(LocParcare& l, string nr_nou)
    {
        l.nrInmatriculare=nr_nou;
    }
    void modifica_tarif(LocParcare& l, int tarif_nou)
    {
        l.tarif=tarif_nou;
    }
    void modifica_intrare(LocParcare& l, int o_intrare, int m_intrare)
    {
        l.oraIntrare=o_intrare;
        l.minIntrare=m_intrare;
    }
    void modifica_iesire(LocParcare& l, int o_iesire, int m_iesire)
    {
        cout<<endl<<"Locul cu id "<<l.idParcare<<" a fost eliberat la "<<o_iesire<<":"<<m_iesire<<endl;
        l.oraIesire=o_iesire;
        l.minIesire=m_iesire;
    }
    void calc_plata(LocParcare& l)
    {
        cout<<endl<<"Vehiculul cu numarul de inmatriculare "<<l.nrInmatriculare<<" a fost parcat timp de "<<((l.oraIesire*60+l.minIesire)-(l.oraIntrare*60+l.minIntrare))/60<<" ore si "<<((l.oraIesire*60+l.minIesire)-(l.oraIntrare*60+l.minIntrare))%60<<" minute si trebuie sa plateasca "<<l.tarif*l.calc_timp_ocupat()<<"RON"<<endl;
    }
};

int main()
{
    maximizeWindow();
    int i,k, optiune, v1, v2, v3;
    int ok=1;
    string vs1;
    Admin admin;
    while(ok)
    {
        cout<<"Se creeaza parcarea."<<" Cate locuri sunt in parcare? ";
        cin>>k;
        if(k<=0)
            {
                cout<<endl<<"Parcarea trebuie sa aiba minim un loc! ";
                cin>>k;
            }
        else ok=0;
    }
    const int n=k;
    nrGoale=n;
    LocParcare* locuri[n+1];
    for(i=1; i<=n+1; i++)
        locuri[i]=new LocParcare("gol", i, -1, -1, -1, -1, -1);
        system("CLS");

    do
    {
        cout<<"                                 MENIU GESTIONARE"<<endl<<endl;
        admin.afisareParcare(locuri, n);
        meniu();
        cin>>optiune;

        switch(optiune)
        {
            case 1:
                ok=1; v1=1;
                system("CLS");
                cout<<"                                 CREARE BILET"<<endl<<endl;
                admin.afisareParcare(locuri, n);
                cout<<endl<<"Introduceti id-ul locului de parcare dorit sau 0 pentru a reveni la meniu: "; cin>>v1;
                if(v1!=0)
                {
                    while(ok)
                    {
                        if(v1>n || v1<1)
                        {
                            cout<<endl<<"Locul nu exista! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else if(v1!=0 && locuri[v1]->get_nrInmatriculare()!="gol")
                        {
                            cout<<endl<<"Locul este ocupat! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else
                            ok=0;
                    }
                    if(v1!=0)
                    {
                        cout<<endl<<"Introduceti numarul de inmatriculare al vehiculului care parcheaza pe acest loc: "; cin>>vs1; convertire(vs1); admin.modifica_numar(*locuri[v1], vs1);
                        cout<<endl<<"Introduceti tariful locului de parcare (RON/ora): "; cin>>v2; admin.modifica_tarif(*locuri[v1], v2);
                        cout<<endl<<"Introduceti ora curenta(doar ora): "; cin>>v2; cout<<endl<<"Si minutul curent: "; cin>>v3; admin.modifica_intrare(*locuri[v1], v2, v3);
                        admin.actualizare_istoric(*locuri[v1], locuri[v1]->get_nrInmatriculare());
                        nrOcupate++; nrGoale--; nrVehicule++;
                        system("CLS");
                        cout<<endl<<"Biletul a fost creat cu succes."<<endl;
                        locuri[v1]->afisare_detalii();
                        if(verificaExistenta(p, locuri[v1]->get_nrInmatriculare())==0)
                            {
                                vehiculNou(p, locuri[v1]->get_nrInmatriculare(), nrVehicule); system("CLS");
                            }
                    }
                    else
                        system("CLS");
                }
               break;

            case 2:
                ok=1; v1=1;
                system("CLS");
                cout<<"                                 OPRIRE BILET"<<endl<<endl;
                admin.afisareParcare(locuri, n);
                cout<<endl<<"Introduceti id-ul locului care se elibereaza sau 0 pentru a reveni la meniu: "; cin>>v1;
                if(v1!=0)
                {
                    while(ok)
                    {
                        if(v1>n || v1<1)
                        {
                            cout<<endl<<"Locul nu exista! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else if(v1!=0 && locuri[v1]->get_nrInmatriculare()=="gol")
                        {
                            cout<<endl<<"Locul este deja liber! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else
                            ok=0;
                    }
                    if(v1!=0)
                    {
                        locuri[v1]->afisare_detalii();
                        cout<<"Suntenti sigur/sigura ca doriti sa opriti biletul? (da/nu) "; cin>>vs1;
                        if(vs1=="da" || vs1=="DA" || vs1=="Da" || vs1=="dA" || vs1=="d" || vs1=="y")
                        {
                            cout<<endl<<"Introduceti ora curenta(doar ora): "; cin>>v2; cout<<endl<<"Si minutul curent: "; cin>>v3; admin.modifica_iesire(*locuri[v1], v2, v3);
                            locuri[v1*2]=locuri[v1];
                            system("CLS");
                            cout<<endl<<"Biletul a fost oprit cu succes."<<endl;
                            nrOcupate--; nrGoale++;
                            admin.calc_plata(*locuri[v1]);
                            admin.eliberare_loc(*locuri[v1]);
                        }
                    }
                }
                break;

            case 3:
                v1=1; ok=1;
                system("CLS");
                admin.afisareParcare(locuri, n);
                cout<<endl<<"Introduceti id-ul locului caruia doriti sa verificati starea sau 0 pentru a reveni la meniu: "; cin>>v1;
                if(v1!=0)
                {
                    while(ok)
                    {
                        if(v1>n)
                        {
                            cout<<endl<<"Locul nu exista! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else
                            ok=0;
                    }
                    if(v1!=0)
                    {
                        system("CLS");
                        locuri[v1]->afisare_detalii();
                    }
                }
                break;

            case 4:
                v1=1; ok=1;
                system("CLS");
                cout<<"                                 VIZUALIZARE ISTORIC"<<endl<<endl;
                admin.afisareParcare(locuri, n);
                cout<<endl<<"Introduceti id-ul locului caruia doriti sa vedeti istoricul sau 0 pentru a reveni: "; cin>>v1;
                if(v1!=0)
                {
                    while(ok)
                    {
                        if(v1>n)
                        {
                            cout<<endl<<"Locul nu exista! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else
                            ok=0;
                    }
                    if(v1!=0)
                    {
                        system("CLS");
                        admin.vizualizare_istoric(*locuri[v1]);
                    }
                }
                break;

            case 5:
                v1=1;
                system("CLS");
                cout<<"         VIZUALIZARE VEHICULE"<<endl<<endl;
                admin.afisareVehicule(p);
                cout<<endl<<"Introduceti 0 pentru a reveni la meniu: "; cin>>v1;
                while(v1)
                {
                    system("CLS");
                    cout<<endl<<"Introduceti 0 pentru a reveni la meniu"; cin>>v1;
                }
                system("CLS");
                break;

            case 6:
                return 0;

            default:
                system("CLS");
                cout<<endl<<"Nu este o optiune valida"<<endl;
        }
    } while (1);
    return 0;
}
