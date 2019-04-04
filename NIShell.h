/* NIShell.h
 * 
 * Authors: Nate Gamble
 *					Ian Christensen
 * Date:    March 28, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#ifndef NISHELL_H
#define NISHELL_H

#include "CommandLine.h"
#include "Path.h"
#include "Prompt.h"
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sched.h>

#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

class NIShell {
	public:
		NIShell();
		void run();
	private:
		Path myPath;
		Prompt myPrompt;
		bool commands(string str, CommandLine myCommandLine); 
};

#endif /* NISHELL_H */
