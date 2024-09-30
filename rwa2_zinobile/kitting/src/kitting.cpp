#include <iostream>
#include <array>

void get_initial_state(int &ri, int &gi, int &bi) {
    std::cout << "------------------------------------------------------------------------\n";
    std::cout << "Please enter the number of blocks in each bin (maximum 10 blocks per bin)\n";
    std::cout << "------------------------------------------------------------------------\n";
    std::cout << "Red: ";
    std::cin >> ri;
    std::cout << "Green: ";
    std::cin >> gi;
    std::cout << "Blue: ";
    std::cin >> bi;
    std::cout << "------------------------------------------------------------------------\n";
}

void get_goal_state(int &rg, int &gg, int &bg) {
    std::cout << "Please enter the number of blocks for each color to place in the tray (max 10 blocks per color)\n";
    std::cout << "-----------------------------------------------------------------------------------------------\n";
    std::cout << "Red blocks: ";
    std::cin >> rg;
    std::cout << "Green blocks: ";
    std::cin >> gg;
    std::cout << "Blue blocks: ";
    std::cin >> bg;
    std::cout << "---------------------------------------------------------------------------------------------\n";
}

int pick(int int_color, int bin_status) {
    std::array color{"red", "green", "blue"};    
    std::cout << "Picking 1 " << color.at(int_color) << " block\n"; 
    bin_status = bin_status-1;
    std::cout << "  " << bin_status << " blocks remaining in " << color.at(int_color) << "bin\n";
    return bin_status;
}

int place(int int_color, int blocks_needed) {
    std::array color{"red", "green", "blue"};
    std::cout << "Placing 1 " << color.at(int_color) << " block\n";
    blocks_needed = blocks_needed - 1;
    std::cout << "  " <<blocks_needed << " " << color.at(int_color) <<" blocks still needed in the tray\n";
    return blocks_needed;
}

std::string gripper_status(bool gripper_empty) {
    if (gripper_empty == true) {
        return "  Gripper is empty\n";
    }
    else {
        return "  Gripper holding block\n";
    }

}