#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define TARGET 'e'

int main(int argc, char *argv[]){
  if (argc<2){cout << "one command line argument needed\n"; return -1;}
  int n = strlen(argv[1]);
  char *a = new char[n*2+3];
  if (!a) {cout << "allocation failed.\n"; return -1;}
  a[0] = '!';

  int pos = 1;

  for(int i=0;i<n;i++){
    if(argv[1][i] == TARGET){
      a[pos++] = 'e';
      a[pos++] = 'e';
    }
    else{
      a[pos++] = argv[1][i];
    }
  }
  a[pos] = '.';

  cout << a <<endl;

  string s = "!";
  s += argv[1];
  s += ".";
  int pos_2 = 0;

  while (s.find("e",pos_2) != string::npos){
    pos_2 = s.find("e",pos_2);
    s.insert(pos_2,"e");
    pos_2+=2;
  }
  cout << s <<endl;
  return 0;
}
