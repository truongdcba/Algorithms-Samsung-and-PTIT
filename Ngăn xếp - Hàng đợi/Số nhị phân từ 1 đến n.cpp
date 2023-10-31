// Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n.
// Input:
// Dòng đầu tiên ghi lại số lượng test T (T≤100).
// Mỗi test là một số tự nhiên n được ghi trên một dòng (n≤10000).
// Output:
// Đưa ra kết quả mỗi test trên một dòng.

#include <bits/stdc++.h>

using namespace std;
vector<string> v;

void sinh() {
    queue<string> q;
    q.push("1");
    v.push_back("1");

    while(!q.empty()) {
        string top=q.front();
        q.pop();
        if(top.size()==14) break;
        q.push(top+"0");
        q.push(top+"1");
        v.push_back(top+"0");
        v.push_back(top+"1");
    }
}
int main() {
    int t;
    cin >>t;
    sinh();

    while(t--) {
        int n;
        cin >>n;

        for(int i=1;i<=n;i++) {
            cout <<v[i-1] <<" ";
        }
        cout <<endl;
    }
    return 0;
}