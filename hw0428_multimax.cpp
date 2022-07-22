#include <iostream>
#include<algorithm>

using namespace std;

bool desc(int a, int b){
  return a > b;
}

int main(){
  int n;
  cin >> n;
  int arr[n]={0,};
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  sort(arr,arr+n,desc);

  int two_sum=1;
  int third_sum=1;
  int two_sum_mi =0;
  int third_sum_mi = 0;
  int count=0;
  int answer=0;

  for (int i=0;i<2;i++){
    two_sum = two_sum * arr[i];
  }
  for (int i=0;i<3;i++){
    third_sum = third_sum * arr[i];
  }
  for (int i=0;i<n;i++){
    if (arr[i]<0) count++;
  }
  if (count>=2){
    two_sum_mi =1;
    third_sum_mi = 1;
    for (int i=n-1;i>n-3;i--){
      two_sum_mi = two_sum_mi * arr[i];
    }
    third_sum_mi = two_sum_mi * arr[0];
  }
  // cout << count << endl;
  // cout << two_sum << "," <<third_sum << endl;
  // cout << two_sum_mi << ", " << third_sum_mi << endl;
  answer = max(two_sum, third_sum);
  answer = max(answer, two_sum_mi);
  answer = max(answer, third_sum_mi);
  cout << answer << endl;
}
