/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h> 
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "radix.h"
#include "datastructure.hh"

using namespace std;

Datastructure::Datastructure(): WordList(0), lengthOfMinWord(),
	lengthOfMaxWord()
{

}
// built in destructor for Datastructure class
Datastructure::~Datastructure(){ 
}


RadixSort::RadixSort(const unsigned int cores) { 
	//create datatype for 1 core, then multiple cores.
}

void RadixSort::msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists) { 
	Datastructure ds; //MIGHT NEED TO BE BROADER SCO
	std::vector<unsigned int> v1 = lists[0];
	for (auto i = v1.begin(); i != v1.end(); ++i) //print
		std::cout << *i << ' ';

	for(unsigned int k = 0; k < v1.size(); k++) { //change notation to access element of vector at a time
		std::string s = std::to_string(v1[k]);
		ds.add(s); //may have to be a string. Could have to backtrack.
	}
	ds.sort();
	//	ds.print();
	vector <string> sorted = ds.WordList;
	unsigned int num;
	vector <unsigned int> sortedNums;

	for (auto i = sorted.begin(); i != sorted.end(); ++i){
		stringstream ss(*i);
		while(ss >> num)
		{
			sortedNums.push_back(num);
		}
	}	

//	for(auto i: sortedNums)		cout << i << '\n';
	
	lists[0] = sortedNums;
	std::vector<unsigned int> v2 = lists[0];
	for (auto i = v2.begin(); i != v2.end(); ++i) //print
		std::cout << *i << ' ';

}
void Datastructure::radixSort(vector<string> tempOneDimWordList,
		unsigned int oneDimVecSize,  unsigned int offset)
{ 

	if(offset == lengthOfMaxWord.length ){
		return;
	}
	vector<string> towDimWordlist [MAX_LENGTH];

	for (unsigned int i = 0; i < oneDimVecSize; i++){
		if(offset < tempOneDimWordList[i].size()){
			char c = tempOneDimWordList[i][offset];

			if (c != '\0'){
				towDimWordlist[(((unsigned int)c) )].
					push_back(tempOneDimWordList[i]);
			}
		}
		else{
			WordList.push_back(tempOneDimWordList[i]);
		}
	}

	// this loop is used to call the function recursively
	// to sort the words according to offset.
	for (unsigned int i = 0; i < (unsigned int)MAX_LENGTH; i++) {
		unsigned int sizeCheck = (unsigned int)towDimWordlist[i].size();
		if (sizeCheck > 1){                 
			radixSort(towDimWordlist[i], sizeCheck, offset+1);
		}
		else if(sizeCheck == 1)
		{ 
			WordList.push_back(towDimWordlist[i][0]);
		}
	}
}

void Datastructure::sort()
{

	vector<string> tempOneDimWordList;

	tempOneDimWordList = WordList;
	WordList.clear();

	radixSort(tempOneDimWordList, (unsigned int)tempOneDimWordList.size(), 0);	
}

// prints the sorted wordlist
void Datastructure::print()
{

	unsigned int iSize = (unsigned int)WordList.size();

	if(iSize == 0){
		cout << MSG_EMPTY_DS << endl;
	}
	else{
		for (unsigned int j = 0; j < WordList.size(); j++){
			cout << SEPARATOR << WordList[j];		
		}
		cout << endl;
	}

}

//Empty the datastructure
void Datastructure::empty()
{
	WordList.clear();
}

// Add all the words from the input files to the data strructure and 
// finds the max and min words eventually.
void Datastructure :: add(std::string& word)
{

	unsigned long i = WordList.size();

	WordDirectory eachword;
	eachword.wordname = word;
	eachword.length =  word.size();	

	if(i == 0){
		lengthOfMinWord.length = eachword.length;
		lengthOfMaxWord.length = eachword.length;		
		i = i + 1;
	}	

	if(eachword.length <= lengthOfMinWord.length){
		lengthOfMinWord.length=eachword.length;
		lengthOfMinWord.wordname = eachword.wordname;	   
	}

	if(eachword.length > lengthOfMaxWord.length){
		lengthOfMaxWord.length = eachword.length;
		lengthOfMaxWord.wordname = eachword.wordname;	  
	}

	WordList.push_back(word);


}
