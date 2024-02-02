class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        int n = str.size();
        vector<int> result;

        for(int i=0; i<n; i++)
        {
            string temp = " ";
            temp += str[i];
            int tempNum = stoi(temp);
            if(tempNum>=low && tempNum <= high)
                result.push_back(tempNum);

            for(int j=i+1; j<n; j++)
            {
                temp += str[j];
                tempNum = stoi(temp);
                if(tempNum>=low && tempNum <= high)
                    result.push_back(tempNum);
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
    
};