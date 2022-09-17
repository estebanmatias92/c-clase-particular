# Get folder name
get_filename_component(ProjectID ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Set Project Name out of Folder's name
project(${ProjectID})


# Add the binary files
set(SOURCE_FILES 
    ejercicios.cpp 
)
# Set the include path for this module
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME})

# Add the binaries to this project
add_library(${PROJECT_NAME} ${SOURCE_FILES})

# Link the include path to this project
target_include_directories(${PROJECT_NAME} 
    PUBLIC
    ${INCLUDE_DIR})


    # Create dynamic source list
file(GLOB EJERCICIOS_SOURCES *.cpp)
# Remove main file from source list
list(REMOVE_ITEM EJERCICIOS_SOURCES ${SOURCE_FILES})
target_sources(${PROJECT_NAME} 
    PRIVATE 
    ${EJERCICIOS_SOURCES})