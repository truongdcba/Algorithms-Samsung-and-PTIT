// Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 109+7.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).
// Output: 
// Với mỗi test, in ra đáp án trên một dòng.
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll arr[1001][1001];
int mod=(int)1e9+7;

void sinh() {
    for(int i=0;i<=1000;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0 || i==j) arr[i][j]=1;
            else arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
            arr[i][j]%=mod;
        }
    }
}
int main() {
    int t;
    cin >>t;
    sinh();

    while(t--) {
        int n,k;
        cin >>n >>k;

        cout <<arr[n][k] <<endl;
    }
    return 0;
}