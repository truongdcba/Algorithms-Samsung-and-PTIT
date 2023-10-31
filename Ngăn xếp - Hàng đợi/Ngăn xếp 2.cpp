// Yêu cầu bạn xây dựng một stack với các truy vấn sau đây:
// “PUSH x”: Thêm phần tử x vào stack (0 ≤ x ≤ 1000).
// “PRINT”: In ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.
// “POP”: Xóa phần tử đầu tiên của stack. Nếu stack rỗng, không làm gì cả.
// Input:
// Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).
// Mỗi truy vấn có dạng như trên.
// Output: 
// Với mỗi truy vấn “PRINT”, hãy in ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >>q;
    stack<int> st;

    while(q--) {
        string s;
        cin >>s;

        if(s=="PUSH") {
            int x;
            cin >>x;
            st.push(x);
        }
        else if(s=="PRINT") {
            st.empty()?cout <<"NONE" <<endl:cout <<st.top() <<endl;
        }
        else {
            if(!st.empty()) st.pop();
        }
    }
    return 0;
}