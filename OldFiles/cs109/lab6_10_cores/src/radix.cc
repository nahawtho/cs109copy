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
		for (auto list: lists){

			std::vector <std::reference_wrapper<std::vector<unsigned int>>> bucketsRef(buckets.begin(), buckets.end());
			std::vector <unsigned int> sorted;

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
					sorted.push_back(number);
			//		std::cout << number << " "<< std::endl;
				}
			}
			list.get() = std::ref(sorted);
			//for (unsigned int number: list.get()) {
			//	std::cout << number << std::endl;	
			//}
		}
	}
}

