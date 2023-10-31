// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng tiền tố về dạng trung tố.
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// Output: Đưa ra kết quả mỗi test theo từng dòng.

#include <iostream>
#include <stack>

using namespace std;

string convertPrefixToInfix(string s) {
    stack<string> st;
    for(int i=s.size()-1;i>=0;i--) {
        if(isalpha(s[i])) {
            st.push(string(1,s[i]));
        }
        else {
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string res='(' + top1 + s[i] + top2 + ')';
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
        cout <<convertPrefixToInfix(s) <<endl;
    }
    return 0;
}