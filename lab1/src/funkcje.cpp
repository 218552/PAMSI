#include <iostream>

#include "funkcje.hpp"

using namespace std;

/* Funkcja zwieksza rozmiar tablicy o zadana wartosc           */
/* Parametry                                                   */
/* tab - tablica                                               */
/* n - rozmiar tablicy przed powiekszeniem                     */
/* zwieksz - ilosc elementow o jaka tablica zostanie zwiekszona*/

bool *zmien_rozmiar(bool *tab, int n, int zwieksz)
{
  bool *tmp=new bool[n];

  for(int i=0;i<n;i++)
    tmp[i]=tab[i];

  delete[] tab;
  tab=new bool[n*zwieksz];

  for(int i=0;i<n;i++)
    tab[i]=tmp[i];

  delete[] tmp;
  return tab;
}

/* Funkcja wyswietla tablice */

void wyswietl(bool *tab,int n)
{
  for(int i=0;i<n;i++)
    cout<<tab[i]<<endl;
}
