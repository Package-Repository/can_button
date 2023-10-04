#include "can_button.h"
#include <unistd.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include <thread>

#define READ_BYTES_ERROR(bytes) bytes<0
#define FIRST_BYTE(frame_data) frame_data[0]

constexpr const char* READ_ERROR_MESSAGE        =  "Error when reading bytes";
constexpr const char* ROBOT_STARTING_MESSAGE    =  "Button press signal received! Starting robot...\n";
constexpr const int   SUB_STATE_SIGNAL_ID       =   0x07;    
constexpr const int   START_CODE                =   0x04;

bool received_start_command(CAN_Setup_Info& setup_info)
{
    return setup_info.frame.can_id == SUB_STATE_SIGNAL_ID && FIRST_BYTE(setup_info.frame.data) == START_CODE;
}

int main(int argc, char * argv[])
{
    CAN_Setup_Info setup_info = setupCan();
    while (true) 
    {
        if (READ_BYTES_ERROR(read(setup_info.socket, &setup_info.frame, sizeof(struct can_frame)))) {
            perror(READ_ERROR_MESSAGE);
            break;
        }

        if (received_start_command(setup_info)) {
            printf(ROBOT_STARTING_MESSAGE);
            startTargetProgram("/");
        }
    }
    exit(EXIT_SUCCESS);
}

