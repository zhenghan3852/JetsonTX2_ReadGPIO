# JetsonTX2_ReadGPIO
## ReadGPIO.c
 > Defined 4 GPIO: 
 - `GPIO8` = sysfs GPIO #388 on TX2(connected with a pull-down resistor)
 - `GPIO9` = sysfs GPIO #298 on TX2(connected with a pull-up resistor)
 - `GPIO_EXP0_INT` = sysfsGPIO #480 on TX2(normal GPIO)
 - `GPIO_EXP1_INT` = sysfsGPIO #486 on TX2(normal GPIO)

  -In the ReadGPIO.c file, use the `GPIO_EXP0_INT`. The program will print the level of pin on the terminal.

## GPIO_init.sh
 - This script will initialize the `GPIO_EXP0_INT`. Execute it before use the program.

***By  Zheng*** 
