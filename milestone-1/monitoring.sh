#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
mem_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
mem_used=$(free --mega | awk '$1 == "Mem:" {print $3}')
mem_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK
disk_stats=$(df -m | grep "/dev/" | grep -v "/boot" | awk '
{
    total += $2
    used += $3
} 
END {
    if (total > 0) {
        percent = int((used * 100) / total)
        total_gb = total / 1024
        printf "%dMB/%dGB (%d%%)", used, total_gb, percent
    }
}')

# CPU LOAD
cpu_load=$(top -bn2 | grep "Cpu(s)" | tail -1 | awk -F',' '{usage=100 - $4; printf "%.1f", usage}')

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $mem_used/${mem_total}MB ($mem_percent%)
	Disk Usage: $disk_stats
	CPU load: $cpu_load%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
