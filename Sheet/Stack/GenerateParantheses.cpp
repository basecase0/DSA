class Solution {
private:
    void backTrack(vector<string> &ans,string res,int open,int close,int n){
        if(open==n&&close==n){
            ans.push_back(res);
            return;
        }
        if(open<n){
            backTrack(ans,res+"(",open+1,close,n);
        }
        if(close<open){
            backTrack(ans,res+")",open,close+1,n);  // during call close=3
            // here close=2. and res is without ")".
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTrack(ans,"",0,0,n);
        return ans;
    }
};