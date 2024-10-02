#include <iostream>
#include <array>

//!Function to retrieve initial state of bins
void get_initial_state(int &ri, int &gi, int &bi) //!Initialize function with int reference inputs
{
    std::array<int*, 3> intl_states {&ri, &gi, &bi}; //!Create array of pointers to addresses of initial states
    std::array colors {"Red", "Green", "Blue"};

    std::cout << "---------------------------------------------------------------------------------------------\n";
    std::cout << "Please enter the number of blocks in each bin (maximum 10 blocks per bin)\n";
    std::cout << "---------------------------------------------------------------------------------------------\n";
    
    for (char i = 0; i < 3; i++)
    {
        std::cout << colors.at(i) << ": ";
        std::cin >> *intl_states.at(i); //!Write initial state inputs to memory addresses in pointer array

        //!Reject invalid initial state inputs 
        while (*intl_states.at(i) < 0 || *intl_states.at(i) > 10) {
            std::cout << "Error: minimum 1, maximum 10 blocks per bin\n";
            std::cout << colors.at(i) << ": ";
            std::cin >> *intl_states.at(i);
        }
    }
    

    std::cout << "---------------------------------------------------------------------------------------------\n";
}

//!Function to retrieve desired state of tray
void get_goal_state(int &rg, int &gg, int &bg)//!Initialize function with int reference inputs
{
    std::array<int*, 3> goal_states {&rg, &gg, &bg};//!Create array of pointers to addresses of goal states
    std::array colors {"Red", "Green", "Blue"};

    std::cout << "Please enter the number of blocks for each color to place in the tray (minimum 1, maximum 10 total blocks on tray)\n";
    std::cout << "---------------------------------------------------------------------------------------------\n";
    
    for (char i = 0; i < 3; i++)
    {   
        std::cout << colors.at(i) << " blocks: ";
        std::cin >> *goal_states.at(i);//!Write goal state inputs to memory addresses in pointer array

        //!Reject invalid goal state inputs
        while (*goal_states.at(i) < 0) {
            std::cout << "Error: cannot place negative blocks on tray\n";
            std::cout << colors.at(i) << " blocks: ";
            std::cin >> *goal_states.at(i);
        }   
    }

    std::cout << "---------------------------------------------------------------------------------------------\n";
}

//!Function to confirm tray goal state requirements and if enough blocks are in bins to meet goal
bool check_inputs(int ri, int gi, int bi, int rg, int gg, int bg) {
    std::cout << "---------------------------------------------------------------------------------------------\n";
    std::cout << "Checking input requirements\n";
    std::array bin_quantities{ri, gi, bi};
    std::array tray_quantities{rg, gg, bg};
    std::array colors{"red", "green", "blue"};
    bool pass_check = true;

    //!Confirm if enough blocks in bins to meet goal
    for (char i = 0; i < 3; i++) {
        if (tray_quantities.at(i) > bin_quantities.at(i)) {
            std::cout << "Error: not enough blocks in " << colors.at(i) << " bin.\n";
            pass_check = false;
        }
        else {
            std::cout << "Enough blocks in " << colors.at(i) << " bin\n";
        }
    }

    //!Confirm minimum 1, maximum 10 total blocks on tray
    int sum{rg + gg + bg};
    if (sum < 1) {
        std::cout << "Error: must place at least 1 block on tray\n";
        pass_check = false;
    }
    else if (sum > 10) {
        std::cout << "Error: maximum 10 blocks total on tray\n";
        pass_check = false;
    }
    else {
        std::cout << "Total blocks on tray within required range\n";
    }

    return pass_check;//!Return true/false value on if the input check passed

}

//!Pick function
int pick(int int_color, int bin_status, bool gripper_empty)
{
    if (gripper_empty == true)//!Gripper status precondition
    {
        std::array color{"red", "green", "blue"};
        std::cout << "Picking 1 " << color.at(int_color) << " block\n";
        bin_status = bin_status - 1;
        std::cout << "  " << bin_status << " blocks remaining in " << color.at(int_color) << " bin\n";
    }
    else
    {
        std::cout << "Error: Unexpected gripper status\n";
    }

    return bin_status;
}

//!Place function
int place(int int_color, int blocks_needed, bool gripper_empty)
{
    if (gripper_empty == false)//!Gripper status precondition
    {
        std::array color{"red", "green", "blue"};
        std::cout << "Placing 1 " << color.at(int_color) << " block\n";
        blocks_needed = blocks_needed - 1;
        std::cout << "  " << blocks_needed << " " << color.at(int_color) << " blocks still needed in the tray\n";
    }
    else
    {
        std::cout << "Error: Unexpected gripper status\n";
    }

    return blocks_needed;
}

//!Function to return status of gripper
void gripper_status(bool gripper_empty)
{
    if (gripper_empty == true)
    {
        std::cout << "  Gripper is empty\n";
    }
    else
    {
        std::cout << "  Gripper holding block\n";
    }
}