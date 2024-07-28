// Simple Brute force giving TLE as T.C. O(n^2) but quetion expecting NLogN

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++){
            long long one = 0, zero = 0;
            for(int j=i; j<n; j++){
                if(s[j] == '1') one++;
                else zero++;
                if(one >= zero*zero) ans++;
            }
        }
        return ans;
    }
};