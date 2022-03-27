#include "bibliotekos.h"
#include "funkcijos.h"

int main()
{
    while(VedimoPasirinkimas != "t" && VedimoPasirinkimas != "n")
    {
        cout << "Ar norite sugeneruoti 5 studentu sarasu failus? (t/n): ";
        cin >> VedimoPasirinkimas;
        if(VedimoPasirinkimas == "t")
        {
            FailuGeneravimas();
            while(cout << "Kiek pazymiu tures studentai? (nuo 1 iki 25): " && (!(cin >> n)
                || n < 1 || n > 25))
                {
                    ArIntTikrinimas();
                }
            for(int i = 0; i < 5; i++)
            {
                EilSk *= 10;
                DuomenuGeneravimas(n, i);
            }
        }
        if(VedimoPasirinkimas == "n")
        {
            break;
        }
    }

    VedimoPasirinkimas = "";

    while(VedimoPasirinkimas != "p" && VedimoPasirinkimas != "f")
    {
        cout << "Ar norite duomenis ivesti patys, ar nuskaityti is failo? (p - patys, f - is failo): ";
        cin >> VedimoPasirinkimas;
    }
    cout << "\n";

    vector<data> sarasas;
    data temp;

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Duomenu suvedimas ir isvedimas.

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

        VedimoPasirinkimas = "p";
        SurusiavimasPagalPavarde(sarasas);
        IsvedimoParuosimas();
        for(int i = 0; i < (int)sarasas.size(); i++)
        {
            Isvedimas(sarasas.at(i));
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Duomenu ivedimas ir isvedimas is failo.

    if(VedimoPasirinkimas == "f")
    {
        vector<string> Splitted;
        string Eilute;
        stringstream Buferis;

        // Atidarom faila.
        ifstream file("studentai3.txt");
        // Exception handling.
        try
        {
        if(!file) throw "Failo atidaryti nepavyko.";
        }
        catch(const char* txtException)
        {
            cout << "Klaida: " << txtException << endl;
            return -1;
        }

        Buferis << file.rdbuf();
        while(Buferis)
        {
            if(!Buferis.eof())
            {
                getline(Buferis, Eilute);
                Splitted.push_back(Eilute);
            }
            else break;
        }

        cout << "Eiluciu skaicius: " << Splitted.size() << "\n";
        cout << "Vienos eilutes simboliu skaicius: " << Splitted.at(0).size() << "\n";
        // Skaiciuojama kiek zodziu yra vienoje eiluteje.
        string zodziuSkaicius = Splitted.at(0);
        size_t NWords = zodziuSkaicius.empty() || zodziuSkaicius.back() == ' ' ? 0 : 1;
        for(size_t s = zodziuSkaicius.size(); s > 0; --s)
        {
            if(zodziuSkaicius[s] == ' ' && zodziuSkaicius[s-1] != ' ')
            {
                ++NWords;
            }
        }
        cout << "Elementu skaicius eiluteje: " << NWords << "\n";

        // Griztam i failo pradzia.
        file.clear();
        file.seekg (0, ios::beg);
        // Praleidziama pirma eilute.
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int i = 0; i < (int)Splitted.size() - 1; i++)
        {
            file >> temp.Vardas >> temp.Pavarde;
            for(int i = 0; i < (int)NWords - 3; i++)
            {
                file >> temp.Nd[i];
            }
            temp.NdSk = NWords - 3;
            file >> temp.Egz;
            sarasas.push_back(temp);
        }
        // Uzdarom faila.
        file.close();
        // Isvedam apdorotus duomenis i faila.
        //SurusiavimasPagalPavarde(sarasas);
        // Nukreipiam irasyma i faila.
        freopen("isvestis.txt", "w", stdout);
        IsvedimoParuosimas();
        for(int i = 0; i < (int)Splitted.size() - 1; i++)
        {
            Isvedimas(sarasas.at(i));
        }
        cout << "\n";
        // Nukreipiam irasyma atgal i konsole.
        freopen("CON","w",stdout);
        cout << "\n" << "Apdoroti duomenys isvesti i faila 'isvestis.txt'." << "\n";

        Splitted.clear();
    }
}

#include "funkcijos.cpp"
