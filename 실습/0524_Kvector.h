#include <iostream>
#ifndef _KVECTOR_
#define _KVECTOR_

using namespace std;

template <class T>
class Kvector;

template <class T>
bool operator==(const Kvector<T>& v, const Kvector<T>& w){
  if (v.len!=w.len){
    return false;
  }
  for (int i=0;i<v.len;i++){
    if (v.m[i]!=w.m[i]) return false;
  }
  return true;
}

template <class T>
bool operator!=(const Kvector<T>& v, const Kvector<T>& w){
  return !(v==w);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Kvector<T>& v){
  for (int i=0;i<v.len;i++){
    os << v[i] << ' ';
  }
  return os;
}

template <class T>
class Kvector{
protected:
  T *m;
  int len;
public:
  Kvector<T>(int sz=0, T value=0){
    len = sz;
    if (len==0) m=NULL;
    else m= new T[len];
    for (int i=0;i<len;i++){
      m[i]=value;
    }
    cout << this << " : Kvector(" << sz << "," << value << ")" << endl;
  }
  Kvector<T>(const Kvector<T>& v){
    len = v.len;
    m = new int[len];
    for (int i=0;i<len;i++){
      m[i]=v.m[i];
    }
    cout << this << " : Kvector(*" << &v << ")" << endl;
  }
  virtual ~Kvector<T>(){
    cout << this << " : ~Kvector() \n";
    delete[] m;
  }
  virtual void print() const{
    for (int i=0;i<len;i++){
      cout << m[i] << " ";
    }
    cout << endl;
  }
  void clear(){ delete[] m; m=NULL; len=0;}
  int size() const {return len;}
  T sum() const{
    if (!len) return T();
    T s = m[0];
    for (int i=1; i<len; i++) s+=m[i];
    return s;
  }
  Kvector<T>& operator=(const Kvector<T>& v){
    if (len !=v.len){
      delete[] m;
      m= new int[v.len];
      len = v.len;
    }
    copy(v.m, v.m+len, m);
    return *this;
  }
  friend bool operator==<>(const Kvector<T>& v,const Kvector<T>& w);
  friend bool operator!=<>(const Kvector<T>& v, const Kvector<T>& w);
  T& operator[](int idx){return m[idx];}
  const T& operator[](int idx) const {return m[idx];}
  friend std::ostream& operator<<<>(ostream& os,const Kvector<T>& v);
};
#endif
