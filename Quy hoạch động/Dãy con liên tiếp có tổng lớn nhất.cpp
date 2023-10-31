// Cho mảng A[] gồm N số có cả các số âm và số dương. Nhiệm vụ của bạn là tìm mảng con liên tục có tổng lớn nhất của mảng. 
// Ví dụ với mảng A[]={-2, -5, 6, -2,-3, 1, 5, -6} ta có kết quả là 7 tương ứng với dãy con {6, -2, -3, 1, 5}.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào hai số N tương ứng với số phần tử của mảng; 
// dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤100; -100≤A[i] ≤100.
// Output:
// Đưa ra tổng con liên tục lớn nhất của mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int f[101][101];

int dp(int n,int arr[]) {
    int res=-1e9;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            f[i][j]=f[i][j-1]+arr[j];
            res=max(res,f[i][j]);
        }
    }
    return res;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        int n;
        cin >>n;
        int arr[n+1];

        for(int i=1;i<=n;i++) cin >>arr[i];
        cout <<dp(n,arr) <<endl;
    }
    return 0;
}