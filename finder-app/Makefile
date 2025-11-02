SRC := writer.c
OBJ := $(SRC:.c=.o)
TARGET := writer

CC := $(CROSS-COMPILE)gcc


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) 

clean:
	rm -f $(OBJ) $(TARGET)
