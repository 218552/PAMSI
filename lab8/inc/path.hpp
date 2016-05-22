#ifndef PATH_HPP
#define PATH_HPP

class Path
{
  std::priority_queue<int,std::vector<int>,std::greater<int>> q;
  Queue vertices;
public:
  void new_node(int index, int weight) {q.push(index);q.push(weight);}
  int get_size() {return vertices.size();}
  int get_min() { return q.top();}
};

#endif
