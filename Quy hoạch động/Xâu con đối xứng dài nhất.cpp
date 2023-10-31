// Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

// Hãy tìm xâu con đối xứng dài nhất của S.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.
// Output:  Với mỗi test, in ra đáp án tìm được.
#include <bits/stdc++.h>

using namespace std;
int f[1001][1001];

void solve(string s) {
    //khởi tạo độ dài dãy con đối xứng có 1 phần tử
    for(int i=1;i<s.size();i++) f[i][i]=1;
    // Từ dãy con có 2 phần tử đến có n phần tử (n là độ dài của cả dãy ban đầu)
    for(int length=2;length<s.size();length++) {
        int index=s.size()-length; //Vị trí bắt đầu cuối cùng của 1 dãy con có độ dài là length
        for(int i=1;i<=index;i++) {
            int j=i+length-1;
            if(length==2 && s[i]==s[j]) f[i][j]=length;
            else if(length!=2 && s[i]==s[j] && f[i+1][j-1]) {
                f[i][j]=length;
            }  
        }
    }
}
int main() {
    int t;
    cin >>t;
    
    while(t--) {
        memset(f,0,sizeof(f));
        string s;
        cin >>s;
        s='@'+s;
        solve(s);

        int maxLength=0;
        for(int i=1;i<s.size();i++) {
            for(int j=i;j<s.size();j++) maxLength=max(maxLength,f[i][j]);
        }
        cout <<maxLength <<endl;
    }
    return 0;
}