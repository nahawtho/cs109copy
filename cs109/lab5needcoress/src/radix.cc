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
#include <iterator>
#include <iostream>
#include <sstream>
#include <thread>
#include <string>
#include <vector>
#include <cstdlib>
#include "radix.h"
#include "datastructure.hh"
#include <sys/stat.h>
#include<fcntl.h>
#define SEM_OCCUPIED "/occupied"
#define SEM_VACANT "/vacant"

using namespace std;

int coress;
std::vector<std::reference_wrapper<std::vector<unsigned int>>> lists2;

Datastructure::Datastructure(): WordList(0), lengthOfMinWord(),
	lengthOfMaxWord()
{

}
// built in destructor for Datastructure class
Datastructure::~Datastructure(){ 
}


RadixSort::RadixSort(const unsigned int cores) { 
	//create datatype for 1 core, then multiple cores.
	coress=cores;
occupied = sem_open(SEM_OCCUPIED, O_CREAT, S_IRUSR | S_IWUSR, 0);
vacant = sem_open(SEM_VACANT, O_CREAT, S_IRUSR | S_IWUSR, size);
sem_unlink(SEM_OCCUPIED);
sem_unlink(SEM_VACANT);
}

void sortV_i(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists, int moop){
	lists2 = lists;
	std::vector<unsigned int> v1 = lists[moop];
	Datastructure ds;
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

	cout << coress << endl;
	std::vector<std::thread> threads(coress);
	int coresCanUse = lists.size() % coress;
	cout << endl << coresCanUse << endl;
	bool shallmoop = true;
	std::mutex critical;

	for (unsigned int moop = 0; moop < lists.size(); moop++) // loops across each vector
	{
		cout << "\nlistssize" << lists.size() << endl;
		cout << "\ncores and moop" << coress << ' ' << moop << endl;
		if (lists.size()  >= coress + moop){
			cout << "first place I wanna b";
			for (int t = 0; t < coress ; t++){
				threads[t] = thread(std::bind(sortV_i, std::ref(lists), moop+t));
			}
			std::for_each(threads.begin(),threads.end(),[](std::thread& x){x.join();});
		}
		else {//if (shallmoop == true){
			std::vector<std::thread> lastThreads(coresCanUse);
			shallmoop = false;
			cout << "where i wanna b";
			//	coresCanUse = lists.size() - moop;
			cout << endl << coresCanUse << endl;

			for (int t = 0; t < coresCanUse ; t++){
				
				lastThreads[t] = thread(std::bind(sortV_i, std::ref(lists), moop+t));
				if (moop >= lists.size()) break;
			}
			cout << "got here";
			std::for_each(lastThreads.begin(),lastThreads.end(),[](std::thread& x){x.join();});

			//for (int t = 0; t < coress - moop; t++){
			//	threads[t] = thread(std::bind(sortV_i, std::ref(lists), moop++));
			//	if (moop >= lists.size()) break;
		}
		}


		//std::thread th1(sortV_i, std::ref(lists), moop);
		//std::thread th2(sortV_i, std::ref(lists), ++moop);
		//th1.join();
		//th2.join();
		}

		//}
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
		/*void Datastructure::print()
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
