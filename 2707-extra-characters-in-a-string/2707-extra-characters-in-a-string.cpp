class Solution {
public:
    //)(n*n*n)
    //s.C:
    int solve(int i, string &s,unordered_set<string>& st, int &n, unordered_map<int, int> &mp) {
        if(i>=n){
            return 0;
        }
        
        if(mp.count(i)){
            return mp[i];
        }
        
        int result=1+solve(i+1,s,st,n,mp);
        
        for(int j=i;j<n;j++){
            string curr=s.substr(i, j-i+1);
            if(st.count(curr)){
                //valid substring
                result=min(result, solve(j+1,s,st,n,mp));
            }
        }
        return mp[i]=result;
    }
    int minExtraChar(string s, vector<string>& dict){
        int n=s.length();
        unordered_map<int, int>mp;
        unordered_set<string> st(begin(dict), end(dict));
        
        return solve(0,s,st,n, mp);
    }
};