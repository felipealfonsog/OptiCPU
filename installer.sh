#!/bin/bash

# Installer for OptiCPU on Linux systems

# Define paths and file names
INSTALL_DIR="/usr/local/bin"
EXECUTABLE_NAME="opticpu"
SOURCE_FILE="opticpu"

# Compile the program
echo "Compiling the program..."
gcc -o "$EXECUTABLE_NAME" "$SOURCE_FILE.c"
if [ $? -ne 0 ]; then
    echo "Error: Failed to compile the program."
    exit 1
fi

# Move the executable to the installation directory
echo "Installing the program to $INSTALL_DIR..."
sudo mv "$EXECUTABLE_NAME" "$INSTALL_DIR"
if [ $? -ne 0 ]; then
    echo "Error: Failed to move the executable to $INSTALL_DIR."
    exit 1
fi

# Clean up temporary files
rm -f "$SOURCE_FILE"

echo "OptiCPU has been successfully installed to $INSTALL_DIR."
