#include "types.h"
#include "stat.h"
#include "user.h"

#define WNOHANG 1

//test for WHNOHANG options
int
main(int argc, char *argv[])
{
  printf(1, "\n  Part e) the waitpid option WNOHANG, test program CELEBW02 \n");

    int pid, retpid;
    int status;

    if ((pid = fork()) < 0)
        printf(2, "fork() error");
    else if (pid == 0)
    {
        sleep(5);
        exit(1);
    }
    else
        do
        {
            retpid = waitpid(pid, &status, WNOHANG);
            
            if (retpid == 0)
            {
                printf(1, "child is still running \n");
                sleep(1);
            }
            else
            {
                printf(1, "child exited with status of %d\n", status);
            }
        } while (retpid == 0);

    exit(0);
}
