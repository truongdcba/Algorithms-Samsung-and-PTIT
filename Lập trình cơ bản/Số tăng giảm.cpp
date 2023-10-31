// Một số được gọi là số tăng giảm nếu số đó có các chữ số thỏa mãn hoặc không giảm, hoặc không tăng từ trái qua phải. 
// Hãy kiểm tra xem một số có phải số tăng giảm hay không.

// Dữ liệu vào: Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng một số nguyên dương cần kiểm tra, không quá 500 chữ số.
// Kết quả: Mỗi bộ test viết ra chữ YES nếu đó đúng là số tăng giảm, chữ NO nếu ngược lại.
#include <bits/stdc++.h>

using namespace std;

bool check1(string s) {
    for(int i=1;i<s.size();i++) {
        if(s[i]<s[i-1]) return false;
    }
    return true;
}
bool check2(string s) {
    for(int i=1;i<s.size();i++) {
        if(s[i]>s[i-1]) return false;
    }
    return true;
}
int main() {
    int t;
    cin >>t;
    cin.ignore();

    while(t--) {
        string s;
        cin >>s;
        if(check1(s) || check2(s)) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
}