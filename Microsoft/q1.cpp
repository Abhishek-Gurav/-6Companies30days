// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto x : tokens){
            if(x == "+"){
                int k = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(k+l);
                continue;
            }
            if(x == "-"){
                int k = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(l-k);
                continue;

            }
            if(x == "*"){
                int k = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(k*l);
                continue;

            }
            if(x == "/"){
                int k = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(l/k);
                continue;
            }
            st.push(stoi(x));
        }
        return st.top();
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    } 
    Solution ans;
    cout << ans.evalRPN(a) << endl;
}
