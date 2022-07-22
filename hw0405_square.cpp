#include <iostream>
#include <stdlib.h>

using namespace std;

float signedArea(int *x, int *y, int n){
  float area;
  int sum;
  for (int i=0;i<n-1;i++){
    sum+=(x[i]+x[i+1])*(y[i+1]-y[i]);
  }
  sum+=(x[n-1]+x[0])*(y[0]-y[n-1]);
  area = 0.5 * sum;
  return area;
}


int main(){
  int n;
  int xx,yy;
  float size;
  int order;
  cin >> n;
  int *x = new int[n];
  int *y = new int[n];
  for (int i=0;i<n;i++){
    cin >> xx >> yy;
    x[i]=xx;
    y[i]=yy;
  }

  size = signedArea(x,y,n);

  if (size<0) order=-1;
  else if (size>0) order=1;
  else order=0;

  size = abs(size)*2;

  cout << size << " " << order << endl;

  return 0;
}
