#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona() { this->re = 0; this->im = 0; }

  LZespolona  operator * (double  Skl) const;// nowe
  LZespolona&  operator = (double  Skl);// nowe
  LZespolona&  operator += (LZespolona  Skl);// nowe
  LZespolona&  operator -= (LZespolona  Skl);// nowe
  LZespolona&  operator *= (LZespolona  Skl);// nowe
  bool  operator < (double  Skl) const;// nowe
  bool  operator > (double  Skl) const;// nowe
};


LZespolona utworz(double r, double i);
std::istream & operator >> (std::istream & in, LZespolona & Z); //Wczytaj
std::ostream & operator << (std::ostream & out, const LZespolona & Z); //Wyswietl

LZespolona  sprzezona(LZespolona Z1); // Liczba sprzezona

double modul(LZespolona Z1); // wartosc bezwzgledna/odleglosc

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */



LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (double  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  double  Skl2);

LZespolona  operator / (double  Skl1,  LZespolona  Skl2);

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

bool  operator != (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator = (LZespolona  Skl1,  LZespolona  Skl2);

double&  operator += (double&  Skl1,  LZespolona  Skl2);

#endif
