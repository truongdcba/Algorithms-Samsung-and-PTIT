// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. 
//Phép hoán vị vủa một cách được xem là giống nhau. 
//Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T, N≤10.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int n,x[20];
vector<vector<int>> v;
vector<int> tmp;
int sum=0;

void Try(int i) {
    for(int j=n;j>=1;j--) {
        if(j<=x[i-1]) {
            x[i]=j;
            sum+=j;
            tmp.push_back(j);
            if(sum==n) v.push_back(tmp);
            else if(sum<n) Try(i+1);
            sum-=j;
            tmp.pop_back();
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        cin >>n;
        x[0]=1e9;
        Try(1);

        for(auto it : v) {
            cout <<"(";
            for(int i=0;i<it.size();i++) {
                if(i!=it.size()-1) cout <<it[i] <<" ";
                else cout <<it[i];
            }
            cout <<") ";
        }
        cout <<endl;
    }
}