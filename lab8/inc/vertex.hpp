#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex
{
  int index;             //Indeks wierzcholka
  char color='W';            // kolor wierzcholka, W - white, B - black, G - grey
  int previous;          //Indeks poprzedniego wierzcholka
  int length;            //Dlugosc sciezki
  List adjacency_list;   //Lista sasiedztwa
  Vertex* address;       //Adres wierzcholka
public:
  //Konstruktor przypisuje indeks wierzcholkowi
  Vertex(int i) {index=i;}
  //Metoda dodaje adres wierzcholka
  void add_address( Vertex* a) {address=a;}
  //Metoda zwraca adres wierzcholka
  Vertex* get_address(int index) {return address;}
  //Metoda zwraca indeks wierzcholka
  int get_index() {return index;}
  //Metoda zwraca kolor wierzcholka
  char get_color() {return color;}
  //Metoda zmienia color wierzcholka
  void change_color(char c) {color=c;}
  //Metoda dodaje do listy sasiedztwa indeks zadanego wierzcholka
  void add_adjacency(int index, int w) {adjacency_list.add(index,w,1);}
  //Metoda zwraca liste sasiedztwa wierzcholka
  List get_adjacency(){return adjacency_list;}
  //Metoda zwraca rozmiar listy sasiedztwa wierzcholka
  int get_adjacency_size() {return adjacency_list.size();}
  //Metoda zwraca 1 jezeli znajdzie zadany numer na liscie sasiedztwa lub 0
  //w przeciwnym wypadku
  bool search_in_adjacency_list(int number)
  {
    if(adjacency_list.search(number)!=0)return 1;
    else return 0;
  }
  //Metoda zwraca 1 jezeli lista sasiedztwa jest pusta lub 0 w przeciwnym wypadku
  bool is_adjacency_list_empty()
  {
    if(adjacency_list.size()==0)return 1;
    else return 0;
  }
  //Metoda zwraca 1 jezeli lista sasiedztwa posiada tyle samo lub wiecej niz
  // x elementow lub 0 w przeciwnym wypadku
  bool set_minimal_adjacency(int x)
  {
   if(adjacency_list.size()>=x) return 1;
   else return 0;
  }
  //Metoda zmienia wartosc atrybutu previous na zadana
  void change_previous(int index) {previous=index;}
  //Metoda zmienia wartosc atrybutu length na zadana
  void change_length(int l) {length=l;}
  //Metoda zwraca wartosc atrybutu length
  int get_length() {return length;}
};

#endif
