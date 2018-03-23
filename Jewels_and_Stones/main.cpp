#include <unordered_map>
#include <string>
#include <iostream>

class Solution {
public:
    int numJewelsInStones(const std::string& J, const std::string& S) {
        std::unordered_map<char, int> all_stones;

        for (auto c : S) {
        	all_stones[c]++;
        }

        int jewels_count = 0;
        for (auto c : J) {
        	jewels_count += all_stones[c];
        }

        return jewels_count;
    }
};

int main(int argc, char** argv) {
	Solution s;
	std::cout<<s.numJewelsInStones("aA", "aAAbbbb")<<std::endl;
}