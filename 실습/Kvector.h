#include <iostream>
#ifndef _KVECTOR_
#define _KVECTOR_

class Kvector{
protected:
  int *m;
  int len;
public:
  Kvector(int sz=0,int value=0);
  Kvector(const Kvector& v);
virtural ~Kvector();
virtual void print() const{ std::cout << "Kvector\n";}
  void clear(){ delete[] m; m=NULL; len=0;}
  int size() const {return len;}
Kvector& operator=(const Kvector& v);
friend bool operator==(const Kvector& v,const Kvector& w);
friend bool operator!=(const Kvector& v, const Kvector& w);
int& operator[](int idx){ return m[idx];}
const int& operator[](int idx) const {return m[idx];}
friend std::ostream& operator<<(std::ostream& os,const Kvector& v);
};
#endif
