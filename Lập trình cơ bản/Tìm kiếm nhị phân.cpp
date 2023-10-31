// Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.

// Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không. Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test bắt đầu bằng số nguyên N và K (N ≤ 100 000, 0 ≤ K ≤ 10^6).
// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^6), các phần tử là riêng biệt.
// Output: 
// Với mỗi test in ra trên một dòng đáp án tìm được.
#include <bits/stdc++.h>

using namespace std;

int find(int n,int k,int arr[]) {
    int l=1,r=n;
    while(l<=r) {
        int mid=(l+r)/2;
        if(arr[mid]==k) return mid;
        else if(arr[mid]>k) r=mid-1;
        else l=mid+1;
    } 
    return -1;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,k;
        cin >>n >>k;
        int arr[n+1];

        for(int i=1;i<=n;i++) cin >>arr[i];
        int res=find(n,k,arr);
        if(res!=-1) cout <<res <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}