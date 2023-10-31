// Cho số nguyên dương N.

// Nhiệm vụ của bạn là hãy xác định xem có bao nhiêu ước số của N chia hết cho 2.
// Input:Dòng đầu tiên là số lượng bộ test T (T ≤ 100). Mỗi bộ test gồm một số nguyên N (1 ≤ N ≤ 109)
// Output:  Với mỗi test, in ra đáp án tìm được trên một dòng.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int dem=0;

        for(int i=1;i<=sqrt(n);i++) {
            if(n%i==0) {
                if(i%2==0) dem++;
                if(i!=n/i && n/i%2==0) dem++;
            }
        }
        cout <<dem <<endl;
    }
    return 0;
}