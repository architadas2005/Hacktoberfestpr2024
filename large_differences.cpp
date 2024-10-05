#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    for (int r=0;r<t;r++)
    {
        int n, k;
        cin>> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            cin>> nums[i];
        int sum = 0;
        for (int i = 1; i < n; ++i)
        {
            sum += abs(nums[i] - nums[i - 1]);
        }
        int maxSum = sum;

        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                int currSum = sum - abs(nums[i] - nums[i - 1]) + abs(1 - nums[i - 1]);
                if (i < n - 1)
                {
                    currSum -= abs(nums[i] - nums[i + 1]);
                    currSum += abs(1 - nums[i + 1]);
                }
                maxSum = max(maxSum, currSum);

                currSum = sum - abs(nums[i] - nums[i - 1]) + abs(k - nums[i - 1]);
                if (i < n - 1)
                {
                    currSum -= abs(nums[i] - nums[i + 1]);
                    currSum += abs(k - nums[i + 1]);
                }
                maxSum = max(maxSum, currSum);
            }
            else
            {
                int currSum = sum;
                if (i < n - 1)
                {
                    currSum -= abs(nums[i] - nums[i + 1]);
                    currSum += abs(1 - nums[i + 1]);
                }
                maxSum = max(maxSum, currSum);

                currSum = sum;
                if (i < n - 1)
                {
                    currSum -= abs(nums[i] - nums[i + 1]);
                    currSum += abs(k - nums[i + 1]);
                }
                maxSum = max(maxSum, currSum);
            }
        }
        cout <<maxSum<<endl;
        
    }
    return 0;
}
