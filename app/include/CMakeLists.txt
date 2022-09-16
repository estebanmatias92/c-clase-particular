project(${PROJECT_NAME})


# My custom function to list all subdirectories with a CMakeList.txt file in it
get_subdirectories(SUBDIRECTORIES ${CMAKE_CURRENT_LIST_DIR})

# My custom function to invoke "add_subdirectory" with a foreach
add_subdirectories(${SUBDIRECTORIES})