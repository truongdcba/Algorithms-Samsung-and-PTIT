// Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n. 

// Dữ liệu vào: dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ liệu ghi một số nguyên dương n duy nhất không qua 10^18. 
// Kết quả: Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư của kết quả tìm được khi chia cho 123456789.
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int mod=123456789;

ll powMod(ll a ,ll b) {
    if(b==0) return 1;
    ll res=powMod(a,b/2);
    if(b%2==0) {
        return (res*res)%mod;
    }
    else return ((res*res)%mod * a%mod)%mod;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        ll n;
        cin >>n;
        cout <<powMod(2,n-1) <<endl;
    }
    return 0;
}