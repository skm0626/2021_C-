#include <iostream>
using namespace std;

int main(){
  int a,b;
  int plus,minus, abs_mi, mul, q, r, max, same;
  cin >> a >> b;
  plus = a+b;
  minus = a-b;
  if (a>b){
    abs_mi=a-b;
  }
  else{
    abs_mi=b-a;
  }
  mul = a*b;
  q = a/b;
  r = a%b;
  if (a>b){
    max = a;
  }
  else{
    max=b;
  }
  if (a==b){
    same=1;
  }
  else{
    same=0;
  }

  cout << plus << " " << minus << " " << abs_mi << " " << mul << " " << q << " " << r << " " << max << " " << same << endl;
  return 0;
}
