#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string nume;
    int varsta;
    float medie;

public:
    //Constructor cu variabila auxiliara
    Student(string nume_student, int varsta_student, float medie_student) {
        nume=nume_student;
        varsta=varsta_student;
        medie=medie_student;
        cout<<"Constructorul a fost apelat pentru: "<<nume<<endl;
    }

    //Constructor folosind THIS
   /* Student(string nume, int varsta, float medie) {
        this->nume=nume;
        this->varsta=varsta;
        this->medie=medie;
        cout<<"Constructorul a fost apelat pentru: "<<nume<<endl;
    }*/

    ~Student()
    {
        cout<<"Destructorul a fost apelat pentru: "<<nume<<endl;
    }

    void afisare_informatii()
    {
        cout<<"Nume: "<<nume<<", Varsta: "<<varsta<<", Medie: "<<medie<<endl;
    }

    float returneaza_media()
    {
        return medie;
    }

    //void afiseaza_media()
    //{
    //    cout<<medie<<endl;
    //}
};

void sortare_medie(Student* studenti[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1; j++)
        {
            if(studenti[i]->returneaza_media()>studenti[j+1]->returneaza_media())
            {
                Student* aux=studenti[j];
                studenti[j]=studenti[j+1];
                studenti[j+1]=aux;
            }
        }
}

int main()
{
    int k, i;
    cout<<"Introduceti nr de studenti: ";
    cin>>k;
    const int n=k;
    Student* studenti[n];
    for(i=0; i<n; i++)
    {
        string nume;
        int varsta;
        float medie;
        //Citim de la tastatura datele despre studentul curent (i)
        cout<<"Introduceti numele studentului "<<i+1<<": "; cin>>nume;
        cout<<"Introduceti varsta studentului "<<i+1<<": "; cin>>varsta;
        cout<<"Introduceti media studentului "<<i+1<<": "; cin>>medie;
        //Crearea unui nou obiect Student si stocarea lui intr-un array
        studenti[i]=new Student(nume, varsta, medie);
    }
    sortare_medie(studenti,n);
    cout<<"Cea mai mare medie este: "<<studenti[n-1]->returneaza_media()<<endl;
    //Afisare studenti
    for(i=0; i<n; i++)
    {
        studenti[i]->afisare_informatii();
    }
    //Eliberare memoria alocata dinamic
    for(i=0; i<n; i++)
    {
        delete studenti[i];
    }
    return 0;
}
