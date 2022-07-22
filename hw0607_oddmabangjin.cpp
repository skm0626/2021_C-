#include<cstdio>
#include<cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int MAX;
	cin >> MAX;
	int list[100][100] = { 0, };
	int i, j, k, t, p;
	j = 1;
	k = MAX / 2 + 1;
	for (i = 1; i < MAX*MAX + 1; i++)
	{
		j = j - 1;
		k = k - 1;

		while (j < 0)
		{
			j = j + MAX;
		}
		while (k < 0)
		{
			k = k + MAX;
		}
		if (list[j][k] == 0)
			list[j][k] = i;
		else
		{
			while (list[j][k] != 0)
			{
				j = j + 2;
				k = k + 1;
				while (j > MAX - 1)
				{
					j = j - MAX;
				}
				while (k > MAX - 1)
				{
					k = k - MAX;
				}
			}
			list[j][k] = i;

		}
	}

	for (t = 0; t < MAX; t++)
	{
		for (p = MAX - 1; p >= 0; p--)
		{
			cout << list[t][p] << " ";
		}
		cout << endl;
	}
}
