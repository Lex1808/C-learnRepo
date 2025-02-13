/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.
*/
class Solution {
public:
    std::string result = "";
    string mergeAlternately(string word1, string word2) {
        for (int i = 0; i <= (word1.length() + word2.length()); i++) {
            if (i < word1.length()) {
                result.push_back(word1[i]);
            }
            if (i < word2.length()) {
                result.push_back(word2[i]);
            }
        }

        return result;
    }
};
