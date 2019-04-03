/* CommandLine.h
 * 
 * Authors:  Nate Gamble
 *					 Ian Christensen
 * Date:    April 4, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <istream>
using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	char* getCommand() const { return myArgv[0]; }
	int getArgCount() const { return myArgc; }
	char** getArgVector() const { return myArgv; }
	char* getArgVector(int i) const { return myArgv[i]; }
	bool noAmpersand() const { return !ampersand; }

private:
	string myCommandLine;
	int myArgc = 0;
	char** myArgv;
	bool ampersand;
};

#endif /* COMMANDLINE_H_ */
