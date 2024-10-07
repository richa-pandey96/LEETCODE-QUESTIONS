class Solution {
public:
    //optimal solution
    int minLength(string s) {
        
          int n=s.length();
        
        int i=0;//write
        int j=1;//read
        
        while(j<n){
            if(i<0){
                i++;
                s[i]=s[j];
                
            }
            else if((s[i]=='A' && s[j]=='B')||
                   (s[i]=='C' && s[j]=='D')){
                i--;
            }else{
                i++;
                s[i]=s[j];
            }
            
            j++;
        }
        return i+1;
    }
};
//better approach
// int minLength(string s) {
        
//         stack<char> st;
        
//         for(char c: s){
//             if(!st.empty() && ((st.top()=='A' && c=='B') ||(st.top()=='C' && c=='D'))){
//                 st.pop();//remove the pair by popping the stack
//             }else{
//                 st.push(c);
//             }
//         }
//         return st.size();
//     }