#include <iostream>
using namespace std;

int main(){
  int k;
  cin >> k;

  for(int i=0;i<k;i+=2){
    for (int j=1;j<(k-i);j+=2){
      cout << "*";
    }
    for(int j=0;j<=i;j++){
      cout << "+";
    }
    for (int j=1;j<(k-i);j+=2){
      cout << "*";
    }
    cout << endl;
  }

  for(int i=k-2;i>0;i-=2){
    for(int j=1;j<=(k-i);j+=2){
      cout << "*";
    }
    for(int j=0;j<i;j++){
      cout <<"+";
    }
    for(int j=1;j<=(k-i);j+=2){
      cout << "*";
    }
    cout<<endl;
  }
  return 0;
}
