#include "bibliotekos.h"
#include "funkcijos.h"

int main()
{
    vector<data> sarasas;
    data temp;

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

    int e = 0, ea = 1;
    while(VedimoPasirinkimas != "t" && VedimoPasirinkimas != "n")
    {
        cout << "Ar norite istirti siuos failus? (t/n): ";
        cin >> VedimoPasirinkimas;
        if(VedimoPasirinkimas == "t")
        {
            for(int i = 0; i <= 4; i++)
            {
                cout << "\n";
                vector<string> Splitted;
                vector<data> geri;
                vector<data> blogi;
                string Eilute;
                stringstream Buferis;

                // Atidarom faila.
                ifstream file(FailuVardai[i]);
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
                auto start1 = chrono::high_resolution_clock::now();
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
                auto end1 = chrono::high_resolution_clock::now();
                chrono::duration<double> diff1 = end1 - start1;
                cout << "Duomenu nuskaitymas is failo '" << FailuVardai[i] << "' uztruko: " << diff1.count() << "s\n";

                // Suskaiciuojam kiek zodziu yra vienoje eiluteje.
                string zodziuSkaicius = Splitted.at(0);
                size_t NWords = zodziuSkaicius.empty() || zodziuSkaicius.back() == ' ' ? 0 : 1;
                for(size_t s = zodziuSkaicius.size(); s > 0; --s)
                {
                    if(zodziuSkaicius[s] == ' ' && zodziuSkaicius[s-1] != ' ')
                    {
                        ++NWords;
                    }
                }

                // Griztam i failo pradzia.
                file.clear();
                file.seekg (0, ios::beg);
                // Praleidziam pirma eilute.
                file.ignore(numeric_limits<streamsize>::max(), '\n');
                // Suskirstom gerus ir blogus studentus i du vektorius.
                auto start2 = chrono::high_resolution_clock::now();
                for(int i = 0; i < (int)Splitted.size() - 2; i++)
                {
                    file >> temp.Vardas >> temp.Pavarde;
                    double kaire = 0, desine = 0;
                    int suma = 0;
                    for(int i = 0; i < (int)NWords - 3; i++)
                    {
                        file >> temp.Nd[i];
                        suma += temp.Nd[i];
                    }
                    temp.NdSk = NWords - 3;
                    kaire = (double)suma / (double)temp.NdSk * 4 / 10;
                    file >> temp.Egz;
                    desine = (double)temp.Egz * 6 / 10;
                    if(desine + kaire < 5)
                    {
                        blogi.push_back(temp);
                    }
                    if(desine + kaire >= 5)
                    {
                        geri.push_back(temp);
                    }
                }
                auto end2 = chrono::high_resolution_clock::now();
                chrono::duration<double> diff2 = end2 - start2;
                cout << "Studentu isrusiavimas i dvi grupes ('geru' ir 'blogu') uztruko: " << diff2.count() << "s\n";
                // Uzdarom faila.
                file.close();

                // Surusiuojam geru ir blogu studentu isvedima pagal pavarde.
                auto start4 = chrono::high_resolution_clock::now();
                sort(geri.begin(), geri.end(), compare);
                sort(blogi.begin(), blogi.end(), compare);
                auto end4 = chrono::high_resolution_clock::now();
                chrono::duration<double> diff4 = end4 - start4;
                cout << "'Geru' ir 'blogu' studentu surusiavimas pagal pavarde uztruko: " << diff4.count() << "s\n";

                // Nukreipiam irasyma i "geru" faila.
                freopen(KituFailuVardai[e], "w", stdout);
                // Isvedam apdorotus geru studentu duomenis i faila.
                auto start3 = chrono::high_resolution_clock::now();
                IsvedimoParuosimas();
                for(int i = 0; i < (int)geri.size(); i++)
                {
                    Isvedimas(geri.at(i));
                }
                fclose(stderr);
                // Nukreipiam irasyma i "blogu" faila.
                freopen(KituFailuVardai[ea], "w", stdout);
                // Isvedam apdorotus blogu studentu duomenis i faila.
                IsvedimoParuosimas();
                for(int i = 0; i < (int)blogi.size(); i++)
                {
                    Isvedimas(blogi.at(i));
                }
                fclose(stderr);
                e = e + 2, ea = ea + 2;
                cout << "\n";

                // Nukreipiam irasyma atgal i konsole.
                freopen("CON","w",stdout);
                auto end3 = chrono::high_resolution_clock::now();
                chrono::duration<double> diff3 = end3 - start3;
                cout << "Studentu isvedimas i du failus '" << KituFailuVardai[e - 2] << "' (Vidurkis > 5) ir '" << KituFailuVardai[ea - 2]
                << "' (Vidurkis < 5) uztruko: " << diff3.count() << "s\n";
                cout << "Bendras darbo su failu '" << FailuVardai[i] << "' laikas: "
                << diff1.count() + diff2.count() + diff3.count() + diff4.count() << "s\n";

                // Isvalom visus naudotus vektorius.
                Splitted.clear();
                sarasas.clear();
                geri.clear();
                blogi.clear();
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
