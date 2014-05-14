CC=g++
CLASSES = CryptoMachine.o 
TARGET = CryptoMachine

$(TARGET): $(CLASSES)
	$(CC) $(CLASSES) -o $(TARGET)

.cpp.o:
	$(CC) -c $<

clean:
	rm $(CLASSES) $(TARGET)

run:
	./${TARGET}
