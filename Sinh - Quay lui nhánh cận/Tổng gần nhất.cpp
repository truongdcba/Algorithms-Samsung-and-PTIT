// Cho dãy số A[] có N số nguyên dương và số M.
// Hãy chọn ra 3 số trong dãy A[] sao cho tổng 3 số đó nhỏ hơn M nhưng gần với M nhất.
// In ra tổng 3 số tìm được.
// Input
// Dòng đầu ghi số bộ test (không quá 10)
// Mối test có hai dòng. Dòng đầu ghi 2 số N và M (1 ≤ N ≤ 100; 10 ≤ M ≤ 300000). Dòng thứ 2 ghi N số của dãy số A[]. 
// Các số đều nguyên dương và không quá 6 chữ số.
// Input đảm bảo luôn có ít nhất một bộ ba số có tổng nhỏ hơn M.
// Output
// Mỗi test ghi giá trị tổng của 3 số tìm được trên một dòng.
#include <bits/stdc++.h>

using namespace std;
int n,m,arr[101];
int sum=0,res=-1;

void Try(int i,int index) {
    for(int j=index;j<=n;j++) {
        sum+=arr[j];
        if(i==3 && sum<=m) res=max(res,sum);
        else if(i<3 && sum<m) Try(i+1,j+1);
        sum-=arr[j];
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        res=-1;
        cin >>n >>m;
        for(int i=1;i<=n;i++) cin >>arr[i];
        Try(1,1);
        cout <<res <<endl;
    }
    return 0;
}