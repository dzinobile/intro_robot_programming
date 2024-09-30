/**
 * @file kitting.hpp
 * @author Daniel Zinobile (zinobile@umd.edu)
 * @brief ENPM-702 assignment 2
 */
#include <iostream>
void get_initial_state(int &ri, int &gi, int &bi);
void get_goal_state(int &rg, int &gg, int &bg);
int pick(int color, int bin_status, bool gripper_empty);
int place(int color, int blocks_needed, bool gripper_empty);
void gripper_status(bool gripper_empty);
