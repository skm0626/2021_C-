#include <iostream>

using namespace std;

// void sub1(int a[]){
//   a+=1;
//   *a = 1;
// }
//
// void sub2(int *a){
//   a+=1;
//   *a=2;
// }

int main(){
  int a[10];
  // sub1(a);
  // cout << a[1] << endl;
  // sub2(a);
  *(a+1) = 1;
  cout << a[1] << endl;
}
