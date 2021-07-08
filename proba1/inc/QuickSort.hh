#ifndef QUICKSORT_HH
#define QUICKSORT_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <ctime>

using namespace std;
template <int rozmiar1>
class Quicksort
{
    int wektor_do_sortowania[rozmiar1];
    int wektor_posortowany[rozmiar1];

public:
    int getwektor_do_sortowania() const { return wektor_do_sortowania; }
    int &getwektor_do_sortowania() { return wektor_do_sortowania; }
    Quicksort()
    {
        for (int i = 0; i < rozmiar1; i++)
        {
            wektor_do_sortowania[i] = 0;
            wektor_posortowany[i] = 0;
        }
        cout << "pomyslnie zainicjowane quicksort" << endl;
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
    int sortuj(int tablica[rozmiar1], int pierwszy, int ostatni)
    {
        int i = pierwszy - 1;
        int j = ostatni + 1;
        int pivot = tablica[(pierwszy + ostatni) / 2];

        while (1)
        {
            while (pivot > tablica[++i])
                ;
            while (pivot < tablica[--j])
                ;
            if (i <= j)
                swap(tablica[i], tablica[j]);
            else
                break;
        }
        if (j > pierwszy)
            sortuj(tablica, pierwszy, j);
        if (i < ostatni)
            sortuj(tablica, i, ostatni);
        return 0;
    }

    int sortowanie_przez_quicksort(int *wektor[rozmiar1], int a)
    {
          cout << "sortowanie w quicksort" << endl;
        clock_t start, stop;
        start = clock();
        for (int i = 0; i < 100; i++)
        {
              cout << "p";
            sortuj(wektor[i], 0, a - 1);
        }
        stop = clock();
        unsigned long int czas = 100 * (stop - start) / CLOCKS_PER_SEC;
        cout << "jest okej?2" << endl;
        return czas;
    }
}

;

#endif