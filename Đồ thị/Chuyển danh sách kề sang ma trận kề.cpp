// Cho đơn đồ thị vô hướng có n đỉnh dưới dạng danh sách kề.

// Hãy biểu diễn đồ thị bằng ma trận kề.
// Input: Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 ≤  n ≤  1000). 
// n dòng tiếp theo, dòng thứ i chứa các số nguyên là các đỉnh kề với đỉnh i.  
// Output:  Ma trận kề của đồ thị.
#include <bits/stdc++.h>

using namespace std;
int arr[1001][1001];

int main() {
    int n;
    cin >>n;
    cin.ignore();
    
    for(int i=1;i<=n;i++) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string tmp;

        while(ss >>tmp) {
            arr[i][stoi(tmp)]=1;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout <<arr[i][j] <<" ";
        cout <<endl;
    }
    return 0;
}