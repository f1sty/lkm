obj-m += hello_world.o hello_world_simple.o device_simple.o

all:
	make -C /usr/lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /usr/lib/modules/$(shell uname -r)/build M=$(PWD) clean
