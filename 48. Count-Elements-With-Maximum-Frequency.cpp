class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int maxFreq = 0;
        vector<int> freqMap(101, 0);

        for(int i=0; i<n; i++)
        {
            freqMap[nums[i]]++;
            int currFreq = freqMap[nums[i]];
            if(currFreq > maxFreq) maxFreq = currFreq;
        }

        for(int i=0; i<=100; i++)
        {
            if(freqMap[i] >= maxFreq)
                result += freqMap[i];
        }

        return result;
    }
};