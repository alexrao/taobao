# Author : rxp
# Date: 2015.04.14

LOCAL_PWD := $(shell cd ./; pwd)
CFLAGS += -I$(LOCAL_PWD)/src
CFLAGS += -I$(LOCAL_PWD)/include
CFLAGS += -g 
CFLAGS += -std=c99

SOURCE := src/main.c src/dprintf.c

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
	rm src/*.o -f 
	rm main
	