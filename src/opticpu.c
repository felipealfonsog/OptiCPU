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

#define MEMORY_ALLOC_SIZE (1024 * 1024 * 100) // 100 MB

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

// Function to check if CPU optimization is needed
int cpu_needs_optimization() {
    // Example check for CPU load
    FILE* fp = popen("uptime | awk -F'average:' '{print $2}' | awk '{print $1}'", "r");
    if (fp != NULL) {
        char loadavg[16];
        fgets(loadavg, sizeof(loadavg), fp);
        pclose(fp);

        double cpu_load = atof(loadavg);
        return cpu_load > MAX_CPU_LOAD;
    }
    return 0;
}

// Function to optimize memory usage
void optimize_memory() {
    // Adjust memory settings if usage exceeds threshold
    system("sysctl vm.swappiness=10");
    // Allocate memory to optimize usage
    void* memory = malloc(MEMORY_ALLOC_SIZE);
    if (memory != NULL) {
        free(memory);
    }
    // Adjust memory parameters using sysctl
    system("sysctl -w vm.dirty_ratio=10");
    system("sysctl -w vm.dirty_background_ratio=5");
    system("sysctl -w vm.vfs_cache_pressure=50");
    system("sysctl -w vm.overcommit_memory=2");
    system("sysctl -w vm.overcommit_ratio=50");
    system("sysctl -w vm.min_free_kbytes=65536");
}

// Function to check if memory optimization is needed
int memory_needs_optimization() {
    FILE* fp = popen("free | awk 'NR==2 {print $3/$2 * 100}'", "r");
    if (fp != NULL) {
        char memused[16];
        fgets(memused, sizeof(memused), fp);
        pclose(fp);

        int used_percentage = atoi(memused);
        return used_percentage > MAX_MEM_USAGE;
    }
    return 0;
}

// Function to optimize disk I/O
void optimize_disk_io() {
    // Adjust disk I/O settings if usage exceeds threshold
    system("echo deadline > /sys/block/sda/queue/scheduler");
}

// Function to check if disk I/O optimization is needed
int disk_io_needs_optimization() {
    FILE* fp = popen("iostat -c | awk 'NR==4 {print $2}'", "r");
    if (fp != NULL) {
        char diskutil[16];
        fgets(diskutil, sizeof(diskutil), fp);
        pclose(fp);

        int util = atoi(diskutil);
        return util > MAX_DISK_IO_UTIL;
    }
    return 0;
}

// Function to optimize network activity
void optimize_network() {
    // Adjust network settings if usage exceeds threshold
    system("sysctl -w net.core.netdev_max_backlog=30000");
}

// Function to check if network optimization is needed
int network_needs_optimization() {
    FILE* fp = popen("sar -n DEV 1 1 | grep Average | awk '{print $6}'", "r");
    if (fp != NULL) {
        char netutil[16];
        fgets(netutil, sizeof(netutil), fp);
        pclose(fp);

        int util = atoi(netutil);
        return util > MAX_NET_UTIL;
    }
    return 0;
}

// Function to handle signals
void signal_handler(int signum) {
    if (signum == SIGTERM || signum == SIGINT) {
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[]) {
    if (geteuid() != 0) {
        printf("OptiCPU must be installed and run as a service with root privileges. Please check the instructions on the GitHub page: github.com/felipealfonsog/OptiCPU\n");
        return EXIT_FAILURE;
    }

    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);

    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int optimized = 0;
        
        if (cpu_needs_optimization()) {
            optimize_cpu();
            optimized = 1;
        }
        
        if (memory_needs_optimization()) {
            optimize_memory();
            optimized = 1;
        }
        
        if (disk_io_needs_optimization()) {
            optimize_disk_io();
            optimized = 1;
        }
        
        if (network_needs_optimization()) {
            optimize_network();
            optimized = 1;
        }

        if (optimized) {
            time_t now;
            time(&now);
            struct tm *tm_info = localtime(&now);
            fprintf(log_file, "[%d-%02d-%02d %02d:%02d:%02d] System optimized\n", 
                tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
                tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
            fflush(log_file);
        }
        
        sleep(5);  // Re-check every 5 seconds to avoid rapid looping
    }

    fclose(log_file);
    return 0;
}
