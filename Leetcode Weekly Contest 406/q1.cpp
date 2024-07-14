class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i=1; i<n; i++){
            if(s[i-1] > s[i] && s[i-1]%2 == s[i]%2){
                swap(s[i-1], s[i]);
                break;
            }
        }
        return s;
    }
};