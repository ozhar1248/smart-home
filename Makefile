# this is my target
TARGET = test
# All .c files in this directory are my sources
SOURCES = agent.cpp agentInformation.cpp agentsManagement.cpp compatibelVersion1.cpp event.cpp location.cpp queueManager.cpp server.cpp subQueueManager.cpp subscriptions.cpp testPhase1.cpp uncopyable.cpp 

# Include directory
INC_DIR = inc

# General compilation flags
# The compiler will be gcc("CC" is MAKE variable)
CC = g++
# The compiler flags will be... ("CFLAGS" is MAKE variable)
CFLAGS = -ansi -pedantic -Wall -Werror -g
CXXFLAGS = -pedantic -Wall -g -std=c++11
LDFLAGS = -g -pthread
CPPFLAGS = -I$(INC_DIR) 

# All .o files in this directory are my objects
OBJECTS = $(SOURCES:.cpp=.o)

# convention
.PHONY: all
all: $(TARGET)

# The default command, link all the sources
# $(cc) $(LDFLAGS) $(^) -o $(0)
$(TARGET): $(OBJECTS)
# vector.out: Vector_test.o Vector.o

include depends

depends: 
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > $(@)

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS) depends core *.o *.log 

run:  $(TARGET)
	 ./$(TARGET)
	  
	
