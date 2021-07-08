#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include "../inc/scalanie.hh"
#include "../inc/QuickSort.hh"

void tworz(int **wektor, int zmienna)
{
    for (int i = 0; i < 100; i++)
    {
        wektor[i] = new int[zmienna];
        for (int j = 0; j < zmienna; j++)
        {
            wektor[i][j] = rand() % zmienna;
        }
    }
}

void copy(int **wektor, int **pom, int zmienna)
{
    for (int i = 0; i < 100; i++)
    {
        pom[i] = new int[zmienna];
        for (int j = 0; j < zmienna; j++)
        {
            pom[i][j] = wektor[i][j];
        }
    }
}

int main()
{
    unsigned long int czas = 0;
    const int a = 10000;
    const int b = 50000;
    const int c = 100000;
    const int d = 500000;
    const int e = 1000000;
    int k = 100;
    int zmienna = a;

    int **wektor = new int *[k];
    int **pom = new int *[k];

    tworz(wektor, zmienna);
    copy(wektor, pom, zmienna);

    //          sortowanie przez scalanie
    Scalanie<10000> scalanie_a = Scalanie<10000>();
    czas = scalanie_a.sortowanie_przez_scalanie(wektor, zmienna);
    cout << "rozpoczynam wypisywanie" << endl;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << pom[i][j] << "        " << wektor[i][j] << endl;
        }
    }
    // Scalanie<50000> scalanie_b = Scalanie<50000>();
    // czas = scalanie_b.sortowanie_przez_scalanie(wektor_b, b);
    // Scalanie<100000> scalanie_c = Scalanie<100000>();
    // czas = scalanie_c.sortowanie_przez_scalanie(wektor_c, c);
    // Scalanie<500000> scalanie_d = Scalanie<500000>();
    // czas = scalanie_d.sortowanie_przez_scalanie(wektor_d, d);
    // Scalanie<1000000> scalanie_e = Scalanie<1000000>();
    // czas = scalanie_e.sortowanie_przez_scalanie(wektor_e, e);
    cout << "czas sortowania przez scalanie = " << czas << endl;

    //          sortowanie przez quicksort
    // Quicksort<10000> quicksort_a = Quicksort<10000>();
    // czas = quicksort_a.sortowanie_przez_quicksort(wektor_a, a);
    // Quicksort<50000> quicksort_b = Quicksort<50000>();
    // czas = quicksort_b.sortowanie_przez_quicksort(wektor_b, b);
    // Quicksort<100000> quicksort_c = Quicksort<100000>();
    // czas = quicksort_c.sortowanie_przez_quicksort(wektor_c, c);
    // Quicksort<500000> quicksort_d = Quicksort<500000>();
    // czas = quicksort_d.sortowanie_przez_quicksort(wektor_d, d);
    // Quicksort<1000000> quicksort_e = Quicksort<1000000>();
    // czas = quicksort_e.sortowanie_przez_quicksort(wektor_e, e);
    // cout << "czas sortowania quicksort = " << czas << endl;
}