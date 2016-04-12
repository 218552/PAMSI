#include <iostream>
#include <ctime>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"
#include "/home/piotr/PAMSI/lab3/inc/stack.hpp"
#include "/home/piotr/PAMSI/lab3/inc/queue.hpp"
#include "/home/piotr/PAMSI/lab3/inc/stoper.hpp"

using namespace std;

int main()
{
  List lista;
  Stoper stoper;
  srand(time(NULL));
  // Poczatek pomiaru czasu
  stoper.measure_time(1);
  // Wypelnienie listy
  for(int i=1;i<=100000000;i++)
    {
      lista.add(rand()%101,i);
    }
  // Wyszukanie danego elementu z listy
  lista.search(100);
  // Koniec pomiaru czasu i wyswietlenie wyniku
  cout<<stoper.measure_time(0)<<endl;
  

  return 0;
}
