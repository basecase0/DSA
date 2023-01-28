#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        for(int i=0;i<numRows;i++){
            int icj=1;
            pascal[i].resize(i+1);
            for(int j=0;j<=i;j++){
                pascal[i][j]=icj;
                int icjp1=icj*(i-j)/(j+1);
                icj=icjp1;
            }
        }
        return pascal;
    }
};

int main(){
    int numRows=5;
    for(int i=0;i<numRows;i++){
        int icj=1;
        
        for(int j=0;j<=i;j++){
            cout<<icj<<" ";
            int icjp1=icj*(i-j)/(j+1);
            icj=icjp1;
        }
        cout<<endl;
    }
    Solution s1;
    vector<vector<int>> sol=s1.generate(5);
    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++){
            cout<<sol[i][j];
        }
        cout<<endl;
    }
}