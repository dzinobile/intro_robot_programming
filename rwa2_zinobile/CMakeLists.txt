cmake_minimum_required(VERSION 3.20.0)
project(kitting VERSION 0.1.0)


# Compilation flags
add_compile_options(-Wall -pedantic-errors)

#Include header files
include_directories(kitting/include)

# Add executable
add_executable(kitting kitting/src/kitting.cpp kitting/src/main.cpp)
#add_executable(main kitting/src/main.cpp)

add_custom_command(TARGET kitting POST_BUILD
    COMMAND ./kitting | c++filt -t
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Resolve name mangling"
    VERBATIM
)

add_custom_command(TARGET kitting POST_BUILD
    COMMAND valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./kitting
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running Valgrind after building kitting"
    VERBATIM
)


add_custom_target(demangle ALL
    COMMAND ./kitting ./main | c++filt -t
    DEPENDS kitting
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)


# add_custom_target(demangle ALL
#     COMMAND ./kitting | c++filt -t
#     DEPENDS kitting
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )

# add_custom_command(TARGET lecture3 POST_BUILD
#     COMMAND valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./lecture3
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#     COMMENT "Running Valgrind after building lecture3"
#     VERBATIM
# )


# add_custom_target(run_valgrind ALL
#     COMMAND valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./lecture3
#     DEPENDS lecture3
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )


# Set C++ standard to C++17
set_property(TARGET kitting PROPERTY CXX_STANDARD 17)


