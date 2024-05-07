#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

// Function to daemonize the process
void daemonize() {
    // Fork off the parent process
    pid_t pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    // If we got a good PID, then we can exit the parent process
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Change the file mode mask
    umask(0);

    // Create a new SID for the child process
    pid_t sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    // Change the current working directory
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }

    // Close stdin, stdout, stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    // Daemonize the process
    daemonize();

    // Main daemon logic
    while (1) {
        // Get current process priority
        int priority = getpriority(PRIO_PROCESS, 0);
        printf("Current process priority: %d\n", priority);

        // Set process priority
        setpriority(PRIO_PROCESS, 0, -10); // Set priority to -10

        // Check if priority has been changed
        priority = getpriority(PRIO_PROCESS, 0);
        printf("New process priority: %d\n", priority);

        // Limit number of processes running
        // You can adjust the limit according to your system's capacity
        system("pkill -STOP -u $(id -u)"); // Stop new processes from starting
        sleep(5); // Sleep for 5 seconds
        system("pkill -CONT -u $(id -u)"); // Resume process execution

        // Adjust CPU frequency (requires appropriate permissions)
        // Uncomment the following line and replace "n" with desired frequency value
        // system("cpupower frequency-set -f n");

        // Here you can add more logic to optimize CPU usage

        // Sleep for a while before repeating
        sleep(60); // Sleep for 60 seconds
    }

    return 0;
}

