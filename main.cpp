#include <iostream>
#include <cstring>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Wyszukiwanie {
public:
    string szukana,tekst[10000],linia;
    int liczba_wierszy;
    Wyszukiwanie(istream& Tekst, istream& Szukana);
    void Znajdz();
};

Wyszukiwanie::Wyszukiwanie(istream& Tekst, istream& Szukana)
{
    liczba_wierszy=0;
    getline(Szukana, linia);
    szukana=linia;
    do
    {
        getline(Tekst, linia);
        tekst[liczba_wierszy]=linia;
        liczba_wierszy++;
    }while(!Tekst.eof());
}

void Wyszukiwanie::Znajdz()
{
    int m=szukana.length(), n,j;
    for(int i=0;i<liczba_wierszy;i++)
    {
        n=tekst[i].length();
        for(j=0;j<n-m+1;j++)
        {

            if(tekst[i].substr(j, m)==szukana)
            {
                cout<<"Szukany fragment zaczyna sie w wierszu "<<i+1<<" kolumnie "<<j<<endl;
            }
        }
    }
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream tekst("dane.txt"), szukana("Szukany_fragment.txt");
    Wyszukiwanie C(tekst, szukana);
    C.Znajdz();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Funkcja dzialala przez: "<< duration.count() << " milisekund." << endl;

    return 0;
}
