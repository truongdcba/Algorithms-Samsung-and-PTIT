// Cho mảng A[] gồm n số nguyên dương. Gọi L, R là min và max các phần tử của A[].
// Nhiệm vụ của bạn là tìm số phần tử cần thiết cần thêm vào mảng để mảng có đầy đủ các số trong khoảng [L, R]. Ví dụ A[] = {5, 7, 9, 3, 6, 2 } ta nhận được kết quả là 2 tương ứng với các số còn thiếu là 4, 8.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, tương ứng với số phần tử của mảng A[]; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.
// T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3  ; A[i] ≤10^6
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int f[1000001];

int find(int arr[],int l,int r) {
    int dem=0;
    for(int i=l;i<=r;i++) {
        if(!f[i]) dem++;
    }
    return dem;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        int n,minValue=1e9,maxValue=-1;
        cin >>n;
        int arr[n];

        for(int &x : arr) {
            cin >>x;
            f[x]=1;
            minValue=min(minValue,x);
            maxValue=max(maxValue,x);
        }
        cout <<find(arr,minValue,maxValue) <<endl;
    }
    return 0;
}