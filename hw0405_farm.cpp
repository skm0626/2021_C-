#include <iostream>

using namespace std;

int main(){
  int x,y;
  int a,b,n,w;
  cin >> a >> b >> n >> w;

  if(a!=b){
    if (((float(w)-float(a)*float(n))/(float(b)-float(a))) == int((w-a*n)/(b-a))){
      y=(w-a*n)/(b-a);
      x=n-y;
    }
    else{
      cout << "-1" << endl;
      return 0;
    }
  }
  else{
    if (n==2){
      cout << "1" << " " << "1" << endl;
    }
    else{
      cout << "-1" << endl;
    }
    return 0;
  }


  if (x<=0 || y<=0){
    cout << "-1" << endl;
    return 0;
  }
  cout << x << " " << y << endl;
  return 0;
}
