# Author : rxp
# Date: 2015.04.14

LOCAL_PWD := $(shell cd ./; pwd)
CFLAGS += -g 
CFLAGS += -std=c99

SOURCE := main.c dprintf.c fun.c

OBJS = $(patsubst %.c,%.o,$(SOURCE))

APPLICATION := main

.PHONY: all

all: $(APPLICATION)

$(APPLICATION): $(OBJS)
	@echo [Link $@]
	$(Q_) $(CC) -o $@ $(OBJS) $(LDFLAGS)
	md5sum main
	sync
%.o: %.c	
	@echo [Compile $^ ...]	
	$(Q_)$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm *.o -f 
	rm main
	