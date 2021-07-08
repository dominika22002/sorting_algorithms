#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <iomanip>
#include "../inc/scalanie.hh"
#include "../inc/QuickSort.hh"
#include "../inc/Shella.hh"
#include "../inc/wektory.hh"
#include "../inc/porzadkowe.hh"

int main()
{
    unsigned long int czas_s = 0, czas_q = 0, czas_sh = 0; //zmienne do liczenia czasu trwania sortowania
    int k = 100;                                           //ilość wektorow do posortowania
    const int zmienna = 10000;                              //ilosc liczb do posotrowania
    const float procent = 0.75;                            //0.25 , 0.5 , 0.75 , 0.95 , 0.99 , 0.997 <- procent liczb posortowanych

    float tab_procent[6];

    tab_procent[0] = 0.25;
    tab_procent[1] = 0.5;
    tab_procent[2] = 0.75;
    tab_procent[3] = 0.95;
    tab_procent[4] = 0.99;
    tab_procent[5] = 0.997;

    int **wektor = new int *[k]; //wektor ktory będziemy sortować
    int **pom = new int *[k];    //tablice pomocnicze
    int **posortowana = new int *[k];
    int **pierwotny = new int *[k];
    int **odwrotna = new int *[k];

    int tab_czas_s[10];
    int tab_czas_sh[10];
    int tab_czas_q[10];

    stworz_z_wartoscia_losowa(wektor, zmienna);
    stworz_z_wartoscia_zadana(wektor, pom, zmienna);
    stworz_z_wartoscia_zadana(wektor, pierwotny, zmienna);
    stworz(odwrotna, zmienna);
    stworz(posortowana, zmienna);

    for (int i = 0; i < 1; i++) //ilosc prob
    {
        cout << "dla " << i+1 << " przejcia przez petle" << endl;
        //nieposortowane
        tab_czas_s[i] = sortowanie_przez_scalanie<zmienna>(wektor); //sortowanie przez scalanie, zwraca czas, [scalanie.hh]
        copy(pom, wektor, zmienna);
        tab_czas_q[i] = sortowanie_przez_quicksort<zmienna>(wektor); //sortowanie przez quicksort, zwraca czas, [Quicksort.hh]
        copy(pom, wektor, zmienna);
        tab_czas_sh[i] = sortowanie_shella<zmienna>(wektor);
        raport(1, k, zmienna, tab_procent[i], tab_czas_s[i], tab_czas_q[i], tab_czas_sh[i]);
        //posortowane w ... procencie
        copy(wektor, posortowana, zmienna);
        for (int j = 0; j < 6; j++)
        {
            zmien_wektor_procentowy(wektor, pierwotny, zmienna, tab_procent[i]);
            copy(wektor, pom, zmienna);
            tab_czas_s[i] = sortowanie_przez_scalanie<zmienna>(wektor); //sortowanie przez scalanie, zwraca czas, [scalanie.hh]
            copy(pom, wektor, zmienna);
            tab_czas_q[i] = sortowanie_przez_quicksort<zmienna>(wektor); //sortowanie przez quicksort, zwraca czas, [Quicksort.hh]
            copy(pom, wektor, zmienna);
            tab_czas_sh[i] = sortowanie_shella<zmienna>(wektor);
            raport(2, k, zmienna, tab_procent[j], tab_czas_s[i], tab_czas_q[i], tab_czas_sh[i]);
        }
        odwrotnesortowanie(posortowana,wektor,zmienna);
        copy(wektor, pom, zmienna);
        //posortowane od tylu
        tab_czas_s[i] = sortowanie_przez_scalanie<zmienna>(wektor); //sortowanie przez scalanie, zwraca czas, [scalanie.hh]
        copy(pom, wektor, zmienna);
        tab_czas_q[i] = sortowanie_przez_quicksort<zmienna>(wektor); //sortowanie przez quicksort, zwraca czas, [Quicksort.hh]
        copy(pom, wektor, zmienna);
        tab_czas_sh[i] = sortowanie_shella<zmienna>(wektor);
        raport(3, k, zmienna, tab_procent[i], tab_czas_s[i], tab_czas_q[i], tab_czas_sh[i]);
        random(wektor, zmienna);

    }
    delete[] wektor; //zwolnienie pamieci
    delete[] pom;
    delete[] posortowana;
    delete[] pierwotny;
    return 0;
}