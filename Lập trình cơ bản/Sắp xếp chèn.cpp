#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];

    for(int i=0;i<n;i++) cin >>arr[i];
    for(int i=0;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j+1]<arr[j]) {
                swap(arr[j+1],arr[j]);
            }
            else break;
        }
        cout <<"Buoc " <<i <<": ";
        for(int j=0;j<=i;j++) cout <<arr[j] <<" ";
        cout <<endl;
    }
}