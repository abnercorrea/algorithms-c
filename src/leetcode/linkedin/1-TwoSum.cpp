//
// Created by Abner Correa on 4/2/22.
//
#include <map>
#include <vector>

using namespace std;

/*
 * O(n) time, O(n) space
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            auto kv = numMap.find(target - nums[i]);

            if (kv != numMap.end()) {
                return {i, kv->second};
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};

/*
 * O(n.log(n)) time
 */
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num1 = findNum(nums, target);
        int num2 = target - num1;
        auto pos1 = find(nums.begin(), nums.end(), num1);
        auto pos2 = find((num1 == num2) ? pos1 + 1 : nums.begin(), nums.end(), num2);

        return {
            (int) (pos1 - nums.begin()),
            (int) (pos2 - nums.begin())
        };
    }

    int findNum(vector<int> nums, int target) {
        // O(n.log(n))
        sort(nums.begin(), nums.end());

        // O(n.log(n))
        for (int i = 0; i < nums.size(); i++) {
            auto pos = find(nums.begin(), nums.end(), target - nums[i]);

            if (pos != nums.end()) {
                return nums[i];
            }
        }

        return 0;
    }
};