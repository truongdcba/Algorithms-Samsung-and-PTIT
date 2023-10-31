// Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn:

// K không chứa chữ số 0
// Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần
// Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1. 
// Hãy liệt kê tất cả các số thỏa mãn theo thứ tự tăng dần.

// Input

// Dòng đầu ghi số bộ test (không quá 10)
// Mỗi bộ test là 1 số nguyên dương N (2 < N < 10)
// Output

// Liệt kê tất cả các số thỏa mãn, mỗi số trên một dòng.

// Sau mỗi test in ra một khoảng trống.
#include <bits/stdc++.h>

using namespace std;
bool visited[20];
int n;
string s;

bool check(string s) {
    for(int i=1;i<s.size();i++) {
        if(s[i]=='0' || abs(s[i]-s[i-1])==1) return false;
    }
    return true;
}
void Try(int i) {
    for(int j=1;j<=n;j++) {
        if(!visited[j]) {
            s+=to_string(j);
            visited[j]=true;
            if(i==n) {
                if(check(s)) cout <<s <<endl;
            }
            else Try(i+1);
            s.pop_back();
            visited[j]=false;
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        cin >>n;
        Try(1);
    }
    return 0;
}