#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "opticpu.log"
#define MAX_CPU_LOAD 2.0
#define MAX_MEM_USAGE 75
#define MAX_DISK_IO_UTIL 50
#define MAX_NET_UTIL 10

// Function to adjust CPU parameters using cpupower
void adjust_cpu_parameters() {
    // Logic to adjust CPU parameters using cpupower
    system("cpupower frequency-set -g performance");
}

// Function to optimize CPU usage
void optimize_cpu() {
    // Set process priority to optimize CPU usage
    setpriority(PRIO_PROCESS, 0, -10); // Set priority to -10

    // CPU parameters using cpupower
    adjust_cpu_parameters();
}

// Function to optimize memory usage
void optimize_memory() {
    // Check available memory and swap usage
    FILE* fp = popen("free | awk 'NR==2 {print $3}'", "r");
    if (fp != NULL) {
        char memused[256];
        fgets(memused, sizeof(memused), fp);
        pclose(fp);
        
        int used = atoi(memused);
        if (used > MAX_MEM_USAGE) {
            // Logic to adjust memory settings if needed
            system("sysctl vm.swappiness=10");
        }
    }
}

// Function to optimize disk I/O
void optimize_disk_io() {
    // Check disk I/O activity and adjust disk scheduler for better performance
    FILE* fp = popen("iostat -c | awk 'NR==4 {print $2}'", "r");
    if (fp != NULL) {
        char diskutil[256];
        fgets(diskutil, sizeof(diskutil), fp);
        pclose(fp);
        
        int util = atoi(diskutil);
        if (util > MAX_DISK_IO_UTIL) {
            // Logic to adjust disk I/O settings if needed
            system("echo deadline > /sys/block/sda/queue/scheduler");
        }
    }
}

// Function to optimize network activity
void optimize_network() {
    // Check network activity and optimize network settings for better performance
    FILE* fp = popen("sar -n DEV 1 1 | grep Average | awk '{print $6}'", "r");
    if (fp != NULL) {
        char netutil[256];
        fgets(netutil, sizeof(netutil), fp);
        pclose(fp);
        
        int util = atoi(netutil);
        if (util > MAX_NET_UTIL) {
            // Logic to adjust network settings if needed
            system("sysctl -w net.core.netdev_max_backlog=30000");
        }
    }
}

// Function to optimize overall system resources
void optimize_system() {
    // Optimize CPU usage
    optimize_cpu();

    // Optimize memory usage
    optimize_memory();

    // Optimize disk I/O
    optimize_disk_io();

    // Optimize network activity
    optimize_network();

    // More optimization tasks as needed based on system requirements
}

// Function to handle signals
void signal_handler(int signum) {
    if (signum == SIGTERM || signum == SIGINT) {
        // Add cleanup logic here if needed
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[]) {
    // Check if the program is running as root
    if (geteuid() != 0) {
        printf("OptiCPU must be installed and run as a service with root privileges. Please check the instructions on the GitHub page: github.com/OptiCPU\n");
        return EXIT_FAILURE;
    }

    // Register signal handler for SIGTERM and SIGINT
    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);

    // Open log file
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    // Main optimization loop
    while (1) {
        // Get current time
        time_t now;
        time(&now);
        struct tm *tm_info = localtime(&now);

        // Optimize system resources
        optimize_system();

        // Log activity
        fprintf(log_file, "[%d-%02d-%02d %02d:%02d:%02d] System optimized\n", 
            tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
            tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

        // Sleep for a short period of time before repeating
        sleep(30); // Sleep for 30 seconds
    }

    // Close log file
    fclose(log_file);

    return 0;
}
