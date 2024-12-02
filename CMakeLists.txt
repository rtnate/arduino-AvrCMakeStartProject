cmake_minimum_required(VERSION 3.23)
# Change to your project name (sketch name or similar)
project(MyArduinoProject LANGUAGES C CXX ASM)

######################
# Include Arduino CMAKE Script 
######################
# Path to arduino.cmake - change if not included in the project cmake directory
include(${CMAKE_CURRENT_LIST_DIR}/cmake/arduino.cmake)

######################
# Project variables
######################
# -- Arduino Sketch Name - Change to be the name of your sketch
set(ARDUINO_SKETCH_NAME "MyArduinoSketch")
# -- Arduino Board Name - Change to match the name of your board
set(ARDUINO_BOARD "Arduino Nano")
# -- Arduino Core Path - Change if in different location
set(ARDUINO_CORE_PATH ${CMAKE_CURRENT_LIST_DIR}/libs/ArduinoCore)

######################
# Create the Sketch 
######################
# First add the board to set all the board variables (or set the board 
# variables manually)
add_arduino_board(${ARDUINO_BOARD})
# Then add a sketch
add_arduino_sketch(${ARDUINO_SKETCH_NAME} ${ARDUINO_CORE_PATH})

######################
# Add Sketch Source Files
######################
target_sources(${ARDUINO_SKETCH_NAME} PRIVATE
    src/Sketch.cpp
)

######################
# Add Sketch Include Directories
######################
target_include_directories(${ARDUINO_SKETCH_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src
)


######################
# Add Additional Libraries as needed here
######################
include_arduino_library("EEPROM")
include_arduino_library("Wire")
include_arduino_library(arduino_DS1881_2 C:\\Users\\nate\\source\\Arduino\\libraries\\DS1881_2)
target_link_libraries(arduino_DS1881_2 PRIVATE arduino_Wire)
