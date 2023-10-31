// Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.

// Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không. Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test bắt đầu bằng số nguyên N và K (N ≤ 100 000, 0 ≤ K ≤ 10^6).
// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^6), các phần tử là riêng biệt.
// Output: 
// Với mỗi test in ra trên một dòng đáp án tìm được.
#include <iostream>

using namespace std;
int arr[100001];

int binarySearch(int k,int l,int r) {
    if(l>r) return -1;
    int mid=(l+r)/2;
    if(arr[mid]==k) return mid;
    else if(arr[mid]>k) return binarySearch(k,l,mid-1);
    else return binarySearch(k,mid+1,r);
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,k;
        cin >>n >>k;
        for(int i=1;i<=n;i++) cin >>arr[i];

        int res=binarySearch(k,1,n);
        if(res==-1) cout <<"NO" <<endl;
        else cout <<res <<endl;
    }
    return 0;
}