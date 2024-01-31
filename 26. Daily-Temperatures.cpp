class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        
        st.push({temperatures[n-1], n-1});

        for(int idx=n-2; idx>=0; idx--)
        {
            pair<int, int> topTemperature = st.top();
            int currTemperature = temperatures[idx];
            if(topTemperature.first > currTemperature)
            {
                result[idx] = topTemperature.second - idx;
                st.push({currTemperature, idx});
                continue;
            }

            while(!st.empty())
            {
                if(st.top().first > currTemperature)
                {
                    result[idx] = st.top().second - idx;
                    break;
                }
                st.pop();
            }
            st.push({currTemperature, idx});
        }

        return result;
    }
};