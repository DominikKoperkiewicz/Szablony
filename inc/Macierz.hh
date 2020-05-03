#ifndef MACIERZ_HH
#define MACIERZ_HH

//#include "rozmiar.h"
#include "Wektor.hh"

#include <iostream>

template <class TYP, int ROZMIAR>
class Macierz {
    Wektor<TYP, ROZMIAR> tab[ROZMIAR];

  public:

    Macierz() { Wektor<TYP, ROZMIAR> W; for(int i = 0; i < ROZMIAR; i++) { this->tab[i] = W; this->tab[i][i] = 1; } } //Jednostkowa
    //Macierz(Wektor* tab);
    //Macierz(Wektor A, Wektor B, Wektor C);

    Macierz<TYP, ROZMIAR> & operator += (const Macierz<TYP, ROZMIAR> & M);
    Macierz<TYP, ROZMIAR> & operator -= (const Macierz<TYP, ROZMIAR> & M);
    Macierz<TYP, ROZMIAR> operator+ (const Macierz<TYP, ROZMIAR> & M) const;
    Macierz<TYP, ROZMIAR> operator- (const Macierz<TYP, ROZMIAR> & M) const;
    Macierz<TYP, ROZMIAR> operator* (const double l) const;
    Wektor<TYP, ROZMIAR> operator* (const Wektor<TYP, ROZMIAR> W) const;
    Macierz<TYP, ROZMIAR> operator/ (const double l) const;

    const Macierz<TYP, ROZMIAR> transponowana() const;
    const TYP wyznacznik() const; //metoda Gaussa
    const Macierz<TYP, ROZMIAR> odwrotna() const;

    const Wektor<TYP, ROZMIAR> & operator[] (int index) const; //element - M[wiersz][kolumna]
    Wektor<TYP, ROZMIAR> & operator[] (int index);
};


template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP, ROZMIAR> &Mac)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP, ROZMIAR> &Mac)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm << Mac[i] << "\n";
    }
    return Strm;
}

#endif
