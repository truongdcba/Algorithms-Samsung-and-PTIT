// Một số Smith là một số tự nhiên thỏa mãn tổng các chữ số của nó bằng với tổng các chữ số của các nhân tử. 
// Một vài số Smith đó là 4, 22, 27, 58, 85, 94, …
// Nhiệm vụ của bạn là hãy xác định xem số nguyên N đã cho có là số Smith hay không?

// Ví dụ 1:
// 378 = 2 x 3 x 3 x 3 x 7
// Tổng các chữ số là 3 + 7 + 8 = 18.
// Tổng các chữ số của các nhân tử là 2 + 3 + 3 + 3 + 7 = 18.
// Ví dụ 2:
// 4937775 = 3 x 5 x 5 x 65837.
// Ta có 4+9+3+7+7+7+5 = 42 = 3+5+5+6+5+8+3+7.
// Input
// Dòng đầu ghi số bộ test.
// Mỗi test là một số nguyên dương N (1 < N < 2^32).
// Output
// In ra “YES” nếu số đã cho là số Smith, in ra “NO” trong trường hợp ngược lại.
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int sum(ll n) {
    int res=0;
    while(n) {
        res+=n%10;
        n/=10;
    }
    return res;
}
bool check(ll n) {
    int res1=sum(n),res2=0;
    for(int i=2;i<=sqrt(n);i++) {
        while(n%i==0) {
            res2+=sum(i);
            n/=i;
        }
    }
    if(n!=1) res2+=sum(n);
    return res1==res2;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        ll n;
        cin >>n;
        if(check(n)) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}