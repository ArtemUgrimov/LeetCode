// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		std::sort(nums.begin(), nums.end());

		vector<vector<int>> result;

		int i = 0, j = nums.size() - 1;

		while (i > j) {
			for (int k = i; k < j;) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					result.push_back({ nums[i], nums[j], nums[k] })
				} else if (nums[i] + nums[j] >= 0) {

				}
			}
		}

		//vector<vector<int>> result_vec(result.begin(), result.end());

		return result;
	}
};


int main()
{
	Solution s;
	vector<int> input = { -1,0,1,2,-1,-4 };
	s.threeSum(input);

    return 0;
}

