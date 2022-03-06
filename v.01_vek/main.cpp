#include "bibliotekos.h"
#include "funkcijos.h"

int main()
{
    while(VedimoPasirinkimas != "p" && VedimoPasirinkimas != "f")
    {
        cout << "Ar norite duomenis ivesti patys, ar nuskaityti is failo? (p - patys, f - is failo): "; cin >> VedimoPasirinkimas;
    }

    cout << "\n";
    vector<data> sarasas;
    data temp;

    if(VedimoPasirinkimas == "p")
    {
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

    if(VedimoPasirinkimas == "f")
    {
        ifstream file("kursiokai.txt");

        if(!file)
        {
            cerr << "Failo 'kursiokai.txt' atidaryti nepavyko." << endl;
            terminate();
        }

        for(int i = 0; i < 10; i++)
        {
            file >> temp.Vardas >> temp.Pavarde;
            for(int i = 0; i < 15; i++)
            {
                file >> temp.Nd[i];
                temp.NdSk = 15;
            }
            file >> temp.Egz;
            sarasas.push_back(temp);
        }

        IsvedimoParuosimas();
        for(int i = 0; i < sarasas.size(); i++)
        {
            Isvedimas(sarasas.at(i));
        }
    }
}

#include "funkcijos.cpp"
