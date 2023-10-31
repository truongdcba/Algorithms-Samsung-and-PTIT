// Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.
// T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <iostream>

using namespace std;

void next(int n,int arr[]) {
    int i=n-1;
    while(i>=1 && arr[i]>arr[i+1]) i--;
    if(i==0) {
        for(int j=1;j<=n;j++) arr[j]=j;
    }
    else {
        for(int j=n;j>i;j--) {
            if(arr[j]>arr[i]) {
                swap(arr[j],arr[i]);
                break;
            }
        }
        int l=i+1,r=n;
        while(l<r) {
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n+1];

        for(int i=1;i<=n;i++) cin >>arr[i];
        next(n,arr);
        for(int i=1;i<=n;i++) cout <<arr[i] <<" ";
        cout <<endl;
    }
    return 0;
}