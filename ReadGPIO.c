#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define GPIO8_DIR "/sys/class/gpio/gpio388/direction"
#define GPIO8_VAL "/sys/class/gpio/gpio388/value"

#define GPIO9_DIR "/sys/class/gpio/gpio298/direction"
#define GPIO9_VAL "/sys/class/gpio/gpio298/value"

#define GPIO_EXP0_INT_DIR "/sys/class/gpio/gpio480/direction"
#define GPIO_EXP0_INT_VAL "/sys/class/gpio/gpio480/value"

#define GPIO_EXP1_INT_DIR "/sys/class/gpio/gpio486/direction"
#define GPIO_EXP1_INT_VAL "/sys/class/gpio/gpio486/value"

int fd = -1; //定义文件名
int dir = -1;
char buf[1] = "1";
char last_buf[1] = "1";

int main()
{
	while(1)
	{
		last_buf[0] = buf[0];
		fd = open(GPIO_EXP0_INT_VAL, O_RDWR);
		dir = open(GPIO_EXP0_INT_DIR, O_RDWR);

		if(fd < 0)
		{
			printf("Failed to open GPIO value in %s.\n", 
					GPIO_EXP0_INT_VAL);
			return -1;
		}
		if(dir < 0)
		{
			printf("Fail to open GPIO direction in %s.\n",
					GPIO_EXP0_INT_DIR);
		}
		read(fd, buf, 1);

		if(buf[0] == '0')
		{
			write(dir, "out", 3);
			write(fd, "1", 1);
			write(dir, "in", 2);
		}
		if(buf[0] == '0' && last_buf[0] == '1')
		{
			printf("take a picture!\n");
		}

		close(fd);
		close(dir);
	}
	return 0;
}
