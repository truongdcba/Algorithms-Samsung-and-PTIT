#include <bits/stdc++.h>

using namespace std;
int f[1000001];

int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        int n,maxValue=-1e9;
        cin >>n;
        int arr[n];

        for(int &x : arr) {
            cin >>x;
            maxValue=max(maxValue,x);
            f[x]++;
        }
        for(int i=1;i<=maxValue;i++) {
            if(f[i]%2!=0) {
                cout <<i <<endl;
                break;
            }
        }
    }
    return 0;
}