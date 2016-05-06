#ifndef SORT_HPP
#define SORT_HPP

void quicksort(int *tab,int lewy, int prawy);
int partition(int *tab,int lewy, int prawy);
void merge(int *tab, const int dol, const int srodek, const int gora);
void mergesort(int *tab,const int dol, const int gora);

#endif
