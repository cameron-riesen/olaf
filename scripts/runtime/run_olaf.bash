#!/bin/bash

source /home/pi/Documents/olaf/setenv.sh

xterm -T "cam" -hold -geometry 60x10-1500-800 -e $OLAF_BUILD_ROOT/bin/proc/camera_process &
echo "Started camera with PID $!"
xterm -T "gps" -hold -geometry 60x10-1500-600 -e $OLAF_BUILD_ROOT/bin/proc/gps_process &
echo "Started gps with PID $!"
xterm -T "Hardware interface" -hold -geometry 60x10-1500-400 -e $OLAF_BUILD_ROOT/bin/proc/hw_if_process &
echo "Started hw_if with PID $!"
xterm -T "imu" -hold -geometry 60x10-1100-800 -e $OLAF_BUILD_ROOT/bin/proc/imu_process &
echo "Started imu with PID $!"
