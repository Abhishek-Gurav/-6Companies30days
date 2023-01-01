#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(int i, int k, int n, vector<int> &ds, vector<vector<int>> &ans)
    {
        
        if(n == 0 && k == 0){
            ans.push_back(ds);
            return;
        }
        if(k == 0 || i == 0){
            return;
        }
        
        f(i-1, k, n, ds, ans);
        if(i > n){
            return;
        }
        ds.push_back(i);
        f(i-1, k-1, n-i, ds, ans);
        ds.pop_back();
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int s = 0;
        int i = k;
        int l = 9;
        while(i--){
            s+=l;
            l--;
        }
        if(n > s){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> ds;
        f(9, k, n, ds, ans);
        return ans;
    }
};
int main(){
    int n, k;
    cin >> n >> k;
    Solution ans;
    for(auto x : ans.combinationSum3(k,n)){
        for(auto m : x){
            cout << m << " ";
        }
        cout << endl;
    }
}