// Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.
// Input:
// Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
// T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
// Output:
// Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in đáp án theo thứ tự tăng dần.
#include <bits/stdc++.h>

using namespace std;

void sinh(int n) {
    queue<string> q;
    vector<string> v;
    q.push("6");
    q.push("8");
    v.push_back("6");
    v.push_back("8");

    while(1) {
        string top=q.front();
        if(top.size()==n) break;
        q.pop();
        q.push(top+"6");
        q.push(top+"8");
        v.push_back(top+"6");
        v.push_back(top+"8");
    }
    cout <<v.size() <<endl;
    for(string x : v) cout <<x <<" ";
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        sinh(n);
        cout <<endl;
    }
    return 0;
}