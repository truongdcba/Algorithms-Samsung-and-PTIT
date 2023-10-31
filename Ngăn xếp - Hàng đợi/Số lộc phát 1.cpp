// Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.
// Input:
// Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
// T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
// Output:
// In ra đáp án theo thứ tự giảm dần.
#include <bits/stdc++.h>

using namespace std;
int n;
string s="68";
vector<string> v;
string tmp="";

void Try(int i) {
    for(int j=0;j<=1;j++) {
        tmp+=s[j];
        v.push_back(tmp);
        if(tmp.size()<n) Try(i+1);
        tmp.pop_back();
    }
}
bool cmp(string a,string b) {
    if(a.size()!=b.size()) return a.size()>b.size();
    return a>b;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        cin >>n;
        
        Try(1);
        sort(v.begin(),v.end(),cmp);
        for(string it : v) cout <<it <<" ";
        cout <<endl;
    }
    return 0;
}