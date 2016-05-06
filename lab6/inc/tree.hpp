#ifndef TREE_HPP
#define TREE_HPP

class ITree
{
public:
  virtual void add(int value)=0;
  virtual int find(int value)=0;
};

class Tree:public ITree
{
  Tree_node *root;     //wskaznik na pierwszy wezel drzewa
  Tree_node *sentinel; //wskaznik na straznika
public:
 Tree()
  {
    sentinel=new Tree_node;
    sentinel->father=sentinel->left=sentinel->right=sentinel;
    sentinel->color='B';
    root=sentinel;
    root->color='B';
  };
  void add(int value);
  int find(int value);
  Tree_node *get_first(){return root;};
  void display(Tree_node* node, int indent);
  void rotate_left(Tree_node *node);
  void rotate_right(Tree_node *node);
  void fixup(Tree_node *node);
};

#endif
