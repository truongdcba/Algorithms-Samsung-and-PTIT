// Cho bảng A[] kích thước N x M (N hàng, M cột).
// Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].
// Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm số nguyên dương N và M (1 < N, M < 500)
// N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).
// Output: 
// Với mỗi test, in ra giá trị tổng điểm nhỏ nhất tìm được trên một dòng.
#include <bits/stdc++.h>

using namespace std;
int arr[501][501],f[501][501];

void path(int n,int m) {
    f[0][0]=0;
    for(int i=1;i<=n;i++) f[i][0]=1e9;
    for(int i=1;i<=m;i++) f[0][i]=1e9;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            f[i][j]=min({f[i-1][j-1],f[i-1][j],f[i][j-1]})+arr[i][j];
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        int n,m;
        cin >>n >>m;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) cin >>arr[i][j];
        }
        path(n,m);
        cout <<f[n][m] <<endl;
    }
    return 0;
}