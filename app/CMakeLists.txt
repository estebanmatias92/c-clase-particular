cmake_minimum_required(VERSION ${CMAKE_VERSION})

# Project name
project($ENV{PROJECT_NAME} LANGUAGES C CXX)


# Macro to add list of subdirectories
macro(add_subdirectories SUBDIRS)
    foreach(subdir ${SUBDIRS})
        add_subdirectory(${subdir})
    endforeach()
endmacro()

# Macro to add automatically all subdirectories in a folder
macro(get_subdirectories result curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach(child ${children})
        #IF(IS_DIRECTORY ${curdir}/${child})
        if(IS_DIRECTORY ${curdir}/${child} AND EXISTS ${curdir}/${child}/CMakeLists.txt)
            list(APPEND dirlist ${child})
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()

## Function to parse string to PascalCase
#function(to_pascalcase parsed message)
#
#    set(new_message "")
#    string(TOLOWER ${message} message)
#
#    string(REGEX REPLACE "[^A-Za-z0-9]" ";" words "${message}")
#    foreach(word ${words})    
#        message(STATUS ${word})
#
#        string(SUBSTRING ${word} 0 1 first_letter)
#        string(TOUPPER ${first_letter} first_letter)
#        string(REGEX REPLACE "^.(.*)" "${first_letter}\\1" pascal_cased "${word}")
#        
#        list(APPEND new_message ${pascal_cased})
#    endforeach()
#
#    string(REGEX REPLACE ";" "" new_message "${new_message}")
#
#    set(${parsed} ${new_message} PARENT_SCOPE)
#endfunction()
#

# Add the modules of the program
add_subdirectory(include)
add_subdirectory(src)


# Create an CMake option to build the examples for the libs
option(BUILD_EXAMPLE "Build the libraries examples" OFF)

if (BUILD_EXAMPLE)
    message(STATUS "Building examples...")
    #add_subdirectory(examples)
endif()
