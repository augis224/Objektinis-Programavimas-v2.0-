#include "bibliotekos.h"

int StudentuCounter = 0, NdCounter;
string tnPasirinkimas, paPasirinkimas;

struct data
{
    string Vardas, Pavarde;
    int Nd[25], Egz = 0, NdSk;
    double GalutinisVid, GalutinisMed;
};

#include "funkcijos.h"

int main()
{
    int StudentuSkaicius;

    while(cout << "Iveskite studentu skaiciu (bent 1 studentas): " && (!(cin >> StudentuSkaicius) || StudentuSkaicius <= 0))
    {
        ArIntTikrinimas();
    }

    data* mas = new data[StudentuSkaicius];

    for(data* a = mas; a < mas + StudentuSkaicius; a++)
    {
        Ivedimas(*a);
    }

    cout << "\n" << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
    for(int i; i < 76; i++)
    {
        cout << "-";
    }

    for(data* a = mas; a < mas + StudentuSkaicius; a++)
    {
        Isvedimas(*a);
    }
    delete[]mas;
    mas = NULL;
}

#include "funkcijos.cpp"
