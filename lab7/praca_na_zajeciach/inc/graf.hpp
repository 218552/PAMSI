#ifndef GRAF_HPP
#define GRAF_HPP

class IGraf
{
public:
  virtual void add_vertex(Vertex v)=0;
  virtual void add_edge(Vertex x,Vertex y)=0;
};

class Graf:public IGraf
{
public:

};

#endif
