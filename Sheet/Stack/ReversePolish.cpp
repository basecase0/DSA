#include<bits/stdc++.h>
using namespace std;

class Solution {    // postfix evaluation

public:
    int operation(int a,int b,string optor){
        if(optor=="+"){
            return a+b;
        }
        else if(optor=="-"){
            return a-b;
        }
        else if(optor=="*"){
            return a*b;
        }
        else{
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;  // postfix evaluation
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"|| tokens[i]=="-"|| tokens[i]=="*" || tokens[i]=="/"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                int res=operation(num1,num2,tokens[i]);
                st.push(res);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        int ans=st.top();
        return ans;
    }
};