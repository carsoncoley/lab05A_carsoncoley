// WordCount.cpp

#include "WordCount.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int size = 0;
	for (size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			size += table[i][j].second;
		}
	}
	return size;
}

int WordCount::getNumUniqueWords() const {
	int size = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		size += table[i].size();
	}
	return size;

}

int WordCount::getWordCount(std::string word) const {
	string testString = makeValidWord(word);
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			if(table[i][j].first == testString){
				return table[i][j].second;
			}
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	string testString = makeValidWord(word);
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			if(table[i][j].first == testString){
				table[i][j].second++;
				return table[i][j].second;
			}
		}
	}
	size_t index = hash(testString);
	table[index].push_back(std::pair<std::string, int>(testString, 1));
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	
	string testString = makeValidWord(word);
	if(word == ""){
		return -1;
	}
	return -1;
}


bool WordCount::isWordChar(char c) {
	if(isalpha(c) != 0){
		return true;
	}else{
		return false;
	}
}

std::string WordCount::makeValidWord(std::string word) {
	for(size_t i = 0; i < word.length(); i++){
		word[i] = std::tolower(word[i]);
	}
	while((word.size() > 0) && (!isWordChar(word[0]))){
		word.erase(word.begin());
	}
	if(word.compare("") == 0){
		return "";
	}
	while((word.size() > 0) && (!isWordChar(word[word.size()-1]))){
		word.pop_back();
	}
	if(word == ""){
		return "";
	}

	for(size_t i = word.length() - 1; i > 0; i--){
		if((word[i] != '-') && (word[i] != '\'') && (isWordChar(word[i])) == 0){
			word.erase(word.begin() + i);
		}
	}
	return word;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	std::vector<string> myVector;
	for(size_t i = 0; i < CAPACITY; i++){
		if(table[i].size() > 0){
			//create dummy vector
			
			for(size_t j = 0; j < table[i].size(); j++){
				//dummyvector.push_back(table[i]);
				myVector.push_back(table[i][j].first);
			}
		}
	}
	std::sort(myVector.begin(), myVector.end());
	for(int k = myVector.size() - 1; k >= 0; k--){
		out << myVector[k]<< "," << getWordCount(myVector[k]) << endl;
	}

}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	std::vector<std::pair<size_t, string>> myVector;
	for(size_t i = 0; i < CAPACITY; i++){
		if(table[i].size() > 0){
			//std::vector<std::pair<size_t, string> myVector;
			for(size_t j = 0; j < table[i].size(); j++){
				myVector.push_back(std::pair<size_t,string>(table[i][j].second,table[i][j].first));
			}
		}
	}
	std::sort(myVector.begin(), myVector.end());
	for(size_t k = 0; k < myVector.size(); k++){
		std::cout << myVector[k].second << "," << myVector[k].first << endl;
	}
}

void WordCount::addAllWords(std::string text) {
	if(text == ""){
		return;
	}
	std::string tempString;
	//size_t index = 0;
	//size_t i = 0;
	while((text.find(" ") != string::npos)||(text.find("\n") != string::npos) ||(text.find("\t") != string::npos)){
		size_t a;
		size_t b;
		size_t c;
		size_t minimum = 0;
		/*if(text.find(" ") != string::npos){
			a = text.find(' ');
		}
		if(text.find("\n") != string::npos){
			b = text.find("\n");
		}
		if(text.find("\t") != string::npos){
			c = text.find("\t");
		}*/
		a = text.find(" ");
		b = text.find("\n");
		c = text.find("\t");
		if(a < b){

			if(a > c){
				minimum = c;
			}
			else{
			
				minimum = a;
			}
		}
		else{
			
			if(b > c){
				minimum = c;
			}else{
				minimum = b;
			}
		}
		
		tempString = text.substr(0, minimum);
		WordCount::incrWordCount(tempString);
		text.erase(0, minimum + 1);

		/*
		for(size_t i = 0; i < text.size(); i++){
			if(text[i] == ' '){
				tempString = text.substr(0,i-1);
				WordCount::incrWordCount(tempString);
				text.erase(0,i);
				//index = static_cast<size_t> (*i);

			}
			else if(text[i] == '\n'){
				tempString = text.substr(0,i-1);
				WordCount::incrWordCount(tempString);
				text.erase(0,i);
				//index = static_cast<size_t> (*i);
			}
			else if(text[i] == '\t'){
				tempString = text.substr(0, i-1);
				WordCount::incrWordCount(tempString);
				text.erase(0,i);
				//index = static_cast<size_t> (*i);
			}
		}*/
	}

}














