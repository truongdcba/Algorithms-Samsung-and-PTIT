// Cho xâu ký tự mã hóa str. Hãy viết chương trình giải mã xâu ký tự str. Xâu ký tự mã hóa được thực hiện theo số lần lặp các xâu con của str như sau:
// Xâu đầu vào: “abbbababbbababbbab ”
// Xâu mã hóa : "3[a3[b]1[ab]]"
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một xâu mã hóa str được viết trên một dòng.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc: T, str thỏa mãn ràng buộc: 1≤T≤100; 1≤length(str)≤100.
#include <bits/stdc++.h>

using namespace std;
string loop=""; // trường hợp test case là các số nhiều hơn 1 chữ số

string giaiMa(string s) {
    stack<string> st;

    for(int i=s.size()-1;i>=0;i--) {
        if(s[i]==']' || isalpha(s[i])) st.push(string(1,s[i]));
        else if(s[i]=='[') {
            string tmp="";
            while(st.top()!="]") {
                tmp+=st.top();
                st.pop();
            }
            st.pop();
            st.push(tmp);
        }
        else {
            loop+=s[i];
            if(!isdigit(s[i-1])) {
                string tmp="";
                reverse(loop.begin(),loop.end());
                int num=stoi(loop);
                for(int i=1;i<=num;i++) {
                    tmp+=st.top();
                }
                st.pop();
                st.push(tmp);
                loop="";
            }
        }
    }
    if(st.size()==1) return st.top();
    else {
        string res="";
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        return res;
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        string s;
        cin >>s;
        cout <<giaiMa(s) <<endl;
    }
    return 0;
}