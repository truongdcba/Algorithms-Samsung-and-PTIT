// Cho đơn đồ thị G vô hướng liên thông được mô tả bởi danh sách kề. Hãy in ra danh sách cạnh tương ứng của G.

// Input
// Dòng đầu tiên ghi số N là số đỉnh (1
// N dòng tiếp theo mỗi dòng ghi 1 danh sách kề lần lượt theo thứ tự từ đỉnh 1 đến đỉnh N
// Output: Ghi ra lần lượt từng cạnh của đồ thị theo thứ tự tăng dần.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    vector<pair<int,int>> v;

    for(int i=i;i<=n;i++) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string tmp;
        while(ss >>tmp) {
            if(stoi(tmp)>i) {
                v.push_back({i,stoi(tmp)});
            }
        }
    }
    for(auto it : v) cout <<it.first <<" " <<it.second <<endl;
    return 0;
}