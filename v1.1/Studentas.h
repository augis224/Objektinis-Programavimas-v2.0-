#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

class Studentas
{
private:
    //attributes
    string vardas;
    string pavarde;
    int nd[25];
    int egz;
    int ndSk;
    double galutinisVid;
    double galutinisMed;

public:
    //constructor
    Studentas()
    {
        egz = 0;
    }
    //destructor
    ~Studentas() {};

    //setters & getters
    void set_vardas(const string& _vardas) { vardas = _vardas; }
    const string& get_vardas() const{ return vardas; }
    void set_pavarde(const string& _pavarde) { pavarde = _pavarde; }
    const string& get_pavarde() const{ return pavarde; }
    void set_nd(const int& index, const int& pazymis) { nd[index] = pazymis; }
    const int get_nd(int i) const{ return nd[i]; }
    void set_egz(const int& _egz) { egz = _egz; }
    const int get_egz() const { return egz; }
    const int get_ndSk() const { return sizeof(nd)/sizeof(nd[0]); }
    void set_galutinisVid(const double& _galutinisVid) { galutinisVid = _galutinisVid; }
    const double get_galutinisVid() const { return galutinisVid; }
    void set_galutinisMed(const double& _galutinisMed) { galutinisVid = _galutinisMed; }
    const double get_galutinisMed() const { return galutinisMed; }

    //methods (prototypes)
    void Ivedimas(Studentas& temp);
    void ArIntTikrinimas();
    int AtsitiktinisSkaicius();
    void IsvedimoParuosimas();
    //bool compare(const Studentas& x, const Studentas& y);
    void Isvedimas(Studentas& temp);
    void FailuGeneravimas();
    void KituFailuGeneravimas();
    void DuomenuGeneravimas(int n, int i, int EilSk);
    int isFailo(Studentas& temp, vector<Studentas>& sarasas);
    int Vector(Studentas& temp);
};

#endif // STUDENTAS_H_INCLUDED