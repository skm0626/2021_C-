#include <iostream>
using namespace std;

int main(){
  int k;
  cin >> k;

  int a[k][k];
  int b=0;

  for (int i=0;i<k;i++){
    for (int j=0;j<=i;j++){
      b=b+1;
      a[i][j]=b;
    }
  }
  
  for (int i=0;i<k;i++){
    for (int j=0;j<=i;j++){
      cout << a[i][j] << " " ;
    }
    cout << endl;
  }
  return 0;
}
