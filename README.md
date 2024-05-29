### OptiCPU 🔧

OptiCPU is an advanced utility crafted to continuously optimize system resources, with a primary focus on enhancing CPU usage efficiency, on Linux-based operating systems. The project aims to provide users with a comprehensive toolset to dynamically manage CPU resources, fine-tune system parameters, and adaptively adjust system settings to maintain optimal performance under varying workloads. By employing sophisticated algorithms and real-time monitoring techniques, OptiCPU intelligently adjusts CPU frequency, process priorities, memory management settings, disk I/O configurations, and network parameters to ensure efficient resource utilization while minimizing system overhead. Whether you're operating on older hardware with limited resources or managing high-performance systems, OptiCPU offers a versatile solution to enhance system responsiveness and overall performance, providing a seamless computing experience for users across diverse environments.

# 

[![OptiCPU Philosophy](https://img.shields.io/badge/OptiCPU-Philosophy-green)](https://github.com/OptiCPU)


In today's fast-paced technological landscape, older hardware often struggles to keep up with the demands of modern software. Many users still rely on aging computers that may not have the resources to smoothly run the latest operating systems and applications. Recognizing this challenge, my goal is to provide a solution tailored to such older hardware, particularly those running Linux, with a preference for Arch Linux due to its lightweight and customizable nature.

The idea is to develop a suite of optimization tools that enhance the performance of these older systems, allowing them to run more efficiently and effectively. By focusing on optimizing resource usage, such as CPU, memory, disk I/O, and network activity, we aim to breathe new life into these aging machines.

The key philosophy behind this project is to leverage the flexibility and versatility of Linux, particularly Arch Linux, to create a tailored optimization solution. This involves fine-tuning system settings, adjusting resource allocation, and implementing intelligent monitoring mechanisms to dynamically adapt to changing workload demands.

By empowering users with the ability to optimize their systems, we enable them to extend the lifespan of their hardware, reduce electronic waste, and continue to benefit from the many advantages of Linux computing. Ultimately, this initiative aligns with the principles of sustainability, accessibility, and empowerment, ensuring that even older hardware can thrive in today's digital ecosystem.

#

[![Warning: This Project is Unstable](https://img.shields.io/badge/Warning-This_Project_is_Unstable-red)](#)

<sub>* This is currently an experimental phase where the primary focus is on making the system functional and establishing a practical and logical pathway that aligns with both my vision and the project's goals. It might contain errors, bugs, etc. Many other non-core elements of the project are considered secondary.</sub>

![Version](https://img.shields.io/github/release/felipealfonsog/OptiCPU.svg?style=flat&color=blue)
![Main Language](https://img.shields.io/github/languages/top/felipealfonsog/OptiCPU.svg?style=flat&color=blue)
[![Open Source? Yes!](https://badgen.net/badge/Open%20Source%20%3F/Yes%21/blue?icon=github)](https://github.com/Naereen/badges/)


[![BSD 3-Clause License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

<!--
[![GPL license](https://img.shields.io/badge/License-GPL-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
-->

[![Vim](https://img.shields.io/badge/--019733?logo=vim)](https://www.vim.org/)
[![Visual Studio Code](https://img.shields.io/badge/--007ACC?logo=visual%20studio%20code&logoColor=ffffff)](https://code.visualstudio.com/)

#

#### In this code

- `adjust_cpu_parameters()` Function:
  - Adjusts CPU parameters by setting the CPU frequency governor to "performance" using the `cpupower frequency-set -g performance` command with superuser privileges.

- `optimize_cpu()` Function:
  - Sets the priority of the process to optimize CPU usage by calling `setpriority(PRIO_PROCESS, 0, -10)`.

- `optimize_memory()` Function:
  - Monitors available memory and swap usage to optimize memory usage. It may adjust memory settings if memory usage exceeds a defined threshold.

- `optimize_disk_io()` Function:
  - Monitors disk I/O activity using the `iostat` command and adjusts disk scheduler settings if disk utilization is high.

- `optimize_network()` Function:
  - Monitors network activity using the `sar` command and adjusts network settings if network utilization is high.

- `optimize_system()` Function:
  - Calls all optimization functions (`optimize_cpu()`, `optimize_memory()`, `optimize_disk_io()`, `optimize_network()`) to continuously optimize system resources. This function is executed in a loop to repeatedly optimize the system.



#



#### Installation
#### Via AUR using YAY

[![OptiCPU](https://img.shields.io/badge/OptiCPU-green)](#)

[![AUR](https://img.shields.io/aur/version/opticpu)](https://aur.archlinux.org/packages/opticpu)

<!-- 
[![AUR](https://img.shields.io/aur/version/opticpu.svg)](https://aur.archlinux.org/packages/opticpu)
-->

https://aur.archlinux.org/packages/opticpu

OptiCPU is available on AUR (Arch User Repository), and it can be installed using the `yay` package manager. Follow the steps below to install it:

1. Make sure you have `yay` installed. If not, you can install it with the following command:
   
   ```
   sudo pacman -S yay
   ```
   
   Once yay is installed, you can install by running the following command:
   
   ```
   yay -S opticpu
   ```

This command will automatically fetch the package from AUR and handle the installation process for you.
Run it with the command opticpu.

<sub>After to install it with yay, install it as a service with -sudo-.</sub>

#

#### Bash Installer 🚀 for Linux

[![Bash Installer Version](https://img.shields.io/badge/Bash%20Installer%20Version-Available-brightgreen)](#)

#### To Install it: 

To install it, simply run the installer script available [here](https://github.com/felipealfonsog/OptiCPU/raw/main/installer.sh).

Or just Copy - Paste in your terminal and use -curl- to start downloading the installer:

   ```
   curl -O https://raw.githubusercontent.com/felipealfonsog/OptiCPU/main/installer.sh
   ```

If you want to use -wget- just copy/paste this line:

   ```
   wget https://github.com/felipealfonsog/OptiCPU/raw/main/installer.sh
   ```

   On macOS to download - wget - just install it with Homebrew:

   ```
   brew install wget
   ```

<sub>After to install it with yay, install it as a service with -sudo-.</sub>

#### Important note when installing:

If you encounter issues executing the file in the terminal, like this message "-bash: ./installer.sh: Permission denied", follow these simple steps to fix it:

1. Open your terminal.
2. Navigate to the directory where the installer script is located using the `cd` command.
3. Run the following command to grant execute permission to the installer script:

   ```
   chmod +x installer.sh
   ```
   
4. Now you can run the installer without any problems.

   ```
   ./installer.sh
   ```
   NOTE: The script will ask for -sudo permissions-. Just simply type in Linux your -sudo- password.

Now type 'opticpu' in the terminal and enjoy using it! 😊🚀


Feel free to reach out if you need any further assistance!

#### Updating with the script: 

If you want to update the program in your system, download the bash and re-run the script:

   ```
   ./installer.sh
   ```
Please note that if you encounter any issues or have suggestions, feel free to raise an issue on the [OptiCPU repository](https://github.com/felipealfonsog/OptiCPU/issues). Your feedback is invaluable!

Thank you for joining me on this journey, and I hope it brings value to your life and workflow. Let's continue making technology accessible and enjoyable for everyone!

#


#### Setting up "OptiCPU" as a Service

1. Create a Service File

Create a new service file for "OptiCPU" using a text editor of your choice. For example:

```
sudo nano /etc/systemd/system/opticpu.service
```

2. Add Service Configuration
Paste the following configuration into the opticpu.service file:

```
[Unit]
Description=OptiCPU Optimization Service
After=network.target

[Service]
Type=simple
ExecStart=/usr/bin/opticpu
Restart=always

[Install]
WantedBy=multi-user.target
```

This configuration specifies that the service should start "OptiCPU" on boot and restart it if it crashes.

3. Save and Close the File

After adding the configuration, save and close the file.

4. Enable and Start the Service

Enable the "opticpu" service to start automatically on boot:

```
sudo systemctl enable opticpu
```

```
Start the "opticpu" service:
```

```
sudo systemctl start opticpu
```

5. Check Service Status

You can check the status of the "opticpu" service to ensure it's running:

```
sudo systemctl status opticpu
```

6. Optionally, Stop or Disable the Service

To stop the "opticpu" service:

```
sudo systemctl stop opticpu
```

To disable the "opticpu" service from starting automatically on boot:

```
sudo systemctl disable opticpu
```

#


#### 🌟 Contact the Creator and Engineer Behind This Project



👨‍💻 **Felipe Alfonso González**  
📧 Email: [f.alfonso@res-ear.ch](mailto:f.alfonso@res-ear.ch)  
🐦 x (Twitter): [@felipealfonsog](https://twitter.com/felipealfonsog)  
🔗 GitHub: [felipealfonsog](https://github.com/felipealfonsog)  
📄 License: BSD 3-Clause  


#

#### 🤝 Support and Contributions

If you find this project helpful and would like to support its development, there are several ways you can contribute:

- **Code Contributions**: If you're a developer, you can contribute by submitting pull requests with bug fixes, new features, or improvements. Feel free to fork the project (development branch) and create your own branch to work on.
- **Bug Reports and Feedback**: If you encounter any issues or have suggestions for improvement, please open an issue on the project's GitHub repository. Your feedback is valuable in making the project better.
- **Documentation**: Improving the documentation is always appreciated. If you find any gaps or have suggestions to enhance the project's documentation, please let me know.

[![Buy Me a Coffee](https://img.shields.io/badge/Buy%20Me%20a%20Coffee-%E2%98%95-FFDD00?style=flat-square&logo=buy-me-a-coffee&logoColor=black)](https://www.buymeacoffee.com/felipealfonsog)
[![PayPal](https://img.shields.io/badge/Donate%20with-PayPal-00457C?style=flat-square&logo=paypal&logoColor=white)](https://www.paypal.me/felipealfonsog)
[![GitHub Sponsors](https://img.shields.io/badge/Sponsor%20me%20on-GitHub-%23EA4AAA?style=flat-square&logo=github-sponsors&logoColor=white)](https://github.com/sponsors/felipealfonsog)

Your support and contributions are greatly appreciated! Thank you for your help in making this project better. If you need to mail me, this is the way: f.alfonso@res-ear.ch (I'm Felipe, the Computer Science Engineer behind this idea. Cheers!)


#### 📄 License

This project is licensed under the [BSD 3-Clause License](LICENSE). It will have some restrictions, ask about it.
