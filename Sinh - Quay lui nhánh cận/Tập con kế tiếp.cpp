// Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử tiếp theo của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 4} thì tập con tiếp theo của X[] là {2, 3, 5}.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
// T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <iostream>

using namespace std;

void next(int n,int k,int arr[]) {
    int i=k;
    while(i>=1 && arr[i]==n-k+i) {
        i--;
    }
    if(i==0) {
        for(int j=1;j<=k;j++) arr[j]=j;
    }
    else {
        arr[i]++;
        for(int j=i+1;j<=k;j++) arr[j]=arr[j-1]+1;
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,k;
        cin >>n >>k;
        int arr[n];

        for(int i=1;i<=k;i++) cin >>arr[i];
        next(n,k,arr);
        for(int i=1;i<=k;i++) cout <<arr[i] <<" ";
        cout <<endl;
    }
    return 0;
}