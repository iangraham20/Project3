/* NIShell.cpp
 * 
 * Authors:  Ian Christensen
 *					 Nate Gamble
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
		cout << myPrompt.get() << flush;
		CommandLine myCommandLine(cin);
		int index = myPath.find(myCommandLine.getCommand());
		string dir = myPath.getDirectory(index);
		string filename = dir + "/" + myCommandLine.getCommand();

		pid_t pid = fork();
		if (pid == 0) {
			extern char** environ;
			cout << endl;

			if (myCommandLine.getCommand() == "cd") {
				chdir(myCommandLine.getArgVector(1));
			} else if (myCommandLine.getCommand() == "pwd") {
				char cwd[PATH_MAX];
				if (getcwd(cwd, sizeof(cwd)) != NULL) {
					cout << cwd << endl;
				}
			} else if (myCommandLine.getCommand() == "exit") {
				exit(0);
			} else {
				int sysCmd = execve(filename.c_str(), myCommandLine.getArgVector(), environ);
				if (sysCmd == -1) { cout << errno << endl; }
			}
		exit(0);

		} else if (myCommandLine.noAmpersand()) {
			int status;
			while (waitpid(0, &status, WNOHANG) == 0) {
				sched_yield();
			}
		} 
	}
}
