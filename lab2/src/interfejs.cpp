#include <iostream>

#include "interfejs.hpp"

/* Metoda zwieksza rozmiar tablicy o zadana wartosc           */
/* Parametry                                                   */
/* tab - tablica                                               */
/* n - rozmiar tablicy przed powiekszeniem                     */
/* zwieksz - ilosc elementow o jaka tablica zostanie zwiekszona*/
bool* Interfejs2::zmien_rozmiar(bool *tab,int n,int zwieksz)
{
  bool *tmp=new bool[n];

  for(int i=0;i<n;i++)
    tmp[i]=tab[i];

  delete[] tab;
  tab=new bool[n+zwieksz];

  for(int i=0;i<n;i++)
    tab[i]=tmp[i];

  delete[] tmp;
  return tab;
}


double Interfejs2::stoper(bool flag)
{
  if(flag==1)
    {
      start=clock();
      return 0;
    }
  else
    return double(clock()-start)/(double)CLOCKS_PER_SEC;
}
