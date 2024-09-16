class Solution {
public:
    bool isPalindrome(string s) {
        
        int start=0, end= s.size()-1;
        
        while(start<=end){
            // Move start pointer if it's not alphanumeric
            
            if(!isalnum(s[start])){
                start++;
                
            }
            // Move end pointer if it's not alphanumeric
            else if(!isalnum(s[end])){
                end--;
            }
             // If both are alphanumeric, compare them
            else{
                if(tolower(s[start])!=tolower(s[end])){
                    return false;// Mismatch found
                }
                start++;
                end--;
            }
        }
        return true;
        
    }
};


// OR // bool isPalindrome(string s) {
//        int start=0;
//        int end=s.size()-1;
//        while(start<=end){
//            if(!isalnum(s[start])){start++; continue;}
//            if(!isalnum(s[end])){end--;continue;}
//            if(tolower(s[start])!=tolower(s[end]))return false;
//            else{
//                start++;
//                end--;
//            }
//        }
//        return true;
// }