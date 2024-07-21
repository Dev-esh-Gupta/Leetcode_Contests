class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCount = 0;
        for(auto &ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelCount++;
            }
        }
        if(vowelCount != 0 ){
            return true;
        }else{
            return false;
        }
    }
};