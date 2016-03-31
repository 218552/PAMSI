#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Interfejs
{
public:
  virtual double stoper(bool flag)=0;
};

class Interfejs2
  :public Interfejs
{
  clock_t start;
public:
  double stoper(bool flag);
  bool *zmien_rozmiar(bool *tab,int n,int zwieksz);
};
  
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

void wyswietl(bool *tab,int n)
{
  for(int i=0;i<n;i++)
    cout<<tab[i]<<endl;
}

int main()
{
  Interfejs2 inter;
  int n=10;              //poczatkowa ilosc elementow tablicy
  int liczba=1;          //liczba do przypisania wartosci elementom tablicy
  int zwieksz=100;         //ilosc elementow o jaka zwiekszana bedzie tablica
  bool *tab=new bool[n];
  inter.stoper(1);
  for(int i=0;i<100000;i++)
    {
      if(i<n)
	{
	  tab[i]=liczba;
	}
      else
	{
	  tab=inter.zmien_rozmiar(tab,n,zwieksz);
	  tab[i]=liczba;
	  n=n+zwieksz;
	}
    }   
  inter.stoper(0);	
  delete[] tab;
}
