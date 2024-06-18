class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, 
                            vector<int>& profit, 
                            vector<int>& worker) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        int n = difficulty.size();
        int m = worker.size();
        int result = 0;

        for(int i=0; i<n; i++)
            pq.push({profit[i], difficulty[i]});

        sort(worker.begin(), worker.end(), greater<int>());

        int ctr = 0;
        while(!pq.empty() && ctr < m)
        {
            pair<int, int> top = pq.top();

            if(top.second > worker[ctr])
                pq.pop();
            else
            {
                result += top.first;
                ctr++;
            }
        }

        return result;
    }
};