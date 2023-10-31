// Khu dân cư ABC tiến hành bầu tổ trưởng dân phố. Có M ứng viên và N cử tri. Người dân trong khu dân cư đã chán ngấy với việc các ứng viên vận động tranh cử, câu kéo phiếu bầu trong các nhiệm kỳ trước nên họ quyết định đặt ra quy định mới như sau:

// Các ứng viên được đánh số từ 1 tới M. Mỗi cử tri sẽ viết ra đúng 1 số thứ tự ứng viên mình muốn chọn và bỏ vào hòm phiếu.
// Người trúng cử là người có số phiếu bầu nhiều thứ hai
// Nếu không có người đứng thứ hai thì kết quả bầu cử sẽ bị hủy bỏ
// Nếu có nhiều hơn 1 người cùng có số phiếu nhiều thứ hai thì người nào có số thứ tự nhỏ nhất sẽ được chọn.
// Viết chương trình xác định người trúng cử.

// Input

// Dòng đầu ghi hai số N và M (1 < M < 10, 5 < N < 500).

// Dòng thứ 2 ghi N giá trị trong các phiếu bầu. Các giá trị đảm bảo hợp lệ (tức là từ 1 đến M).

// Output

// Ghi ra số thứ tự của người trúng cử.

// Hoặc nếu không có ai trúng cử thì ghi ra NONE
#include <bits/stdc++.h>

using namespace std;

bool check(map<int,int> mp) {
    auto it=mp.begin();
    int tmp=(*it).second;
    for(auto it : mp) {
        if(it.second!=tmp) return true;
    }
    return false;
}
int main() {
    int n,m;
    cin >>n >>m;
    int arr[n];
    map<int,int> mp;

    for(int i=0;i<n;i++) {
        cin >>arr[i];
        mp[arr[i]]++;
    }
    if(!check(mp)) cout <<"NONE";
    else {
        int top1=0,top2=0,key;
        for(auto it : mp) {
            top1=max(top1,it.second);
        }
        for(auto it : mp) {
            if(it.second>top2 && it.second!=top1) {
                key=it.first;
                top2=it.second;
            }
        }
        cout <<key;
    }
    return 0;
}