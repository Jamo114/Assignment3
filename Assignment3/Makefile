CC=g++
CLASSES = Assignment3.o 
TARGET = Assignment3

$(TARGET): $(CLASSES)
	$(CC) $(CLASSES) -o $(TARGET)

.cpp.o:
	$(CC) -c $<

clean:
	rm $(CLASSES) $(TARGET)

run:
	./${TARGET}
