#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,k;
        cin >>n >>k;
        int arr[n];

        for(int i=0;i<n;i++) cin >>arr[i];
        sort(arr,arr+n);
        long long dem=0;
        for(int i=0;i<n;i++) {
            auto it1=lower_bound(arr+i+1,arr+n,k-arr[i]);
            auto it2=upper_bound(arr+i+1,arr+n,k-arr[i]);
            dem+=it2-it1;
        }
        cout <<dem <<endl;
    }
    return 0;
}