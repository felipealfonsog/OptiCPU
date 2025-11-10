#!/bin/bash

PROGRAM="opticpu"
SERVICE_PATH="/etc/systemd/system/$PROGRAM.service"

# Function to create a systemd service for the program
create_service() {
    echo "Creating systemd service for $PROGRAM..."
    sudo bash -c "cat > $SERVICE_PATH" <<EOL
[Unit]
Description=$PROGRAM service

[Service]
ExecStart=/usr/bin/$PROGRAM
User=root
Restart=always

[Install]
WantedBy=multi-user.target
EOL
    echo "Service created successfully."
}

# Function to enable the service
enable_service() {
    sudo systemctl enable "$PROGRAM"
    echo "Service enabled."
}

# Function to disable the service
disable_service() {
    sudo systemctl disable "$PROGRAM"
    echo "Service disabled."
}

# Function to start the service
start_program() {
    sudo systemctl start "$PROGRAM"
    echo "$PROGRAM started."
}

# Function to stop the service
stop_program() {
    sudo systemctl stop "$PROGRAM"
    echo "$PROGRAM stopped."
}

# Function to check if the service is active
check_status() {
    systemctl is-active --quiet "$PROGRAM"
    if [ $? -eq 0 ]; then
        echo "$PROGRAM is running."
    else
        echo "$PROGRAM is not running."
    fi
}

# Main script
echo "OptiCPU Daemon Manager"
echo "----------------------"

# Check if the service exists, if not, create it
if [ ! -f "$SERVICE_PATH" ]; then
    echo "Service not found. Creating service for $PROGRAM..."
    create_service
fi

# Menu to enable, disable, start, stop, check status, or quit
while true; do
    echo ""
    echo "Options:"
    echo "1. Enable $PROGRAM daemon"
    echo "2. Disable $PROGRAM daemon"
    echo "3. Start $PROGRAM"
    echo "4. Stop $PROGRAM"
    echo "5. Check $PROGRAM status"
    echo "6. Quit"
    echo ""
    read -p "Choose an option: " choice

    case $choice in
        1) enable_service ;;
        2) disable_service ;;
        3) start_program ;;
        4) stop_program ;;
        5) check_status ;;
        6) echo "Exiting."; exit ;;
        *) echo "Invalid option. Please select 1, 2, 3, 4, 5, or 6." ;;
    esac
done

