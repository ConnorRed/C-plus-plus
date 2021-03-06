/*
* utilities.h
*
*  Created on: Aug 28, 2016
*      Author: Keith
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#ifndef UTILITIES_H_
#define UTILITIES_H_

const int 			SUCCESS			 				=  0;
const int 			FAIL							=  SUCCESS - 1;
const int 			USER_CHOSE_TO_EXIT 				=  SUCCESS - 2;
const int 			COULD_NOT_OPEN_FILE				=  SUCCESS - 3;
const int 			COULD_NOT_READ_FILE				=  SUCCESS - 4;
const int			UNINITIALIZED					=  SUCCESS - 5;
const char			CHAR_TO_SEARCH_FOR				=',';

//this is where the loaded data goes
struct process_stats{
	int process_number;
	int	start_time;
	int cpu_time;
};

enum SORT_ORDER { CPU_TIME, PROCESS_NUMBER, START_TIME };

//allthe functions available for use

//attempt to open file 'filename' to read, parse its rows
//into process_stats structs and add these structs to a vector
//
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int loadData(const char* filename);

//attempt to open file 'filename' to write, and serialize a
//vector full of process_stats structs to it.  Should be in the same
//format as original file but not necessarily the same order or length
//
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int saveData(const char* filename);

//sorts the vector, returns nothing (thats what void means)
void sortData(SORT_ORDER mySortOrder);

//return the first struct in the vector
//then deletes it from the vector
process_stats getNext();

#endif /* UTILITIES_H_ */
