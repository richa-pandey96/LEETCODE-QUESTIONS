class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
        string ans=strs[0];
        for(auto s:strs){
            string temp="";
            for(int i=0;i<min(ans.length(),s.length());i++){
                if(ans[i]==s[i]){
                    temp.push_back(s[i]);
                }
                else{
                    break;
                }
                
                
                
            }
            ans=temp;
            if(ans.empty()){
                break;
            }
        }
        return ans;
        
    }
};