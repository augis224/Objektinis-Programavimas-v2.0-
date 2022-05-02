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
#include <random>

using std::cout;
using std::cin;
using std::string;
using namespace std;

string tnPasirinkimas, paPasirinkimas, VedimoPasirinkimas;
string FailuVardai[5] = {"1000.txt", "10000.txt", "100000.txt", "1000000.txt", "10000000.txt"};
char KituFailuVardai[10][200] = {"geri_1000.txt", "blogi_1000.txt", "geri_10000.txt", "blogi_10000.txt",
"geri_100000.txt", "blogi_100000.txt", "geri_1000000.txt", "blogi_1000000.txt", "geri_10000000.txt", "blogi_10000000.txt"};

struct data
{
    string Vardas, Pavarde;
    int Nd[25], Egz = 0, NdSk;
    double GalutinisVid, GalutinisMed;
};

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int>  int_distribution;
mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
int_distribution dist(1, 10);

#endif // BIBLIOTEKOS_H_INCLUDED
