#include <iostream>
#include <string>
using namespace std;

class Persoana{
protected:
    string nume;
    int varsta;

public:
    Persoana(string nume, int varsta)
    {
        this->nume=nume;
        this->varsta=varsta;
    }
    void afiseaza_informatii()
    {
        cout<<"Numele:"<<nume<<" Varsta:"<<varsta<<endl;
    }
};

class Student:public Persoana{
private:
    float medie;
    friend class Admin;
public:
    Student(string nume, int varsta, float medie):Persoana(nume,varsta)
    {
        this->medie=medie;
    }
    void afiseaza_informatii()
    {
        cout<<"Numele:"<<nume<<" Varsta:"<<varsta<<" Medie:"<<medie<<endl;
    }
};

class Admin{
public:
    void modifica_medie(Student& s, float noua_medie)
    {
        cout<<"Modific media pentru "<<s.nume<<" de la "<<s.medie<<" la "<<noua_medie<<endl;
        s.medie=noua_medie;
    }
    void afiseaza_detalii_student(const Student& s)
    {
        cout<<"Admin -> Student:"<<s.nume<<" Varsta:"<<s.varsta<<" Medie:"<<s.medie<<endl;
    }
};

int main(){
    Student s1("Mihai",20,7.5);
    Student s2("Victor",21,10);

    s1.afiseaza_informatii();
    s2.afiseaza_informatii();

    Admin admin;
    admin.modifica_medie(s2, 5);
    admin.afiseaza_detalii_student(s2);
    return 0;
}
