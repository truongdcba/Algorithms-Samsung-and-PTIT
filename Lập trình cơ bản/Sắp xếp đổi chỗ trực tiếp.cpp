#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];

    for(int &x : arr) cin >>x;
    for(int i=0;i<n-1;i++) {
        cout <<"Buoc " <<i+1 <<": ";
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[i]) swap(arr[i],arr[j]);
        }
        for(int k=0;k<n;k++) cout <<arr[k] <<" ";
        cout <<endl;
    }
    return 0;
}