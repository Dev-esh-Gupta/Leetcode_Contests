class Solution {
    bool isPrime(long long num){
        if(num == 1) return false;
        if(num == 2) return true;
        for(long long i=2; i<=sqrt(num); i++){
            if(num%i == 0) return false;
        }
        return true;
    }
public:
    int nonSpecialCount(int l, int r) {
        // long long start = sqrt(l);
        // cout << start <<  endl;
        int properCount = 0;
        for(long long i = sqrt(l) + 1; i <= sqrt(r); i++){
            if(isPrime(i)){
                properCount++;
            }
        }
        // cout << properCount;
        int ans = r - l + 1 - properCount;
        if(l == ((int)sqrt(l) * (int)sqrt(l)) && isPrime(sqrt(l))){
            ans--;
        }
        return ans;
    }
};