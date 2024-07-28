class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > 9){
                sum -= nums[i];
            }else{
                sum += nums[i];
            }
        }
        if(sum == 0) return false;
        else return true;
    }
};