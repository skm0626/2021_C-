#include <iostream>

using namespace std;

class Kvector{
  int *m;
  int len;
public:
  static int total_len;
  Kvector(int sz=0, int value=0);
  Kvector(const Kvector& v);
  Kvector& operator=(const Kvector& v);
  friend bool operator==(const Kvector& lhs, const Kvector& rhs);
  int& operator[](int idx);
  friend ostream& operator<<(ostream& os, const Kvector& v);

  ~Kvector(){
    cout << this << " : ~Kvector() \n";
    total_len -= len;
    delete[] m;
  }
  void print() const {
    for (int i=0;i<len;i++) cout << m[i] << " ";
    cout << endl;
  }
  void clear(){
    delete[] m;
    m = NULL;
    total_len -= len;
    len = 0;
  }
  int size() {return len;}
};

int Kvector::total_len = 0;

Kvector::Kvector(int sz, int value){
  len = sz;
  total_len+=len;
  if (len>0) m = new int[sz];
  else m = NULL;
  for (int i=0;i<len;i++){
    m[i]=value;
  }
  cout << this  << " : Kvector(int)" << endl;
}

Kvector::Kvector(const Kvector& v){
  len = v.len;
  total_len+=len;
  if (len>0) m = new int[len];
  else m = NULL;
  for (int i=0;i<len;i++){
    m[i]=v.m[i];
  }
  cout << this << " : Kvector(Kvector&)" << endl;
}

Kvector& Kvector::operator=(const Kvector& v){
  if(len != v.len){
    delete[] m;
    m = new int[v.len];
    len = v.len;
    for (int i=0;i<len;i++){
      m[i]=v.m[i];
    }
  }
  return *this;
}

bool operator==(const Kvector& lhs, const Kvector& rhs){
  if (lhs.len != rhs.len) return false;
  for (int i=0;i<lhs.len;i++){
    if (lhs.m[i] != rhs.m[i]) return false;
  }
  return true;
}

bool operator!=(const Kvector& lhs, const Kvector& rhs){
  return !(lhs==rhs);
}

int& Kvector::operator[](int idx){
  return m[idx];
}

ostream& operator<<(ostream& os, const Kvector& v){
  for (int i=0;i<v.len;i++){
    os << v.m[i]<<" ";
  }
  return os;
}
int main(){
  Kvector v1(3);
  v1.print();
  Kvector v2(2,9);
  v2.print();
  Kvector v3(v2);
  v3.print();
  cout << (v1==v2) << endl;
  cout << (v3==v2) << endl;
  v3 = v2 = v1;
  cout << v1 << endl;
  cout << v2 << endl;
  cout << v3 << endl;
  cout << (v3!=v2) << endl;
  v1[2]=2;
  v2[0]=v1[2];
  cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
  return 0;
}
