#include "Studentas.h"

//methods
void Studentas::Ivedimas(Studentas& temp)
{
    int ivertinimas, NdCounter = -1;
    tnPasirinkimas = "";
    paPasirinkimas = "";

    cout << "Iveskite studento varda: ";
    cin >> temp.vardas;
    cout << "Iveskite studento pavarde: ";
    cin >> temp.pavarde;
    tnPasirinkimas = "";

    while(paPasirinkimas != "p" && paPasirinkimas != "a")
    {
        cout << "Ar namu darbu ivertinimus ir egzamino pazymi irasysite patys, ar juos generuoti atsitiktinai? (p - patys, a - atsitiktinai): ";
        cin >> paPasirinkimas;
    }

    if(paPasirinkimas == "p")
    {
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar studentas turi bent viena n.d. ivertinima? (t/n): ";
            cin >> tnPasirinkimas;
        }
        while(tnPasirinkimas == "t")
        {
            NdCounter++;
            while(cout << "Irasykite " << NdCounter + 1 << " n.d. ivertinima: " && (!(cin >> ivertinimas)
                    || ivertinimas < 1 || ivertinimas > 10))
            {
                ArIntTikrinimas();
            }
            temp.nd.push_back(ivertinimas);
            cout << "Ar norite irasyti dar viena ivertinima? (t - testi, bet koks simbolis - baigti): ";
            cin >> tnPasirinkimas;
        }
        tnPasirinkimas = ""; //Flushinam tnPasirinkimo reiksme
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar studentas turi egzamino pazymi? (t/n): ";
            cin >> tnPasirinkimas;
        }
        if(tnPasirinkimas == "t")
        {
            while(cout << "Irasykite egzamino pazymi: " && (!(cin >> temp.egz)
                    || temp.egz < 1 || temp.egz > 10))
            {
                ArIntTikrinimas();
            }
        }
        if(tnPasirinkimas == "n")
        {
            temp.egz = 0;
        }
    }

    if(paPasirinkimas == "a")
    {
        srand(time(0));
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar studentas turi bent viena n.d. ivertinima? (t/n): ";
            cin >> tnPasirinkimas;
        }
        while(tnPasirinkimas == "t")
        {
            NdCounter++;
            cout << NdCounter + 1 << " n.d. ivertinimas: ";
            temp.nd.push_back(AtsitiktinisSkaicius());
            cout << temp.nd[NdCounter];
            cout << "\nAr norite irasyti dar viena ivertinima? (t - testi, bet koks simbolis - baigti): ";
            cin >> tnPasirinkimas;
        }
        tnPasirinkimas = ""; //Flushinam tnPasirinkimo reiksme
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar studentas turi egzamino pazymi? (t/n): ";
            cin >> tnPasirinkimas;
        }
        if(tnPasirinkimas == "t")
        {
            temp.egz = AtsitiktinisSkaicius();
            cout << "Egzamino ivertinimas: " << temp.egz << "\n";
        }
        if(tnPasirinkimas == "n")
        {
            temp.egz = 0;
        }
    }
}

void Studentas::ArIntTikrinimas()
{
    cerr << "Padarete klaida.\n";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Studentas::AtsitiktinisSkaicius()
{
    return dist(mt);
}

void Studentas::IsvedimoParuosimas()
{
    cout << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
    for(int i = 0; i < 76; i++)
    {
        cout << "-";
    }
    cout << "\n";
}

/*bool Studentas::compare(const Studentas& x, const& Studentas y)
{
    return x.get_pavarde() < y.get_pavarde();
}*/

void Studentas::Isvedimas(Studentas& temp)
{
    int suma = 0;
    double kaireVidurkis = 0, kaireMediana = 0, desine = 0;

    for(int j = 0; j < (int)temp.nd.size(); j++)
    {
        suma = accumulate(temp.nd.begin(), temp.nd.end(), 0);
    }

    if(suma > 0)
    {
        kaireVidurkis = (double)suma / (double)temp.nd.size() * 4 / 10;

        sort(temp.nd.begin(), temp.nd.end());
        if(temp.nd.size() % 2 != 0)
        {
            kaireMediana = (double)temp.nd[temp.nd.size() / 2] * 4 / 10;
        }
        else
        {
           kaireMediana = (double)(temp.nd[(temp.nd.size() - 1) / 2] + temp.nd[temp.nd.size() / 2]) / 2.0 * 4 / 10;
        }
    }
    else
    {
        kaireVidurkis = 0;
    }

    if(temp.egz > 0)
    {
        desine = (double)temp.egz * 6 / 10;
    }
    else
    {
        desine = 0;
    }

    temp.galutinisVid = kaireVidurkis + desine;
    temp.galutinisMed = kaireMediana + desine;

    cout << left << setw(20) << temp.vardas << left << setw(20) << temp.pavarde;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << left << setw(20) << temp.galutinisVid;
    cout << left << setw(20) << temp.galutinisMed << "\n";

}

void Studentas::FailuGeneravimas()
{
    for(int i = 0; i < 5; i++)
    {
        ofstream {FailuVardai[i]};
    }
}

void Studentas::KituFailuGeneravimas()
{
    for(int i = 0; i < 10; i++)
    {
        ofstream {KituFailuVardai[i]};
    }

}

void Studentas::DuomenuGeneravimas(int n, int i, int EilSk)
{
    int x = 20;
    auto start = chrono::high_resolution_clock::now();
    ofstream ofs(FailuVardai[i]);
    ofs << "VARDAS" << setw(21) << "PAVARDE" << setw(22);
    for(int k = 1; k < n + 1; k++)
    {
        ofs << "ND" << k << setw(19);
    }
    ofs << "EGZ" << "\n";
    for(int j = 1; j < EilSk + 1; j++)
    {
        if(j > 9 && j < 99)           x = 19;
        if(j > 99 && j < 999)         x = 18;
        if(j > 999 && j < 9999)       x = 17;
        if(j > 9999 && j < 99999)     x = 16;
        if(j > 99999 && j < 999999)   x = 15;
        if(j > 999999 && j < 9999999) x = 14;
        if(j > 9999999)               x = 13;
        ofs << "Vardas" << j << setw(x);
        ofs << "Pavarde" << j << setw(x);
        for(int k = 0; k < n; k++)
        {
            ofs << AtsitiktinisSkaicius() << setw(20);
        }
        ofs << AtsitiktinisSkaicius() << "\n";
    }
    ofs.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Generuoti faila '" << EilSk << ".txt' uztruko: " << diff.count() << "s\n";

}

int Studentas::isFailo(Studentas& temp, vector<Studentas>& sarasas)
{
    int ivertinimas;
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
        file >> temp.vardas >> temp.pavarde;
        for(int i = 0; i < (int)NWords - 3; i++)
        {
            file >> ivertinimas;
            temp.nd.push_back(ivertinimas);
        }
        file >> temp.egz;
        sarasas.push_back(temp);
    }
    // Uzdarom faila.
    file.close();
    // Surusiuojam isvedima pagal pavarde.
    sort(sarasas.begin(),
         sarasas.end(),
         [](const Studentas& lhs, const Studentas& rhs)
    {
        return lhs.pavarde < rhs.pavarde;
    });
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
    return 0;
}

int Studentas::Vector(Studentas& temp)
{
    vector<Studentas> sarasas;
    int e = 0, ea = 1, suma, n, pasirinkimas = 0, ivertinimas;
    vector<Studentas> geri;
    vector<Studentas> blogi;
    string Eilute, zyme = "ND";
    size_t position = 0;

    while(pasirinkimas != 1 && pasirinkimas != 2)
    {
        cout << "Pasirinkite strategija (1/2): ";
        cin >> pasirinkimas;
    }

    cout << "\nVECTOR";
    for(int i = 0; i < 5; i++)
    {
        cout << "\n";
        n = 0;
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

        //-------------------------------------------------------------------------------------------------------------------------------------------------
        // Nuskaitom visa failo turini i buferi.
        auto start1 = chrono::high_resolution_clock::now();
        Buferis << file.rdbuf();
        getline(Buferis, Eilute);
        while ((( position = Eilute.find(zyme))) != std::string::npos)
        {
            n++;
            Eilute.erase(0, position + zyme.length());
        }
        while(!Buferis.eof())
        {
            suma = 0;
            Buferis >> temp.vardas >> temp.pavarde;
            for(int i = 0; i < n; i++)
            {
                Buferis >> ivertinimas;
                temp.nd.push_back(ivertinimas);
                suma += ivertinimas;
            }
            Buferis >> temp.egz;
            temp.galutinisVid = ( (double)suma / (double)n * 4 / 10 ) + ( (double)temp.egz * 6 / 10 );
            sort(temp.nd.begin(), temp.nd.begin() + n);
            if(n % 2 != 0)
            {
                temp.galutinisMed = ( (double)temp.nd[n / 2] * 4 / 10 ) + ( (double)temp.egz * 6 / 10 );
            }
            else
            {
                temp.galutinisMed = ( (double)(temp.nd[(n - 1) / 2] + temp.nd[n / 2]) / 2.0 * 4 / 10 ) + ( (double)temp.egz * 6 / 10 );
            }
            temp.nd.clear();
            sarasas.push_back(temp);
        }
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff1 = end1 - start1;
        cout << "Duomenu nuskaitymas is failo '" << FailuVardai[i] << "' uztruko: " << diff1.count() << "s\n";
        file.close();

        //-------------------------------------------------------------------------------------------------------------------------------------------------
        // Surusiuojam geru ir blogu studentu isvedima pagal pavarde.
        auto start2 = chrono::high_resolution_clock::now();
        sort(sarasas.begin(),
             sarasas.end(),
             [](const Studentas& lhs, const Studentas& rhs)
        {
        return lhs.pavarde < rhs.pavarde;
        });
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff2 = end2 - start2;
        cout << "'Geru' ir 'blogu' studentu surusiavimas pagal pavarde uztruko: " << diff2.count() << "s\n";

        //-------------------------------------------------------------------------------------------------------------------------------------------------
        // Isskirstom konteineri pagal studento vidurki.
        auto start3 = chrono::high_resolution_clock::now();
        if(pasirinkimas == 1)
        {
            for(auto& stud : sarasas)
            {
                if(stud.galutinisVid >= 5) geri.push_back(stud);
                else blogi.push_back(stud);
            }
        }
        if(pasirinkimas == 2)
        {
            for(auto& stud : sarasas)
            {
                if(stud.galutinisVid >= 5) geri.push_back(stud);
            }
            sarasas.erase(remove_if(sarasas.begin(), sarasas.end(), [&](Studentas const& sarasas)
            {
                return sarasas.galutinisVid >= 5;
            }), sarasas.end());
        }
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff3 = end3 - start3;
        cout << "'Geru' ir 'blogu' studentu isskirstymas uztruko: " << diff3.count() << "s\n";
        if(pasirinkimas == 1) sarasas.clear();

        //-------------------------------------------------------------------------------------------------------------------------------------------------
        // Isvedam is dvieju konteineriu i du failus.
        if(pasirinkimas == 1)
        {
            // Isvedam apdorotus geru studentu duomenis i faila.
            auto start4 = chrono::high_resolution_clock::now();
            ofstream file1(KituFailuVardai[e]);
            file1 << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
            file1 << "----------------------------------------------------------------------------" << "\n";
            for(vector<Studentas>::const_iterator it = geri.begin(); it != geri.end(); ++it)
            {
                file1 << left << setw(20) <<  (*it).vardas << left << setw(20) << (*it).pavarde << fixed << showpoint << setprecision(2) << left << setw(20) << (*it).galutinisVid << left << setw(20) << (*it).galutinisMed << "\n";
            }
            file1.close();

            // Isvedam apdorotus blogu studentu duomenis i faila.
            ofstream file2(KituFailuVardai[ea]);
            file2 << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
            file2 << "----------------------------------------------------------------------------" << "\n";
            for(vector<Studentas>::const_iterator it = blogi.begin(); it != blogi.end(); ++it)
            {
                file2 << left << setw(20) << (*it).vardas << left << setw(20) << (*it).pavarde << fixed << showpoint << setprecision(2) << left << setw(20) << (*it).galutinisVid << left << setw(20) << (*it).galutinisMed << "\n";
            }
            file2.close();
            e += 2, ea += 2;

            auto end4 = chrono::high_resolution_clock::now();
            chrono::duration<double> diff4 = end4 - start4;
            cout << "Studentu isvedimas i du failus '" << KituFailuVardai[e - 2] << "' (Vidurkis > 5) ir '" << KituFailuVardai[ea - 2]
            << "' (Vidurkis < 5) uztruko: " << diff4.count() << "s\n";
            cout << "Bendras darbo su failu '" << FailuVardai[i] << "' laikas: "
                 << diff1.count() + diff2.count() + diff3.count() + diff4.count() << "s\n";
        }
        if(pasirinkimas == 2)
        {
            // Isvedam apdorotus geru studentu duomenis i faila.
            auto start4 = chrono::high_resolution_clock::now();
            ofstream file1(KituFailuVardai[e]);
            file1 << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
            file1 << "----------------------------------------------------------------------------" << "\n";
            for(vector<Studentas>::const_iterator it = geri.begin(); it != geri.end(); ++it)
            {
                file1 << left << setw(20) <<  (*it).vardas << left << setw(20) << (*it).pavarde << fixed << showpoint << setprecision(2) << left << setw(20) << (*it).galutinisVid << left << setw(20) << (*it).galutinisMed << "\n";
            }
            file1.close();

            // Isvedam apdorotus blogu studentu duomenis i faila.
            ofstream file2(KituFailuVardai[ea]);
            file2 << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
            file2 << "----------------------------------------------------------------------------" << "\n";
            for(vector<Studentas>::const_iterator it = sarasas.begin(); it != sarasas.end(); ++it)
            {
                file2 << left << setw(20) << (*it).vardas << left << setw(20) << (*it).pavarde << fixed << showpoint << setprecision(2) << left << setw(20) << (*it).galutinisVid << left << setw(20) << (*it).galutinisMed << "\n";
            }
            file2.close();
            e += 2, ea += 2;

            auto end4 = chrono::high_resolution_clock::now();
            chrono::duration<double> diff4 = end4 - start4;
            cout << "Studentu isvedimas i du failus '" << KituFailuVardai[e - 2] << "' (Vidurkis > 5) ir '" << KituFailuVardai[ea - 2]
            << "' (Vidurkis < 5) uztruko: " << diff4.count() << "s\n";
            cout << "Bendras darbo su failu '" << FailuVardai[i] << "' laikas: "
                 << diff1.count() + diff2.count() + diff3.count() + diff4.count() << "s\n";
        }
        geri.clear();
        if(pasirinkimas == 1) blogi.clear();
        if(pasirinkimas == 2) sarasas.clear();
    }
    return 0;
}
