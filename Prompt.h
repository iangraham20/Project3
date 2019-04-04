/* Prompt.h is the header for the class representing the command-line prompt
 * 
 * Author:  Ian Christensen
 * Date:    March 28, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class Prompt {
	public:
		Prompt();
		~Prompt();
		string get() const;
	private:
		char myFullPath[FILENAME_MAX];
};

#endif /* PROMPT_H */
