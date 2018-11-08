/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 dd */
#include <iostream>
#include <algorithm>
#include <thread>
#include <sstream>
#include <vector>
#include <typeinfo>

#include "radix.h"

static unsigned int cores_;

static bool isParallel;

ParallelRadixSort::ParallelRadixSort(const unsigned int cores){
	cores_ = cores;
}

static bool compare(const unsigned int &a, const unsigned int &b) {
	return std::to_string(a) < std::to_string(b);
}

static unsigned int firstTwoDigits(unsigned int x) {
	while (x > 99) {
		x /= 10;
	}
	return x;
}

static void sort(std::vector<unsigned int> &list) {
	std::sort(list.begin(), list.end(), compare);
}

void ParallelRadixSort::msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists, unsigned int cores) { 
	// your implementation goes here :)
	std::cout << cores << std::endl;
	std::vector <std::thread> threads;
	std::vector <std::vector<unsigned int>> buckets (100);
	isParallel = false;
	unsigned int created = 0;



	for (auto list: lists) { // must be changed to reflect single list brken into chunks
		for (unsigned int number: list.get()){
			//std::cout << number << std::endl;
			//std::cout << firstTwoDigits(number) << std::endl;
			buckets[firstTwoDigits(number)].push_back(number);		//create 100 sublists
		}

		if (cores == 10 || cores == 20) {
			isParallel = true;
			break;
		}

		threads.push_back(std::thread(sort, list));

		if (++created == lists.size() || threads.size() == cores) {
			for (auto &thread : threads) 
				thread.join();
			threads.clear();
		}



	}
	if (isParallel){

		std::vector <std::reference_wrapper<std::vector<unsigned int>>> bucketsRef(buckets.begin(), buckets.end());

		for (auto bucket: bucketsRef){
			threads.push_back(std::thread(sort, bucket));

			if (++created == buckets.size() || threads.size() == cores) {
				for (auto &thread : threads) 
					thread.join();
				threads.clear();
			}
		}
		for (auto bucket: bucketsRef) {
				for (unsigned int number: bucket.get()){
					std::cout << number << " "<< std::endl;
				}
		}

		//for (unsigned int numbers: buckets[i]) {
		//	std::cout << numbers << std::endl;
		//	if ( i >= buckets[i].size() ) break;
		//}
		for (unsigned int i = 0; i < lists.size(); i++){
			//lists[i] = std::ref(bucketsRef[i]); //statement has no effect
			//			for (unsigned int k = 0; k < lists[i].get().size(); k++) {
			//				std::cout << "and here?";
			//				std::cout << lists[i].get()[k] << std::endl;
			for (auto list:lists){
				//std::cout << "and here";
				for (unsigned int number: list.get()){
				//	std::cout << number << std::endl;	
				}
			}
			for (auto bucket: buckets){
				//std::cout << "buckets place";
				for (unsigned int number: bucket){
					//std::cout << number << " "<< std::endl;
				}
				//std::cout << std::endl;
			}
		}

		}
	}
