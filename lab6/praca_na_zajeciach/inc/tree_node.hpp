#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

class Tree_node
{
  Tree_node *father;
  Tree_node *left;
  Tree_node *right;
  int value;
  bool color;
  friend class Tree;
};

#endif
