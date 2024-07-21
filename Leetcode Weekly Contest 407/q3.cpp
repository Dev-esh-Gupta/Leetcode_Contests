class Solution {
public:
    int maxOperations(string s) {
        int zeroCount = 0;
        int n = s.length();
        int i = n-1;
        int ans = 0;
        while(i>=0){
            bool flag = true;
            while(i >= 0 && s[i] == '0'){
                if(flag){
                    zeroCount++;
                    flag = false;
                }
                i--;
            }
            int oneCount = 0;
            while(i >= 0 && s[i] == '1'){
                oneCount++;
                i--;
            }
            // cout << oneCount<< " " << zeroCount << endl;
            ans += oneCount*zeroCount;
        }
        return ans;
    }
};