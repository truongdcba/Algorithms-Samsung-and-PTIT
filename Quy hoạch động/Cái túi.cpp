// Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo (N≤1000), 
// mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). 
// Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.

// Input
// Dòng đầu ghi số bộ test T (T<10)
// Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng A. Sau đó là một dòng ghi N số của mảng C.
// Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.
// Output
// Với mỗi bộ test, ghi trên một dòng giá trị lớn nhất có thể đạt được.
#include <bits/stdc++.h>

using namespace std;
int f[1001][1001];

void dp(int n,int v,int a[],int c[]) {
    f[0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=v;j++) {
            if(j>=a[i]) f[i][j]=max(f[i-1][j-a[i]]+c[i],f[i-1][j]);
            else f[i][j]=f[i-1][j];
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        int n,v;
        cin >>n >>v;
        int a[n+1],c[n+1];

        for(int i=1;i<=n;i++) cin >>a[i];
        for(int i=1;i<=n;i++) cin >>c[i];
        dp(n,v,a,c);
        cout <<f[n][v] <<endl;
    }
    return 0;
}