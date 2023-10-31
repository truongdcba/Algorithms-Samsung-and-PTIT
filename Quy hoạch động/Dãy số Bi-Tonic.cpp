// Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần.
// Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[].
// Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số phần tử của dãy A[]; 
// dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 0≤A[i] ≤100.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int f1[105],f2[105];

void dp1(int n,int arr[]) {
    for(int i=0;i<n;i++) {
        f1[i]=arr[i];
        for(int j=0;j<i;j++) {
            if(arr[j]<arr[i]) f1[i]=max(f1[i],f1[j]+arr[i]);
        }
    }
}
void dp2(int n,int arr[]) {
    for(int i=n-1;i>=0;i--) {
        f2[i]=arr[i];
        for(int j=n-1;j>i;j--) {
            if(arr[j]<arr[i]) f2[i]=max(f2[i],f2[j]+arr[i]);
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n];
        for(int i=0;i<n;i++) cin >>arr[i];
        dp1(n,arr);
        dp2(n,arr);

        int res=0;
        for(int i=0;i<n;i++) {
            res=max(res,f1[i]+f2[i]-arr[i]);
        }
        cout <<res <<endl;
    }
    return 0;
}