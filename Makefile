CC = g++
CXXFLAGS = -Wall -Wextra -O3
#-I $(INCDIR)

#INCDIR = include/
OBJDIR = obj/
SRCDIR = src/

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

TARGET = filesys

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) ${OBJS}

.PHONY: clean
