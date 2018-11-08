#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h> 
#include <regex>
#include <map> 
#include <vector>
#include <iterator> 
#include <algorithm>    // std::find


using namespace std;


int main(int argc, char *argv[]){
	ifstream testFile;

	if (argc > 1) { //setup
		std::string fname(argv[1]);
		testFile.open(fname.c_str());
	}

	std::string line;
	int linenum = 1;
	while (std::getline(testFile, line))
	{
		if (line.empty()) continue; //skip blank lines
		std::istringstream iss(line);
		//		std::cout << "linenum: " << linenum++ //print entire line
		//			<< " " << line << std::endl;

		//remove leading and trailing whitespace from string
		//requires g++ -std=c++17
		line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

		vector <string> tokens; //tokenize within line
		string intermediate;
		stringstream line_check(line);
		while(std::getline(line_check, intermediate, ' '))
		{
			tokens.push_back(intermediate);
		}

		std::string forComment = tokens[0];	
		if ( forComment[0] != '#'){
			for(int i = 0; i < tokens.size(); i++){ 
				cout << tokens[i] << '\n'; //print tokens
				//process tokens here
			}
		} 
	}

	testFile.close();
	return 0;
}
