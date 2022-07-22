#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int a,b,c,d,e,f;
  float n,m,k;
  cin >> a >> b >> c >> d >> e >>f;

  n = sqrt(pow(abs(c-a),2) + pow(abs(d-b),2));
  m = sqrt(pow(abs(e-c),2) + pow(abs(f-d),2));
  k = sqrt(pow(abs(e-a),2) + pow(abs(f-b),2));

  if (n>=m+k || m>=n+k || k>=n+m){
    cout << "0" << endl;
  }
  else{
    if (pow(n,2)==pow(m,2)+pow(k,2) || pow(m,2)==pow(n,2)+pow(k,2) || pow(k,2)==pow(m,2)+pow(n,2)){
      cout << "1" << endl;
    }
    else {
      if (pow(n,2)>pow(m,2)+pow(k,2) || pow(m,2)>pow(n,2)+pow(k,2) || pow(k,2)>pow(m,2)+pow(n,2)){
        cout << "2" <<endl;
      }
      else {
        cout << "3" << endl;
      }
    }
  }

  return 0;
}
