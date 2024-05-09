class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int, vector<int>> pq;
        int ctr = 0;
        int n = happiness.size();
        long long result = 0;

        for(int happinessValue : happiness)
            pq.push(happinessValue);

        while(!pq.empty() && k>0)
        {
            int topHappieness = pq.top();
            int actualHappieness = max(0, topHappieness - ctr);
            result += actualHappieness;
            pq.pop();
            ctr++;
            k--;
        }

        return result;
    }
};