// Cho một biểu thức đúng, tức là các dấu ngoặc đơn đều đầy đủ mở và đóng, đảm bảo đúng thứ tự. 
// Hãy viết chương trình đánh số các cặp dấu ngoặc theo thứ tự xuất hiện, tính từ 1.

// Ví dụ với biểu thức    (a + (b *c) ) + (d/e)
// ta có thứ tự của các cặp ‘(‘, ‘)’ là   1  2  2  1  3  3
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T (không quá 100).
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một biểu thức số học được đưa vào trên một dòng, độ dài không quá 10^6.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int f[1000005];

void solve(string s) {
    stack<pair<int,int>> st;
    int dem=0;

    for(int i=1;i<s.size();i++) {
        if(s[i]=='(') {
            dem++;
            st.push({i,dem});
        }
        else {
            f[st.top().first]=f[i]=st.top().second;
            st.pop();
        }
    }
}
int main() {
    int t;
    cin >>t;
    cin.ignore();

    while(t--) {
        memset(f,0,sizeof(f));
        string a;
        getline(cin,a);
        string s;
        s='@'+s;

        for(int i=0;i<a.size();i++) {
            if(a[i]=='(' || a[i]==')') s+=a[i];
        }
        solve(s);
        for(int i=1;i<s.size();i++) cout <<f[i] <<" ";
        cout <<endl;
    }
    return 0;
}