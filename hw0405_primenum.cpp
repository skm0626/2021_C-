#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

bool prime(int a){
  int n=(int) sqrt(a);
  for (int i=2;i<=n;i++){
    if(a%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int a, answer;
  cin >> a;

  if(a==2){
    cout << "1" << endl;
    return 0;
  }

  answer=prime(a);

  if(answer) cout <<"1"<<endl;
  else cout << "0" << endl;

  return 0;
}
