// Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:

// -     Xâu rỗng là 1 dãy ngoặc đúng.

// -     Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.

// -     Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.
// Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.
// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm một xâu S có độ dài không vượt quá 105 kí tự.
// Output:  Với mỗi test in ra một số nguyên là độ dài dãy ngoặc đúng dài nhất tìm được.
#include <bits/stdc++.h>

using namespace std;
int f[100001];

void addIndex(string s) {
    stack<int> st;

    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') st.push(i);
        else if(!st.empty()) {
            f[st.top()]=st.top();
            st.pop();
            f[i]=i;
        }
    }
}
int findMaxLength(int size) {
    int length=0,dem=1;
    for(int i=1;i<size;i++) {
        if(f[i]-1==f[i-1]) dem++;
        else {
            length=max(length,dem);
            dem=1;
        }
    }
    if(dem!=1) length=max(length,dem); // TH test case ((()
    return length;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,-1,sizeof(f));
        string s;
        cin >>s;
        addIndex(s);
        cout <<findMaxLength(s.size()) <<endl;
    }
    return 0;
}