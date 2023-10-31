// Cho xâu ký tự S. Ta gọi giá trị của xâu S là tổng bình phương số lần xuất hiện mỗi ký tự trong S. 
// Hãy tìm giá trị nhỏ nhất của xâu S sau khi thực hiện K lần loại bỏ ký tự.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số K; phần thứ hai là một xâu ký tự S được viết trên một dòng.
// T, S, K thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤K≤1000.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int k;
        string s;
        cin >>k >>s;
        priority_queue<int> q;
        map<char,int> mp;

        for(char x : s) mp[x]++;
        for(auto it : mp) q.push(it.second);

        while(k--) {
            int top=q.top();
            if(top==0) break;
            q.pop();
            top--;
            q.push(top); 
        }
        
        int sum=0;
        while(!q.empty()) {
            int top=q.top();
            sum+=top*top;
            q.pop();
        }
        cout <<sum <<endl;
    }
    return 0;
}