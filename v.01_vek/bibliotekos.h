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

int StudentuCounter = 0, NdCounter, n, EilSk = 100;
string tnPasirinkimas, paPasirinkimas, VedimoPasirinkimas;
char FailuVardai[5][14] = {"1000.txt", "10000.txt", "100000.txt", "1000000.txt", "10000000.txt"};

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
