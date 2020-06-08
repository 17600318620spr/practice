SHELL 	= /bin/sh

LIB_DIR 	= /home/hjy/Desktop/0605/makefile_dynamiclib2/lib/
BIN_DIR 	= /home/hjy/Desktop/0605/makefile_dynamiclib2/bin/
OBJECT_DIR 	= /home/hjy/Desktop/0605/makefile_dynamiclib2/test/obj/
APP_DIR 	= /home/hjy/Desktop/0605/makefile_dynamiclib2/testapp/

$(shell mkdir -p ${LIB_DIR})
$(shell mkdir -p ${BIN_DIR})
$(shell mkdir -p ${OBJECT_DIR})

RM 	= rm -fr

#****************************************************************************

CC 		= gcc
SHARED 		= -shared -o
FPIC		= -fPIC -c
RDY		= -rdynamic -s

SRC_OBJECT 	= $(APP_DIR)getdate.c $(APP_DIR)gettime.c
H_OBJECT 	= $(APP_DIR)datetime.h
OBJECT 		= getdate.o gettime.o

DY_SRC_OBJECT 	= $(APP_DIR)dy.c
DY_OBJECT	= dy.o

LIB_OBJECT 	= libmy.so
BIN_OBJECT 	= dy

#****************************************************************************

.PHONY:all

all:$(LIB_OBJECT) $(BIN_OBJECT)

$(LIB_OBJECT):$(OBJECT)
	$(CC) $(OBJECT) $(SHARED) -fPIC -o $(LIB_OBJECT)
	mv $(LIB_OBJECT) $(LIB_DIR)

$(OBJECT):$(SRC_OBJECT) $(H_OBJECT)
	$(CC) $(FPIC) $(SRC_OBJECT)

$(BIN_OBJECT):$(DY_OBJECT)
	$(CC) $(RDY) -o $(BIN_OBJECT) $(OBJECT_DIR)$(DY_OBJECT) -ldl -L$(LIB_DIR) -lmy
	mv $(BIN_OBJECT) $(BIN_DIR)

$(DY_OBJECT):$(DY_SRC_OBJECT)
	$(CC) -c $(DY_SRC_OBJECT) -o $(DY_OBJECT)
	mv $(OBJECT) $(DY_OBJECT) $(OBJECT_DIR)

clean:
	$(RM) $(LIB_DIR) $(BIN_DIR) $(OBJECT_DIR)
