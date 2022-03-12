#include "bibliotekos.h"
#include "funkcijos.h"

int main()
{
    vector<data> sarasas;
    data temp;

    VedimoPasirinkimas = "t";
    while(VedimoPasirinkimas == "t")
    {
        StudentuCounter++;
        cout << StudentuCounter << " STUDENTAS\n";
        Ivedimas(temp);
        sarasas.push_back(temp);
        cout << "Ar norite ivesti " << StudentuCounter + 1 << " studento duomenis? (t - taip, bet koks simbolis - ne): ";
        cin >> VedimoPasirinkimas;
        cout << "\n";
    }

    IsvedimoParuosimas();
    for(int i = 0; i < sarasas.size(); i++)
    {
            Isvedimas(sarasas.at(i));
    }
}

#include "funkcijos.cpp"
