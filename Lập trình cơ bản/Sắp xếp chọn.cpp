#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];

    for(int &x : arr) cin >>x;
    for(int i=0;i<n-1;i++) {
        cout <<"Buoc " <<i+1 <<": ";
        int index=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[index]) {
                index=j;
            }
        }
        if(index!=i) swap(arr[i],arr[index]);
        for(int j=0;j<n;j++) cout <<arr[j] <<" ";
        cout <<endl;
    }
    return 0;
}