class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length()<s2.length()){
            swap(s1,s2);
            
        }
        vector <string> vec1, vec2;
        string token;
        stringstream ss1(s1);
        while(ss1>>token){
            vec1.push_back(token);
        }
        stringstream ss2(s2);
        
        while(ss2>>token){
            vec2.push_back(token);
        }
        int i=0,j=vec1.size()-1;
        int k=0, l=vec2.size()-1;
        while(k<vec2.size()&& i<vec1.size()&& vec2[k]==vec1[i]){
            i++;
            k++;
        }
        while(l>=k && vec2[l]==vec1[j]){
            j--;
            l--;
        }
        if(l<k){
            return true;
        }
        return false;
    }
};