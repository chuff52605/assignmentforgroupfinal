#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::ifstream dictionaryFile("/usr/share/dict/words");
	if (!dictionaryFile) {
		std::cerr << "Error operating dictionary file." << std::endl; 
		return 1;
	}


	std::vector<std::string> words;
	std::string word;
	while (dictionaryFile >> word) {
		words.push_back(word);
	}
	dictionaryFile.close();

	std::string fileToCheck = "file_to_check.txt";
	//replace this with the file path that you would like to check
	std::ifstream file(filetocheck); //once again replace with checked faile
	if (!file) {
		std::cerr << "Error opening file to check." << std::endl;
		return 1;
	}

	while (file >> word) {
		if (std::find(words.begin(), words.end(), word) == words.end()) {
			std::cout << "Misspelled word:" << word << std::endl;
			words.push_back(word);
		}
	}
	file.close();

	return 0;
}

// this will open the system dictionary file and will read the words into a vector // 
// Following that, it will open the file that must be checked for spelling erros and will compare it to each word in the provided dictionary
// if a word is not found in the dictionary, it will be shown as being misspelled. 