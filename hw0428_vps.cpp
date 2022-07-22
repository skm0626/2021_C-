#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	stack<char> st;
	string s;
	cin >> s;

	for (int j = 0; j < s.length(); j++){
		if (s[j] == '(' || st.empty()) {
              st.push(s[j]);
          }
		else if(st.top() == '('){
              st.pop();
          }
	}

	if (st.empty()) {
          cout << "1" << endl;
      }
	else{
          cout << "0" << endl;
      }
      while (!st.empty()) {
          st.pop();
    }
}
