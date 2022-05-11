#include "bibliotekos.h"
#include "funkcijos.h"

int main()
{
    vector<data> sarasas;
    data temp;
    int n = 0;

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  5 studentu sarasu failu generavimas (1000, 10000, 100000, 1000000 ir 10000000 studentu).

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
            cout << "\n";
            int EilSk = 100;
            for(int i = 0; i < 5; i++)
            {
                EilSk *= 10;
                DuomenuGeneravimas(n, i, EilSk);
            }
        }
        if(VedimoPasirinkimas == "n")
        {
            break;
        }
    }
    cout << "\n";
    VedimoPasirinkimas = "";

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  10 failu studentu suskirstymui kurimas (5 - geru studentu, 5 - blogu studentu).

    while(VedimoPasirinkimas != "t" && VedimoPasirinkimas != "n")
    {
        cout << "Ar norite sugeneruoti 10 failu studentu suskirstymui? (t/n): ";
        cin >> VedimoPasirinkimas;
        if(VedimoPasirinkimas == "t")
        {
            KituFailuGeneravimas();
        }
        if(VedimoPasirinkimas == "n")
        {
            break;
        }
    }
    cout << "\n";
    VedimoPasirinkimas = "";

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Kiekvieno sugeneruoto studentu saraso failo suskirstymas i 2 failus pagal vidurki.

    while(VedimoPasirinkimas != "1" && VedimoPasirinkimas != "2" && VedimoPasirinkimas != "3" && VedimoPasirinkimas != "4")
    {
        cout << "Kuri konteineri naudosite (1 - vector, 2 - list, 3 - deque, 4 - praleisti sia dali): ";
        cin >> VedimoPasirinkimas;
        if(VedimoPasirinkimas == "1")
        {
            Vector(temp);
        }
        if(VedimoPasirinkimas == "2")
        {
            List();
        }
        if(VedimoPasirinkimas == "3")
        {
            Deque();
        }
        if(VedimoPasirinkimas == "4")
        {
            break;
        }
    }
    cout << "\n";
    VedimoPasirinkimas = "";

//-------------------------------------------------------------------------------------------------------------------------------------------------

    while(VedimoPasirinkimas != "p" && VedimoPasirinkimas != "f")
    {
        cout << "Ar norite duomenis ivesti patys, ar nuskaityti is failo? (p - patys, f - is failo): ";

        cin >> VedimoPasirinkimas;
    }
    cout << "\n";

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Duomenu suvedimas ir isvedimas.

    if(VedimoPasirinkimas == "p")
    {
        VedimoPasirinkimas = "t";
        int StudentuCounter = 0;
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
        sort(sarasas.begin(), sarasas.end(), compare);
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
        ifstream file("studentai4.txt");
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

        // Nuskaitom visa failo turini i buferi.
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

        //cout << "Eiluciu skaicius: " << Splitted.size() << "\n";
        //cout << "Vienos eilutes simboliu skaicius: " << Splitted.at(0).size() << "\n";
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
        //cout << "Elementu skaicius eiluteje: " << NWords << "\n";

        // Griztam i failo pradzia.
        file.clear();
        file.seekg (0, ios::beg);
        // Praleidziam pirma eilute.
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
        // Surusiuojam isvedima pagal pavarde.
        sort(sarasas.begin(), sarasas.end(), compare);
        // Nukreipiam irasyma i isvesties faila.
        freopen("isvestis.txt", "w", stdout);
        // Isvedam apdorotus duomenis i faila.
        IsvedimoParuosimas();
        for(int i = 0; i < (int)Splitted.size() - 1; i++)
        {
            Isvedimas(sarasas.at(i));
        }
        cout << "\n";
        // Nukreipiam irasyma atgal i konsole.
        freopen("CON","w",stdout);
        cout << "Apdoroti duomenys isvesti i faila 'isvestis.txt'." << "\n";

        Splitted.clear();
        sarasas.clear();
    }
}

#include "funkcijos.cpp"
#include "vector.cpp"
#include "list.cpp"
#include "deque.cpp"
