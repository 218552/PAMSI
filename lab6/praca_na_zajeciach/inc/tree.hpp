#ifndef TREE_HPP
#define TREE_HPP

class ITree
{
public:
  virtual void add(int value)=0;
  virtual int find()=0;
};

class Tree:public ITree
{
  Tree_node *first; //wskaznik na pierwszy wezel drzewa
public:
  void add(int value);
  int find();
};

#endif
