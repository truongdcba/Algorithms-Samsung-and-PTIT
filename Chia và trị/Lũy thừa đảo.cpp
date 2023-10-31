// Cho mảng số N. Ta gọi số đảo của N là R. Hãy tìm lũy thừa R của N. Đưa ra kết quả của bài toán dưới dạng modulo với 10^9 + 7.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là số N được ghi trên một dòng.
// T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10^10.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int mod=(int)1e9+7;

ll latNguoc(ll n) {
    ll number=0;
    while(n) {
        number=number*10+n%10;
        n/=10;
    }
    return number;
}
ll powMod(ll a,ll b) {
    if(b==0) return 1;
    ll res=powMod(a,b/2);
    if(b%2==0) return (res*res)%mod;
    else return ((res*res)%mod *a%mod)%mod;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        ll n;
        cin >>n;
        cout <<powMod(n,latNguoc(n)) <<endl;
    }
    return 0;
}