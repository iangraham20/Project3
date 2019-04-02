/* Path.cpp is the class representing the directories a shell searches
 * 
 * Authors:  Ian Christensen
 *					 Nate Gamble
 * Date:    March 28, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#include "Path.h"

/* Function: Default Constructor Method
 * Precondition: The environment path must not be NULL
 * Postcondition: myDirectories is not empty
 * Parameters: none
 * Returns: A Path object
 */
Path::Path() {
	myPath = getenv("PATH");
	if (myPath == NULL)
		cerr << "Error: invalid path" << endl;
  char* directory = strtok(myPath, ":");
  while (directory != NULL) {
      myDirectories.push_back(directory);
      directory = strtok(NULL, ":");
  }
}

/* Function: Default Destructor Method
 * Precondition:
 * Postcondition:
 * Parameters:
 * Returns:
 */
Path::~Path() {

}

/* Function: find locates the directory that contains program
 * Precondition: The program exists somewhere in one of the directoryectories
 * Postcondition: Either the location was returned or -1 was
 * Parameters: program, a const string&; A reference to the program
 * Returns: index, an int; The index for the releventry path in myDirectories
 */
int Path::find(const string& program) const {
	DIR *directory;
	struct dirent *entry;
	for (int i = 0; i < myDirectories.size(); i++) {
		directory = opendir(myDirectories[i].c_str());
		while ((entry = readdir(directory)) != NULL) {
			if (entry->d_type == DT_REG) {
				if (entry->d_name == program)
					return i;
			}
		}
	}
	return -1;
}

/* Function: Accessor method for directoryectories in myDirectories
 * Precondition: The index is within the range of myDirectories
 * Postcondition: The correct directory path was returned
 * Parameters: i, an int; The index of the directory path being accessed
 * Returns: myDirectories[i], a string; The releventry directory path
 */
string Path::getDirectory(int i) const {
	if (i >= myDirectories.size() || i < 0) {
		cerr << "Error: invalid index" << endl;
	} else {
		return myDirectories[i];
	}
}
