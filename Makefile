CC=gcc
CFLAGS=-Wall

all:
	$(CC) main.c monitor.c logger.c whitelist.c analyzer.c -ludev -o usb_monitor

clean:
	rm -f usb_monitor