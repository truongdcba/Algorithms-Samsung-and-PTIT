// Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:
// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    stack<int> st;

    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') st.push(i);
        else if(s[i]==')') {
            if(i-st.top()==2 || (s[i-1]=='(' && s[st.top()+1]==')')) return false;
            st.pop();
        }
    }
    return true;
}
int main() {
    int t;
    cin >>t;
    cin.ignore();

    while(t--) {
        string s;
        getline(cin,s);

        if(check(s)) cout <<"No" <<endl;
        else cout <<"Yes" <<endl;
    }
    return 0;
}