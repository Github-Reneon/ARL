COMP=g++

COMPILER_FLAGS=-Wall -g

LINKER_FLAGS=-lSDL2

SOURCE=$(wildcard *.cpp)

HEADERS=$(wildcard hdd/*.h) 

OBJDIR=objs

OBJECTS:=$(foreach sourcefile, $(SOURCE), $(basename $(OBJDIR)/$(sourcefile)).o)

TARGET=start

ALL: $(TARGET) 

$(TARGET): $(OBJECTS)
	$(COMP) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(TARGET) $(OBJECTS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(COMP) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c $< -o $@
	
$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -r $(OBJDIR)
	rm $(TARGET)
