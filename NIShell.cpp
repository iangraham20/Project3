/* NIShell.cpp
 * 
 * Authors: Nate Gamble
 *					Ian Christensen
 * Date:    March 28, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#include "NIShell.h"

/* Function: 
 * Precondition:
 * Postcondition:
 * Parameters:
 * Returns:
 */
NIShell::NIShell() {

}

/* Function:
 * Precondition:
 * Postcondition:
 * Parameters:
 * Returns:
 */
void NIShell::run() {
	while (true) {

		cout << myPrompt.get() << "$" << flush;
		CommandLine myCommandLine(cin);
		string filename;
		if (myPath.find(myCommandLine.getCommand()) != -1) {
			int index = myPath.find(myCommandLine.getCommand());
			string dir = myPath.getDirectory(index);
			filename = dir + "/" + myCommandLine.getCommand();
		}

		pid_t pid = fork();
		string str(myCommandLine.getCommand());
		if (pid == 0) {
			extern char** environ;
			if (str == "cd") {
				chdir(myCommandLine.getArgVector(1));
				Prompt newPrompt;
				myPrompt = newPrompt;
				continue;
			} else if (str == "pwd") {
				char cwd[PATH_MAX];
				if (getcwd(cwd, sizeof(cwd)) != NULL) {
					cout << cwd << endl;
				}
				continue;
			} else if (str == "exit") {
				exit(0);
			} 
			// if (commands(str, myCommandLine)) {
			// 	continue;
			// } 
			else {
				int sysCmd = execve(filename.c_str(), myCommandLine.getArgVector(), environ);
				if (sysCmd == -1) { cout << errno << endl; }
				continue;
			}
		} else if (myCommandLine.noAmpersand()) {
			int status;
			while (waitpid(0, &status, WNOHANG) == 0) {
				sched_yield();
			}
			if (str == "exit") {
				exit(0);
			}
		}
	}
}

bool NIShell::commands(string str, CommandLine myCommandLine) {
	if (str == "cd") {
		chdir(myCommandLine.getArgVector(1));
		Prompt newPrompt;
		myPrompt = newPrompt;
	} else if (str == "pwd") {
		char cwd[PATH_MAX];
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			cout << cwd << endl;
		}
	} else if (str == "exit") {
		exit(0);
	} else {
		return true;
	}
	return false;
}