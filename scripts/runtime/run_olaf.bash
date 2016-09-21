#!/bin/bash

source /home/pi/Documents/olaf/setenv.sh

xterm -T "init" -hold -geometry 150x10-1000-900 -e $OLAF_BUILD_ROOT/bin/proc/initializer_process ~/olaf_config.ini &
echo "Started init with PID $!"
xterm -T "cam" -hold -geometry 150x10-1000-700 -e $OLAF_BUILD_ROOT/bin/proc/camera_process &
echo "Started camera with PID $!"
xterm -T "gps" -hold -geometry 150x10-1000-500 -e $OLAF_BUILD_ROOT/bin/proc/gps_process &
echo "Started gps with PID $!"
xterm -T "Hardware interface" -hold -geometry 150x10-1000-300 -e $OLAF_BUILD_ROOT/bin/proc/hw_if_process &
echo "Started hw_if with PID $!"
xterm -T "imu" -hold -geometry 150x10-1000-100 -e $OLAF_BUILD_ROOT/bin/proc/imu_process &
echo "Started imu with PID $!"
