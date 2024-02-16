class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++)
            mp[arr[i]]++;

        for(auto it : mp)
            pq.push(it.second);

        while(k>0)
        {
            int freq = pq.top();
            if(freq>k) break;
            k -= freq;
            pq.pop();
        }

        return pq.size();
    }
};