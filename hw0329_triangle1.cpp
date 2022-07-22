#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c ;

  if (a>=b+c || b>=a+c || c>=a+b){
    cout << "0" << endl;
  }
  else {
    if (a==b && b==c && a==c){
      cout << "1" <<endl;
    }
    else {
      if (pow(a,2)==pow(b,2)+pow(c,2) || pow(b,2)==pow(a,2)+pow(c,2) || pow(c,2)==pow(a,2)+pow(b,2)){
        cout << "2" << endl;
      }
      else {
        if (a==b || b==c || a==c){
          cout << "3" << endl;
        }
        else {
          cout << "4" << endl;
        }
      }
    }
  }

  return 0;
}
