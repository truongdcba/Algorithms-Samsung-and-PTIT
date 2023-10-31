// Cho một biểu thức toán học với các dấu ngoặc đơn, các toán hạng và các toán tử.

// Với mỗi cặp dấu ngoặc đúng, hãy thay thế dấu mở ngoặc ( thành số 0 và dấu đóng ngoặc thành số 1.
// Với các vị trí dấu ngoặc không đúng thì thay thế bằng số -1
// Ví dụ biểu thức  ((a+b)- (c+d) thì sẽ được thay thế thành -10a+b1-0c+d1
// Input
// Dòng đầu ghi số bộ test.
// Mỗi bộ test sẽ viết trên một dòng biểu thức có độ dài không quá 1000.
// Output
// Với mỗi bộ test, viết trên một dòng xâu ký tự sau khi đã thay thế dấu ngoặc.
#include <bits/stdc++.h>

using namespace std;

string convert(string s) {
    string res=s;
    stack<int> st;

    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') st.push(i);
        else if(s[i]==')') {
            if(st.empty()) res[i]='@';
            else {
                res[i]='1';
                res[st.top()]='0';
                st.pop();
            }
        }
    }
    while(!st.empty()) {
        res[st.top()]='@';
        st.pop();
    }
    return res;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        string s;
        cin >>s;
        string res=convert(s);
        for(int i=0;i<res.size();i++) {
            if(res[i]=='@') cout <<-1;
            else cout <<res[i];
        }
        cout <<endl;
    }
    return 0;
}
