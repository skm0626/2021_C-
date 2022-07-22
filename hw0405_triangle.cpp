#include <iostream>
#include <stdlib.h>

using namespace std;

float signedArea(int ax, int ay, int bx, int by, int cx, int cy){
  float area;
  area = 0.5 * ((bx-ax)*(cy-ay)-(cx-ax)*(by-ay));
  return area;
}


int main(){
  int ax,ay,bx,by,cx,cy;
  float size;
  int order;
  cin >> ax >> ay >> bx >> by >> cx >> cy;

  if((ax==bx && ay==by) || (ax==cx &&ay==cy) || (bx==cx&&by==cy)){
    return 0;
  }
  else{
    size = signedArea(ax,ay,bx,by,cx,cy);

    if (size<0) order=-1;
    else if (size>0) order=1;
    else order=0;

    size = abs(size)*2;

    cout << size << " " << order << endl;
  }

  return 0;
}
