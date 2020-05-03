#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

template <class TYP, int ROZMIAR>
class UkladRownanLiniowych {
  Macierz<TYP,ROZMIAR> A;
  Wektor<TYP,ROZMIAR> b;
public:
  UkladRownanLiniowych() {};
  UkladRownanLiniowych(Macierz<TYP,ROZMIAR> AA, Wektor<TYP,ROZMIAR> bb) : A(AA), b(bb) {}
  const Macierz<TYP,ROZMIAR> & get_A() const;
  const Wektor<TYP,ROZMIAR> & get_b() const;
  Macierz<TYP,ROZMIAR> & get_A();
  Wektor<TYP,ROZMIAR> & get_b();
  void set_A(const Macierz<TYP,ROZMIAR> & AA);
  void set_b(const Wektor<TYP,ROZMIAR> & bb);

  Wektor<TYP,ROZMIAR> oblicz() const;
  Wektor<TYP,ROZMIAR> blad() const;
};



template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown)
{
    Strm >> UklRown.get_A() >> UklRown.get_b();
    return Strm;
}

template <class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm << "| ";
        for(int j = 0; j < ROZMIAR; j++)
        {
            Strm << UklRown.get_A()[i][j] << " ";
        }
        Strm << "|";

        Strm << "| x_" << i+1 << " |";

        if( i == (int)(ROZMIAR/2) )
        {
            Strm << " = ";
        }
        else
        {
            Strm << "   ";
        }
        Strm << "| " << UklRown.get_b()[i] << " |\n";
    }

    return Strm;
}

#endif
