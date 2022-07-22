#include <iostream>

using namespace std;

class Kvector{
protected:
  int *m;
  int len;
public:
  Kvector(int sz=0, int value=0);
  Kvector(const Kvector& v);
  Kvector& operator=(const Kvector& v);
  friend bool operator==(const Kvector& lhs, const Kvector& rhs);
  int& operator[](int idx);
  friend ostream& operator<<(ostream& os, const Kvector& v);

  ~Kvector(){
    cout << this << " : ~Kvector() \n";
    delete[] m;
  }
  void print() const {
    for (int i=0;i<len;i++) cout << m[i] << " ";
    cout << endl;
  }
  void clear(){
    delete[] m;
    m = NULL;
    len = 0;
  }
  int size() {return len;}
};

Kvector::Kvector(int sz, int value) : len(sz){
  if (len>0) m = new int[sz];
  else m = NULL;
  for (int i=0;i<len;i++){
    m[i]=value;
  }
  cout << this  << " : Kvector(" << sz << ", " << value << ")\n";
}

Kvector::Kvector(const Kvector& v){
  len = v.len;
  if (len>0) m = new int[len];
  else m = NULL;
  for (int i=0;i<len;i++){
    m[i]=v.m[i];
  }
  cout << this << " : Kvector(* "<< &v << ")\n";
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

#define N 3
class Avector : public Kvector{
  char table[N];
public:
  Avector(int sz=0, int v=0,const char *t="abc"):Kvector(sz,v){
    for (int i=0;i<N;i++){
      table[i]=t[i];
    }
    cout << this << " : Kvector(" << sz << ", " << v << ", " << t << ")" << endl;
  }
  void setTable(const char* t){
    for (int i=0;i<N;i++){
      table[i]=t[i];
    }
  }
  friend ostream& operator<<(ostream& os, const Avector& v);
};

ostream& operator<<(ostream& os, const Avector& v){
  for (int i=0;i<v.len;i++){
    os << v.table[v.m[i]%3] << " ";
  }
  return os;
}
int main(int argc, char *argv[]){
  if (argc != 2){
    cout << "usage : ./avector pqr\n";
    return 1;
  }
  Avector v1(3);
  v1.print();
  Avector v2(2,1, "xyz");
  v2.print();
  Avector v3(v2);
  v3.print();
  cout << "v1 == v2 " << (v1==v2) << endl;
  cout << "v3 == v2 " << (v3==v2) << endl;
  v3 = v2 = v1;
  cout << "v1 : " <<v1 << endl;
  v1.print();
  cout << "v2 : " << v2 << endl;
  v2.print();
  cout << "v3 : " << v3 << endl;
  v3.print();
  cout << "v3 != v2 " << (v3!=v2) << endl;
  v1[2]=2;
  v2[0]=v1[2];
  v1.setTable(argv[1]);
  cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
  v1.print();
  v2.print();
  v3.print();
  return 0;
}
