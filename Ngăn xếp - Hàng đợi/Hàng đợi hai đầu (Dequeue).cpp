// Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:
// “PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue (0 ≤ x ≤ 1000).
// “PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”.
// “POPFRONT”: Xóa phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả.
// “PUSHBACK x”: Thêm phần tử x vào cuối của dequeue (0 ≤ x ≤ 1000).
// “PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”.
// “POPBACK”: Xóa phần tử cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.
// Dữ liệu vào:
// Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).
// Mỗi truy vấn có dạng như trên.
// Kết quả: 
// Với mỗi truy vấn “PRINTFRONT” và “PRINTBACK”, hãy in ra kết quả trên một dòng.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;
    deque<int> q;

    while(t--) {
        string s;
        cin >>s;

        if(s=="PUSHFRONT") {
            int x;
            cin >>x;
            q.push_front(x);
        }
        else if(s=="PRINTFRONT") {
            !q.empty()?cout <<q.front() <<endl:cout <<"NONE" <<endl;
        }
        else if(s=="POPFRONT") {
            if(!q.empty()) q.pop_front();
        }
        else if(s=="PUSHBACK") {
            int x;
            cin >>x;
            q.push_back(x);
        }
        else if(s=="PRINTBACK") {
            !q.empty()?cout <<q.back() <<endl:cout <<"NONE" <<endl;
        }
        else {
            if(!q.empty()) q.pop_back();
        }
    }
    return 0;
}