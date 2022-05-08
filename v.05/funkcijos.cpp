#include "funkcijos.h"

void Ivedimas(data& temp)
{
    vector<int> myvector(10);
    int NdCounter = -1;
    tnPasirinkimas = "";
    paPasirinkimas = "";

    cout << "Iveskite studento varda: ";
    cin >> temp.Vardas;
    cout << "Iveskite studento pavarde: "; cin >> temp.Pavarde;
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
            cout << "Ar studentas turi bent viena n.d. ivertinima? (t/n): "; cin >> tnPasirinkimas;
        }
            while(tnPasirinkimas == "t")
            {
                NdCounter++;
                while(cout << "Irasykite " << NdCounter + 1 << " n.d. ivertinima: " && (!(cin >> temp.Nd[NdCounter])
                || temp.Nd[NdCounter] < 1 || temp.Nd[NdCounter] > 10))
                {
                    ArIntTikrinimas();
                }
                cout << "Ar norite irasyti dar viena ivertinima? (t - testi, bet koks simbolis - baigti): "; cin >> tnPasirinkimas;
            }
            tnPasirinkimas = ""; //Flushinam tnPasirinkimo reiksme
            while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
            {
                cout << "Ar studentas turi egzamino pazymi? (t/n): "; cin >> tnPasirinkimas;
            }
                if(tnPasirinkimas == "t")
                {
                    while(cout << "Irasykite egzamino pazymi: " && (!(cin >> temp.Egz)
                    || temp.Egz < 1 || temp.Egz > 10))
                    {
                        ArIntTikrinimas();
                    }
                }
                if(tnPasirinkimas == "n")
                {
                    temp.Egz = 0;
                }
    }

    if(paPasirinkimas == "a")
    {
        srand(time(0));
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar studentas turi bent viena n.d. ivertinima? (t/n): "; cin >> tnPasirinkimas;
        }
            while(tnPasirinkimas == "t")
            {
                NdCounter++;
                cout << NdCounter + 1 << " n.d. ivertinimas: ";
                temp.Nd[NdCounter] = AtsitiktinisSkaicius();
                cout << temp.Nd[NdCounter];
                cout << "\nAr norite irasyti dar viena ivertinima? (t - testi, bet koks simbolis - baigti): "; cin >> tnPasirinkimas;
            }
        tnPasirinkimas = ""; //Flushinam tnPasirinkimo reiksme
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar studentas turi egzamino pazymi? (t/n): "; cin >> tnPasirinkimas;
        }
            if(tnPasirinkimas == "t")
            {
                temp.Egz = AtsitiktinisSkaicius();
                cout << "Egzamino ivertinimas: " << temp.Egz << "\n";
            }
            if(tnPasirinkimas == "n")
            {
                temp.Egz = 0;
            }
    }
    temp.NdSk = NdCounter + 1;
}

void ArIntTikrinimas()
{
    cerr << "Padarete klaida.\n";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int AtsitiktinisSkaicius()
{
    return dist(mt);
}

void IsvedimoParuosimas()
{
    cout << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
    for(int i = 0; i < 76; i++)
    {
        cout << "-";
    }
    cout << "\n";
}

bool compare(const data& x, const data& y)
{
    return x.Pavarde < y.Pavarde;
}

void Isvedimas(data& temp)
{
    int suma = 0;
    double kaireVidurkis = 0, kaireMediana = 0, desine = 0;

    for(int j = 0; j < temp.NdSk; j++)
    {
        suma = suma + temp.Nd[j];
    }

    if(suma > 0)
    {
        kaireVidurkis = (double)suma / (double)temp.NdSk * 4 / 10;

        sort(temp.Nd, temp.Nd + temp.NdSk);
        if(temp.NdSk % 2 != 0)
        {
            kaireMediana = (double)temp.Nd[temp.NdSk / 2] * 4 / 10;
        }
        else
        {
            kaireMediana = (double)(temp.Nd[(temp.NdSk - 1) / 2] + temp.Nd[temp.NdSk / 2]) / 2.0 * 4 / 10;
        }
    }
    else
    {
        kaireVidurkis = 0;
    }

    if(temp.Egz > 0)
    {
        desine = (double)temp.Egz * 6 / 10;
    }
    else
    {
        desine = 0;
    }

    temp.GalutinisVid = kaireVidurkis + desine;
    temp.GalutinisMed = kaireMediana + desine;

    cout << left << setw(20) << temp.Vardas << left << setw(20) << temp.Pavarde;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << left << setw(20) << temp.GalutinisVid;
    cout << left << setw(20) << temp.GalutinisMed << "\n";
}

void FailuGeneravimas()
{
    for(int i = 0; i < 5; i++)
    {
        ofstream {FailuVardai[i]};
    }
}

void KituFailuGeneravimas()
{
    for(int i = 0; i < 10; i++)
    {
        ofstream {KituFailuVardai[i]};
    }
}

void DuomenuGeneravimas(int n, int i, int EilSk)
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
