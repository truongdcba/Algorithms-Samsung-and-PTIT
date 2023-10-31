// Cho dãy số A[] gồm có N phần tử.
// Một dãy con liên tiếp được gọi là dãy tam giác nếu như dãy đó tăng dần rồi lại giảm dần, 
// hay tồn tại i, j, k sao cho A[i] ≤ A[i+1] ≤ … ≤ A[k] ≥ A[k+1] ≥ … ≥ A[j].

// Nhiệm vụ của bạn là hãy tìm dãy con liên tiếp là dãy tam giác có độ dài lớn nhất.
// Lưu ý: Dãy đơn điệu không giảm hoặc không tăng cũng là dãy tam giác. Ví dụ A[] = {10, 20, 30, 40} là một dãy tam giác.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm số nguyên N(1≤ N ≤ 100 000).
// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^6).
// Output: 
// Với mỗi test, in ra trên một dòng là độ dài của dãy con tìm được.
#include <bits/stdc++.h>

using namespace std;
int f1[100005],f2[100005];

void dp1(int n,int arr[]) {
    for(int i=1;i<=n;i++) {
        if(arr[i]>arr[i-1]) f1[i]=f1[i-1]+1;
        else f1[i]=1;
    }
}
void dp2(int n,int arr[]) {
    for(int i=n;i>=1;i--) {
        if(arr[i]>arr[i+1]) f2[i]=f2[i+1]+1;
        else f2[i]=1;
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n+1];

        for(int i=1;i<=n;i++) cin >>arr[i];
        dp1(n,arr);
        dp2(n,arr);

        int res=0;
        for(int i=1;i<=n;i++) {
            res=max(res,f1[i]+f2[i]-1);
        }
        cout <<res <<endl;
    }
    return 0;
}