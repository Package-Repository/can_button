#include "can_button.h"
#include <sys/socket.h>
#include <cstring>
#include <sys/ioctl.h>
#include <net/if.h>

constexpr const char* CAN_INTERFACE     = "can0";

CAN_Setup_Info setupCan()
{
    int* sock = new int();
    struct sockaddr_can addr;
    struct ifreq ifr;
    *sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    strcpy(ifr.ifr_name, CAN_INTERFACE);
    ioctl(*sock, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(*sock, (struct sockaddr *)&addr, sizeof(addr));
    struct can_frame* frame = new can_frame();
    return CAN_Setup_Info{*sock, *frame};
}