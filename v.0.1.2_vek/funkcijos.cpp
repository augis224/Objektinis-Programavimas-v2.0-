#include "funkcijos.h"

void Ivedimas(vector<data>& sarasas)
{
    NdCounter = -1;
    tnPasirinkimas = "";
    paPasirinkimas = "";

    cout << "Iveskite studento varda: ";
    sarasas.push_back(data());
    cin >> sarasas[StudentuCounter - 1].Vardas;
    cout << "Iveskite studento pavarde: "; cin >> sarasas[StudentuCounter - 1].Pavarde;
    tnPasirinkimas = "";

    while(paPasirinkimas != "p" && paPasirinkimas != "a")
    {
        cout << "Ar namu darbu ivertinimus ir egzamino pazymi irasysite patys ar juos generuoti atsitiktinai? (p - patys, a - atsitiktinai): ";
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
                while(cout << "Irasykite " << NdCounter + 1 << " n.d. ivertinima: " && (!(cin >> sarasas[StudentuCounter - 1].Nd[NdCounter])
                || sarasas[StudentuCounter - 1].Nd[NdCounter] < 1 || sarasas[StudentuCounter - 1].Nd[NdCounter] > 10))
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
                    while(cout << "Irasykite egzamino pazymi: " && (!(cin >> sarasas[StudentuCounter - 1].Egz)
                    || sarasas[StudentuCounter - 1].Egz < 1 || sarasas[StudentuCounter - 1].Egz > 10))
                    {
                        ArIntTikrinimas();
                    }
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
                sarasas[StudentuCounter - 1].Nd[NdCounter] = AtsitiktinisSkaicius();
                cout << sarasas[StudentuCounter - 1].Nd[NdCounter];
                cout << "\nAr norite irasyti dar viena ivertinima? (t - testi, bet koks simbolis - baigti): "; cin >> tnPasirinkimas;
            }
        tnPasirinkimas = ""; //Flushinam tnPasirinkimo reiksme
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar studentas turi egzamino pazymi? (t/n): "; cin >> tnPasirinkimas;
        }
            if(tnPasirinkimas == "t")
            {
                sarasas[StudentuCounter - 1].Egz = AtsitiktinisSkaicius();
                cout << "Egzamino ivertinimas: " << sarasas[StudentuCounter - 1].Egz << "\n";
            }
    }
    sarasas[StudentuCounter - 1].NdSk = NdCounter + 1;
}

void ArIntTikrinimas()
{
    cout << "Padarete klaida.\n";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int AtsitiktinisSkaicius()
{
    return rand() % 10 + 1;
}

void Isvedimas(vector<data>& sarasas, int i)
{
    int suma = 0;
    double kaireVidurkis = 0, kaireMediana = 0, desine = 0;
    cout << "\n" << left << setw(20) << sarasas[i].Vardas << left << setw(20) << sarasas[i].Pavarde;

    for(int j = 0; j < sarasas[i].NdSk; j++)
    {
        suma = suma + sarasas[i].Nd[j];
    }

    if(suma > 0)
    {
        kaireVidurkis = (double)suma / (double)sarasas[i].NdSk * 4 / 10;

        sort(sarasas[i].Nd, sarasas[i].Nd + sarasas[i].NdSk);
        if(sarasas[i].NdSk % 2 != 0)
        {
            kaireMediana = (double)sarasas[i].Nd[sarasas[i].NdSk / 2] * 4 / 10;
        }
        else
        {
            kaireMediana = (double)(sarasas[i].Nd[(sarasas[i].NdSk - 1) / 2] + sarasas[i].Nd[sarasas[i].NdSk / 2]) / 2.0 * 4 / 10;
        }
    }
    else
    {
        kaireVidurkis = 0;
    }

    if(sarasas[i].Egz > 0)
    {
        desine = (double)sarasas[i].Egz * 6 / 10;
    }
    else
    {
        desine = 0;
    }

    sarasas[i].GalutinisVid = kaireVidurkis + desine;
    sarasas[i].GalutinisMed = kaireMediana + desine;

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << left << setw(20) << sarasas[i].GalutinisVid;
    cout << left << setw(20) << sarasas[i].GalutinisMed << "\n";
}
