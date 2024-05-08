class Solution {
public:

    unordered_map<int, string> rankToMedalMp = {
        make_pair(1, "Gold Medal"),
        make_pair(2, "Silver Medal"),
        make_pair(3, "Bronze Medal")
    };

    string findMedal(int rank)
    {
        return rankToMedalMp[rank];
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        int n = score.size();
        vector<string> result(n);

        for(int i=0; i<n; i++)
            pq.push({score[i], i});

        int ctr = 1;
        while(!pq.empty())
        {
            pair<int, int> currTop = pq.top();
            pq.pop();
            string temp = ctr <= 3 ? 
                            findMedal(ctr) :
                            to_string(ctr);
            ctr++;
            result[currTop.second] = temp;
        }

        return result;
    }
};