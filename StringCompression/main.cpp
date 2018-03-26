#include <iostream>
#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        if (chars.size() < 2) return chars.size();

    	int insert_pos = 0;
    	int search_begin = 0;

    	int current_seq_length = 1;
    	int output_len = 0;

    	for (int i = 1; i < chars.size(); ++i) {
    		char begin_char = chars[search_begin];
    		char char_i = chars[i];

    		if (begin_char == char_i) {
    			++current_seq_length;
    		} 

			if (begin_char != char_i || i == chars.size() - 1) {
				if (current_seq_length > 1) {
					chars[insert_pos++] = begin_char;
					++output_len;
					for (char c : std::to_string(current_seq_length)) {
						chars[insert_pos++] = c;
						++output_len;
					}
				} else {
					for (int j = 0; j < current_seq_length; ++j) {
						chars[insert_pos++] = begin_char;
						++output_len;
					}
				}

				if (i == chars.size() - 1 && begin_char != char_i) {
					chars[insert_pos] = char_i;
					++output_len;
				}

				search_begin = i;
				current_seq_length = 1;
			}
    	}
		chars.resize(output_len);
    	return output_len;
    }
};

int main(int argc, char** argv) {

	std::vector<char> input_vec {'a','b','b','b','b','b','b','b','b','b','b','b','b'};

	Solution s;
	s.compress(input_vec);

	std::cout<<input_vec.size()<<std::endl;
	for (char c : input_vec) {
		std::cout<<c<<" ";
	}
	std::cout<<std::endl;

	return 0;
}