#!/bin/bash

echo "=== System Information ==="

# OS Information
echo -e "\nOperating System:"
uname -a
if [ -f /etc/os-release ]; then
    cat /etc/os-release | grep "PRETTY_NAME" | cut -d "=" -f 2
fi

# CPU Information
echo -e "\nCPU Information:"
lscpu | grep "Model name" || sysctl -n machdep.cpu.brand_string
echo "CPU Cores: $(nproc 2>/dev/null || sysctl -n hw.ncpu)"

# Memory Information
echo -e "\nMemory Information:"
if [ "$(uname)" == "Linux" ]; then
    free -h
else
    vm_stat | perl -ne '/page size of (\d+)/ and $size=$1; /Pages\s+([^:]+)[^\d]+(\d+)/ and printf("%-16s % 16.2f MB\n", "$1:", $2 * $size / 1048576)'
fi

# Disk Usage
echo -e "\nDisk Usage:"
df -h | grep -v "tmpfs" | grep -v "devtmpfs"

# Network Information
echo -e "\nNetwork Interfaces:"
if [ "$(uname)" == "Linux" ]; then
    ip addr show | grep -E "^[0-9]+:|inet "
else
    ifconfig | grep -E "^[a-zA-Z0-9]+:|inet "
fi

# System Load
echo -e "\nSystem Load:"
uptime

# Memory-Intensive Processes
echo -e "\nTop Memory-Intensive Processes:"
ps aux | sort -rn -k 4 | head -5

# CPU-Intensive Processes
echo -e "\nTop CPU-Intensive Processes:"
ps aux | sort -rn -k 3 | head -5
