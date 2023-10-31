// Cho xâu ký tự S bao gồm các ký tự in thường và số D. 
// Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để tất cả các ký tự giống nhau đều có khoảng cách là D hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số D; dòng tiếp theo là xâu S.
// T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤D≤100.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;

vector<pair<char,int>> v;
bool visited[10001];

bool cmp(pair<char,int> a,pair<char,int> b) {
    return a.second>b.second;
}
bool check(int d,string s) {
    for(auto it : v) {
        int tmp=it.second,check=0;
        for(int i=0;i<s.size();!visited[i]?visited[i]=true,i+=d:i++) {           
            if(!visited[i]) {
                tmp--;
            }
            if(tmp==0) {
                check=1;
                break;
            }
        }
        if(check==0) return false;
    }
    return true;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        memset(visited,false,sizeof(visited));
        int d;
        string s;
        cin >>d >>s;
        map<char,int> mp;

        for(char x : s) mp[x]++;
        for(auto it : mp) v.push_back({it.first,it.second});
        sort(v.begin(),v.end(),cmp);

        if(check(d,s)) cout <<1 <<endl;
        else cout <<-1 <<endl;
    }
    return 0;
}