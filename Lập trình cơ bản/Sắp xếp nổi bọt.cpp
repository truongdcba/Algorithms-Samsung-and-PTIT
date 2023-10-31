#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];

    for(int &x : arr) cin >>x;
    for(int i=0;i<n;i++) {
        bool check=false;
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                check=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(check==false) break;
        cout <<"Buoc " <<i+1 <<": ";
        for(int k=0;k<n;k++) cout <<arr[k] <<" ";
        cout <<endl;
    }
    return 0;
}