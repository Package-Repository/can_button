#include "can_button.h"
#include <unistd.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include <thread>

#define READ_BYTES_ERROR(bytes) bytes<0
#define FIRST_BYTE(frame_data) frame_data[0]

constexpr const char* PYTHON_PATH               =  "/usr/bin/python";
constexpr const char* ROBOT_PROGRAM             =  "/home/mechatronics/hectorstuff/repos/helloWorld.py";
constexpr const char* READ_ERROR_MESSAGE        =  "Error when reading bytes";
constexpr const char* ROBOT_STARTING_MESSAGE    =  "Button press signal received! Starting robot...\n";
constexpr const int   SUB_STATE_SIGNAL_ID       =   0x07;    
constexpr const int   START_CODE                =   0x04;

bool received_start_command(CAN_Setup_Info& setup_info)
{
    const bool is_sub_state_msg = setup_info.frame.can_id == SUB_STATE_SIGNAL_ID;
    const bool is_start_code = FIRST_BYTE(setup_info.frame.data) == START_CODE;
    return is_sub_state_msg && is_start_code;
}

int main(int argc, char * argv[])
{
    CAN_Setup_Info setup_info = setupCan();
    for (;;) 
    {
        if (READ_BYTES_ERROR(read(setup_info.socket, &setup_info.frame, sizeof(struct can_frame)))) {
            perror(READ_ERROR_MESSAGE);
            break;
        }

        if (received_start_command(setup_info)) {
            printf(ROBOT_STARTING_MESSAGE);
            startTargetProgram(PYTHON_PATH, ROBOT_PROGRAM);
        }
    }
    exit(EXIT_SUCCESS);
}

