/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#include <vector>
#include <string>
#include <iostream>
#include <functional>

/*
 * Simple multi-threaded Radix Sort with support for Most Significant Digit 
 * sorting only.
 */
class RadixSort {
public:
    /*
     * Create a multi-threaded RadiX Sort restricted to using no more than 
     * CORES processor cores.
     */
    RadixSort(const unsigned int cores);

    /*
     * Perform an in-place Most Significant Digit Radix Sort on each list of
     * unsigned integers in LISTS.
     */
    void msd(std::vector<std::reference_wrapper<std::vector<unsigned int>>> &lists);
};
static const char SEPARATOR = ' ';
static const int MAX_LENGTH = 125;
const std::string MSG_EMPTY_DS = "ds i m-t";




class theDS {
 public:

  std::vector<std::string> WordList;

  theDS();

  ~theDS();

  // Adds one word to the datastructure
  void add(std::string& word);

  // Sorts the datastructure
  void sort();

  // Prints datastructure
  // Stream is given as a parameter and it is either cout or file
  void print();

   // Prints shortest word and length
  void shortest();

  // Prints longest word and length
  void longest();

  // Empties the datastructure
  void empty();

 private:
  // Copy constructor is forbidden
  theDS(const theDS&);
  // Assignment operator is forbidden
  theDS& operator=(const theDS&);

  // Student impelements data structure(s), private member(s) and
  // private function(s) here, if needed.
struct WordDir
 {
   unsigned long length;
   std::string wordname;
   //unsigned int _position;

 };

// This structure is used to save maximum and minimum length word 
  // This is the main word list where words are stored sortely.
//  std::vector<std::string> WordList; //made public

  // structure object to keep max and min length of the word.
  WordDir lengthOfMin;

  WordDir lengthOfMax;

  // MSD radix function decleration to sort words 
  //lexicgraphically using most significat bits.
  void radixSort(std::vector<std::string> tempOneDimList,
        unsigned int siz,  unsigned int m);


};

