int List()
{
    data temp;
    list<data> sarasas;
    int e = 0, ea = 1, suma, n;
    list<data> geri;
    list<data> blogi;
    string Eilute, zyme = "ND";
    size_t position = 0;

    cout << "\nLIST";
    for(int i = 0; i < 5; i++)
    {
        cout << "\n";
        n = 0;
        stringstream Buferis;
        // Atidarom faila.
        ifstream file(FailuVardai[i]);
        // Exception handling.
        try
        {
            if(!file) throw "Failo atidaryti nepavyko.";
        }
        catch(const char* txtException)
        {
            cout << "Klaida: " << txtException << endl;
            return -1;
        }

        auto start1 = chrono::high_resolution_clock::now();
        // Nuskaitom visa failo turini i buferi.
        Buferis << file.rdbuf();
        getline(Buferis, Eilute);
        while ((( position = Eilute.find(zyme))) != std::string::npos)
        {
            n++;
            Eilute.erase(0, position + zyme.length());
        }
        while(!Buferis.eof())
        {
            suma = 0;
            Buferis >> temp.Vardas >> temp.Pavarde;
            for(int i = 0; i < n; i++)
            {
                Buferis >> temp.Nd[i];
                suma += temp.Nd[i];
            }
            Buferis >> temp.Egz;
            temp.GalutinisVid = ( (double)suma / (double)n * 4 / 10 ) + ( (double)temp.Egz * 6 / 10 );
            sort(temp.Nd, temp.Nd + n);
            if(n % 2 != 0)
            {
                temp.GalutinisMed = ( (double)temp.Nd[n / 2] * 4 / 10 ) + ( (double)temp.Egz * 6 / 10 );
            }
            else
            {
                temp.GalutinisMed = ( (double)(temp.Nd[(n - 1) / 2] + temp.Nd[n / 2]) / 2.0 * 4 / 10 ) + ( (double)temp.Egz * 6 / 10 );
            }
            sarasas.push_back(temp);
        }
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff1 = end1 - start1;
        cout << "Duomenu nuskaitymas is failo '" << FailuVardai[i] << "' uztruko: " << diff1.count() << "s\n";
        file.close();

        // Surusiuojam geru ir blogu studentu isvedima pagal pavarde.
        auto start2 = chrono::high_resolution_clock::now();
        sarasas.sort(compare);
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff2 = end2 - start2;
        cout << "'Geru' ir 'blogu' studentu surusiavimas pagal pavarde uztruko: " << diff2.count() << "s\n";

        auto start3 = chrono::high_resolution_clock::now();
        for(auto& stud : sarasas)
        {
            if(stud.GalutinisVid >= 5) geri.push_back(stud);
            else blogi.push_back(stud);
        }
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff3 = end3 - start3;
        cout << "'Geru' ir 'blogu' studentu isskirstymas uztruko: " << diff3.count() << "s\n";
        sarasas.clear();

        // Isvedam apdorotus geru studentu duomenis i faila.
        auto start4 = chrono::high_resolution_clock::now();
        ofstream file1(KituFailuVardai[e]);
        file1 << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
        file1 << "----------------------------------------------------------------------------" << "\n";
        for(list<data>::const_iterator it = geri.begin(); it != geri.end(); ++it)
        {
            file1 << left << setw(20) <<  (*it).Vardas << left << setw(20) << (*it).Pavarde << fixed << showpoint << setprecision(2) << left << setw(20) << (*it).GalutinisVid << left << setw(20) << (*it).GalutinisMed << "\n";
        }
        file1.close();

        // Isvedam apdorotus blogu studentu duomenis i faila.
        ofstream file2(KituFailuVardai[ea]);
        file2 << left << setw(20) << "VARDAS" << left << setw(20) << "PAVARDE"<< left << setw(20) << "GALUTINIS (VID.)" << left << setw(20) << "GALUTINIS (MED.)" << "\n";
        file2 << "----------------------------------------------------------------------------" << "\n";
        for(list<data>::const_iterator it = blogi.begin(); it != blogi.end(); ++it)
        {
            file2 << left << setw(20) << (*it).Vardas << left << setw(20) << (*it).Pavarde << fixed << showpoint << setprecision(2) << left << setw(20) << (*it).GalutinisVid << left << setw(20) << (*it).GalutinisMed << "\n";
        }
        file2.close();
        e += 2, ea += 2;

        auto end4 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff4 = end4 - start4;
        //cout << "Studentu isvedimas i du failus '" << KituFailuVardai[e - 2] << "' (Vidurkis > 5) ir '" << KituFailuVardai[ea - 2]
             //<< "' (Vidurkis < 5) uztruko: " << diff4.count() << "s\n";
        cout << "Bendras darbo su failu '" << FailuVardai[i] << "' laikas: "
             << diff1.count() + diff2.count() + diff3.count() + diff4.count() << "s\n";

        // Isvalom visus naudotus vektorius.
        geri.clear();
        blogi.clear();
    }
    return 0;
}
