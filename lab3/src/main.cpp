#include <iostream>
#include <ctime>

#include "node.hpp"
#include "list.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "stoper.hpp"

using namespace std;

int main()
{
  List lista;
  Stoper stoper;
  srand(time(NULL));

  // Wypelnienie listy
  for(int i=1;i<=10;i++)
    {
      lista.add(rand()%101,i);
    }
  // Poczatek pomiaru czasu
  stoper.measure_time(1);
  // Wyszukanie danego elementu z listy
  lista.search(100);
  // Koniec pomiaru czasu i wyswietlenie wyniku
  cout<<stoper.measure_time(0)<<endl;
  
  return 0;
}
