// Cho mảng A[] gồm n-1 phần tử bao gồm các khác nhau từ 1, 2, .., n. Hãy tìm số không có mặt trong mảng A[].

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n l; 
// dòng tiếp theo đưa vào n-1 số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, n, A thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10^7.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;

int find(int n,int arr[]) {
    int l=1,r=n;
    int res=-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(arr[mid]==mid) {
            l=mid+1;
        }
        else {
            res=mid;
            r=mid-1;
        }
    }
    return res;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n+1];

        for(int i=1;i<=n-1;i++) cin >>arr[i];
        cout <<find(n,arr) <<endl;
    }
}