#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

int minInsAndDel(int A[], int B[], int n, int m){
    unordered_set<int> x(B, B+m);
    vector<int> s;
    for(int i=0;i<n;i++){
        if(x.find(A[i]) != x.end()){
            s.push_back(A[i]);
        }
    }
    vector<int> y;
    for (auto e : s) {
        auto q = lower_bound(y.begin(), y.end(), e);
        if (q != y.end())
            *q = e;
        else
            y.push_back(e);
    }
    int maxCount = y.size();
    return (m+n)-(2*maxCount);
}

int main(){
    int n,m;
    cin >> n;
    int* A = new int[n]; 
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cin >> m;
    int* B = new int[m];
    for(int i=0;i<m;i++){
        cin >> B[i];
    }
    cout << minInsAndDel(A,B,n,m);
}