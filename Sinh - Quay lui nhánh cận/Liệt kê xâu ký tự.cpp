// Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

// Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.
// Xem ví dụ để hiểu thêm yêu cầu đề bài.
// Input
// Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.
// Output
// Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.
#include <bits/stdc++.h>

using namespace std;
char c;
int k;
vector<string> v;
string s="ABCDEFGHIJ",tmp="";

void Try(int i,int index) {
    for(int j=index;j<=(c-'A');j++) {
        tmp+=s[j];
        if(i==k) {
            v.push_back(tmp);
        }
        else Try(i+1,j);
        tmp.pop_back();
    }
}
int main() {
    cin >>c >>k;
    Try(1,0);
    for(string x : v) cout <<x <<endl;
    return 0;
}