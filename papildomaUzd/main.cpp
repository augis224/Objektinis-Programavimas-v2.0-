#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <regex>
using namespace std;

typedef map<string, int> StringIntMap;

void count_words(StringIntMap& words)
{
    string text;
    string e = "ei";
    ifstream in1("Tekstas.txt");
    while(in1 >> text)
    {
        if( text.find(e) != string::npos ) ++words[text];
    }
    in1.close();

    //Besikartojanciu zodziu suskaiciavimas ir isvedimas
    ofstream zodziai("Zodziai.txt");
    for(StringIntMap::iterator it = words.begin(); it!= words.end(); it++)
    {
        if(it -> second > 1)
        {
            zodziai << it -> first << " occured " << it -> second << endl;
        }
    }
    zodziai.close();
}
void lentele(StringIntMap& words, vector<StringIntMap> Vector)
{
    string eilute;
    StringIntMap wordsVector;
    int count = -1;
    ifstream in2("Tekstas.txt");
    while(!in2.eof())
    {
        count++;
        getline(in2, eilute);
        istringstream my_string(eilute);
        string text;
        while(my_string >> text)
        {
            ++wordsVector[text];
        }
        Vector.push_back(wordsVector);
        wordsVector.clear();
        my_string.clear();
    }
    in2.close();

    //Lenteles isvedimas
    ofstream lentele("Lentele.txt");
    lentele.width(18); lentele << left << "Words";
    for(int i = 1; i <= count; i++)
    {
        lentele.width(18); lentele << left << i;
    }
    lentele << endl;
    for(int i = 1; i <= count*18 + 2; i++)
    {
        lentele << "-";
    }
    lentele << endl;

    vector<int> index;
    int x;
    int y = 0;
    count = 0;
    for(auto const& pair: words)                                                                    // words:               pair.first = key(string); pair.second = occurances(int)
    {
        if(pair.second <= 1) continue;
        if(pair.second > 1)
        {
            lentele.width(18); lentele << pair.first;
        }
            for(vector<StringIntMap>::iterator it = Vector.begin(); it!= Vector.end(); it++)        // i over Vector of maps
            {
                for(auto const& j: (*it))                                                           // StringIntMap in vector: j.first = key(string); j.second = occurances(int)
                {
                    if(pair.first == j.first)
                    {
                        index.push_back(it - Vector.begin());
                        if(index.size() == 1)
                        {
                            x = index.front();
                            //cout << "(" << x << ")";
                            if(j.second > 9) y++;
                            lentele.width(18*x-y); lentele << left << "";
                            lentele << left << j.second;
                        }
                        if(index.size() > 1)
                        {
                            y++;
                            x = index.back() - index.front();
                            //cout << "(" << x << ")";
                            if(j.second > 9) y++;
                            lentele.width(18*x-y); lentele << left << "";
                            lentele << left << j.second;
                            index.erase(index.begin());
                        }
                        y = 0;
                    }

                }
            }
            index.clear();
            lentele << endl;
            count = 0;
    }
    lentele.close();
}

int main()
{
    int pasirinkimas;
    cout << "Zodziu, kurie tekste pasikartoja daugiau nei viena karta ir cross reference lenteles isvedimas - veskite 1." << endl;
    cout << "URL radimas tekste - veskite 2.\n" << endl;
    while(pasirinkimas != 1 && pasirinkimas != 2)
    {
        cout << "Iveskite 1 arba 2: ";
        cin >> pasirinkimas;
    }
    cout << endl;

    if(pasirinkimas == 1)
    {
        ifstream file1("Tekstas.txt");
        file1 >> noskipws;
        // Exception handling.
        try
        {
            if(!file1) throw "Failo atidaryti nepavyko.";
        }
        catch(const char* txtException)
        {
            cout << "Klaida: " << txtException << endl;
            return -1;
        }

        vector<char> text;
        char letter;
        while(file1 >> letter)
        {
            if(isalpha(letter) || isspace(letter)) text.push_back(letter);
        }
        file1.close();

        ofstream file2("Tekstas.txt");
        for(vector<char>::const_iterator it = text.begin(); it != text.end(); ++it)
        {
            file2 << (*it);
        }
        file2.close();
        text.clear();

        StringIntMap words;
        vector<StringIntMap> Vector;
        count_words(words);
        cout << "Zodziu, pasikartojanciu daugiau nei viena karta, kiekis isvestas i faila 'Zodziai.txt'." << endl;
        lentele(words, Vector);
        words.clear();
        Vector.clear();
        cout << "Lentele, parodanti kiek kartu tam tikras zodis pasikartojo kiekvienoje eiluteje, isvesta i faila 'Lentele.txt'." << endl;
    }

    if(pasirinkimas == 2)
    {
        string word;
        vector<string> urls;
        vector<string> domains = {".lt", ".com", ".de", ".net", ".cn", ".uk", ".org", ".info", ".nl", ".eu", ".ru", ".aero", ".asia", ".biz", ".cat", ".com", ".coop", ".store"
        ".edu", ".gov", ".info", ".int", ".jobs", ".mil", ".mobi", ".museum", ".name", ".pro", ".tel", ".travel", ".co", ".tv", ".fm", ".ly", ".ws", ".me", ".cc", ".site", ".blog"};
        string dot = ".";
        ifstream ss("Url.txt");
        try
        {
            if(!ss) throw "Failo atidaryti nepavyko.";
        }
        catch(const char* txtException)
        {
            cout << "Klaida: " << txtException << endl;
            return -1;
        }
        while(ss >> word)
        {
            if( word.find(dot) != string::npos )
            {
                for(auto a: domains)
                {
                    if( word.find(a) != string::npos)
                    {
                       urls.push_back(word);
                       break;
                    }
                }
            }
        }
        ss.close();
        cout << "Rasti URL'ai: " << endl;
        if(urls.size()) for(auto a: urls) cout << a << endl;
        else cout << "Deja, tekste URL'u nera :(" << endl;
        urls.clear();
    }
}
