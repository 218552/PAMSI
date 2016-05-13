#include <iostream>

#include "node.hpp"
#include "list.hpp"
#include "vertex.hpp"
#include "graph.hpp"

void Graph::add_vertex()
{
  Vertex* v=new Vertex(vertices);
  tab[vertices]=v;
  vertices++;
}

void Graph::add_edge(int x, int y, int w)
{
  if(!(tab[x]->search_in_adjacency_list(y))) //Jezeli dodawany indeks sie nie powtarza
  {
    if(x!=y)   //Jezeli indeksy sa od siebie rozne
    {
      tab[x]->add_adjacency(y,w);
      tab[y]->add_adjacency(x,w);
      edges++;
    }
  }
}

void Graph::display_adjacency(int index)
{
  List l;
  l=tab[index]->get_adjacency();
  l.display();
}

void Graph::DFS_visit(int index)
{
  List adj;
  tab[index]->change_color('G');      //Zmiana koloru na szary po pierwszym odwiedzeniu
  adj=tab[index]->get_adjacency();    //Zapisanie listy sasiedztwa elemtu
  for(int i=1;i<adj.size();i++)
  {
     if(tab[adj.get_data(i)]->get_color()=='W') //Jezeli kolor jest bialy (nieodwiedzony)
     {
       tab[adj.get_data(i)]->change_previous(index); //Zmiana poprzedniego indeksu
       DFS_visit(adj.get_data(i));
     }
  }
  tab[index]->change_color('B');    //Zmiana koloru na czarny
}

/* Metoda sluzy do przeszukiwania grafu wglab */
void Graph::DFS()
{
  for(int i=0;i<vertices;i++)
  {
    tab[i]->change_color('W');  //Przypisanie wszystkim wierzcholkom koloru bialego (nieodwiedzone)
    tab[i]->change_previous(-1);//Przypisanie wszystkim wierzcholkom atrybutu previous na -1 (brak)
  }
  for(int i=0;i<vertices;i++)
  {
    if(tab[i]->get_color()=='W') //Jezeli kolor wierzcholka jest bialy (nieodwiedzony)
      DFS_visit(i);
  }
}

/* Metoda sluzy do przeszukiwania grafu wszerz
   Parametr wejsciowy first wskazuje indeks poczatkowego elementu
   od ktorego zacznie sie przeszukiwanie */
void Graph::BFS(int first)
{
  List tmp;
  List adj;
  Vertex *v;
  for(int i=0;i<vertices;i++)   //Przypisanie wszystkim wierzcholkom wartosci
  {
    tab[i]->change_color('W');   //Zmien kolor na bialy
    tab[i]->change_previous(-1); //Oznacz poprzedni wierzcholek jako -1 (brak)
    tab[i]->change_length(-1);   //Oznacz dlugosc jako -1 (brak)
  }
  tab[first]->change_color('G'); //Przypisanie poczatkowemu wierzcholkowi wartosci
  tab[first]->change_length(0);
  tmp.add(first,0,1);              //Dodanie do listy indeksu poczatkowego wierzcholka
  while(tmp.size()!=0)           //Petla wykonuje sie dopoki lista nie jest pusta
  {
    v=tab[tmp.get_data(tmp.size())]; //Pobranie adresu danego wierzcholka
    tmp.remove(tmp.size());          //Usuniecie z listy ostatniego elementu
    adj=v->get_adjacency();          //Pobranie listy sasiedztwa dla danego wierzcholka
    for(int i=1;i<=adj.size();i++)   //Zmiana parametrow kazdego wierzcholka z listy sasiedztwa
    {
      if(tab[adj.get_data(i)]->get_color()=='W') //Jezeli kolor wierzcholka jest bialy (nieodwiedzony)
      {
        tab[adj.get_data(i)]->change_color('G');
        tab[adj.get_data(i)]->change_length(v->get_length()+1);
        tab[adj.get_data(i)]->change_previous(v->get_index());
        tmp.add(adj.get_data(i),0,1);
      }
    }
    v->change_color('B');  //Zmiana koloru na czarny (odwiedzony)
  }
}

void Graph::display_color()
{
  for(int i=0;i<vertices;i++)
    std::cout<<tab[i]->get_color()<<std::endl;
}

void Graph::display_weight()
{
  List tmp;
  for(int i=0;i<vertices;i++)
  {
    tmp=tab[i]->get_adjacency();
    std::cout<<i<<"   ";
    for(int j=1;j<=tmp.size();j++)
      std::cout<<tmp.get_weight(j)<<" ";
    std::cout<<std::endl;
  }
}

void Graph::Branch_and_Bound(int first,int find)
{
  List tmp;
  int x=-1;
  while(x!=find)
  {
    tmp=tab[first]->get_adjacency();
    for(int i=1;i<=tmp.size();i++)
    {
      if(tmp-)
    }
  }
}
