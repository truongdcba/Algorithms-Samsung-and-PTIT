// Cho dãy số A[] gồm có N phần tử và số nguyên K.
// Với mỗi dãy con liên tiếp có độ dài bằng K (từ trái sang phải), bạn hãy in ra phần tử lớn nhất trong dãy con này.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 1 ≤ K ≤ N).
// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).
// Output: 
// Với mỗi test, in ra trên một dòng N-K+1 số nguyên là đáp án tìm được.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,k;
        cin >>n >>k;
        int arr[n];

        for(int i=0;i<n;i++) {
            cin >>arr[i];
        }
        multiset<int> ms;
        //khoi tao cua so dau tien
        for(int i=0;i<k;i++) ms.insert(arr[i]);
        cout <<*(ms.rbegin()) <<" ";
        //tu cac cua so sau tro di
        for(int i=k;i<n;i++) {
            auto it=ms.find(arr[i-k]);
            ms.erase(it);
            ms.insert(arr[i]);
            cout <<*(ms.rbegin()) <<" ";
        }
        cout <<endl;
    }
    return 0;
}