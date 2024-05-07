### OptiCPU
OptiCPU is an advanced utility crafted to continuously optimize system resources, with a primary focus on enhancing CPU usage efficiency, on Linux-based operating systems. The project aims to provide users with a comprehensive toolset to dynamically manage CPU resources, fine-tune system parameters, and adaptively adjust system settings to maintain optimal performance under varying workloads. By employing sophisticated algorithms and real-time monitoring techniques, OptiCPU intelligently adjusts CPU frequency, process priorities, memory management settings, disk I/O configurations, and network parameters to ensure efficient resource utilization while minimizing system overhead. Whether you're operating on older hardware with limited resources or managing high-performance systems, OptiCPU offers a versatile solution to enhance system responsiveness and overall performance, providing a seamless computing experience for users across diverse environments.

#### In this code

- The optimize_cpu function monitors the system load using the uptime command and adjusts the CPU frequency accordingly.
- The optimize_memory function checks the amount of used memory and adjusts the swappiness parameter if memory usage is high.
- The optimize_disk_io function monitors disk I/O activity using the iostat command and adjusts the disk scheduler if disk utilization is high.
- The optimize_network function monitors network activity using the sar command and adjusts the netdev_max_backlog parameter if network utilization is high.
- All these functions are called within the optimize_system function, which is executed in a loop to continuously optimize the system resources.

