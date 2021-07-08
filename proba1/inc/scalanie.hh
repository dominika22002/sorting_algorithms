#ifndef SCALANIE_HH
#define SCALANIE_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <ctime>

using namespace std;
template <int rozmiar1>
class Scalanie
{
    int wektor_do_sortowania[rozmiar1];
    int wektor_posortowany[rozmiar1];

public:
    int getwektor_do_sortowania() const { return wektor_do_sortowania; }
    int &getwektor_do_sortowania() { return wektor_do_sortowania; }
    Scalanie()
    {
        for (int i = 0; i < rozmiar1; i++)
        {
            wektor_do_sortowania[i] = 0;
            wektor_posortowany[i] = 0;
        }
          cout << "pomyslnie zainicjowane scalanie" << endl;
    };
    void wpisz_wektor(int liczby[rozmiar1])
    {
        for (int i = 0; i < rozmiar1; i++)
        {
            wektor_do_sortowania[i] = liczby[i];
        }
        // cout << "skonczylam wpisaywac liczby" << endl;
    }
    void wyswietl_przed()
    {
        for (int i = 0; i < rozmiar1; i++)
        {
            cout << wektor_do_sortowania[i] << endl;
        }
    }

    void wyswietl_po()
    {
        for (int i = 0; i < rozmiar1; i++)
        {
            cout << wektor_posortowany[i] << endl;
        }
    }
    void scal_tablice(int tablica[rozmiar1], int pierwszy, int srodek, int ostatni)
    {
        int i = pierwszy, j = srodek + 1;
        for (int i = pierwszy; i <= ostatni; i++)
            wektor_posortowany[i] = tablica[i]; // tworze tablice pomocnicza

        for (int k = pierwszy; k <= ostatni; k++)
        {
            if (i <= srodek)
                if (j <= ostatni)
                    if (wektor_posortowany[j] < wektor_posortowany[i])
                        tablica[k] = wektor_posortowany[j++];
                    else
                        tablica[k] = wektor_posortowany[i++];
                else
                    tablica[k] = wektor_posortowany[i++];
            else
                tablica[k] = wektor_posortowany[j++];
        }
        // for (int i = 0; i <= rozmiar1; i++)
        // {
        //     wektor_posortowany[i] = tablica[i]; // tworze tablice pomocnicza
        // }
    }
    int sortuj(int tablica[rozmiar1], int pierwszy, int ostatni)
    {
        if (ostatni <= pierwszy)
        {
            return 0;
        }
        int srodek = (pierwszy + ostatni) / 2;

        sortuj(tablica, pierwszy, srodek);
        sortuj(tablica, srodek + 1, ostatni);

        scal_tablice(tablica, pierwszy, srodek, ostatni);
        return 0;
    }

    int sortowanie_przez_scalanie(int *wektor[rozmiar1], int a)
    {
        clock_t start, stop;
        start = clock();
        for (int i = 0; i < 100; i++)
        {
            sortuj(wektor[i], 0, a - 1);
        }
        stop = clock();
        unsigned long int czas = 100 * (stop - start) / CLOCKS_PER_SEC;
                cout << "jest okej?" << endl;
        return czas;
    }
};

#endif