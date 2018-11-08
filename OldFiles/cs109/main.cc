/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */
// https://opencast-player-1.lt.ucsc.edu:8443/engage/theodul/ui/core.html?id=e37d6e88-1809-4058-9c2d-fed46395e6dd
// https://codereview.stackexchange.com/questions/95935/c-2d-shape-intersections-template-reduction
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <regex>
using namespace std;
#include <exception>
#include <vector>
#include "circle.h"
#include "cube.h"
#include "polygon.h"
#include "reuleaux.h"
#include "point.h"
//#include "cube.cc"
#define min(a,b) (((a)<(b)? a:b))
#define max(a,b) (((a)<(b)? b:a))
#define CIRCLE 0
#define CONVEXPOLYGON 1
#define REGULARCONVEXPOLYGON 2
#define REULEAUXTRIANGLE 3
#define CUBE 4
#define SPHERE 5
#define REULEAUXTETRAHEDRON 6
#define INNER 0
#define OUTER 1

Point getPoint(vector <string> tokens, unsigned int i){
	//parse numbers from double,double format
	//create point
	//print point
	//return point
	//cout << tokens[i];
	double x, y;
	char comma;
	if ((++i) < tokens.size()){

		std::istringstream wDoubles(tokens[i]);
		//if (tokens[i].length() != 3) cout << "point in wrong format\n"; //find a way to skip line
		//else cout << "point in right format\n";
		wDoubles >> x;
		wDoubles >> comma;
		wDoubles >> y;
		std::cout << "x: " << x << "y: " << y << std::endl;

		//cout << tokens[i];
	}
	return Point(x, y);
}
double getRad(vector <string> tokens, unsigned int i){
	double rad;
	//std::cout << "hopefully rad" << tokens[i+2] << "<here";
	std::istringstream wRad(tokens[i+2]); //circles only have static points, so non-pointer arithmetic will work HERE
	if ((++i) < tokens.size()){ wRad >> rad;}
	else {std::cerr << "no rad\n";}
	std::cout << "\nrad: " << rad;
	return rad;
}

	template<typename I, typename O>
static void test(I inner, O outer, bool expected, const char *msg)
{
	if (inner.containedBy(outer) == expected)
		std::cout << "PASS\n";
	else
		std::cout << "FAIL\n";
	std::cout << " " << msg << std::endl;

}

int main(int argc, char *argv[]) 
{
	ifstream testFile;
	vector <string> tokens; //tokenize within line

	if (argc > 1) {
		std::string fname(argv[1]);
		testFile.open(fname.c_str());
	}

	unsigned int lastLength = 0;

	std::string line;
	int lineNum=0;
	//int shapeCountTemp=0;
	while (std::getline(testFile, line))
	{
		lineNum++;
		if (line.empty()) continue; //skip blank lines
		std::istringstream iss(line);
		//std::cout << line << std::endl;
		//remove leading and trailing whitespace from string
		//requires g++ -std=c++17
		//std::cout << line <<std::endl;
		string forComment = line;

		line = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");
		string intermediate;
		stringstream line_check(line);
		while(std::getline(line_check, intermediate, ' '))
		{
			//std::cout << line_check << std::endl;
			tokens.push_back(intermediate);
		}

		//PROCESS FORMAT, FUCTIONS, POINTS
		std::string shapes[7] = {"Circle", "ConvexPolygon", "RegularConvexPolygon", "ReuleauxTriangle", "Cube", "Sphere", "ReuleauxTetrahedron"};
		int shapeCount = 0;

		std::vector<Point> zeroPoints = std::vector<Point>{};
		Circle c1 = Circle (Point(0,0), 0); 
		Circle c2 = Circle (Point(0,0), 0);
		//ConvexPolygon cp1;
		//ConvexPolygon cp2;
		std::vector<Point> poly1 = {};
		std::vector<Point> poly2 = {};	
		RegularConvexPolygon rcp1 = RegularConvexPolygon(zeroPoints);
		RegularConvexPolygon rcp2 = RegularConvexPolygon(zeroPoints);
		ConvexPolygon cp1 = ConvexPolygon(zeroPoints);
		Point3D upper[4] = {Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0)};
		Point3D lower[4] = {Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0)};
		Cube cube = Cube(upper, lower);
		/*ReuleauxTriangle rt1;
		  ReuleauxTriangle rt2;
		  Cube cube1;
		  Cube cube2;
		  Sphere s1;
		  Sphere s2;
		  ReuleauxTetrahedron rtet1;
		  ReuleauxTetrahedron rtet2;
		 */
		bool oneIsCirc = false;
		bool oneIsRCP = false;

		bool ContainedByC = false;
		bool ContainedByRCP = false;

		char forComment2 = forComment[0];
		if ( forComment2 == '#' ) std::cout << "found a pound sign" << std::endl;
		if ( forComment2 != '#'){ //IF NO COMMENT PROCESS TOKENS
			for(unsigned int i =  lastLength; i < tokens.size(); i++){  //loop ovr new tokens (next line)
				std::vector<Point> poly1 = {};
				std::vector<Point> poly2 = {};
				//std::cout << tokens[i]; 
				//std::cout << "tokens.size(): " << tokens.size() << std::endl;
				//std::cout << "lastLength: " << lastLength << std::endl;
				//std::cout << "tokens[" << i << "]: " << tokens[i] << std::endl; //print tokens
				for (int j=0; j<7; j++){
					if (shapes[j] == tokens[i]){
						std::cout << tokens[i] << "<<token"<< std::endl;
						shapeCount = shapeCount + 1;
						//std::cout << shapeCount << std::endl;
						//std::cout << "\nFound " << shapes[j] << std::endl;
						if (tokens[i] == "Circle"){
							//std::vector<Point> points = std::vector<Point>{Point(-8.0,-8.0), Point(0.0,8.0), Point(8.0, -8.0)};
							if (shapeCount == 1){
								cout << "shape1";
								c1 = Circle(getPoint(tokens, i),getRad(tokens, i));
								oneIsCirc = true;
							}
							if (shapeCount == 2){ 
								cout << "shape2";
								std::cout << "found 2 shapes on line " << lineNum << std::endl;

								std::string text;
								if ((i+3) < tokens.size()){
									std::cout << "T/F" << tokens[i+3] << std::endl;
									if("true" == tokens[i+3]){ cout<< "isTRUE"; ContainedByC  = true;}
									if("false" == tokens[i+3]){ cout<< "isFALSE"; ContainedByC = false;}
									Circle c2 = Circle(getPoint(tokens, i),getRad(tokens, i));
									if (oneIsCirc){
										test(c1, c2, ContainedByC, "Circle-is too big"); //change inner param for other possibilities
										std::cout << "\nCircle C1pt,rad: " << c1.center().x << c1.center().y << c1.radius() << std::endl;
										std::cout << "\nCircle C2pt,rad: " << c2.center().x << c2.center().y << c2.radius() << std::endl;
									}
									if (oneIsRCP){

										test(rcp1, c2, ContainedByC, " ok ");	
										std::cout << "\npolyPts" << rcp1.vertices_[0].x << rcp1.vertices_[0].y 
											<< rcp1.vertices_[1].x << rcp1.vertices_[1].y;
										std::cout << "\nCircle C2pt,rad: " << c2.center().x << c2.center().y << c2.radius() << std::endl;
									}
								}
							}
						}
						if (tokens[i] == "RegularConvexPolygon" || tokens[i] == "ConvexPolygon" ){ // design something for different i numbers
							//std::vector<Point> points = std::vector<Point>{Point(-8.0,-8.0), Point(0.0,8.0), Point(8.0, -8.0)};
							if (shapeCount == 1){
								//seek number of points. Make std::vector<Point> of points.
								int numberOfVertices = 4;  //wrong. assumes i is at end of pts of tokens
								for (unsigned int l = lastLength; l < lastLength + numberOfVertices ; l++) poly1.push_back(getPoint(tokens, l));
								rcp1 = RegularConvexPolygon(poly1);//(getPoint(tokens, i),getRad(tokens, i));
								oneIsRCP = true;
							}
							if (shapeCount == 2){
								int numberOfVertices = tokens.size() - i - 2;
								std::cout << "NVert: " << numberOfVertices << std::endl;
								std::cout << "found 2 shapes on line " << lineNum << std::endl;
								for (unsigned int l = i; l < numberOfVertices + i; l++) poly2.push_back(getPoint(tokens, l));

								if ((i+2+numberOfVertices) == tokens.size()){
									std::cout << "T/F" << tokens[i+1+numberOfVertices] << std::endl;
									if("true" == tokens[i+1+numberOfVertices]){ cout<< "isTRUE"; ContainedByRCP  = true;}
									if("false" == tokens[i+1+numberOfVertices]){ cout<<"isFALSE"; ContainedByRCP = false;}
									rcp2 = RegularConvexPolygon(poly2);//(getPoint(tokens, i),getRad(tokens, i));
								}
								if (oneIsCirc) test(c1, rcp2, ContainedByRCP, "Circle-is too big"); //change inner param for other possibilities
								if (oneIsRCP) test(rcp1, rcp2, ContainedByRCP, " ok2 ");
							}
						}
					}
				}
				//std::cout << "found 2 shapes on line " << lineNum << std::endl;
				if (i == (tokens.size() - 1)){
					lastLength = tokens.size();
				}
			}
		}
	}
	testFile.close();
	return -1;
}
#undef min
#undef max
#undef CIRCLE 
#undef CONVEXPOLYGON 
#undef REGULARCONVEXPOLYGON 
#undef REULEAUXTRIANGLE 
#undef CUBE 
#undef SPHERE 
#undef REULEAUXTETRAHEDRON 
#undef INNER
#undef OUTER
