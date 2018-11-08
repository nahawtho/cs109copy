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

static void sort(std::vector<unsigned int> &list) {
	if (isParallel == false)std::sort(list.begin(), list.end(), compare);
	else {}
}
static inline int firstDigit(int x) {
    while (x > 9) {
        x /= 10;
    }
    return x;
}
/*static std::string firstNumber(unsigned int num)
  {
  std::stringstream ss;
  ss << num;
  return ss.str();
  }
 */

void ParallelRadixSort::msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists, unsigned int cores) { 
	// your implementation goes here :)
	std::cout << cores << std::endl;
	std::vector <std::thread> threads;
	isParallel = false;
	unsigned int created = 0;
	for (auto list: lists) {
		if (cores != 10 || cores != 20) threads.push_back(std::thread(sort, list));
		else {
			isParallel = true;
			threads.push_back(std::thread(sort, list));
		}
		//	add digit buckets to thread vector here
		//	std::cout << firstNumber(num) << std::endl;
		if (++created == lists.size() || threads.size() == cores) {
			for (auto &thread : threads) 
				thread.join();
			threads.clear();
		}
	}
}
