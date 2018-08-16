#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

static const auto sync = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	bool isValid(string s) {

		static const map<char, char> o_to_c = {
			{ '{', '}' },
			{ '(', ')' },
			{ '[', ']' }
		};

		static const map<char, char> c_to_o = {
			{ '}', '{' },
			{ ')', '(' },
			{ ']', '[' }
		};

		stack<char> prent;

		for (const char c : s) {
			if (o_to_c.count(c)) {
				prent.push(c);
			} else {
				if (prent.empty()) return false;

				if (c_to_o.at(c) == prent.top()) {
					prent.pop();
				} else {
					return false;
				}
			}
		}

		if (!prent.empty()) return false;

		return true;
	}
};

int main()
{
	Solution s;
	std::cout << s.isValid("]");

	std::getchar();
	return 0;
}