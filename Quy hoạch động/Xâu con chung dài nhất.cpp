// Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). 
// Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.
// Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.
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