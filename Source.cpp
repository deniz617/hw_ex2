#include <map>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> splitString(std::string str, char delimiter)
{
	std::vector<std::string> res;
	std::istringstream is(str);
	std::string tempstr;

	while (std::getline(is, tempstr, delimiter))
	{
		res.push_back(tempstr);
	}

	return res;
}

void checkWord(std::map<std::string, int>& words, std::string word)
{
	if (words.find(word) != words.end())
	{
		// Word already exists do your thing..
		words[word]++; // Increase word count variable..
		// DEBUG
		printf_s("Found an already existing word. We have %d of %s now!\n", words[word], word.c_str());
	}
	else
	{
		// Word not found
		words[word] = 1; // Define new word with count as 1
		// DEBUG
		printf_s("New word %s!\n", word.c_str());
	}
}

void main()
{
	std::map<std::string, int> words;

	// Read your file and put the data int o a string..
	// ...
	
	std::string stringFromFile = "asidoaidj asdiaijdoa asdjiadas adsa asd asd asd fijfgi fdifd1";

	// Split the string by ' ' (spaces)
	auto wordsFromFile = splitString(stringFromFile, ' ');

	// Loop through your words in any way you like
	for (std::string word : wordsFromFile)
	{
		// Call our function for each word in the array.
		checkWord(words, word);
	}
	
	// All words were counted ! Now we can print and see the result..

	// DEBUG
	// Loop through our word map where our words and their count is stored to print them
	for (std::map<std::string, int>::iterator it = words.begin(); it != words.end(); it++)
	{
		printf_s("Word: %14s | Count: %4d\n", it->first.c_str(), it->second);
	}
}