#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using namespace std;

struct Studentas
{
    string Vardas = "";
    string Pavarde = "";
    int Egz = 0;
    int NdSk = 0;
    double GalutinisVid = 0;
    double GalutinisMed = 0;
    int Nd[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
};
typedef struct Studentas TStudentas;

void IntTikrinimas();
int AtsitiktinisSkaicius();
int studentoPridejimas(TStudentas* &pStudentai, int &pStudentuSkaicius, TStudentas* pStudentas);

int main()
{
    int studentuSkaicius = 0;
    TStudentas* studentai = new TStudentas[1];
    TStudentas* studentas = new TStudentas;

    int NdCounter;
    string tnPasirinkimas = "t";
    string paPasirinkimas;

    while(tnPasirinkimas == "t")
    {
        NdCounter = -1;
        tnPasirinkimas = "";
        paPasirinkimas = "";
        delete studentas;
        studentas = new TStudentas;

        cout << studentuSkaicius + 1 << " STUDENTAS\n";
        cout << "Iveskite studento varda: ";
        cin >>  studentas -> Vardas;
        cout << "Iveskite studento pavarde: ";
        cin >>  studentas -> Pavarde;

        while(paPasirinkimas != "p" && paPasirinkimas != "a")
        {
            cout << "Ar namu darbu ivertinimus ir egzamino pazymi irasysite patys ar juos generuoti atsitiktinai? (p - patys, a - atsitiktinai): ";
            cin >> paPasirinkimas;
        }

//-------------------------------------------------------------------------------------------------------------------------------------------------
//      Duomenu suvedimas.

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
                while(cout << "Irasykite " << NdCounter + 1 << " n.d. ivertinima: " && (!(cin >> studentas -> Nd[NdCounter]) ||
                studentas -> Nd[NdCounter] < 1 || studentas -> Nd[NdCounter] > 10))
                {
                    IntTikrinimas();
                }
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
                while(cout << "Irasykite egzamino pazymi: " && (!(cin >> studentas -> Egz) ||  studentas -> Egz < 1 ||
                studentas -> Egz > 10))
                {
                    IntTikrinimas();
                }
            }
        }

//-------------------------------------------------------------------------------------------------------------------------------------------------
//      Atsitiktinis duomenu ivedimas.

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
                studentas -> Nd[NdCounter] = AtsitiktinisSkaicius();
                cout << studentas -> Nd[NdCounter];
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
                studentas -> Egz = AtsitiktinisSkaicius();
                cout << "Egzamino ivertinimas: " << studentas -> Egz << "\n";
            }
        }

//-------------------------------------------------------------------------------------------------------------------------------------------------
//      Studento duomenu issaugojimas, sekancio studento ivedimas.

        studentas -> NdSk = NdCounter + 1;

        studentoPridejimas(studentai, studentuSkaicius, studentas);
        tnPasirinkimas = "";
        while(tnPasirinkimas != "t" && tnPasirinkimas != "n")
        {
            cout << "Ar norite ivesti dar vieno studento duomenis? (t/n): ";
            cin >> tnPasirinkimas;
        }
        if(tnPasirinkimas == "n")
        {
            break;
        }
        cout << "\n";
    }

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Duomenu isvedimas.

    cout << "\n" << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" <<
    left << setw(20) << "GALUTINIS (MED.)" << "\n";
    for(int i; i < 76; i++)
    {
        cout << "-";
    }

    for(int i = 0; i < studentuSkaicius; i++)
    {
        int suma = 0;
        double kaireVidurkis = 0, kaireMediana = 0, desine = 0;
        cout << "\n" << left << setw(20) << studentai[i].Vardas << left << setw(20) << studentai[i].Pavarde;
        for(int j = 0; j < studentai[i].NdSk; j++)
        {
            suma = suma + studentai[i].Nd[j];
        }
        if(suma > 0)
        {
            kaireVidurkis = (double)suma / (double)studentai[i].NdSk * 4 / 10;

            sort(studentai[i].Nd, studentai[i].Nd + studentai[i].NdSk);
            if(studentai[i].NdSk % 2 != 0)
            {
                kaireMediana = (double)studentai[i].Nd[studentai[i].NdSk / 2] * 4 / 10;
            }
            else
            {
                kaireMediana = (double)(studentai[i].Nd[(studentai[i].NdSk - 1) / 2] +
                studentai[i].Nd[studentai[i].NdSk / 2]) / 2.0 * 4 / 10;
            }
        }
        else
        {
            kaireVidurkis = 0;
        }

        if(studentai[i].Egz > 0)
        {
            desine = (double)studentai[i].Egz * 6 / 10;
        }
        else
        {
            desine = 0;
        }

        studentai[i].GalutinisVid = kaireVidurkis + desine;
        studentai[i].GalutinisMed = kaireMediana + desine;

        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << left << setw(20) << studentai[i].GalutinisVid;
        cout << left << setw(20) << studentai[i].GalutinisMed << "\n";
    }
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------
//Kitos funkcijos

void IntTikrinimas()
{
    cout << "Padarete klaida.\n";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int AtsitiktinisSkaicius()
{
    return rand() % 10 + 1;
}

int studentoPridejimas(TStudentas* &pStudentai, int &pStudentuSkaicius, TStudentas* pStudentas)
{
    pStudentuSkaicius++;
    int k = pStudentuSkaicius - 1;
    //Jei vienas studentas.
    if(k == 0)
    {
        pStudentai[k].Vardas = pStudentas -> Vardas;
        pStudentai[k].Pavarde = pStudentas -> Pavarde;
        pStudentai[k].Egz = pStudentas -> Egz;
        pStudentai[k].NdSk = pStudentas -> NdSk;
        pStudentai[k].GalutinisVid = pStudentas -> GalutinisVid;
        pStudentai[k].GalutinisMed = pStudentas -> GalutinisMed;
        for (int j = 0; j < 25; j++)
        {
            pStudentai[k].Nd[j] = pStudentas -> Nd[j];
        }
    }
    else
    {
    //Jei keli studentai.
        TStudentas * tempStudentai = new TStudentas[pStudentuSkaicius];
        for(int i = 0; i < k; i++)
        {
            tempStudentai[i].Vardas = pStudentai[i].Vardas;
            tempStudentai[i].Pavarde = pStudentai[i].Pavarde;
            tempStudentai[i].Egz = pStudentai[i].Egz;
            tempStudentai[i].NdSk = pStudentai[i].NdSk;
            tempStudentai[i].GalutinisVid = pStudentai[i].GalutinisVid;
            tempStudentai[i].GalutinisMed = pStudentai[i].GalutinisMed;
            for (int j = 0; j < 25; j++)
            {
                tempStudentai[i].Nd[j] = pStudentai[i].Nd[j];
            }
        }
        delete[] pStudentai;
        pStudentai = tempStudentai;

        pStudentai[k].Vardas = pStudentas -> Vardas;
        pStudentai[k].Pavarde = pStudentas ->Pavarde;
        pStudentai[k].Egz = pStudentas -> Egz;
        pStudentai[k].NdSk = pStudentas -> NdSk;
        pStudentai[k].GalutinisVid = pStudentas -> GalutinisVid;
        pStudentai[k].GalutinisMed = pStudentas -> GalutinisMed;
        for (int j=0; j<25; j++)
        {
            pStudentai[k].Nd[j] = pStudentas->Nd[j];
        }
    }
    return 0;
}
