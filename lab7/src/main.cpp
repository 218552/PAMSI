#include <iostream>
#include <cstdlib>

#include "stoper.hpp"
#include "node.hpp"
#include "list.hpp"
#include "vertex.hpp"
#include "graph.hpp"

using namespace std;

int main()
{
  srand(time(NULL));
  Stoper stoper1;
  int size=10;   //Rozmiar grafu
  Graph g(size); //Deklaracja grafu o zadanym rozmiarze

  for(int i=0;i<size;i++) //Dodanie wierzcholkow do grafu
    g.add_vertex();

  for(int i=0;i<size;i++)
  {
    while(!g.set_minimal_adjacency(i,2)) //Dopoki liczba krawedzi kazdego wierzcholka <2
      g.add_edge(i,rand()%size);         //Dodanie krawedzi
  }

  for(int i=0;i<10;i++)
  {
    stoper1.measure_time(1);
    g.BFS(size/2);
    cout<<stoper1.measure_time(0)<<endl;
  }
}
