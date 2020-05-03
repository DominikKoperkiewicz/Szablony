#include "Wektor.hh"
#include "LZespolona.hh"
#include <cmath>
#include <iostream>

/*
template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor(TYP tablica[])
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = tablica[i];
    }
}
*/

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Wektor<TYP,ROZMIAR>::operator += (const Wektor<TYP,ROZMIAR> & W2)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = this->tab[i] + W2.tab[i];
    }

    return *this;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Wektor<TYP,ROZMIAR>::operator -= (const Wektor<TYP,ROZMIAR> & W2)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = this->tab[i] - W2.tab[i];
    }

    return *this;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (const Wektor<TYP,ROZMIAR> & W2) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] = this->tab[i] + W2.tab[i];
    }

    return wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (const Wektor<TYP,ROZMIAR> & W2) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] = this->tab[i] - W2.tab[i];
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator * (const Wektor<TYP,ROZMIAR> & W2) const
{
    TYP wynik;wynik = 0;

    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik += this->tab[i] * W2.tab[i];
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (double l) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] += this->tab[i] * l;
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP ,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (LZespolona l) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] += this->tab[i] * l;
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (double l) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] += this->tab[i] / l;
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (LZespolona l) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] += this->tab[i] / l;
    }
    return wynik;
}
/*
template <class TYP, int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const
{
    double wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik += this->tab[i]*this->tab[i];
    }

    return sqrt(wynik);
}
*/
template <class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator == (const Wektor<TYP,ROZMIAR> & W2) const
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        if( this->tab[i] - W2.tab[i] > 0.00001 || this->tab[i] - W2.tab[i] < -0.00001 ) return false;
    }
    return true;
}

template <class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator != (const Wektor<TYP,ROZMIAR> & W2) const
{
    return !(*this == W2);
}

template <class TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator[] (int index) const
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }

    return this->tab[index];
}

template <class TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator[] (int index)
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }

    return (this->tab[index]);
}


template class Wektor<double, 3>;
template class Wektor<double, 4>;
template class Wektor<double, 5>;
template class Wektor<LZespolona, 3>;
template class Wektor<LZespolona, 4>;
template class Wektor<LZespolona, 5>;
