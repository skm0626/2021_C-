#include <iostream>
using namespace std;

int main(){
  int k;
  cin >> k;

  for(int i=0;i<k;i+=2){
    if (i+2>k){
      for (int p=0;p<k;p++){
        if(p==k/2){
          cout <<"O";
        }
        else{
          cout <<"+";
        }
      }
      cout<<endl;
      continue;
    }
    for (int j=0;j<k/2;j++){
      cout << ".";
    }
    cout << "I";
    for (int j=0;j<k/2-i/2-1;j++){
      cout << ".";
    }
    cout <<"*";
    for (int j=0;j<i;j+=2){
      cout << ".";
    }
    cout << endl;
  }

  for(int i=k-2;i>0;i-=2){
    for (int j=0;j<i-1;j+=2){
      cout << ".";
    }
    cout <<"*";
    for (int j=1;j<k/2-i/2;j++){
      cout << ".";
    }
    cout << "I";
    for (int j=0;j<k/2;j++){
      cout << ".";
    }
    cout<<endl;
  }
  return 0;
}
