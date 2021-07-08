#ifndef WEKTORY_HH
#define WEKTORY_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <ctime>

using namespace std;

//funkcje pomocnicze do obsługi tablic

//tworzy tablicę liczb pseudolosowych
void stworz(int **wektor, int zmienna)
{
    for (int i = 0; i < 100; i++)
    {
        wektor[i] = new int[zmienna];
        for (int j = 0; j < zmienna; j++)
        {
            wektor[i][j] = 0;
        }
    }
}
//zmienia liczby od zadanego zakresu
void zmien_wektor_procentowy(int **wektor, int **pom, int zmienna, float procent)
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = zmienna * procent; j < zmienna; j++)
        {
            wektor[i][j] = pom[i][j];
        }
    }
}
//kopiuje jedną macierz do drugiej
void copy(int **wektor, int **pom, int zmienna)
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < zmienna; j++)
        {
            pom[i][j] = wektor[i][j];
        }
    }
}
//wypisuje na standardeowe wyjście
void wypisz(int **wektor, int zmienna)
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < zmienna; j++)
        {
            cout << wektor[i][j] << endl;
        }
    }
}
//odwraca tablicę
void odwrotnesortowanie(int **posortowana, int **wyjsciowa, int zmienna)
{
    int k = zmienna;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < zmienna; j++)
        {
            wyjsciowa[i][j] = posortowana[i][--k];
        }
        k = zmienna;
    }
}
// int k = zmienna;
// for (int i = 0; i < 100; i++)
// {
//     wyjsciowa[i] = new int[zmienna];
//     for (int j = 0; j < zmienna; j++)
//     {
//         cout << k << endl;
//         wyjsciowa[i][j] = posortowana[i][--k];
//     }
// }
// }
void zmienwartosci(int **wektor, int zmienna)
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < zmienna; j++)
        {
            wektor[i][j] = rand() % zmienna;
        }
    }
}
void random(int **wektor, int zmienna)
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < zmienna; j++)
        {
            wektor[i][j] = rand() % zmienna;
        }
    }
}

void stworz_z_wartoscia_losowa(int **wyjsciowa, int zmienna)
{
    stworz(wyjsciowa, zmienna);
    random(wyjsciowa, zmienna);
}
void stworz_z_wartoscia_zadana(int **podana, int **wyjsciowa, int zmienna)
{
    stworz(wyjsciowa, zmienna);
    copy(podana, wyjsciowa, zmienna);
}
void stworz_z_wartoscia_od_tylu(int **podana, int **wyjsciowa, int zmienna)
{
    stworz(wyjsciowa, zmienna);
    odwrotnesortowanie(podana, wyjsciowa, zmienna);
}


#endif
