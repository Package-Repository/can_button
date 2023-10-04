# CAN Button Initializer

This package is meant to provide functionality for turning on the robot with a physical switch.

## Description

The robot will require a way to be activated without intervention and connection from a computer ... 
It should be able to be activated from a physical stimulus (ie. a button)
To do this, we must wait for a signal from the embedded system and fork a process when it is recieved
In this case, we will be waiting on a CAN Signal. According to the data sheet for CAN our signals will be 

    0x07 - Sub State Device
    0x04 - Kill Signal

## Directories ##

- `can_button/`  
    - `include/`  
        - `can_button.h`                 -     
    - `main/`
        - `main.cpp`                     - loop will wait 
    - `src/`  
        - `can_button.cpp`               - 
    - `CMakeLists.txt`                   -
    - `config.json`                      - 


## Getting Started

The config.json file serves as the API for this program which simply takes a path to the program you would like to start
when the button is pressed.

### Dependencies

* Depends on a CAN based embedded system.

### Install/Linking

* 

### Executing program




## Authors

[@Slix Elixel](https://github.com/Repo-Factory/) Github
