#include <iostream>
#include <bitset>

using namespace std;

unsigned int cal(int n){
  int a=n;
  int cnt=0;
  while (1){
    if(a%2==1) cnt++;
    a/=2;
    if(a==0) break;
  }
  if (cnt%2==0) return n;
  else return n+2147483648;
}


int main(){
  unsigned int n;
  cin >> n;

  cout << cal(n) << endl;

  return 0;
}
