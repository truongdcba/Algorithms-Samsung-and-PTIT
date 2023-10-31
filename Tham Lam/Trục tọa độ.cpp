// Trên trục Ox tính từ vị trí 0, người ta muốn xếp nhiều nhất các đoạn thẳng sao cho không đoạn nào chồng lấn lên nhau. 
// Đoạn thẳng thứ i có vị trí bắt đầu là X1[i] và kết thúc tại X2[i], với X1[i] <= X2[i].

// Hãy tính số đoạn thẳng nhiều nhất có thể được lựa chọn để đưa lên trục Ox và không có đoạn nào chồng lấn lên nhau.
// Input
// Dòng đầu tiên ghi số bộ test, không quá 10.
// Với mỗi bộ test: dòng đầu ghi số N là số đoạn thẳng (không quá 10^5)
// Tiếp theo là N dòng, mỗi dòng có 2 số nguyên mô tả đoạn thẳng. Các giá trị tọa độ đều là các số nguyên không âm và không quá 106.
// Output
// Với mỗi test, viết trên 1 dòng số lượng đoạn thẳng nhiều nhất có thể được lựa chọn thỏa mãn điều kiện đề bài.
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.second<b.second;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++) {
            int x,y;
            cin >>x >>y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end(),cmp);
        int dem=0,end=-1;
        for(auto it : v) {
            if(it.first>=end) {
                dem++;
                end=it.second;
            }
        }
        cout <<dem <<endl;
    }
    return 0;
}