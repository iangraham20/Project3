/* Path.h is the header of the class representing the directories a shell searches
 * 
 * Authors:  Ian Christensen
 *					 Nate Gamble
 * Date:    March 28, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <dirent.h>

using namespace std;

class Path {
	public:
		Path();
		~Path();
		int find(const string& program) const;
		string getDirectory(int i) const;
	private:
		char *myPath;
		vector<string> myDirectories;
};

#endif /* PATH_H */
