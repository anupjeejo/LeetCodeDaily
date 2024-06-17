class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = sqrt(c);

        while(left <= sqrt(c) && right >= 0)
        {
            long long int leftSqr = (left * left);
            long long int rightSqr = (right * right);

            if(leftSqr + rightSqr == c)
                return true;
            else if(leftSqr + rightSqr < c)
                left++;
            else
                right--;
        }

        return false;
    }
};