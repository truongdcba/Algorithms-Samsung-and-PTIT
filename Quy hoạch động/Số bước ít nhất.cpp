// Cho mảng A[] gồm N số nguyên. Nhiệm vụ của bạn là sắp xếp lại mảng số với số lượng bước là ít nhất. 
// Tại mỗi bước, bạn chỉ được phép chèn phần tử bất kỳ của mảng vào vị trí bất kỳ trong mảng. 
// Ví dụ A[] = {2, 3, 5, 1, 4, 7, 6 }sẽ cho ta số phép chèn ít nhất là 3 bằng cách lấy số 1 chèn trước số 2, lấy số 4 chèn trước số 5, 
//lấy số 6 chèn trước số 7 ta nhận được mảng được sắp.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N; dòng tiếp theo đưa vào N số của mảng A[]; 
//các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤1000; 1≤A[i] ≤1000.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n];

        for(int i=0;i<n;i++) cin >>arr[i];
        vector<int> v;
        v.push_back(arr[0]);

        for(int i=1;i<n;i++) {
            if(arr[i]>=v[v.size()-1]) v.push_back(arr[i]);
            else {
                auto it=upper_bound(v.begin(),v.end(),arr[i]);
                *it=arr[i];
            }
        }
        cout <<n-v.size() <<endl;
    }
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int t;
//     cin >>t;
    
//     while(t--) {
//         int n;
//         cin >>n;
//         int arr[n];
    
//         for(int i=0;i<n;i++) cin >>arr[i];
//         vector<int> v;
        
//         for(int i=0;i<n;i++) {
//             auto it=upper_bound(v.begin(),v.end(),arr[i]);
//             if(it==v.end()) v.push_back(arr[i]);
//             else *it=arr[i];
//         }
//         cout <<n-v.size() <<endl;
//     }
// }