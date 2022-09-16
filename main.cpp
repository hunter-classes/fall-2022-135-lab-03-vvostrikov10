
/*
Author: Vladislav Vostrikov
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab 3

Tests functions from reservoir.cpp reverseorder.cpp
*/
#include <iostream>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"

int main(){
    std::cout << "Testing get_east_storage" << std::endl;
    std::cout << get_east_storage("01/01/2018") << std::endl;
    std::cout << get_east_storage("03/15/2018") << std::endl;
    std::cout << get_east_storage("07/19/2018") << std::endl;
    std::cout << get_east_storage("12/30/2018") << std::endl;
    std::cout << "Testing get_min_east" << std::endl;
    std::cout << get_min_east() << std::endl;
    std::cout << "Testing get_max_east" << std::endl;
    std::cout << get_max_east() << std::endl;
    std::cout << "Testing compare_basins" << std::endl;
    std::cout << compare_basins("01/01/2018") << std::endl;//West
    std::cout << compare_basins("12/30/2018") << std::endl; //West
    std::cout << compare_basins("07/26/2018") << std::endl; //East
    std::cout << compare_basins("test_equal") << std::endl; //added entry test_equal at the end of the tsv file to test equal elevations
    std::cout << "Testing reverse_order" << std::endl;
    reverse_order("01/01/2018", "01/01/2018");
    std::cout << "testing reverse_order" << std::endl;
    reverse_order("01/01/2018", "01/15/2018");
    std::cout << "testing reverse_order" << std::endl;
    reverse_order("05/29/2018", "06/02/2018");
       

    return 0;
}
