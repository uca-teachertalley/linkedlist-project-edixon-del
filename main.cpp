/*
 TODO:(student) Add a comment header for the program here.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
/**
 * @brief Searches for a given string value in a list of strings.
 *
 * This is a helper function that searches for a given string value
 * in a list of strings using the standard library find function.
 *
 * Interestingly, the standard list class does not have a find method.
 *
 * @param myList The list to search in.
 * @param value The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool find(const std::list<std::string> &myList, const std::string &value)
{
    bool found = (std::find(myList.begin(),
                            myList.end(),
                            value) != myList.end());
    return found;
}

/**
 * @brief Reads, updates, and writes a list of movies.
 *
 * This function reads in a list of movies from a file,
 * adds new movies to the list, removes movies from the list,
 * and outputs the updated list to a file.
 *
 * @return int The exit status of the program.
 */
int main()
{
    // Follow instructions in project assignment
    return EXIT_SUCCESS;
}
