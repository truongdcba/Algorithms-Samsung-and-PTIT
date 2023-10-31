// Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6. 
// Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ.

// Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi ít nhất để đưa bảng đến trạng thái đích.
// Input:
// Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm hai dòng:
// Dòng đầu tiên chứa 6 số là trạng thái bảng ban đầu (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
// Dòng thứ hai chứa 6 số là trạng thái bảng đích (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
// Output: 
// Với mỗi test, in ra một số nguyên là đáp số của bài toán.
#include <bits/stdc++.h>

using namespace std;

string left(string tmp) {
    char index1=tmp[0], index2=tmp[1], index3=tmp[3], index4=tmp[4];
    tmp[0]=index3;
    tmp[1]=index1;
    tmp[3]=index4;
    tmp[4]=index2;
    return tmp;
}
string right(string tmp) {
    char index1=tmp[1], index2=tmp[2], index3=tmp[4], index4=tmp[5];
    tmp[1]=index3;
    tmp[2]=index1;
    tmp[4]=index4;
    tmp[5]=index2;
    return tmp;
}
int convert(string s,string t) {
    queue<pair<string,int>> q;
    q.push({s,0});
    set<string> se;
    se.insert(s);

    while(!q.empty()) {
        pair<string,int> top=q.front();
        q.pop();
        if(top.first==t) return top.second;
        
        string top1=left(top.first), top2=right(top.first);
        if(se.find(top1)==se.end()) {
            q.push({top1,top.second+1});
            se.insert(top1);
        }
        if(se.find(top2)==se.end()) {
            q.push({top2,top.second+1});
            se.insert(top2);
        }
    }
}
int main() {
    int t;
    cin >>t;
    
    while(t--) {
        string start,final;    
        for(int i=0;i<6;i++) {
            char x;
            cin >>x;
            start+=x;
        }
        for(int i=0;i<6;i++) {
            char x;
            cin >>x;
            final+=x;
        }
        cout <<convert(start,final) <<endl;
    }
    return 0;
}