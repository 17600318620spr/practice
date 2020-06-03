# 指令编译器和选项
CC=gcc
CFLAGS=-Wall -std=gnu99

# 目标文件
TARGET	= test
SRCS 	= test.c \
	  ./test-add/test-add.c \
	  ./test-sub/test-sub.c 

INC = -I./test-add -I./test-sub

OBJS = $(SRCS:.c=.o)

$(TARGET):$(OBJS)
#	@echo TARGET :$@
#	@echo OBJECTS:$^
	$(CC) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
