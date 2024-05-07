### OptiCPU
OptiCPU is a comprehensive utility designed to optimize CPU usage and enhance overall system performance on Linux-based operating systems. The project aims to provide users with tools and techniques to efficiently manage CPU resources, improve responsiveness, and streamline system operation. Through various optimization strategies, such as adjusting process priorities, limiting the number of running processes, and fine-tuning CPU frequency, OptiCPU offers users the ability to customize and optimize their system according to specific needs and preferences. Whether you're a power user seeking to maximize performance or a system administrator looking to optimize resource utilization across multiple machines, OptiCPU provides a versatile solution for enhancing the efficiency and responsiveness of Linux systems.

#### In this code

- The optimize_cpu function monitors the system load using the uptime command and adjusts the CPU frequency accordingly.
- The optimize_memory function checks the amount of used memory and adjusts the swappiness parameter if memory usage is high.
- The optimize_disk_io function monitors disk I/O activity using the iostat command and adjusts the disk scheduler if disk utilization is high.
- The optimize_network function monitors network activity using the sar command and adjusts the netdev_max_backlog parameter if network utilization is high.
- All these functions are called within the optimize_system function, which is executed in a loop to continuously optimize the system resources.

