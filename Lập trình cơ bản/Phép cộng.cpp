// Cho một phép toán có dạng a + b = c với a,b,c chỉ là các số nguyên dương có một chữ số. Hãy kiểm tra xem phép toán đó có đúng hay không.

// Dữ liệu vào: Dòng đầu ghi số bộ test. Mỗi test chỉ có một dòng ghi ra phép toán (gồm đúng 9 ký tự)
// Kết quả: Ghi ra YES nếu phép toán đó đúng. Ghi ra NO nếu sai.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;
    cin.ignore();
    
    while(t--) {
        string s;
        getline(cin,s);
        int num1,num2,num3;
        num1=stoi(string(1,s[0]));
        num2=stoi(string(1,s[4]));
        num3=stoi(string(1,s[8]));

        if(num1+num2==num3) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
}