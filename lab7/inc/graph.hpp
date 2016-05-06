#ifndef GRAPH_HPP
#define GRAPH_HPP

class IGraph
{
public:
  virtual void add_vertex()=0;
  virtual void add_edge(int x, int y)=0;
};

class Graph:public IGraph
{
  int vertices=0; //liczba wierzcholkow
  int edges=0;    //liczba krawedzi
  Vertex **tab;   //Tablica wskaznikow
public:
   //Konstruktor tworzy tablice dynamiczna wskaznikow o zadanym rozmiarze
  Graph(int size){ tab=new Vertex*[size]; }
  //Metoda dodaje wierzcholek
  void add_vertex();
  //Metoda dodaje krawedz miedzy wierzcholkami o zadancyh indeksach
  void add_edge(int x, int y);
  //Metoda wyswietla liste sasiedztwa danego wierzcholka
  void display_adjacency(int index);
  //Metoda sprawdza czy lista sasiedztwa danego wierzcholka jest pusta
  bool is_adjacency_list_empty(int index) {return tab[index]->is_adjacency_list_empty();}
  //Metoda szuka danej wartosci w liscie sasiedztwa wierzcholka o zadanym indeksie
  bool search_in_adjacency_list(int index, int number) {return tab[index]->search_in_adjacency_list(number);}
  //Metoda ustawia minimalny rozmiar listy sasiedztwa
  bool set_minimal_adjacency(int index, int x){ return tab[index]->set_minimal_adjacency(x);}
  //Metoda pomocnicza do algorytmu DFS
  void DFS_visit(int index);
  //Algorytm przeszukania grafu DFS
  void DFS();
  //Algorytm przeszukania BFS, argumentem jest numer wierzcholka od ktorego zacznie sie przeszukanie
  void BFS(int first);
  //Metoda wyswietla kolor wszystkich wierzcholkow w grafie
  void display_color();
};

#endif
