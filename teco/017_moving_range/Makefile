# Makefile
#
##################################################################
#Compiler Setting
CC	= g++
LD	= g++
AR	= ar

#Compile Option
CPP_FLAGS	+=
#CPP_FLAGS	+= -m32
#CPP_FLAGS	+= -O2
CPP_FLAGS	+= -Wall
#CPP_FLAGS	+= -fPIC

#Link Option
LD_FLAGS	+=
#LD_FLAGS	+= -m32

#Archive Option
#AR_FLAGS	+= crsv

#Include Directory
INC		+= -I./

#Lib Directory
LIB_DIR	+=

#Library
LIBS	+=
#LIBS	+= -lrt

##################################################################
#Target File
TARGET	= moveRange

#Archive File
ARFILE	= moveRange.a

#Object Files
OBJS	+= main.o
OBJS	+= moveRange.o

##################################################################
#Make Rule
all:$(TARGET)
#all:$(ARFILE)
#all:$(OBJS)

#Target
$(TARGET): $(OBJS)
	$(LD) $(LD_FLAGS) $(LIB_DIR) $(LIBS) -o $(TARGET) $(OBJS) -v

#Archive
$(ARFILE): $(OBJS)
	$(AR) $(AR_FLAGS) $(ARFILE) $(OBJS)

#Object
%.o: %.cpp
	$(CC) -c $(INC) $(CPP_FLAGS) $(@:.o=.cpp)

clean:
	rm -fv *.o *.so *.a
	rm -fv $(TARGET)


#EOF

