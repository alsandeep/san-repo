VERSION=$(shell uname -r)
obj-m += hello-world.o
obj-m += hello-world-2.o
obj-m += hello-world-3.o
obj-m += hello-world-4.o
obj-m += hello-world-5.o

all:
	make  -C /lib/modules/$(VERSION)/build  SUBDIRS=$(PWD) # M=$(PWD) modules

clean:
	make -C /lib/modules/$(VERSION)/build SUBDIRS=$(PWD) clean #M=$(PWD)
