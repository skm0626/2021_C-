#include <iostream>
using namespace std;

int main(){
  int r,s,t;
  cin >> r >> s >> t;
  int a,b;
  int A[r][s]={0};
  int B[s][t]={0};
  int ans[r][t];

  for (int i=0;i<r;i++){
    for (int j=0;j<s;j++){
      cin >> a;
      A[i][j]=a;
    }
  }

  for (int i=0;i<s;i++){
    for (int j=0;j<t;j++){
      cin >> b;
      B[i][j]=b;
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<t;j++){
      ans[i][j]=0;
      for(int k=0;k<s;k++){
        ans[i][j] += A[i][k]*B[k][j];
      }
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<t;j++){
      cout << ans[i][j] << " ";
    }
    cout<<endl;
  }
  return 0;
}
