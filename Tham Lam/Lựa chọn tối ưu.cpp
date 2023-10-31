// Bạn được giao cho N công việc, công việc thứ i có thời gian bắt đầu là A[i] và kết thúc tại B[i]. 
// Tại một thời điểm, bạn chỉ có thể làm một công việc.
// Bạn hãy lựa chọn các công việc một cách tối ưu sao cho số công việc làm được là nhiều nhất.
// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).
// N dòng tiếp theo, mỗi dòng gồm 2 số A[i] và B[i] (0 ≤ A[i] < B[i] ≤ 10^6).
// Output:  Với mỗi test, in ra đáp án trên một dòng.
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b);

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
        int dem=0,timeEnd=-1;

        for(auto it : v) {
            if(it.first>=timeEnd) {
                dem++;
                timeEnd=it.second;
            }
        }
        cout <<dem <<endl;
    }
    return 0;
}
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.second<b.second;
}