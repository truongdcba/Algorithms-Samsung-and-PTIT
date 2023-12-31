// Cho một xâu chỉ gồm các kí tự ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’. Một dãy ngoặc đúng được định nghĩa như sau:
// -     Xâu rỗng là 1 dãy ngoặc đúng.
// -     Nếu A là 1 dãy ngoặc đúng thì (A), [A], {A} là 1 dãy ngoặc đúng.
// -     Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.
// Cho một xâu S. Nhiệm vụ của bạn là xác định xâu S có là dãy ngoặc đúng hay không?
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000.
// Output: 
// Với mỗi test, in ra “YES” nếu như S là dãy ngoặc đúng, in ra “NO” trong trường hợp ngược lại.
#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    stack<char> st;
    
    for(char x : s) {
        if(x=='(' || x=='[' || x=='{') st.push(x);
        else {
            if(st.empty()) return false;
            else {
                if(x==')' && st.top()!='(') return false; 
                else if(x==']' && st.top()!='[') return false; 
                else if(x=='}' && st.top()!='{') return false; 
                st.pop();
            }
        }
    }
    return st.empty();
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        string s;
        cin >>s;

        if(check(s)) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}