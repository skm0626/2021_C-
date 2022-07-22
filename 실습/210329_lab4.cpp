#include <iostream>
using namespace std;

int main(void){
  char s[10] = {48, '0', '\'', 0x30, '\060', '\x30', '\0'};
  cout << s <<endl;
  int a = s[1]+2;
  int b = s[0]+2;
  cout << a << "   " << b << endl;
  return 0;
}
