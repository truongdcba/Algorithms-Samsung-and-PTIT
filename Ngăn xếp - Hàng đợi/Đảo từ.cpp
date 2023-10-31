// Cho một xâu ký tự str bao gồm nhiều từ trong xâu. Hãy đảo ngược từng từ trong xâu?
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một dòng ghi lại nhiều từ trong xâu str.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:
// T, str thỏa mãn ràng buộc: 1≤T≤100; 2≤length(str)≤106.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;
    cin.ignore();

    while(t--) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string tmp;

        while(ss >>tmp) {
            reverse(tmp.begin(),tmp.end());
            cout <<tmp <<" ";
        }
        cout <<endl;
    }
    return 0;
}