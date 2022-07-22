#include <iostream>
#include <string>

using namespace std;

int hw_1(unsigned int num1);
int hw_2(unsigned int num1, unsigned int num2);

int main(){
	unsigned int num1, num2;
	cin >> num1 >> num2;
	cout << hw_1(num1) << " " << hw_1(num2) << " " << hw_2(num1, num2) << endl;
}
int hw_1(unsigned int num)
{
	int cnt = 0;
	while (num / 2.0 != 0)
	{
		if (num == 1)
		{
			cnt += 1;
			break;
		}
		if (num % 2 == 1)
			cnt += 1;
		num /= 2;
	}
	return cnt;
}

int hw_2(unsigned int num1, unsigned int num2)
{
	int cnt = 0;
	for (int i = 0; i < 32; i++)
	{
		if (num1 % 2 != num2 % 2)
			cnt++;
		num1 /= 2;
		num2 /= 2;
	}
	return cnt;
}
