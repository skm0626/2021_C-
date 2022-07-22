#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int x1,y1,x2,y2;
  int n,m;
  float d1,d2;

  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n >> m;


  if ((x1 <= n) && (n <= x2)) {
    if ((y1 <= m) && (m <= y2)) {
      d1 = 0;
      d2 = 0;
    }
    else if (m < y1) {
      d1 = pow((y1 - m),2);
      d2 = y1 - m;
    }
    else {
      d1 = pow((m - y2),2);
      d2 = m - y2;
    }
  }

  else {
    if ((y1 <= m) && (m <= y2)) {
      if (n>x1){
        d1 = pow((n-x2),2);
        d2 = n-x2;
      }
      else {
        d1 = pow((x1-n),2);
        d2 = x1-n;
      }
    }
    else if (m < y1) {
      if (n < x1) {
        d1 = pow((n - x1),2) + pow((m - y1),2);
        d2 = (x1 - n) + (y1 - m);
        }
      else {
        d1 = pow((n - x2),2) + pow((m - y1),2);
        d2 = (n - x2) + (y1 - m);
        }
      }
    else {
      if (n < x1) {
        d1 = pow((n - x1),2) + pow((m - y2),2);
        d2 = (x1 - n) + (m - y2);
        }
      else {
        d1 = pow((n - x2),2) + pow((m - y2),2);
        d2 = (n - x2) + (m - y2);
        }
      }
  }
  cout << d1 << " " << d2 << endl;

  return 0;
}
