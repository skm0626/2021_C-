#include <iostream>

using namespace std;

int main(){
  int h,w,n;
  cin >> h >> w >> n ;

  int a,b;
  a = n/h;
  b = n%h;
  if (b==0){
    b=h*100;
  }
  else{
    b = b*100;
    a = a+1;
  }
  cout << a+b << endl;
}
