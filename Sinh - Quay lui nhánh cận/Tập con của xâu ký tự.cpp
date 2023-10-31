// Cho một xâu ký tự S không có ký tự lặp lại. Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự từ điển.
// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.
// T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
string s;
vector<string> v;
string tmp="";

void Try(int i,int index) {
    for(int j=index;j<s.size();j++) {
        tmp+=s[j];
        v.push_back(tmp);
        if(i<s.size()-1) Try(i+1,j+1);
        tmp.pop_back();
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        v.clear();
        cin >>s;
        
        Try(0,0);
        sort(v.begin(),v.end());
        for(string x : v) cout <<x <<" ";
        cout <<endl;
    }
}