#include <iostream>

using namespace std;

int main(){
	int m,n;
	int a,b;
	cin >> m >> n;
	int arr1[m][n]={0};
	int arr2[m][n]={0};

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> a;
			arr1[i][j]=a;
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> b;
			arr2[i][j]=b;
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << arr1[i][j] + arr2[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}
