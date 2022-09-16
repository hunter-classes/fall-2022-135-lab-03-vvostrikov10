
/*
Author: Vladislav Vostrikov
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab 3

Contains functions for reading data from tsv file
*/
#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string junk;
    getline(fin, junk);

    std::string current_date, eastSt, eastEl, westSt, westEl;
    while(fin >> current_date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns 
        if (current_date == date){
            fin.close();
            return std::stod(eastSt);
        }
    }

    return -1;
}

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string junk;
    getline(fin, junk);
    double min_st = 1000000;
    std::string current_date, eastSt, eastEl, westSt, westEl;
    while(fin >> current_date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns 
        double cur_storage=std::stod(eastSt);

        if (min_st > cur_storage){
            min_st=cur_storage;
        }
    }

    return min_st;
}


double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string junk;
    getline(fin, junk);
    double max_st = -1;
    std::string current_date, eastSt, eastEl, westSt, westEl;
    while(fin >> current_date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns 
        double cur_storage=std::stod(eastSt);
        if (max_st < cur_storage){
            max_st=cur_storage;
        }
    }

    return max_st;
}

std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string junk;
    getline(fin, junk);

    std::string current_date, eastSt, eastEl, westSt, westEl;
    while(fin >> current_date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns 
        //if (eastEl == westEl){
        //    std::cout << current_date << std::endl;
        //}
        if (current_date == date){
            fin.close();
            double eastNum = std::stod(eastEl);
            double westNum = std::stod(westEl);
            if (eastNum == westNum) return "Equal";
            if (eastNum > westNum) return "East";
            return "West";
        }
    }

    return "ERROR";
}
