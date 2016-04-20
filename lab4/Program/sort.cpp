#include "sort.hpp"

int partition(int *tab,int lewy, int prawy)
{
  int pivot=tab[(lewy+prawy)/2];
  int i=lewy,j=prawy,n;
  while(1)
    {
      while(tab[j]>pivot)
	j--;
      while(tab[i]<pivot)
	i++;
      if(i<j)
	{
	  n=tab[i];
	  tab[i]=tab[j];
	  tab[j]=n;
	  i++;
	  j--;
	}
      else
	return j;
    }
}

void quicksort(int *tab,int lewy,int prawy)
{
  int q;
  if(lewy<prawy)
    {
      q=partition(tab,lewy,prawy);
      quicksort(tab,lewy,q);
      quicksort(tab,q+1,prawy);
    }
}

void merge(int *tab,const int dol,const int srodek,const int gora)
{
  int *tmp=new int[gora-dol+1];
  int lewy=dol;
  int prawy=srodek+1;
  int obecny=0;
  while(lewy<=srodek&&prawy<=gora)
    {
      if(tab[lewy]<=tab[prawy])
	{
	  tmp[obecny]=tab[lewy];
	  lewy++;
	}
      else
	{
	  tmp[obecny]=tab[prawy];
	  prawy++;
	}
      obecny++;
    }
  if(lewy>srodek)
    {
      for(int i=prawy;i<=gora;i++)
	{
	  tmp[obecny]=tab[i];
	  obecny++;
	}
    }
  else
    {
      for(int i=lewy;i<=srodek;i++)
	{
	  tmp[obecny]=tab[i];
	  obecny++;
	}
    }
  for(int i=0;i<=gora-dol;i++)
    tab[i+dol]=tmp[i];
  delete [] tmp;
}

void mergesort(int *tab,const int dol,const int gora)
{
  if(dol>=gora) return;
  int srodek=(dol+gora)/2;
  mergesort(tab,dol,srodek);
  mergesort(tab,srodek+1,gora);
  merge(tab,dol,srodek,gora);
}
