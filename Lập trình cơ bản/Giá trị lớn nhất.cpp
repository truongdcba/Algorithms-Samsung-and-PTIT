// Cho dãy số nguyên A[] có N phần tử.

// Gọi f(i,j) = |ai| + |ai+1| + … + |aj|
// Gọi g(i,j) = ai + ai+1 + … + aj
// Với tất cả các cặp 1 ≤ i ≤ j ≤ N.
// Hãy tính giá trị lớn nhất của f(i,j) + g(i,j).
// Input
// Dòng đầu ghi số N (1 ≤ N ≤ 50000)
// Dòng thứ 2 ghi N số nguyên của dãy A[]
// Output
// Ghi ra giá trị lớn nhất của f(i,j) + g(i,j)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];
    long long sum=0;

    for(int &x : arr) cin >>x;
    sort(arr,arr+n,greater<int>());
    for(int i=0;i<n;i++) {
        if(arr[i]<=0) break;
        sum+=arr[i];
    }
    cout <<2*sum;
    return 0;
}