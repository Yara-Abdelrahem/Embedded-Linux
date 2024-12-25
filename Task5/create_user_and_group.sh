#!/bin/bash

# Variables for user and group
USER_NAME="Yara"
GROUP_NAME="Abdelraheem"

# Check if the group already exists
if getent group "$GROUP_NAME" > /dev/null; then
    echo "Group '$GROUP_NAME' already exists."
else
    echo "Creating group '$GROUP_NAME'..."
    sudo groupadd "$GROUP_NAME"
    echo "Group '$GROUP_NAME' created."
fi

# Check if the user already exists
if id "$USER_NAME" > /dev/null 2>&1; then
    echo "User '$USER_NAME' already exists."
else
    echo "Creating user '$USER_NAME'..."
    sudo useradd -m -g "$GROUP_NAME" "$USER_NAME"
    echo "User '$USER_NAME' created and added to group '$GROUP_NAME'."
fi

# Display user and group information
echo "User Information:"
id "$USER_NAME"

echo "Group Information:"
getent group "$GROUP_NAME"

