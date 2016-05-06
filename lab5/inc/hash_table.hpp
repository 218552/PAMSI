#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

using namespace std;

class IHash_table
{
public:
  virtual void insert(int value)=0;
  virtual int* get_data()=0;
  virtual int get_size()=0;
};

class Hash_table:public IHash_table
{
  List list;
public:
  void insert(int value);
  int* get_data();
  int get_size(){return list.size();};
};

#endif
