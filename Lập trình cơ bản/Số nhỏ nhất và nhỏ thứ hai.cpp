#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n];

        int min1=1e9,min2=1e9;
        for(int &x : arr) {
            cin >>x;
            min1=min(min1,x);
        }
        for(int i=0;i<n;i++) {
            if(arr[i]<min2 && arr[i]!=min1) min2=arr[i];
        }
        if(min2==1e9) cout <<-1 <<endl;
        else cout <<min1 <<" " <<min2 <<endl;
    }
    return 0;
}