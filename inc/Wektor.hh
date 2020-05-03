#ifndef WEKTOR_HH
#define WEKTOR_HH

//#include "rozmiar.h"
#include <iostream>
#include "LZespolona.hh"

template <class TYP, int ROZMIAR>
class Wektor {
    TYP tab[ROZMIAR];

  public:
      Wektor() { for(int i = 0; i < ROZMIAR; i++) this->tab[i] = 0; }
      Wektor(TYP x, TYP y, TYP z) : tab({x,y,z}) {}
      Wektor(TYP tablica[]);

      Wektor<TYP,ROZMIAR> & operator += (const Wektor<TYP,ROZMIAR> & W2); //W1 += W2  , W1 += W3 += W4
      Wektor<TYP,ROZMIAR> & operator -= (const Wektor<TYP,ROZMIAR> & W2);
      Wektor<TYP,ROZMIAR> operator + (const Wektor<TYP,ROZMIAR> & W2) const; //W1 + W2
      Wektor<TYP,ROZMIAR> operator - (const Wektor<TYP,ROZMIAR> & W2) const;
      TYP operator * (const Wektor<TYP,ROZMIAR> & W2) const; //skalarnie
      Wektor<TYP,ROZMIAR> operator * (double l) const; // W1 * 2
      Wektor<TYP,ROZMIAR> operator * (LZespolona l) const; // W1 * Z
      Wektor<TYP,ROZMIAR> operator / (double l) const; // W1 / 2
      Wektor<TYP,ROZMIAR> operator / (LZespolona l) const; // W1 / Z

      //double dlugosc() const; //modul

      bool operator == (const Wektor<TYP,ROZMIAR> & W2) const;
      bool operator != (const Wektor<TYP,ROZMIAR> & W2) const;

      const TYP & operator[] (int index) const;
      TYP & operator[] (int index);
};


template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek)
{

    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek)
{
    Strm << "[" << Wek[0];
    for(int i = 1; i < ROZMIAR; i++)
    {
        Strm << ", " << Wek[i];
    }
    Strm << "]";
    return Strm;
}

#endif
