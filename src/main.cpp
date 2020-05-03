#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "LZespolona.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"


using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "\nBrak nazwy pliku zawierajacej uklad. (np.: zespolone.txt)\n";
        return 0;
    }

    UkladRownanLiniowych<LZespolona,5>   UklRownZ;
    UkladRownanLiniowych<double,5>   UklRownR;

    std::fstream plik;
    plik.open( argv[1], std::ios::in );

    char c;
    plik >> c;
    if(c == 'z')
    {
        plik >> UklRownZ;

        cout << endl << " Start programu " << endl << endl;
        cout << UklRownZ << "\n\n";
        cout << " Rozwiazania: " << UklRownZ.oblicz() << "\n";
        cout << "Wektor bledu:  Ax - b  = " << UklRownZ.blad() << "\n";

    }

    if(c == 'r')
    {
        plik >> UklRownR;

        cout << endl << " Start programu " << endl << endl;
        cout << UklRownR << "\n\n";
        cout << " Rozwiazania: " << UklRownR.oblicz() << "\n";
        cout << "Wektor bledu:  Ax - b  = " << UklRownR.blad() << "\n";

    }

}
