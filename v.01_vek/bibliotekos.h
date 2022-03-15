#ifndef BIBLIOTEKOS_H_INCLUDED
#define BIBLIOTEKOS_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstring>
#include <chrono>
#include <algorithm>
#include <limits>

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
