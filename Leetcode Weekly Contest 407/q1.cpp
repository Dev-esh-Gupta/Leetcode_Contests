class Solution {
public:
    int minChanges(int n, int k) {
        if(k > n) return -1;
        else if(k == n) return 0;
        int change = 0;
        while(n){
            if(n%2 != k%2){
                if(n%2 == 0) return -1;
                else change++;
            }
            n /= 2;
            k /= 2;
        }
        return change;
    }
};