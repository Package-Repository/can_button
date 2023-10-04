#ifndef CAN_BUTTON_H
#define CAN_BUTTON_H
#include <linux/can.h>

struct CAN_Setup_Info
{
    int&        socket;
    can_frame&  frame;
};

CAN_Setup_Info setupCan();
void startTargetProgram(const char* programPath);

#endif
