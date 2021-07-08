#ifndef QUICKSORT_HH
#define QUICKSORT_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <ctime>

using namespace std;

//funkcja sortująca
/* jako argumenty są: 
- tablica, 
- wyraz od ktorego rozpoczniemy sortowanie
- wyraz ktorym skonczymy sortowanie  */
void sortuj_q(int tablica[], int pierwszy, int ostatni)
{
    int i = pierwszy; //zmienne pomocnicze indeksujące
    int j = ostatni;
    int pivot = tablica[(pierwszy + ostatni) / 2]; //zmienna ktora powronujemy przy sortowaniu

    do
    {
        while (tablica[i] < pivot) //szukamy wyrazu ktory jest wiekszy od poczatkowego i znajduje się po jego lewej stronie (od poczatku)
            i++;                   //dopoki nie znajdziemy, zwiekszamy i

        while (tablica[j] > pivot) //szukamy wyrazu ktory jest mniejszy od poczatkowego i znajduje się po jego prawej stronie (od konca)
            j--;                   //dopoki nie znajdziemy, zmniejszamy j

        if (i <= j) // zamieniamy miejscami gdy i < j
        {
            swap(tablica[i], tablica[j]);
            i++; //przechodzimy do nastepnych liczb
            j--; //przechodzimy do nastepnych liczb
        }
    } while (i <= j); //rob dopoki i jest mniejsze rowne j

    if (pierwszy < j)
        sortuj_q(tablica, pierwszy, j); //wywolujemy sortowanie dla lewej czesci tablicy

    if (ostatni > i)
        sortuj_q(tablica, i, ostatni); //wywolujemy sortowanie dla prawej czesci tablicy
}
//funkcja pomocnicza, licząca czas sortowania
template <int rozmiar1>
int sortowanie_przez_quicksort(int *wektor[rozmiar1])
{
    // cout << "quicksort" << endl;
    clock_t start, stop;          //funkcja z biblioteki <ctime.hh> słuąca do policzenia czasu trwania algorytmu sortowania
    start = clock();              //rozpoczęcie liczenia
    for (int i = 0; i < 100; i++) //sortujemy 100 tablic
    {
        sortuj_q(wektor[i], 0, rozmiar1 - 1); //sortowanie
    }
    stop = clock();                                                  //zatrzymujemy czas działania
    unsigned long int czas = 1000 * (stop - start) / CLOCKS_PER_SEC; //liczymy czas działania algorytmu
    return czas;
}

#endif
