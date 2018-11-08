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
//#include <vector>

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

	isParallel = false;
	unsigned int created = 0;



	for (auto list: lists) { // must be changed to reflect single list brken into chunks
		for (auto number: list.get()){
			std::cout << number << std::endl;
			std::cout << firstTwoDigits(number) << std::endl;
		}
		if (cores == 10 || cores == 20) {
			isParallel = true;
		}
		else {
			threads.push_back(std::thread(sort, list));
		}

		if (++created == lists.size() || threads.size() == cores) {
			for (auto &thread : threads) 
				thread.join();
			threads.clear();
		}



	}
}
