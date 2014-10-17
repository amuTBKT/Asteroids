/*
 * FileLoader.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: amu
 */

#include "FileLoader.h"

std::string FileLoader::loadFile(char* file){
	std::ifstream fin(file);

	std::string line;
	std::string output = "";

	if (!fin.is_open()) return "";

	while (std::getline(fin, line)){
		output.append(line);
		output.append(" ");
	}

	fin.close();

	return output;
}
