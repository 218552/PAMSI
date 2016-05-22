#ifndef PATH_HPP
#define PATH_HPP

class Path
{
  List vertices;
  int length=0;
public:
  Path(int index, int l) {vertices.add(index,0,vertices.size()+1); length=l;}
  void add_length(int l) { length+=l; }
  int get_last_node() { return vertices.get_data(vertices.size()); }
  int get_length() { return length; }
  void display_path() { vertices.display(); }
  bool operator < (const Path& l) const { return (length < l.length); }
};

#endif
