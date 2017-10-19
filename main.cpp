//
//  main.cpp
//  CPSC410
//
// Connor Redmon
//
// main.cpp : Defines the entry point for the console application.
//

#include "utilities.h"

using namespace std;

int main() {
    const char* myFile = "testdata.txt";
    int load = 1;
    load = loadData(myFile);     //return loaded data

    SORT_ORDER thing = CPU_TIME;
    sortData(thing);

    const char* myFile2 = "outputdata.txt";
    int save = 1;
    save = saveData(myFile2);

    process_stats first = getNext();
    cout << first.cpu_time;
    cout << first.process_number;
    cout << first.start_time;

    return 0;

}

