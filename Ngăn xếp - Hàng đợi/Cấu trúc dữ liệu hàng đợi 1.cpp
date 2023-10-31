// Ban đầu cho một queue rỗng. Bạn cần thực hiện các truy vấn sau:
// 1.Trả về kích thước của queue
// 2.Kiểm tra xem queue có rỗng không, nếu có in ra “YES”, nếu không in ra “NO”.
// 3.Cho một số nguyên và đẩy số nguyên này vào cuối queue.
// 4.Loại bỏ phần tử ở đầu queue nếu queue không rỗng, nếu rỗng không cần thực hiện.
// 5.Trả về phần tử ở đầu queue, nếu queue rỗng in ra -1.
// 6.Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.
// Dữ liệu vào
// Dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ theo dạng sau.
// Dòng đầu tiên chứa số nguyên n - lượng truy vấn (1 ≤ n ≤ 1000)
// N dòng tiếp theo, mỗi dòng sẽ ghi loại truy vấn như trên, với truy vấn loại 3 sẽ có thêm một số nguyên, không quá 106.
// Kết quả: In ra kết quả của các truy vấn..
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        queue<int> q;
        vector<int> v;

        while(n--) {
            int x;
            cin >>x;

            if(x==1) {
                cout <<q.size() <<endl;
            }
            else if(x==2) {
                q.empty()?cout <<"YES" <<endl:cout <<"NO" <<endl;
            }
            else if(x==3) {
                int y;
                cin >>y;
                q.push(y);
                v.insert(v.begin(),y);
            }
            else if(x==4 && !q.empty()) {
                q.pop();
                v.pop_back();
            }
            else if(x==5) {
                !q.empty()?cout <<q.front() <<endl:cout <<-1 <<endl;
            }
            else if(x==6) {
                !q.empty()?cout <<v[0] <<endl:cout <<-1 <<endl;
            }
        }
    }
    return 0;
}