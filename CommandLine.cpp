/* CommandLine.cpp
 * 
 * Authors:  Nate Gamble
 *					 Ian Christensen
 * Date:    April 4, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#include "CommandLine.h"

/* CommandLine
 * Takes in an istream
 * Finds the number of arguments and puts it in myArgc
 * Puts a char** array of arguments (with the last being NULL) in myArgv
 * Finds if there is an ampersand in the argument list
 */
CommandLine::CommandLine(istream& in) {
	ampersand = false;
	getline(in, myCommandLine);
	if (myCommandLine == "") {
		emptyStr = true;
		return;
	}
	istringstream iss(myCommandLine);
	vector<string> tempArgv;
	for (string s; iss >> s; ) {
		tempArgv.push_back(s);
		myArgc += 1;
	}

	setmyArgv(tempArgv);
}

	// Converts input from a string into a StringStream
	// Reads each character individually from SS
	// Uses calloc() to allocate appropriate amount of space
void CommandLine::setmyArgv(vector<string> tempArgv) {
	istringstream iss2(myCommandLine);
	char* argv[255];
	bool breakout = false;
	char space = ' ';
	char newLine = '\n';
	for (int i = 0; i < myArgc; i++) {
		char *temp = (char*) calloc(255, sizeof(char));
		int j = 0;
		while(true) {
			char singleChar;
			iss2.get(singleChar);
			if (singleChar == space) {
				temp[j] = '\0';
				break;
			} else if (singleChar == newLine || iss2.eof()) {
				temp[j] = '\0';
				breakout = true;
				break;
			} else if (singleChar == '&') {
				ampersand = true;
			} else {
				temp[j] = singleChar;
				j++;
			}
		}
		argv[i] = temp;
		if (breakout) { break; }
	}
	argv[myArgc] = NULL;
	myArgv = (char**) argv;
}
