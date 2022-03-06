#ifndef BIBLIOTEKOS_H_INCLUDED
#define BIBLIOTEKOS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using namespace std;

int StudentuCounter = 0, NdCounter;
string tnPasirinkimas, paPasirinkimas, VedimoPasirinkimas;

struct data
{
    string Vardas, Pavarde;
    int Nd[25], Egz = 0, NdSk;
    double GalutinisVid, GalutinisMed;
};

#endif // BIBLIOTEKOS_H_INCLUDED
