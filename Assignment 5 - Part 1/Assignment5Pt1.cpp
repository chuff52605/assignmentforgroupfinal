/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Lesson #5
** File: 	source.cpp
** Description: Spell checker for words contained inside of a file 
**
** Author: 	Connor Huff, Nicholas Caceres, Denkeis Hunter, Joshua Perry
** Date: 	17/11/2025
** -------------------------------------------------------------------------*/


#include <iostream> // Used for the typical input and output streams such as cout 
#include <fstream>  // used for file streams and allows the programn to read from the input and word file
#include <vector>   // This is used to hold the dictionary 
#include <string>   // This is so std::string is able to be used, it holds words
#include <algorithm> // only included so std::find can be used

/* This program is intended to check a text file for words that may be misspelled. It will open an input file that is supposed to be check from the dictionary file provided. It first loads the dictionary file into memory
then opens the input file being checked, it will read the input file word by word and cross-references it to the dictionary. If by chance the word is not in the dictionary, the compiler will print a "misspelled" error./*/



int main() {
	
	//lines 15 and 16 load the dictionary into a vector
	std::cout << "Loading the dictionary, please hold. " << std::endl;
	std::ifstream dictionaryFile("words");

	if (!dictionaryFile) {
		std::cerr << "Error operating dictionary." << std::endl; 
		return 1;
	}


	std::vector<std::string> words;  // the vector is used here
	std::string word;
	while (dictionaryFile >> word) {
		words.push_back(word);
	}
	dictionaryFile.close();
	std::cout << "Dictionary has been loaded. " << std::endl;



	// This checks the file being input... also named "input"
	std::string fileToCheck = "input";
	std::ifstream file(fileToCheck); 
	
	
	if (!file) {
		std::cerr << "Error opening the checking file." << std::endl;
		return 1;
	}

	// Now the file wil be read and checked for spelling errors.
	while (file >> word) {
		if (std::find(words.begin(), words.end(), word) == words.end()) {
			std::cout << "Misspelled word:" << word << std::endl;
			words.push_back(word);
		}
	}
	file.close();
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Check complete. Press Enter to exit." << std::flush;
	std::cin.get(); // <-- This will wait for the user to press a key to exit

	return 0;
}

// this will open the system dictionary file and will read the words into a vector // 
// Following that, it will open the file that must be checked for spelling erros and will compare it to each word in the provided dictionary
// if a word is not found in the dictionary, it will be shown as being misspelled. 