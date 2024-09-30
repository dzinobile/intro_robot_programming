/**
 * @file kitting.hpp
 * @author Daniel Zinobile (zinobile@umd.edu)
 * @brief ENPM-702 assignment 2
 */
#include <iostream>
void get_initial_state(int &ri, int &gi, int &bi);
void get_goal_state(int &rg, int &gg, int &bg);
int pick(int rgb123, int bin_status);
int place(int rgb123, int blocks_needed);
std::string gripper_status(bool gripper_empty);
