#include "kitting.hpp"
#include <iostream>



int main() {
    
    //Get initial state
    int r_initial{}, g_initial{}, b_initial{};
    get_initial_state(r_initial, g_initial, b_initial);

    //Get goal state
    int r_goal{}, g_goal{}, b_goal{};
    get_goal_state(r_goal, g_goal, b_goal);

    //Set gripper status to empty
    bool gripper_empty = true;

    while (r_goal > 0)
    {
        if (gripper_empty == true) {
            r_initial = pick(0, r_initial);
            gripper_empty = false;
            std::cout << gripper_status(gripper_empty) << "\n";
        }
        
            
        if (gripper_empty == false) {
            r_goal = place(0, r_goal);
            gripper_empty = true;
            std::cout << gripper_status(gripper_empty) << "\n";   
        }
                 
    }

    while (g_goal > 0)
    {
        if (gripper_empty == true) {
            g_initial = pick(1, g_initial);
            gripper_empty = false;
            std::cout << gripper_status(gripper_empty) << "\n";
        }
        if (gripper_empty == false) {
            g_goal = place(1, g_goal);
            gripper_empty = true;
            std::cout << gripper_status(gripper_empty) << "\n";
        }
        
    }

    while (b_goal > 0)
    {
        if (gripper_empty == true) {
            b_initial = pick(2, b_initial);
            gripper_empty = false;
            std::cout << gripper_status(gripper_empty) << "\n";
        }
        
        if (gripper_empty == false) {
            b_goal = place(2, b_goal);
            gripper_empty = true;
            std::cout << gripper_status(gripper_empty) << "\n";
        }
        
    }
    

    return 0;
}