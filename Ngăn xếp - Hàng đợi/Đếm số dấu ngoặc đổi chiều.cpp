// Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).
// Output: 
// Với mỗi test, in ra đáp án tìm được trên một dòng.
#include <bits/stdc++.h>

using namespace std;

void minReverse(string s) {
    stack<char> st;
    int dem1=0; //đếm số dấu đóng ngoặc dư thừa
    int dem2=0; //đếm số dấu mở ngoặc dư thừa

    for(char x : s) {
        if(x=='(') st.push(x);
        else {
            if(st.empty()) dem1++;
            else st.pop();
        }
    }
    dem2=st.size();
    if(dem1%2==0 && dem2%2==0) cout <<dem1/2+dem2/2;
    else cout <<dem1/2+dem2/2+2;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        string s;
        cin >>s;
        minReverse(s);
        cout <<endl;
    }
    return 0;
}