#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  int arr[n][n];
  int answer[2*n];

  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> arr[i][j];
    }
  }

  //아래로 이어붙히기
  int arr2[n*2][n];
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      arr2[i][j] = arr[i][j];
    }
  }
  for (int i=n;i<2*n;i++){
    for (int j=0;j<n;j++){
      arr2[i][j]= arr[i-n][j];
    }
  }
  // 배열 좌우 반전시키기 -> 역방향 주대각선 계산 쉽게하려고
  int i, j, tmp;
  int arr3[n*2][n];
  for (int i = 0; i < 2*n; i++) {
    if (n%2==0){
      for (int j = 0; j < n/2; j++) {
          tmp = arr2[i][j];
          arr3[i][j] = arr2[i][n-1-j];
          arr3[i][n-1-j] = tmp;
      }
    }
    else{
      for (int j = 0; j < n/2+1; j++) {
          tmp = arr2[i][j];
          arr3[i][j] = arr2[i][n-1-j];
          arr3[i][n-1-j] = tmp;
      }
    }
  }

  //정대각선
  for (int i=0;i<n;i++){
    int sum=0;
    for (int j=0;j<n;j++){
      sum+=arr2[i+j][j];
    }
    answer[i] = sum;
  }

 // 위에서 배열 좌우 반전했으니까 정대각선으로 구해도 됨!
  for (int i=0;i<n;i++){
    int sum=0;
    for (int j=0;j<n;j++){
      sum+=arr3[i+j][j];
    }
    answer[n+i] = sum;
  }

  int max=0;
  for (int i=0;i<2*n;i++){
    if (max<answer[i]){
      max= answer[i];
    }
  }

  cout << max << endl;
}
