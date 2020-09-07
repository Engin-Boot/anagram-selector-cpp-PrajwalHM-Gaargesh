#include "anagram.h"
#include <cctype>
#include <algorithm>

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2)
{
	auto word_one = word1;
	word_one.erase(std::remove_if(word_one.begin(), word_one.end(), ::isspace), word_one.end());
	
	auto word_two = word2;
	word_two.erase(std::remove_if(word_two.begin(), word_two.end(), ::isspace), word_two.end());

	std::transform(word_one.begin(), word_one.end(), word_one.begin(), ::toupper);
	std::transform(word_two.begin(), word_two.end(), word_two.begin(), ::toupper);

	std::sort(word_one.begin(), word_one.end());
	std::sort(word_two.begin(), word_two.end());

	if(word_one == word_two)
	{
		return true;
	}
    return false;
}

std::vector<std::string> Anagram::SelectAnagrams(
        const std::string& word,
        const std::vector<std::string>& candidates)
{
	std::vector<std::string> candidateList;
	for(auto& candidate:candidates)
	{
		if(WordPairIsAnagram(word, candidate))
		{
			candidateList.push_back(candidate);
		}
	}	
    return candidateList;
}
