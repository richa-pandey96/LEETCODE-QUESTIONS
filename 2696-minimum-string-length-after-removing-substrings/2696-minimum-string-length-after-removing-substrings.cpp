class Solution {
public:
    int minLength(string s) {
        
        stack<char> st;
        
        for(char c: s){
            if(!st.empty() && ((st.top()=='A' && c=='B') ||(st.top()=='C' && c=='D'))){
                st.pop();//remove the pair by popping the stack
            }else{
                st.push(c);
            }
        }
        return st.size();
    }
};