#ifndef SCALANIE_HH
#define SCALANIE_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <ctime>

using namespace std;


//funkcja słuząca do posortowania i scalenia tablic rozbitych przez scalanie
/* jako argumenty są: 
- tablica, 
- wyraz od ktorego rozpoczniemy sortowanie
- wyraz środkowy
- wyraz ktorym skonczymy sortowanie  */
template <int rozmiar1>
void scal_tablice(int tablica[rozmiar1], int pierwszy, int srodek, int ostatni)
{
    int nieposortowany[rozmiar1];             //tworzymy wektor pomocniczy ktory jest nieposortowany
    int i = pierwszy, j = srodek + 1;         //tworzymy zmienne pomocnicze
    for (int i = pierwszy; i <= ostatni; i++) //petla gdzie tworzymy wektor pomocniczy
        nieposortowany[i] = tablica[i];

    for (int k = pierwszy; k <= ostatni; k++) //petla od pierwszego wyrazu do posortowania do ostatniego do posortowania
    {
        if (i <= srodek) //i == ostatni, z poprzedniej pętli, więc jeśli jest mniejszy od środka, to (1), jeśli nie to (2)
        { 
            if (j <= ostatni) //(2) j == srodek+1, więc jeśli jest mniejszy od ostatniego, to (3), jeśli nie to (4)
            {                                             
                if (nieposortowany[j] < nieposortowany[i]) //(4) sprawdzamy czy wyraz j-ty < i-ty, jeśli nie to(5), jeśli nie, to(6)
                {
                    tablica[k] = nieposortowany[j]; //(6) podstawiamy w miejsce k wyraz j-ty
                    j++; //j zwiększa się o 1 - idziemy o kolejny wyraz w prawo(od środka)
                }
                else //(5)
                {
                    tablica[k] = nieposortowany[i]; //podstawiamy w miejsce k wyraz i-ty
                    i++; //i zwiększa się o 1 - idziemy o kolejny wyraz w prawo od początku
                }
            }
            else //(3) 
            {
                tablica[k] = nieposortowany[i]; //podstawiamy w miejsce k wyraz i-ty
                i++; //i zwiększa się o 1 - idziemy o kolejny wyraz w prawo od początku
            }
        }
        else //(1)
        {
            tablica[k] = nieposortowany[j];//podstawiamy w miejsce k wyraz j-ty
            j++; //j zwiększa się o 1 - idziemy o kolejny wyraz w prawo(od środka)
        }
    }
}
//funkcja dzieląca tablicę na podtablice
/* jako argumenty są: 
- tablica, 
- wyraz od ktorego rozpoczniemy sortowanie 
- wyraz ktorym skonczymy sortowanie  */
template <int rozmiar1>
int sortuj_s(int tablica[rozmiar1], int pierwszy, int ostatni)
{
    if (ostatni <= pierwszy) //sprawdza czy na pewno wyraz kończący sortowanie jest większy od tego ktorym rozpoczynamy
    {
        return 0;
    }
    int srodek = (pierwszy + ostatni) / 2; // dzielimy sortowanie na poł

    sortuj_s<rozmiar1>(tablica, pierwszy, srodek);    //dzielimy pierwszą połowę tablicy
    sortuj_s<rozmiar1>(tablica, srodek + 1, ostatni); //dzielimy drugą połowę tablicy

    scal_tablice<rozmiar1>(tablica, pierwszy, srodek, ostatni); //sortowanie tablic
    return 0;
}

//funkcja pomocnicza, licząca czas sortowania
template <int rozmiar1>
int sortowanie_przez_scalanie(int *wektor[rozmiar1])
{
    // cout << "scalanie" << endl;
    clock_t start, stop;    //funkcja z biblioteki <ctime.hh> słuąca do policzenia czasu trwania algorytmu sortowania
    start = clock();        //rozpoczęcie liczenia
    for (int i = 0; i < 100; i++) //sortujemy 100 tablic
    {
        sortuj_s<rozmiar1>(wektor[i], 0, rozmiar1 - 1); //sortowanie
    }
    stop = clock();         //zatrzymujemy czas działania
    unsigned long int czas = 1000 * (stop - start) / CLOCKS_PER_SEC; //liczymy czas działania algorytmu
    return czas;
}

#endif
