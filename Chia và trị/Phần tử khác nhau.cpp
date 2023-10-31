// Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. 
// Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số N; dòng tiếp theo đưa vào N số của mảng A[];
// dòng tiếp theo đưa vào N-1 số của mảng B[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤10^7; 0≤ A[i]≤10^18.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <iostream>

using namespace std;
#define ll long long
ll a1[1000005],a2[1000005];
int res;

void find(int l,int r) {
    if(l>r) return;
    int mid=(l+r)/2;
    if(a1[mid]!=a2[mid]) {
        res=mid;
        find(l,mid-1);
    }
    else find(mid+1,r);
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        for(int i=1;i<=n;i++) cin >>a1[i];
        for(int i=1;i<=n-1;i++) cin >>a2[i];
        find(1,n);
        cout <<res <<endl;
    }
    return 0;
}