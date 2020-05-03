#include "Macierz.hh"
#include "Wektor.hh"


/*
Macierz::Macierz()
{
    Wektor W;
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = W;
        this->tab[i][i] = 1;
    }
}

Macierz::Macierz(Wektor* tab)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = tab[i];
    }
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{
    this->tab[0] = A;
    this->tab[1] = B;
    this->tab[2] = C;
}
*/
//*********************************
template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> & Macierz<TYP,ROZMIAR>::operator += (const Macierz<TYP, ROZMIAR> & M)
{
    *this = *this + M;
    return *this;
}

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> & Macierz<TYP,ROZMIAR>::operator -= (const Macierz<TYP, ROZMIAR> & M)
{
    *this = *this - M;
    return *this;
}

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::operator+ (const Macierz<TYP, ROZMIAR> & M) const
{
    Macierz<TYP, ROZMIAR> Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] + M[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::operator- (const Macierz<TYP, ROZMIAR> & M) const
{
    Macierz<TYP, ROZMIAR> Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] - M[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::operator* (const double l) const
{
    Macierz<TYP, ROZMIAR> Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] * l;
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::operator* (const Wektor<TYP, ROZMIAR> W) const
{
    Wektor<TYP, ROZMIAR> Wynik;
    TYP tmp;tmp = 0;

    for(int i = 0; i < ROZMIAR; i++)
    {
        tmp += this->tab[i] * W;
        Wynik[i] = tmp;
        tmp = 0;
    }

    return Wynik;
}

template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::operator/ (const double l) const
{
    Macierz<TYP, ROZMIAR> Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] / l;
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
const Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::transponowana() const
{
    Wektor<TYP, ROZMIAR> W;
    Macierz<TYP, ROZMIAR> Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        for(int j = 0; j < ROZMIAR; j++)
        {
            W[j] = this->tab[j][i];
        }
        Wynik.tab[i] = W;
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
const TYP Macierz<TYP,ROZMIAR>::wyznacznik() const
{
    Macierz<TYP, ROZMIAR> M = *this;
    TYP Wynik; Wynik = M[0][0];

    for(int i = 0; i < ROZMIAR - 1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            M[i+j+1] -= M[i] * ( M[i+j+1][i] / M[i][i] );
        }
    }

    for(int i = 1; i < ROZMIAR; i++) { Wynik *= M[i][i]; }

    return Wynik;
}

template <class TYP, int ROZMIAR>
const Macierz<TYP, ROZMIAR> Macierz<TYP,ROZMIAR>::odwrotna() const
{
    Macierz<TYP, ROZMIAR> M = *this;
    Macierz<TYP, ROZMIAR> Wynik; //Macierz jednostkowa
    TYP tmp;
    for(int i = 0; i < ROZMIAR-1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            tmp = ( M[i+j+1][i] / M[i][i] );
            M[i+j+1] -= M[i] * tmp;
            Wynik[i+j+1] -= Wynik[i] * tmp;
        }
    }

    for(int i = 0; i < ROZMIAR-1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            tmp = ( M[(ROZMIAR-1)-(i+j+1)][(ROZMIAR-1)-i] / M[(ROZMIAR-1)-i][(ROZMIAR-1)-i] );

            M[ROZMIAR-i-j-2] -= M[ROZMIAR-i-1] * tmp;
            Wynik[ROZMIAR-i-j-2] -= Wynik[ROZMIAR-i-1] * tmp;
        }
    }

    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = Wynik[i]/M[i][i];
    }

    return Wynik;
}

template <class TYP, int ROZMIAR>
const Wektor<TYP, ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int index) const
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }
    return (this->tab[index]);
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int index)
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }
    return (this->tab[index]);
}


template class Macierz<double, 3>;
template class Macierz<double, 4>;
template class Macierz<double, 5>;
template class Macierz<LZespolona, 3>;
template class Macierz<LZespolona, 4>;
template class Macierz<LZespolona, 5>;
