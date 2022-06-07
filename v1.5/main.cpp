#include "bibliotekos.h"
#include "Studentas.h"

int main()
{
    Studentas student;
    Studentas temp;
    vector<Studentas> sarasas;
    int n = 0;

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  5 studentu sarasu failu generavimas (1000, 10000, 100000, 1000000 ir 10000000 studentu).

    while(VedimoPasirinkimas != "t" && VedimoPasirinkimas != "n")
    {
        cout << "Ar norite sugeneruoti 5 studentu sarasu failus? (t/n): ";
        cin >> VedimoPasirinkimas;
        if(VedimoPasirinkimas == "t")
        {
            student.FailuGeneravimas();
            while(cout << "Kiek pazymiu tures studentai? (nuo 1 iki 25): " && (!(cin >> n)
                    || n < 1 || n > 25))
            {
                student.ArIntTikrinimas();
            }
            cout << "\n";
            int EilSk = 100;
            for(int i = 0; i < 5; i++)
            {
                EilSk *= 10;
                student.DuomenuGeneravimas(n, i, EilSk);
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
            student.KituFailuGeneravimas();
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

    while(VedimoPasirinkimas != "1" && VedimoPasirinkimas != "2")
    {
        cout << "Kuri konteineri naudosite (1 - tyrimas su vector konteineriu, 2 - praleisti sia dali): ";
        cin >> VedimoPasirinkimas;
        if(VedimoPasirinkimas == "1")
        {
            student.Vector(temp);
        }
        if(VedimoPasirinkimas == "2")
        {
            break;;
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
            student.Ivedimas(temp);
            sarasas.push_back(temp);
            cout << "Ar norite ivesti " << StudentuCounter + 1 << " studento duomenis? (t - taip, bet koks simbolis - ne): ";
            cin >> VedimoPasirinkimas;
            cout << "\n";
        }

        VedimoPasirinkimas = "p";
        //sort(sarasas.begin(), sarasas.end(), student.compare);
        student.IsvedimoParuosimas();
        for(int i = 0; i < (int)sarasas.size(); i++)
        {
            student.Isvedimas(sarasas.at(i));
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Duomenu ivedimas ir isvedimas is failo.

    if(VedimoPasirinkimas == "f")
    {
        student.isFailo(temp, sarasas);
    }
    return 0;
}

#include "Studentas.cpp"
