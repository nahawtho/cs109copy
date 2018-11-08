/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */
//https://github.com/johnshumon/C-plus-plus-Projects/tree/master/radix_sort
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h> 
#include <cstring>
#include <mutex>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <thread>
#include <string>
#include <vector>
#include <cstdlib>
#include "radix.h"
#include "datastructure.hh"

using namespace std;

int coress;

theDS::theDS(): WordList(0), lengthOfMin(),
	lengthOfMax()
{

}
// built in destructor for theDS class
theDS::~theDS(){ 
}


RadixSort::RadixSort(const unsigned int cores) { 
	//create datatype for 1 core, then multiple cores.
	coress=cores;

}

void sortV_i(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists, int moop){
	std::vector<unsigned int> v1 = lists[moop];
	theDS ds;
	for(unsigned int k = 0; k < v1.size(); k++) { //change notation to access element of vector at a time
		std::string s = std::to_string(v1[k]);
		ds.add(s); //may have to be a string. Could have to backtrack.
	}
	ds.sort();
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
	lists[moop].get() = sortedNums;

}

void RadixSort::msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists) { 

	cout << "\ncores, lists" << coress << ' ' << lists.size() << endl;
	std::vector<std::thread> threads(coress);
	std::mutex critical;



	for (unsigned int moop = 0; moop < lists.size(); moop++) // loops across each vector
	{
		for (int t = 0; t < coress; t++){
			threads[t] = thread(std::bind(sortV_i, std::ref(lists), moop));
		}
		std::for_each(threads.begin(),threads.end(),[](std::thread& x){x.join();});

		//std::thread th1(sortV_i, std::ref(lists), moop);
		//std::thread th2(sortV_i, std::ref(lists), ++moop);
		//th1.join();
		//th2.join();
	}

	//}
}
void theDS::radixSort(vector<string> tempOneDimWordList,
		unsigned int oneDimVecSize,  unsigned int offset)
{ 

	if(offset == lengthOfMax.length ){
		return;
	}
	vector<string> twoDimWordlist [MAX_LENGTH];

	for (unsigned int k = 0; k < oneDimVecSize; k++){
		if(offset < tempOneDimWordList[k].size()){
			char c = tempOneDimWordList[k][offset];

			if (c != '\0'){
				twoDimWordlist[(((unsigned int)c) )].
					push_back(tempOneDimWordList[k]);
			}
		}
		else{
			WordList.push_back(tempOneDimWordList[k]);
		}
	}

	// this loop is used to call the function recursively
	// to sort the words according to offset.
	for (unsigned int k = 0; k < (unsigned int)MAX_LENGTH; k++) {
		unsigned int sizeCheck = (unsigned int)twoDimWordlist[k].size();
		if (sizeCheck > 1){                 
			radixSort(twoDimWordlist[k], sizeCheck, offset+1);
		}
		else if(sizeCheck == 1)
		{ 
			WordList.push_back(twoDimWordlist[k][0]);
		}
	}
}

void theDS::sort()
{

	vector<string> tempOneDimList;

	tempOneDimList = WordList;
	WordList.clear();

	radixSort(tempOneDimList, (unsigned int)tempOneDimList.size(), 0);	
}

// prints the sorted wordlist
/*void theDS::print()
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
 */


// Add all the words from the input files to the data strructure and 
// finds the max and min words eventually.
void theDS :: add(std::string& word)
{

	unsigned long i = WordList.size();

	WordDir aString;
	aString.wordname = word;
	aString.length =  word.size();	

	if(i == 0){
		lengthOfMin.length = aString.length;
		lengthOfMax.length = aString.length;		
		i = i + 1;
	}	

	if(aString.length <= lengthOfMin.length){
		lengthOfMin.length=aString.length;
		lengthOfMin.wordname = aString.wordname;	   
	}

	if(aString.length > lengthOfMax.length){
		lengthOfMax.length = aString.length;
		lengthOfMax.wordname = aString.wordname;	  
	}

	WordList.push_back(word);


}
