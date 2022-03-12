#include "funkcijos.h"

void Ivedimas(data& temp)
{
    vector<int> myvector(10);
    NdCounter = -1;
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
                    IntTikrinimas();
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
                        IntTikrinimas();
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

void IntTikrinimas()
{
    cerr << "Padarete klaida.\n";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int AtsitiktinisSkaicius()
{
    return rand() % 10 + 1;
}

void IsvedimoParuosimas()
{
    cout << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
    for(int i; i < 76; i++)
    {
        cout << "-";
    }
}

void Isvedimas(data& temp)
{
    int suma = 0;
    double kaireVidurkis = 0, kaireMediana = 0, desine = 0;
    cout << "\n" << left << setw(20) << temp.Vardas << left << setw(20) << temp.Pavarde;

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

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << left << setw(20) << temp.GalutinisVid;
    cout << left << setw(20) << temp.GalutinisMed << "\n";
}
