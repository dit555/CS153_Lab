#include "types.h"
#include "stat.h"
#include "user.h"

//test for waitpid
int
main(int argc, char *argv[])
{
  int ret_pid, exit_status;
    int i;
    int pid_a[5] = {0, 0, 0, 0, 0};
    // use this part to test wait(int pid, int* status, int options)

    printf(1, "\n  Part c) testing waitpid(int pid, int* status, int options):\n");

    for (i = 0; i < 5; i++)
    {
        pid_a[i] = fork();
        if (pid_a[i] == 0)
        { // only the child executed this code
            printf(1, "\n The is child with PID# %d and I will exit with status %d\n", getpid(), getpid() + 4);
            exit(getpid() + 4);
        }
    }

    sleep(5);
    printf(1, "\n This is the parent: Now waiting for child with PID# %d\n", pid_a[3]);
    ret_pid = waitpid(pid_a[3], &exit_status, 0);
    printf(1, "\n This is the partent: Child# %d has exited with status %d\n", ret_pid, exit_status);
    sleep(5);
    printf(1, "\n This is the parent: Now waiting for child with PID# %d\n", pid_a[1]);
    ret_pid = waitpid(pid_a[1], &exit_status, 0);
    printf(1, "\n This is the partent: Child# %d has exited with status %d\n", ret_pid, exit_status);
    sleep(5);
    printf(1, "\n This is the parent: Now waiting for child with PID# %d\n", pid_a[2]);
    ret_pid = waitpid(pid_a[2], &exit_status, 0);
    printf(1, "\n This is the partent: Child# %d has exited with status %d\n", ret_pid, exit_status);
    sleep(5);
    printf(1, "\n This is the parent: Now waiting for child with PID# %d\n", pid_a[0]);
    ret_pid = waitpid(pid_a[0], &exit_status, 0);
    printf(1, "\n This is the partent: Child# %d has exited with status %d\n", ret_pid, exit_status);
    sleep(5);
    printf(1, "\n This is the parent: Now waiting for child with PID# %d\n", pid_a[4]);
    ret_pid = waitpid(pid_a[4], &exit_status, 0);
    printf(1, "\n This is the partent: Child# %d has exited with status %d\n", ret_pid, exit_status);

    exit(0);
}
