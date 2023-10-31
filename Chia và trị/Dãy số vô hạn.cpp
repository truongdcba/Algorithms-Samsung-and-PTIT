// Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau: 
// Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

// Ví dụ với 2 bước biến đổi, ta có [1] à [1 2 1] à [1 2 1 3 1 2 1]. Hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?
// Input:  Dòng đầu tiên là số lượng bộ test T (T ≤ 20).  Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 50, 1 ≤ K ≤ 2^N - 1).
// Output:  Với mỗi test, in ra đáp án trên một dòng.
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll powMod(ll a,ll b) {
    if(b==0) return 1;
    ll res=powMod(a,b/2);
    if(b%2==0) return res*res;
    else return res*res*a;
}
int find(int n,ll k) {
    ll index=powMod(2,n-1);
    if(k==index) return n;
    else if(k<index) return find(n-1,k);
    else return find(n-1,k-index);
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        ll k;
        cin >>n >>k;
        cout <<find(n,k) <<endl;
    }
    return 0;
}