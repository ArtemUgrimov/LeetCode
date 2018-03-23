#include <iostream>
#include <vector>


class Solution {
public:
    int findLengthOfLCIS(const std::vector<int>& nums) {

    	if (nums.empty())
    		return 0;

    	int max_length = 1;
        int cur_length = 1;

        for (int i = 1; i < nums.size(); ++i) {
        	if (nums[i] > nums[i - 1]) {
        		++cur_length;
        		if (cur_length > max_length) {
        			max_length = cur_length;
        		}
        	} else {
        		cur_length = 1;
        	}
        }

        return max_length;
    }
};


int main(int argc, char** argv) {
	Solution s;
	std::cout<<s.findLengthOfLCIS({1,3,5,4,7,8,9,10,1,2,3,4,5,6,7,8,9,10,10,10,10,10,9})<<std::endl;
}