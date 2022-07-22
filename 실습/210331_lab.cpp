#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void init_array(int *a, int n){
  srand(20181630);
  for (int i = 0; i < n; i++){ //10회
    int random = rand() % 100+1;
    a[i]=random;
  }
}

int sum_array1(int *a, int n){
  int sum=0;
  for (int i=0;i< n;i++){
    sum+=a[i];
  }
  return sum;
}

void sum_array2(int *a, int n, int *s){
  *s=0;
  for (int i=0;i< n;i++){
    *s+=a[i];
  }
}

void sum_array3(int *a, int n, int &s){
  s=0;
  for (int i=0;i<n;i++){
    s+=a[i];
  }
}

int main(int argc, char *argv[]){
  if (argc < 2){
    cout << "one command line argument need\n";
  }
  int n = atoi(argv[1]);
  n = (n<1)?1 :n;
  n = (n>10)?10 :n;

  int *a= new int[n];
  if (!a){
    cout << "allocation failed.\n";
  }

  int s;

  init_array(a,n);
  for (int i=0;i<n;i++){
    cout << a[i] << " ";
  }

  s = sum_array1(a,n);
  cout << endl << s << endl;

  sum_array2(a,n,&s);
  cout << s << endl;

  sum_array3(a,n,s);
  cout << s <<endl;
  return 0;
}
