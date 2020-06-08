SHELL 	= /bin/sh

LIB_DIR 	= /home/hjy/Desktop/0605/makefile_staticlib.bak/lib/
BIN_DIR 	= /home/hjy/Desktop/0605/makefile_staticlib.bak/bin/
OBJECT_DIR 	= /home/hjy/Desktop/0605/makefile_staticlib.bak/test/obj/
APP_DIR 	= /home/hjy/Desktop/0605/makefile_staticlib.bak/testapp/

$(shell mkdir -p ${LIB_DIR})
$(shell mkdir -p ${BIN_DIR})
$(shell mkdir -p ${OBJECT_DIR})

RM 	= rm -fr

#****************************************************************************

CC 		= gcc
AR 		= ar rc
SRC_OBJECT 	= $(APP_DIR)test_a.c $(APP_DIR)test_b.c $(APP_DIR)test_c.c
H_OBJECT 	= $(APP_DIR)so_test.h
OBJECT 		= test_a.o test_b.o test_c.o
DY_SRC_OBJECT 	= $(APP_DIR)test.c
DY_OBJECT	= test.o
LIB_OBJECT 	= libtest.a
BIN_OBJECT 	= a.test

#****************************************************************************

.PHONY:all

all:$(LIB_OBJECT) $(BIN_OBJECT)

$(LIB_OBJECT):$(OBJECT)
	$(AR) $(LIB_OBJECT) $(OBJECT)
	mv $(LIB_OBJECT) $(LIB_DIR)

$(OBJECT):$(SRC_OBJECT) $(H_OBJECT)
	$(CC) -c $(SRC_OBJECT)

$(BIN_OBJECT):$(DY_OBJECT)
	$(CC) -o $(BIN_OBJECT) $(OBJECT_DIR)$(DY_OBJECT) $(LIB_DIR)$(LIB_OBJECT)
	mv $(BIN_OBJECT) $(BIN_DIR)

$(DY_OBJECT):$(DY_SRC_OBJECT)
	$(CC) -c $(DY_SRC_OBJECT) -o $(DY_OBJECT)
	mv $(OBJECT) $(DY_OBJECT) $(OBJECT_DIR)

clean:
	$(RM) $(LIB_DIR) $(BIN_DIR) $(OBJECT_DIR)
