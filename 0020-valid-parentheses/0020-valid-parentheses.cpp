class Solution {
public:
    bool isValid(string s) {
        
        if(s.size()==1) return false;
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(stk.size()==0){
                stk.push(s[i]);
            }
            else if(s[i]=='(' || s[i]=='{' or s[i]=='['){
                stk.push(s[i]);
            }
            else if(s[i]==')' and stk.top()=='('){
                stk.pop();
            }
            else if(s[i]=='}' and stk.top()=='{'){
                    stk.pop();
                }
            else if(s[i]==']' and stk.top()=='['){
                    stk.pop();
                }
            else{
                    stk.push(s[i]);
            }
            
        }
                  
        if(stk.size()==0) return true;
        else return false;
    }
};
    