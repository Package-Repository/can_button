# CAN Button Initializer

This package is meant to provide functionality for turning on the robot with a physical switch.

## Description

The robot will require a way to be activated without intervention and connection from a computer ... 
It should be able to be activated from a physical stimulus (ie. a button)
To do this, we must wait for a signal from the embedded system and fork a process when it is recieved
In this case, we will be waiting on a CAN Signal. According to the data sheet for CAN our signals will be 

    0x07 - Sub State Device
    0x04 - Start Signal

## API

For this program to work, you must have a binary called "robot_exec" that can be found by your terminal environment. When the button is pressed, it will fork a process and execute that binary, which would presumably be the robot program

### Dependencies

* Depends on a CAN based embedded system.

### Install/Linking

* Use the CMakeLists to build with a command like this 

    mkdir build && cd build && cmake .. && sudo make

### Executing program

Execute the binary that is built using ./can_button_exec

## Authors

[@Zix](https://github.com/Repo-Factory/) Github
