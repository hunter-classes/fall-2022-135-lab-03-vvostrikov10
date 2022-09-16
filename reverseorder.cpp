
/*
Author: Vladislav Vostrikov
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab 3

Contains revese_order which returns west elevations in reverse chronological order in specified range
*/
#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include "reservoir.h"



void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string junk;
    getline(fin, junk);
    int cond =0;
    std::string current_date, eastSt, eastEl, westSt, westEl;
    std::string ans = "";
    while(fin >> current_date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns 
        if (current_date == date1){
            cond=1;
        }
        if (cond){
            ans = current_date + " " + westEl + "\n" +ans;
        }
        if (current_date == date2){
            std::cout << ans;
        }
    }
}
