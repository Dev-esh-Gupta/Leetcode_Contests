class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n);
        long long ans = 0;
        for(int i=0; i<n; i++){
            diff[i] = target[i] - nums[i];
        }
        int i = 0;
        while(i < n){
            int val = 0;
            while(i < n && diff[i] > 0){
                if(diff[i] - val > 0){
                    ans += (diff[i] - val);
                }
                val = diff[i];
                i++;
            }
            while(i < n && diff[i] == 0){
                i++;
            }
            val = 0;
            while(i < n && diff[i] < 0){
                int val2 = abs(diff[i]);
                if(val2 - val > 0){
                    ans += (val2 - val);
                }
                val = val2;
                i++;
            }
        }
        return ans;
    }
};