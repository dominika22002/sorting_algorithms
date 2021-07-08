#ifndef PORZADKOWE_HH
#define PORZADKOWE_HH

#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <memory>
#include <ctime>
#include <string>
// #include <cstring>

using namespace std;
//funkcja porządkująca zwracanie wartości, pomocnicza
void raport(int a, int k, int zmienna, float procent, int czas_s, int czas_q, int czas_sh)
{
    if (a == 1)
    {
        cout << "raport po sortowaniu tablic nie posortowanych:" << endl;
        cout << "czas sortowania przez scalanie = " << czas_s << endl;
        cout << "czas sortowania quicksort = " << czas_q << endl;
        cout << "czas sortowania shella = " << czas_sh << endl;
        cout << endl;
    }
    if (a == 2)
    {
        cout << "raport po sortowaniu tablic w " << procent * 100 << "% posortowanych" << endl;
        cout << "czas sortowania przez scalanie = " << czas_s << endl;
        cout << "czas sortowania quicksort = " << czas_q << endl;
        cout << "czas sortowania shella = " << czas_sh << endl;
        cout << endl;
    }
    if (a == 3)
    {
        cout << "raport po sortowaniu tablic posortowanych od tyłu:" << endl;
        cout << "czas sortowania przez scalanie = " << czas_s << endl;
        cout << "czas sortowania quicksort = " << czas_q << endl;
        cout << "czas sortowania shella = " << czas_sh << endl;
        cout << endl;
    }
}

void raport_do_pliku(int a, int k, int zmienna, float procent, int czas_s[], int czas_q[], int czas_sh[], string sciezka)
{
    ofstream zapis(sciezka);

    if (a == 1)
    {
        zapis << "raport po sortowaniu tablic nie posortowanych:" << endl;
        // zapis << "dla " << k << " tablic o dlugosci " << zmienna << " elementow:" << endl;
        zapis << "shella \t"
              << "scalanie \t"
              << "quicksort \t" << endl;
        for (int i = 0; i < 6; i++)
        {
            zapis << czas_sh[i] << "\t" << czas_s[i] << "\t" << czas_q[i] << "\t" << endl;
        }
    }
    if (a == 2)
    {
        zapis << "raport po sortowaniu tablic w " << procent * 100 << "% posortowanych" << endl;
        // zapis << "dla " << k << " tablic o dlugosci " << zmienna << " elementow:" << endl;
        zapis << "shella \t"
              << "scalanie \t"
              << "quicksort \t" << endl;
        for (int i = 0; i < 5; i++)
        {
            zapis << czas_sh[i] << "\t" << czas_s[i] << "\t" << czas_q[i] << "\t" << endl;
        }
    }
    if (a == 3)
    {
        zapis << "raport po sortowaniu tablic posortowanych od tyłu:" << endl;
        // zapis << "dla " << k << " tablic o dlugosci " << zmienna << " elementow:" << endl;
        zapis << "shella \t"
              << "scalanie \t"
              << "quicksort \t" << endl;
        for (int i = 0; i < 5; i++)
        {
            zapis << czas_sh[i] << "\t" << czas_s[i] << "\t" << czas_q[i] << "\t" << endl;
        }
    }
    zapis.close();
}
string stworz_nazwe(int a){
    string lp = to_string(a);        
    string napis = "txt/posortowane";  
    napis = napis+lp;
    napis = napis+".txt";
    return napis;
}
        // char *nazwa = nullptr;
        // string napis = "bryly/przeszkoda";                                      //rozpoczenie wpisywania katalogu gdzie ma znalezc sie plik
        // string liczba_porz = to_string(przeszkoda.size());                      //napisanie "ktora to przeskzoda"
        // napis += liczba_porz;                                                   // dodalnie jej do nazwy
        // napis += ".dat";                                                        //dodanie rozszerzenia pliku
        // przeszkoda[przeszkoda.size() - 1].getnazwa() = napis;                   //przypisanie nazwy do przeszkody
        // przeszkoda[przeszkoda.size() - 1].getprzeszkoda().Importdopliku(napis); //import wierzcholkow przeszkody do plikow
        // int chars_to_reserve = napis.size() + 1;                                //sprawdzenie ile miejsca potrzebuje "nazwa"
        // nazwa = new char[chars_to_reserve];                                     //stworzenie dynamicznej pamieci dla napisu
        // strcpy(nazwa, napis.c_str());                                           //zmiana stringa na char* (potrzebne gnuplotowi)
        // Lacze.DodajNazwePliku(nazwa);                                           //dodanie nazwy do gnuplota
// #include <string>
#endif
