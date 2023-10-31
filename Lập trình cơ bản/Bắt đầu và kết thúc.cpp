// Viết chương trình kiểm tra một số nguyên dương bất kỳ (2 chữ số trở lên, không quá 9 chữ số) có chữ số bắt đầu và kết thúc bằng nhau hay không.

// Dữ liệu vào: Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng số nguyên dương tương ứng cần kiểm tra. 
// Kết quả: Mỗi bộ test viết ra YES hoặc NO, tương ứng với bộ dữ liệu vào
#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    return s[0]==s[s.size()-1];
}
int main() {
    int t;
    cin >>t;
    cin.ignore();

    while(t--) {
        string s;
        cin >>s;
        if(check(s)) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
}