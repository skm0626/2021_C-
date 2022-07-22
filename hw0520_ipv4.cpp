#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int num;
	cin >> num;
	if (num == 1) {
		int p1, p2, p3, p4;
		char dot;
		unsigned int num;
		cin >> p1 >> dot >> p2 >> dot >> p3 >> dot >> p4;
		int arr[4] = { p1,p2,p3,p4 };
		num = p1 * pow(2, 24) + p2 * pow(2, 16) + p3 * pow(2, 8) + p4;
		cout << num << endl;
	}
	else {
		unsigned int num;
		cin >> num;
		int p1, p2, p3, p4;
		p1 = num / 256 / 256 / 256;
		p2 = num / 256 / 256 % 256;
		p3 = num / 256 % 256;
		p4 = num % 256;
		cout << p1 << "." << p2 << "." << p3 << "." << p4 << endl;
	}
}
