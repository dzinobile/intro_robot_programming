cmake_minimum_required(VERSION 3.20.0)
project(exercise1 VERSION 0.1.0)

# Compilation flags
add_compile_options(-Wall)

# Add executable
add_executable(exercise1 exercise1/src/exercise1.cpp)

# add_custom_command(TARGET lecture3 POST_BUILD
#     COMMAND ./lecture3 | c++filt -t
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#     COMMENT "Resolve name mangling"
#     VERBATIM
# )

# add_custom_command(TARGET lecture3 POST_BUILD
#     COMMAND valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./lecture3
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#     COMMENT "Running Valgrind after building lecture3"
#     VERBATIM
# )

# add_custom_target(demangle ALL
#     COMMAND COMMAND ./lecture3 | c++filt -t
#     DEPENDS lecture3
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )

# add_custom_target(run_valgrind ALL
#     COMMAND valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./lecture3
#     DEPENDS lecture3
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )


# Set C++ standard to C++17
set_property(TARGET exercise1 PROPERTY CXX_STANDARD 17)
