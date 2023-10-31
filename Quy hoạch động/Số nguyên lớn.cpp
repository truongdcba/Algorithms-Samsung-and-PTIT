// Cho hai số nguyên lớn N và M có không quá 1000 chữ số. 
// Người ta muốn tính xem liệu có thể lấy ra nhiều nhất bao nhiêu chữ số trong N, 
// không cần liên tiếp nhau nhưng phải giữ nguyên thứ tự ban đầu để tạo ra một số X sao cho ta cũng có thể tìm thấy X trong số M theo cách tương tự.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, dòng thứ nhất ghi số N, dòng thứ 2 ghi số M.
// Output:  Với mỗi test, hãy in ra số chữ số nhiều nhất có thể của X.
#include <bits/stdc++.h>

using namespace std;
int f[1005][1005];
string s1,s2;

void dp(int n,int m) {
    f[0][0]=0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        cin >>s1 >>s2;
        
        int n=s1.size(), m=s2.size();
        s1='@'+s1;
        s2='@'+s2;
        dp(n,m);
        cout <<f[n][m] <<endl;
    }
}