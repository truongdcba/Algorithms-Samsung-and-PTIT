// Trong lập trình cơ bản, một từ được hiểu là một dãy ký tự liên tiếp không chứa khoảng trống, dấu tab hoặc dấu xuống dòng.

// Hãy xác định tập hợp các từ khác nhau trong một xâu ký tự, sau khi đã chuyển hết về dạng chữ thường. 
// Sau đó nhập hai dòng ký tự và hiển thị hợp và giao của hai tập từ tương ứng.
// Input
// Chỉ có 2 dòng, mỗi dòng có độ dài không quá 1000 ký tự.
// Output
// Dòng 1 ghi hợp của 2 tập từ theo thứ tự từ điển
// Dòng 2 ghi giao của 2 tập từ theo thứ tự từ điển.
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1,s2;
    set<string> se1 ,se2,se3;

    getline(cin,s1);
    getline(cin,s2);
    stringstream ss1(s1);
    string tmp;
    while(ss1 >>tmp) {
        for(int i=0;i<tmp.size();i++) {
            if(isupper(tmp[i])) tmp[i]=tolower(tmp[i]);
        }
        se1.insert(tmp);
        se3.insert(tmp);
    }
    stringstream ss2(s2);
    while((ss2 >>tmp)) {
        for(int i=0;i<tmp.size();i++) {
            if(isupper(tmp[i])) tmp[i]=tolower(tmp[i]);
        }
        se2.insert(tmp);
        se3.insert(tmp);
    }
    for(string it : se3) cout <<it <<" ";
    cout <<endl;
    for(string it : se1) {
        if(se2.find(it)!=se2.end()) cout <<it <<" ";
    }
    return 0;
}