#! /bin/bash
sudo chmod 777 /sys/class/gpio/export
sudo echo 480 > /sys/class/gpio/export
sudo chmod 777 /sys/class/gpio/gpio480/direction
sudo echo in > /sys/class/gpio/gpio480/direction
