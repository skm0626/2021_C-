#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void happynumber(int n){
  if (n == 1){
           cout << "HAPPY" << endl;
           return ;
  }
  for(int i=0; i<v.size(); i++){
    if (n == v[i]){
      cout << "UNHAPPY" << endl;
      return;
      }
  }
  v.push_back(n);

  int a = n;
  int m = 0;

  while (a){
    m += (a % 10)*(a % 10);
    a /= 10;
  }
  happynumber(m);
}

int main(void){
  int n;
  cin >> n;
  happynumber(n);
  return 0;
}
