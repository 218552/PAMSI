#include <iostream>
#include <cstdlib>

#include "stoper.hpp"
#include "node.hpp"
#include "list.hpp"
#include "vertex.hpp"
#include "graph.hpp"
#include "queue.hpp"

using namespace std;

int main()
{
  srand(time(NULL));
  int size=100;   //Rozmiar grafu
  Graph g(size); //Deklaracja grafu o zadanym rozmiarze

  for(int i=0;i<size;i++) //Dodanie wierzcholkow do grafu
    g.add_vertex();


  for(int i=0;i<size;i++)
  {
    while(!g.set_minimal_adjacency(i,4))   //Dopoki liczba krawedzi kazdego wierzcholka jest mniejsza od zadanej
      g.add_edge(i,rand()%size,rand()%25+1); //Dodanie krawedzi
  }

  g.display_adjacency();

  cout<<endl;
  g.display_weight();

  g.branch_and_bound(0,9);
}
