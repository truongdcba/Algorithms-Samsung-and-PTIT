// Cho biểu thức P chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’. Biểu thức P có thể viết đúng hoặc không đúng. Nhiệm vụ của bạn là tìm tổng độ dài lớn nhất của các biểu thức con viết đúng trong P (các biểu thức đúng không nhất thiết phải liên tiếp nhau).

// Chú ý: Độ dài của biểu thức đúng ngắn nhất là 2.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T (không quá 100)
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức P được viết trên một dòng (độ dài của P không quá 100).
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int f[101];

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
int find(int size) {
    int length=0;
    for(int i=0;i<size;i++) {
        if(f[i]!=-1) length++;
    }
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
        cout <<find(s.size()) <<endl;
    }
    return 0;
}