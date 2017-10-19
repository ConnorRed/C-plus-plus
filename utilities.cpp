//
//  utilities.cpp
//  CPSC410
//
//  Connor Redmon
//

#include <stdio.h>
#include "utilities.h"

using namespace std;
vector<process_stats> cram;

int loadData(const char* filename){
    ifstream myInputFile;
    myInputFile.open(filename, ios::in);

    if (myInputFile.is_open()){
        string line;
        while (!myInputFile.eof()){
            process_stats tempStats;
            getline(myInputFile,line);
            if (line == "")
                break;

            cout<<line;
            string string1 = line.substr(0, line.find_first_of(','));
            string string2 = line.substr(line.find_first_of(',')+1, (line.find_last_of(',') - line.find_first_of(',')-1));
            string string3 = line.substr(line.find_last_of(',')+1, (line.length() - line.find_last_of(',')));
            tempStats.process_number = stoi(string1);
            tempStats.start_time = stoi(string2);
            tempStats.cpu_time = stoi(string3);

            cram.push_back(tempStats);
        }
        myInputFile.close();
        return SUCCESS;
    }
    else {
        return COULD_NOT_OPEN_FILE;
    }

}

int saveData(const char* filename){
    ofstream myOutputFile;
    myOutputFile.open(filename, ios::out);

    if (myOutputFile.is_open()){
        for (std::vector<process_stats>::iterator it = cram.begin(); it != cram.end(); it++){
            myOutputFile << (to_string((*it).process_number) + "," +
                             to_string((*it).start_time) + "," + to_string((*it).cpu_time)+ "\n");
        }

        myOutputFile.close();
        return SUCCESS;
    }
    else
        return COULD_NOT_OPEN_FILE;
}

void sortData(SORT_ORDER mySortOrder){
    if (mySortOrder == PROCESS_NUMBER) {
        int i = 0;
        for (std::vector<process_stats>::iterator it = cram.begin(); it != cram.end(); it++){
            process_stats lowestValue = (*it);
            int j = i;
            process_stats temp = (*it);
            int min = i;
            for (std::vector<process_stats>::iterator it2 = it; it2 != cram.end(); it2++){
                if ((*it2).process_number < lowestValue.process_number) {
                    lowestValue = (*it2);
                    temp = cram[j];
                    min = j;
                }
                j++;
            }
            cram[min] = cram[i];
            cram[i] = temp;
            i++;
        }
    }

    if (mySortOrder == CPU_TIME) {
        int i = 0;
        for (std::vector<process_stats>::iterator it = cram.begin(); it != cram.end(); it++){
            process_stats lowestValue = (*it);
            int j = i;
            process_stats temp = (*it);
            int min = i;
            for (std::vector<process_stats>::iterator it2 = it; it2 != cram.end(); it2++){
                if ((*it2).cpu_time < lowestValue.cpu_time) {
                    lowestValue = (*it2);
                    temp = cram[j];
                    min = j;
                }
                j++;
            }
            cram[min] = cram[i];
            cram[i] = temp;
            i++;
        }
    }

    if (mySortOrder == START_TIME) {
        int i = 0;
        for (std::vector<process_stats>::iterator it = cram.begin(); it != cram.end(); it++){
            process_stats lowestValue = (*it);
            int j = i;
            process_stats temp = (*it);
            int min = i;
            for (std::vector<process_stats>::iterator it2 = it; it2 != cram.end(); it2++){
                if ((*it2).start_time < lowestValue.start_time) {
                    lowestValue = (*it2);
                    temp = cram[j];
                    min = j;
                }
                j++;
            }
            cram[min] = cram[i];
            cram[i] = temp;
            i++;
        }
    }
}

process_stats getNext(){
    process_stats temp = cram[0];
    vector<process_stats> tempVector;
    for (std::vector<process_stats>::iterator it = cram.begin() +1; it != cram.end(); it++){
        tempVector.push_back(*it);
    }

    int i = 0;
    for (std::vector<process_stats>::iterator it = tempVector.begin(); it != tempVector.end(); it++){
        cram[i] = (*it);
        i++;
    }
    cram.pop_back();
    return temp;
}
