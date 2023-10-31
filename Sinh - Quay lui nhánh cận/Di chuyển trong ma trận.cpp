// Cho ma trận A[M][N]. Nhiệm vụ của bạn là đưa ra tất cả các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1]. 
// Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N tương ứng với số hàng và số cột của ma trận; dòng tiếp theo đưa vào các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
// T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 1≤M, N, A[i][j]≤100.
// Output:
// Đưa ra số cách di chuyển của mỗi test theo từng dòng.

#include <bits/stdc++.h>

using namespace std;
int m,n,arr[105][105],dem=0;
pair<int,int> d[2] = {{0,1},{1,0}};

void Try(int i,int j) {
    for(int k=0;k<2;k++) {
        int i1=i+d[k].first, j1=j+d[k].second;
        if(i1>=1 && i1<=m && j1>=1 && j1<=n) {
            if(i1==m && j1==n) dem++;
            else Try(i1,j1);
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        dem=0;
        cin >>m >>n;
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) cin >>arr[i][j];
        }
        Try(1,1);
        cout <<dem <<endl;
    }
    return 0;
}