// Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. 
// Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
// Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
// Output: 
// Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 10^9+7.
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int t;
    cin >>t;
    int mod=(int)1e9+7;

    while(t--) {
        int n,k;
        cin >>n >>k;
        int f[n+1]={0};

        f[0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=k;j++) {
                if(i>=j) {
                    f[i]+=f[i-j];
                    f[i]%=mod;
                }
                else break;
            }
        }
        cout <<f[n] <<endl;
    }
    return 0;
}