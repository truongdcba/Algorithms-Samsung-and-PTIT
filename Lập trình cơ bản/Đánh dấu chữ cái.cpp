#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >>s;
    set<char> se;

    for(char it : s) se.insert(it);
    cout <<se.size();
}