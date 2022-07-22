#include <iostream>

using namespace std;

int func_1(unsigned int num);
int func_2(unsigned int num);
int func_3(unsigned int num);
int func_4(unsigned int num);
int func_5(int i, int j, int k, int t);
int main(){
	unsigned int num;
	cin >> num;
	int i, j, k, t;

	i = func_1(num);
	j = func_2(num);
	k = func_3(num);
	t = func_4(num);
	cout << func_5(i, j, k, t) << endl;

	return 0;

}

int func_1(unsigned int num){
	return num / (256 * 256 * 256);
}

int func_2(unsigned int num){
	return ((num) / (256 * 256)) % 256;
}

int func_3(unsigned int num){
	return (num / 256) % 256;
}

int func_4(unsigned int num){
	return num % 256;
}

int func_5(int i, int j, int k, int t){
	int sum = i + j + k;
	while (sum >= 256){
		sum -= 256;
	}
	if (t == 255 - sum)
		return 1;
	else
		return 0;
}
