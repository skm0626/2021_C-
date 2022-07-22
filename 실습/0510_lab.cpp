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

class Bvector:public Kvector{
protected:
  unsigned int* u_m;
  const int NBITS;
public:
  Bvector(int nbits=32);
  Bvector(const Bvector& e);
  bool bit(int pos) const;
  void set(int pos);
  void reset(int pos);
  int size() const {return NBITS;}
  void clear() {for(int i=0;i<len;i++) m[i]=0;}
  void print() const;
bool operator[] (int idx) const {return bit(idx);}
Bvector& operator=(const Bvector& v);
friend ostream& operator<<(ostream& os, const Bvector& v);
};

Bvector::Bvector(int nbits): Kvector((nbits+31)/32,0),NBITS(nbits){
  cout << this << " : Bvector (" << nbits << ")" << endl;
  u_m = (unsigned int*)m;
}
Bvector::Bvector(const Bvector& e):Kvector(e), NBITS(e.NBITS){
  cout << this << " : Bvector(*"<< &e << ")" << endl;
  u_m = (unsigned int*)m;
}
Bvector& Bvector::operator=(const Bvector& v){
  cout << "Bvector :: operator= "<< &v << endl;
  if(NBITS == v.NBITS){
    for (int i=0;i<len;i++) m[i]=v.m[i];
  }
  return *this;
}
void Bvector::print() const{
  cout << "Bvector with "<< NBITS << " bits" << endl;
  for(int i=0;i<NBITS;i++) cout << bit(i) << " ";
  cout << endl;
}
ostream& operator<<(ostream& os, const Bvector& v){
  for (int i=0;i<v.NBITS;i++) os << v.bit(i)<<" ";
  return os;
}
bool Bvector::bit(int pos) const{
  if (pos >= NBITS) return false;
  unsigned int element = u_m[pos/32];
  int pos_bit = pos%32;
  unsigned int mask = 1 << pos_bit;
  int value = element & mask;
  return value;
}
void Bvector::reset(int pos){
  if (pos >= NBITS) return;
  unsigned int &element = u_m[pos/32];
  int pos_bit = pos%32;
  unsigned int mask = 1 << pos_bit;
  mask=~mask;
  element &=mask;
}
void Bvector::set(int pos){
  if(pos>=NBITS) return;
  unsigned int &element = u_m[pos/32];
  int pos_bit = pos%32;
  unsigned int mask = 1 << pos_bit;
  element |=mask;
}

class BitSet : public Bvector{
public:
  BitSet(int sz = 32);
void insert(int v);
friend BitSet operator+(const BitSet& v1, const BitSet& v2);
friend ostream& operator<< (ostream& os, const BitSet& s);
};

BitSet::BitSet(int sz) : Bvector(sz){}

void BitSet::insert(int v){
  set(v);
}
BitSet operator+ (const BitSet& v1, const BitSet& v2){
  BitSet B(v1.NBITS);
  for (int i=0;i<B.len;i++){
    B.u_m[i] = v1.u_m[i] | v2.u_m[i];
  }
  return B;
}

ostream& operator<<(ostream& os, const BitSet& s){
  os << "{";
  for (int i=0;i<s.NBITS;i++){
    if (s[i]){
      os << i << " ";
    }
  }
  os << "}";
  return os;
}

int main(int argc, char *argv[]){
  BitSet b1(131), b2(131);
  b1.insert(3); b1.insert(5); b1.insert(8);
  b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
  b1.print(); b2.print();
  cout << "b1= "<< b1 << endl;
  cout << "b2= "<< b2 << endl;
  cout << "b1+b2= "<< b1+b2 << endl;
  return 0;
}
