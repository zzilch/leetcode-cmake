#include "leetcode.h"

#include <unordered_map>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        return twoSum_Hash(nums, target);
    }

    vector<int> twoSum_BF(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        }
        return vector<int>{-1, -1};
    }

    vector<int> twoSum_Hash(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            // if (map.contains(target - nums[i])) // C++20
            if (map.find(target - nums[i]) != map.end())
                return vector<int>{map[target - nums[i]], i};
            else
                map[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }

    vector<int> twoSum_Hash2(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++)
        {
            // if (map.contains(target - nums[i]) && map[target - nums[i]] != i) // C++20
            if (map.find(target - nums[i]) != map.end() && map[target - nums[i]] != i)
                return vector<int>{i, map[target - nums[i]]};
        }
        return vector<int>{-1, -1};
    }
};
