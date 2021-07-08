#ifndef SHELLA_HH
#define SHELLA_HH

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
template <int rozmiar1>
int sortuj_sh(int tablica[rozmiar1], int pierwszy, int ostatni)
{
  int h = 0;      // h okresla nam w jakiej odleglosci znajdują się kolejne wyrazy
  int liczba = 0; //wartosc zapamietana liczby ktorą chcemy posortować
  int j=0;

  while (h < rozmiar1) //szukamy takiego h gdzie 3h_n+1 będzie większe od rozmiaru tablicy np tablica[20] 3*13+1 = 40
  {
    h = 3 * h + 1;
  }
  h = h / 9; //dzielimy przez 9 poniewaz dla takiej wartosci shella dziala najlepiej (na podstawie badania Donalda Knuth)
  while (h >= 1)
  {
    for (int i = h; i < rozmiar1; i++) //idziemy pokolei naszej tablicy
    {
      liczba = tablica[i];                                      //wpisujemy liczbę ktorą chcemy zapamiętać
      for (j = i; j >= h && tablica[j - h] > liczba; j = j - h) //dla j=1 co pętlę odejmuj h od j do momentu w ktorym j będzie większe rowne h i wyraz [j-h-ty] będzi ewiększy od liczby.
      {
        tablica[j] = tablica[j - h]; //jeśli tak się stanie, zmień obie liczby
      }
      tablica[j] = liczba;
    }
    h = h / 3; //podziel przez 3 i zrob to samo, dopuki h!=0
  }
  return 0;
}

//funkcja pomocnicza, licząca czas sortowania
template <int rozmiar1>
int sortowanie_shella(int *wektor[rozmiar1])
{
  // cout << "shella" << endl;
  clock_t start, stop;          //funkcja z biblioteki <ctime.hh> słuąca do policzenia czasu trwania algorytmu sortowania
  start = clock();              //rozpoczęcie liczenia
  for (int i = 0; i < 100; i++) //sortujemy 100 tablic
  {
    sortuj_sh<rozmiar1>(wektor[i], 0, rozmiar1 - 1); //sortowanie
  }
  stop = clock();                                                  //zatrzymujemy czas działania
  unsigned long int czas = 1000 * (stop - start) / CLOCKS_PER_SEC; //liczymy czas działania algorytmu
  return czas;
}

#endif
