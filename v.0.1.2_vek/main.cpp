#include "bibliotekos.h"

int StudentuCounter = 0, NdCounter;
string tnPasirinkimas, paPasirinkimas, VedimoPasirinkimas = "t";

struct data
{
    string Vardas, Pavarde;
    int Nd[25], Egz = 0, NdSk;
    double GalutinisVid, GalutinisMed;
};

#include "funkcijos.h"

int main()
{
    vector<data> sarasas;
    while(VedimoPasirinkimas == "t")
    {
        StudentuCounter++;
        cout << StudentuCounter << " STUDENTAS\n";
        Ivedimas(sarasas);
        cout << "Ar norite ivesti " << StudentuCounter + 1 << " studento duomenis? (t - taip, bet koks simbolis - ne): ";
        cin >> VedimoPasirinkimas;
        cout << "\n";
    }

    cout << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
    for(int i; i < 76; i++)
    {
        cout << "-";
    }

    for(int i = 0; i < StudentuCounter; i++)
    {
        Isvedimas(sarasas, i);
    }
}

#include "funkcijos.cpp"
