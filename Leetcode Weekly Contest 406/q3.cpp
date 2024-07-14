class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        if(m == 1 && n == 1) return 0;
        if(m == 1) return accumulate(verticalCut.begin(), verticalCut.end(), 0);
        if(n == 1) return accumulate(horizontalCut.begin(), horizontalCut.end(), 0);
        int horizontalPieces = 1;
        int verticalPieces = 1;
        int ans = 0;
        priority_queue<int> pq1, pq2;
        for(int i=0; i<m-1; i++){
            pq1.push(horizontalCut[i]);
        }
        for(int i=0; i<n-1; i++){
            pq2.push(verticalCut[i]);
        }
        while(!pq1.empty() && !pq2.empty()){
            if(pq1.top() > pq2.top()){
                ans += verticalPieces * pq1.top();
                horizontalPieces += 1;
                pq1.pop();
            }else{
                ans += horizontalPieces * pq2.top();
                verticalPieces += 1;
                pq2.pop();
            }
        }
        while(!pq1.empty()){
            ans += verticalPieces*pq1.top();
            pq1.pop();
        }
        while(!pq2.empty()){
            ans += horizontalPieces*pq2.top();
            pq2.pop();
        }
        return ans;
    }
};