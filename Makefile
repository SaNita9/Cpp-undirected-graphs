GXX = g++
TARGET = out
SOURCES = main.cpp util.cpp structure.cpp test.cpp def.cpp
HEADERS = util.h structure.h test.h def.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(GXX) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)