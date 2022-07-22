#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int idx = 0;
    double arr[1350] = {0,};
    int n = 0;

    cin >> n ;

    for(int i=0; i<30; i++) {
        for(int j=0; j<19; j++) {
            for(int k=0; k<13; k++) {
                double number = pow(2, i) * pow(3, j) * pow(5, k);
                if(number <= 398590750) {
                    arr[idx] = number;
                    if(idx > 1350) break;
                    else idx++;
                }
            }
        }
    }
    sort(arr, arr+1350);

    cout<< int(arr[n-1]) <<endl;

    return 0;
}
