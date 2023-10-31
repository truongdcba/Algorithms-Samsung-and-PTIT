// Cho một ngăn xếp các số nguyên. Các thao tác gồm 3 lệnh: push, pop và show. Trong đó thao tác push kèm theo một giá trị cần thêm (không quá 1000). Hãy viết chương trình ghi ra kết quả của các lệnh show.
// Input: Gồm nhiều dòng, mỗi dòng chứa một lệnh push, pop hoặc show. Input đảm bảo số lượng phần tử trong stack khi nhiều nhất cũng không vượt quá 200.
// Output: Ghi ra màn hình các phần tử đang có trong stack theo thứ tự lưu trữ mỗi khi gặp lệnh show. Các số viết cách nhau đúng một khoảng trống. Nếu trong stack không còn gì thì in ra dòng “empty”
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    stack<int> st;
    vector<int> v;

    while(cin >>s) {
        if(s=="push") {
            int x;
            cin >>x;
            st.push(x);
            v.push_back(x);
        }
        else if(s=="pop" && !st.empty()) {
            st.pop();
            v.pop_back();
        }
        else {  
            if(st.empty()) cout <<"empty";
            else {
                for(int it : v) cout <<it <<" ";
            }
            cout <<endl;
        }
    }
    return 0;
}