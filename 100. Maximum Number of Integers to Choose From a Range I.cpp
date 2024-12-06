class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet;
        int result = 0;
        int sum = 0;

        for(auto item : banned)
            bannedSet.insert(item);

        for(int i=1; i<=n; i++)
        {
            if(bannedSet.find(i) != bannedSet.end())
                continue;
            
            sum += i;
            if(sum > maxSum)
                break;
            result++;
        }

        return result;
    }
};