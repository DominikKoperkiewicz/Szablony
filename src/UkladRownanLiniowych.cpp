#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
template <class TYP, int ROZMIAR>
const Macierz<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::get_A() const
{
    return this->A;
}

template <class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::get_b() const
{
    return this->b;
}

template <class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::get_A()
{
    return this->A;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::get_b()
{
    return this->b;
}

template <class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::set_A(const Macierz<TYP,ROZMIAR> & AA)
{
    this->A = AA;
}

template <class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::set_b(const Wektor<TYP,ROZMIAR> & bb)
{
    this->b = bb;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::oblicz() const
{
    return this->A.odwrotna() * this->b;
}

template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::blad() const
{
    return ( this->A * (this->oblicz()) - this->b );
}


template class UkladRownanLiniowych<double, 3>;
template class UkladRownanLiniowych<double, 4>;
template class UkladRownanLiniowych<double, 5>;
template class UkladRownanLiniowych<LZespolona, 3>;
template class UkladRownanLiniowych<LZespolona, 4>;
template class UkladRownanLiniowych<LZespolona, 5>;
