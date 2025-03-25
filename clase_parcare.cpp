/*Sa se creeze un program c++ pt gestionarea locurilor de parcare
    avem: nr parcare, nr goale
    citim: nr inmatriculare, ora intrare, minutul intrare, ora iesire, tarif pe ora
    implementat: clasa, obiect, constructor, destructor, metoda, clasa derivata, prietena
    */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class LocParcare
{
private:
    friend class Admin;
protected:
    string istoric[5]={"0","0","0","0","0"};
    string nrInmatriculare;
    int idParcare;
    int oraIntrare;
    int minIntrare;
    int oraIesire;
    int minIesire;
    int tarif;
public:
    LocParcare(string nrInmatriculare, int idParcare, int oraIntrare, int minIntrare, int oraIesire, int minIesire, int tarif)
    {
        this->nrInmatriculare=nrInmatriculare;
        this->idParcare=idParcare;
        this->oraIntrare=oraIntrare;
        this->minIntrare=minIntrare;
        this->oraIesire=oraIesire;
        this->minIesire=minIesire;
        this->tarif=tarif;
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

/*class Vehicul:public LocParcare
{
private:
    string numeProprietar;
    int totalPlata;
public:
    Vehicul(string nrInmatriculare, int idParcare, int oraIntrare, int minIntrare, int oraIesire, int minIesire, string numeProprietar, int totalPlata):LocParcare(nrInmatriculare, idParcare, oraIntrare, minIntrare, oraIesire, minIesire)
    {
        this->numeProprietar=numeProprietar;
        this->totalPlata=totalPlata;
    }
};*/

class Admin
{
public:
    void eliberare_loc(LocParcare& l)
    {
        l.nrInmatriculare="-1";
        l.oraIntrare=-1;
        l.minIntrare=-1;
        l.tarif=-1;
    }
    void vizualizare_istoric(LocParcare& l)
    {
        cout<<endl<<"Istoric locului cu id "<<l.idParcare<<":"<<endl;
        for(int i=0; i<5; i++)
        {
            cout<<i+1<<":"<<l.istoric[i]<<endl;
        }
    }
    void actualizare_istoric(LocParcare& l, string nrInRecent)
    {
        for(int i=4; i>=0; i--)
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
    int i,k, optiune, v1, v2, v3;
    int ok=1;
    string vs1;
    Admin admin;
    cout<<"Se creeaza parcarea."<<" Cate locuri sunt in parcare? ";
    cin>>k;
    const int n=k;
    LocParcare* locuri[2*(n+1)];
    for(i=1; i<=2*(n+1); i++)
        locuri[i]=new LocParcare("-1", i, -1, -1, -1, -1, -1);
    cout<<endl<<"A fost creata o parcare cu "<<n<<" locuri."<<endl;

    do
    {
        cout<<endl<<"MENIU MANAGEMENT"<<endl;
        cout<<endl<<"1. Creare bilet parcare"<<endl;
        cout<<endl<<"2. Oprire bilet parcare"<<endl;
        cout<<endl<<"3. Verificare status loc parcare"<<endl;
        cout<<endl<<"4. Vizualizare istoric loc parcare"<<endl;
        cout<<endl<<"5. Iesire"<<endl;
        cout<<endl<<"Alegeti o operatie: ";
        cin>>optiune;

        switch(optiune)
        {
            case 1:
                ok=1; v1=1;
                cout<<endl<<"Introduceti id-ul locului de parcare dorit sau 0 pentru a reveni la meniu: "; cin>>v1;
                if(v1!=0)
                {
                    while(ok)
                    {
                        if(v1>n)
                        {
                            cout<<endl<<"Locul nu exista! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else if(v1!=0 && locuri[v1]->get_nrInmatriculare()!="-1")
                        {
                            cout<<endl<<"Locul este ocupat! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else
                            ok=0;
                    }
                    if(v1!=0)
                    {
                        cout<<endl<<"Introduceti numarul de inmatriculare al vehiculului care parcheaza pe acest loc: "; cin>>vs1; admin.modifica_numar(*locuri[v1], vs1);
                        cout<<endl<<"Introduceti tariful locului de parcare (RON/ora): "; cin>>v2; admin.modifica_tarif(*locuri[v1], v2);
                        cout<<endl<<"Introduceti ora curenta(doar ora): "; cin>>v2; cout<<endl<<"Si minutul curent: "; cin>>v3; admin.modifica_intrare(*locuri[v1], v2, v3);
                        admin.actualizare_istoric(*locuri[v1], locuri[v1]->get_nrInmatriculare());
                        cout<<endl<<"Biletul a fost creat cu succes."<<endl;
                        locuri[v1]->afisare_detalii();
                    }
                    break;
                }
               break;

            case 2:
                ok=1; v1=1;
                cout<<endl<<"Introduceti id-ul locului care se elibereaza sau 0 pentru a reveni la meniu: "; cin>>v1;
                if(v1!=0)
                {
                    while(ok)
                    {
                        if(v1>n)
                        {
                            cout<<endl<<"Locul nu exista! Introduceti un alt id sau 0 pentru a reveni la meniu: "; cin>>v1;
                        }
                        else if(v1!=0 && locuri[v1]->get_nrInmatriculare()=="-1")
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
                            cout<<endl<<"Biletul a fost oprit cu succes."<<endl;
                            admin.calc_plata(*locuri[v1]);
                            admin.eliberare_loc(*locuri[v1]);
                        }
                    }
                    break;
                }
                break;

            case 3:
                v1=1; ok=1;
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
                        locuri[v1]->afisare_detalii();
                    break;
                }
                break;

            case 4:
                v1=1; ok=1;
                cout<<endl<<"Introduceti id-ul locului caruia doriti sa vedeti istoricul: "; cin>>v1;
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
                        admin.vizualizare_istoric(*locuri[v1]);
                    }
                    break;
                }
                break;

            case 5:
                break;

            default:
                cout<<endl<<"Nu este o optiune valida"<<endl;
        }
    } while (optiune !=0);
    return 0;
}
