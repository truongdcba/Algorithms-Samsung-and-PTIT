// Có N ngôi nhà trên một dãy phố, mỗi ngôi nhà chứa đựng một số lượng tài sản khác nhau. 
// Một tên trộm muốn ăp cắp được nhiều nhất tài sản của dãy phố nhưng không muốn lấy tài sản của hai nhà kề nhau. 
// Hãy cho biết, bằng cách đó tên trộm có thể đánh cắp được nhiều nhất bao nhiêu tài sản.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N là số lượng ngôi nhà; 
// dòng tiếp theo đưa vào N số là tài sản tương ứng trong mỗi ngôi nhà; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤10^6; 1≤A[i] ≤10^7.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void dp(int n,int arr[],ll f[]) {
    f[0]=0;
    f[1]=arr[1];
    for(int i=2;i<=n;i++) {
        f[i]=max(f[i-1],f[i-2]+arr[i]);
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n+1];
        ll f[n+1];

        for(int i=1;i<=n;i++) cin >>arr[i];
        dp(n,arr,f);
        cout <<f[n] <<endl;
    }
    return 0;
}