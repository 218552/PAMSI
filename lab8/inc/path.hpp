#ifndef PATH_HPP
#define PATH_HPP

class Path
{
  List vertices;
  int length=0;
public:
  Path(List q, int l) { vertices=q; length=l; }
  List get_vertices() { return vertices; }
  int get_last_node() { return vertices.get_data(vertices.size()); }
  int get_length() { return length; }
  void display_path() { vertices.display(); }
  bool operator < (const Path& l) const { return (length < l.length); }
};

#endif
