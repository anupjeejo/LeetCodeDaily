class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long result = 0;

        for(auto gift : gifts)
            pq.push(gift);

        while(k>0 && !pq.empty())
        {
            int topGift = pq.top();
            pq.pop();
            int newGift = floor(sqrt(topGift));
            pq.push(newGift);
            k--;
        }

        while(!pq.empty())
        {
            int topGift = pq.top();
            result += topGift;
            pq.pop();
        }

        return result;
    }
};