// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng hậu tố về dạng tiền tố.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:
// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
#include <bits/stdc++.h>

using namespace std;

string convertSuffixesToPrefix(string s) {
    stack<string> st;

    for(char x : s) {
        if(isalpha(x)) {
            st.push(string(1,x));
        }
        else {
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string res=x+top2+top1;
            st.push(res);
        }
    }
    return st.top();
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        string s;
        cin >>s;
        cout <<convertSuffixesToPrefix(s) <<endl;
    }
    return 0;
}