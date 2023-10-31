// Cho một dãy các số nguyên dương không quá 9 chữ số, mỗi số cách nhau một khoảng trống. 
// Hãy tìm các số chỉ bao gồm các chữ số nguyên tố và đếm số lần xuất hiện của các số đó.

// Input: Gồm không quá 50000 số nguyên dương, các số đều không quá 9 chữ số.
// Output: Ghi ra các số chỉ có các chữ số nguyên tố kèm theo số lần xuất hiện. 
// Các số được liệt kê theo thứ tự xuất hiện (tức là số nào xuất hiện trước in ra trước).
#include <bits/stdc++.h>

using namespace std;

bool check(int n) {
    while(n) {
        int tmp=n%10;
        if(tmp!=2 && tmp!=3 && tmp!=5 && tmp!=7) return false;
        n/=10;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<int> v;
    map<int,int> mp;

    while(cin >>n) {
        if(check(n)) {
            if(mp.find(n)==mp.end()) v.push_back(n);
            mp[n]++;
        }
    }
    for(auto it : v) {
        cout <<it <<" " <<mp[it] <<endl;
        
    }
    return 0;
}