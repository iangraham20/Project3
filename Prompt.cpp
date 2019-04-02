/* Prompt.cpp is a class representing the command-line prompt
 * 
 * Authors:  Ian Christensen
 *					 Nate Gamble
 * Date:    March 28, Spring Semester 2019
 * Class:   CS-232-A, Operating Systems
 *          with Joel Adams at Calvin College
 * Project: 3, Command Shell
 */

#include "Prompt.h"

/* Function: Default Constructor Method
 * Precondition: The current directory exists
 * Postcondition: buf is equal to the current directory
 * Parameters: none
 * Returns: A Prompt object
 */
Prompt::Prompt() {
	size = pathconf(".", _PC_PATH_MAX);
	if ((buf = (char*)malloc((size_t)size)) != NULL)
    ptr = getcwd(buf, (size_t)size);
  strcat(buf, "$");
}

/* Function: Default Destructor Method
 * Precondition: The malloc command was used
 * Postcondition: All memory has been reclaimed
 * Parameters: none
 * Returns: none
 */
Prompt::~Prompt() {
	free(buf);
}

/* Function: Accessor Method for the buf attribute
 * Precondition: buf exists
 * Postcondition: buf is accessed
 * Parameters: none
 * Returns: buf, the buffer value
 */
string Prompt::get() const {
	return buf;
}
