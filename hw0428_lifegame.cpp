#include <iostream>

using namespace std;

bool isEmpty(int vacteria);
bool isFull(int vacteria);
int* lifegame(int arr[], int size, int time);

int main() {
	int arr[100];
	int *result;
	int size, time;
	cin >> size >> time;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	result = lifegame(arr, size, time);
	for (int j = 0; j < size; j++) {
		cout << result[j] << " ";
	}
	cout << endl;
}

bool isEmpty(int  vacteria) {
	if (vacteria == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool isFull(int vacteria) {
	if (vacteria == 9) {
		return true;
	}
	else {
		return false;
	}
}

int* lifegame(int arr[], int size, int time) {
	int arr2[100];
	for (int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}

	for (int i = 0; i < time; i++) {
		for (int j = 0; j < size; j++) {
			if (j == 0) {
				if (arr2[j + 1] > 3 && arr2[j + 1] <= 7) {
					if (!isFull(arr2[j])) {
						arr[j] = arr[j] + 1;
					}
				}
				else if (arr2[j + 1] < 3 || arr2[j + 1]>7) {
					if (!isEmpty(arr2[j])) {
						arr[j] = arr[j] - 1;
					}
				}
			}
			else if (j == size - 1) {
				if (arr2[j - 1] > 3 && arr2[j - 1] <= 7) {
					if (!isFull(arr2[j])) {
						arr[j] = arr[j] + 1;
					}
				}
				else	if (arr2[j - 1] < 3 || arr2[j - 1]>7) {
					if (!isEmpty(arr2[j])) {
						arr[j] = arr[j] - 1;
					}
				}
			}
			else {
				int midvacte = arr2[j + 1] + arr2[j - 1];
				if (midvacte > 3 && midvacte <= 7) {
					if (!isFull(arr2[j])) {
						arr[j] = arr[j] + 1;
					}
				}
				else if (midvacte < 3 || midvacte>7) {
					if (!isEmpty(arr2[j])) {
						arr[j] = arr[j] - 1;
					}
				}
			}
		}
		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}
	}
	return arr;
}
