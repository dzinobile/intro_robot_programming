#include "kitting.hpp"
#include <iostream>
#include <array>

int main()
{

    //! Get initial state
    int r_initial{}, g_initial{}, b_initial{};
    get_initial_state(r_initial, g_initial, b_initial);

    //! Get goal state
    int r_goal{}, g_goal{}, b_goal{};
    get_goal_state(r_goal, g_goal, b_goal);

    //! Check inputs meet required parameters
    bool input_check = check_inputs(r_initial, g_initial, b_initial, r_goal, g_goal, b_goal);
    while (input_check == false) {
        std::cout << "Input check failed!\n";
        get_initial_state(r_initial, g_initial, b_initial);
        get_goal_state(r_goal, g_goal, b_goal);
        input_check = check_inputs(r_initial, g_initial, b_initial, r_goal, g_goal, b_goal);
    }
    std::cout << "Input check passed!\n";
    std::cout << "---------------------------------------------------------------------------------------------\n";
    
    //! Create arrays for initial states and goal states
    std::array initial_state{r_initial, g_initial, b_initial};
    std::array goal_state{r_goal, g_goal, b_goal};

    //! Set gripper initial status to empty
    bool gripper_empty = true;

    //! Pick and place loop
    for (char i = 0; i < 3; i++)
    {
        while (goal_state.at(i) > 0)
        {
            initial_state.at(i) = pick(i, initial_state.at(i), gripper_empty);
            gripper_empty = false;
            gripper_status(gripper_empty);

            goal_state.at(i) = place(i, goal_state.at(i), gripper_empty);
            gripper_empty = true;
            gripper_status(gripper_empty);
        }
    }

    return 0;
}