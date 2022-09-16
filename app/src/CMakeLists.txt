project(${PROJECT_NAME})


# My custom function to list all subdirectories with a CMakeList.txt file in it
get_subdirectories(SUBDIRECTORIES ${CMAKE_CURRENT_LIST_DIR})

# Set the libraries names out of the Sub-Directories names
set(PROJECT_LIBS 
    ${SUBDIRECTORIES}
)

# Adding executable
add_executable(${PROJECT_NAME} 
    main.cpp
)

# My custom function to add subdirectories with a foreach
add_subdirectories(${SUBDIRECTORIES})

# Link the libraries to this project
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_LIBS})
