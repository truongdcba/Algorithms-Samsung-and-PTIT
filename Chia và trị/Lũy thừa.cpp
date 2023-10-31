// Cho hai số nguyên không âm a và b. Hãy tính a^b.

// Nếu kết quả quá lớn hãy chia dư cho 10^9 + 7.
// Input
// Gồm không quá 20 bộ test, mỗi test ghi trên một dòng hai số a,b; a không quá 9 chữ số, b không quá 18 chữ số.
// Input kết thúc khi a = b = 0
// Output
// Với mỗi test ghi ra kết quả tính được trên một dòng.
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int mod=(int)1e9+7;

ll powMod(ll a,ll b) {
    if(b==0) return 1;
    ll res=powMod(a,b/2);
    if(b%2==0) return (res*res)%mod;
    else return ((res*res)%mod * a%mod)%mod;
}
int main() {
    ll a,b;
    while(1) {
        cin >>a >>b;
        if(a==0 && b==0) break;
        
        cout <<powMod(a,b) <<endl;
    }
    return 0;
}