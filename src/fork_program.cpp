#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h>

#define IS_CHILD_PROGRAM(pid)   pid==0
#define IS_PARENT_PROGRAM(pid)  pid>0
#define FORK_FAILED_MESSAGE "Fork Failed!"

void startTargetProgram(const char* pythonPath, const char* programPath) {    
    pid_t pid = fork();
    if (IS_CHILD_PROGRAM(pid)) {
        execl(pythonPath, programPath, nullptr);
        exit(EXIT_FAILURE);
    } else if (IS_PARENT_PROGRAM(pid)) {
        int status;
        waitpid(pid, &status, 0);
    } else {
        std::cerr << FORK_FAILED_MESSAGE << std::endl;
    }
}