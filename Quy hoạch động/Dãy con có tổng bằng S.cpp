// Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. 
// Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

// Input: Dòng đầu ghi số bộ test T (T<10).  
// Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). 
// Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).
// Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”
#include <bits/stdc++.h>

using namespace std;
bool f[201][40001];

void dp(int n,int s,int arr[]) {
    for(int i=0;i<=n;i++) f[i][0]=true;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=s;j++) {
            if(j>=arr[i]) f[i][j]=f[i-1][j] || f[i][j-arr[i]];
            else f[i][j]=f[i-1][j];
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,false,sizeof(f));
        int n,s;
        cin >>n >>s;
        int arr[n+1];

        for(int i=1;i<=n;i++) cin >>arr[i];
        dp(n,s,arr);
        if(f[n][s]) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}