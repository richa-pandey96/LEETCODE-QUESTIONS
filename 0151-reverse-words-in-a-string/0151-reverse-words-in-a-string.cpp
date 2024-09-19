class Solution {
public:
    string reverseWords(string s) {
        
        //reverse whole string
        reverse(s.begin(),s.end());
        
        int i=0;
        
        //use l ,r for reversing words
        int l=0,r=0;
        
        int n=s.length();
        
        while(i<n){
            while(i<n && s[i]!=' '){// if i gets a char it will give to r then i++ and r++
                s[r++]=s[i++];
                
                
            }
            if(l<r){//reverse l to r
                reverse(s.begin()+l,s.begin()+r);
                
                s[r]=' ';
                r++;
                l=r;
            }
            i++;//i will keep increasing
        }
        s=s.substr(0,r-1);
        
        return s;
        
    }
};