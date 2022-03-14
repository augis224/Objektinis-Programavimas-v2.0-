#include "bibliotekos.h"
#include "funkcijos.h"

int main()
{
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

        ifstream file("studentai1.txt");
        Buferis << file.rdbuf();
        file.close();

        while(Buferis)
        {
            if(!Buferis.eof())
            {
                getline(Buferis, Eilute);
                Splitted.push_back(Eilute);
            }
            else break;
        }

        string Outputas = "";
        for (string &a: Splitted)(a.compare(*Splitted.rbegin()) !=0) ? Outputas += a + "\n" : Outputas += a;

        cout << "Eiluciu skaicius: " << Splitted.size() << "\n";
        cout << "Vienos eilutes simboliu skaicius: " << Splitted.at(0).size() << "\n";

        //Skaiciuojama kiek zodziu yra vienoje eiluteje.
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

        ifstream ofile("studentai1.txt");
        //Praleidziama pirma eilute.
        ofile.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int i = 0; i < Splitted.size() - 1; i++)
        {
            ofile >> temp.Vardas >> temp.Pavarde;
            for(int i = 0; i < (int)NWords - 3; i++)
            {
                ofile >> temp.Nd[i];
            }
            temp.NdSk = NWords - 3;
            ofile >> temp.Egz;
            sarasas.push_back(temp);
        }

        //Isvedam apdorotus duomenis i faila.
        freopen("isvestis.txt", "w", stdout);
        IsvedimoParuosimas();
        for(int i = 0; i < Splitted.size() - 1; i++)
        {
            Isvedimas(sarasas.at(i));
        }
        cout << "\n";
        freopen("CON","w",stdout);
        cout << "\n" << "Apdoroti duomenys isvesti i faila 'isvestis.txt'." << "\n";

        Splitted.clear();
    }
}

#include "funkcijos.cpp"
