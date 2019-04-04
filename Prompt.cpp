/* Prompt.cpp is a class representing the command-line prompt
 * 
 * Author:  Ian Christensen
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
	getcwd(myFullPath, FILENAME_MAX);
}

/* Function: Default Destructor Method
 * Precondition:
 * Postcondition:
 * Parameters: none
 * Returns: none
 */ 
Prompt::~Prompt() {

}

/* Function: Accessor Method for the buf attribute
 * Precondition: buf exists
 * Postcondition: buf is accessed
 * Parameters: none
 * Returns: buf, the buffer value
 */
string Prompt::get() const {
	return string(myFullPath);
}
