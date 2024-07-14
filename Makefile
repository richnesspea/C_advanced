# Tên của trình biên dịch
CC = gcc

# Các flags cho trình biên dịch
CFLAGS = -Wall -g -Wno-unused-variable

# Tên của file thực thi
TARGET = 003_3

# Định nghĩa các file nguồn và file đối tượng
SRCS = 003_3.c
OBJS = $(SRCS:.c=.o)

# Quy tắc mặc định để build chương trình
all: $(TARGET)

# Quy tắc để link các file đối tượng thành file thực thi
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Quy tắc để biên dịch các file .c thành file .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Quy tắc để dọn dẹp các file tạm và file thực thi
clean:
	rm -f $(OBJS) $(TARGET)

# Quy tắc để chạy chương trình
run: $(TARGET)
	./$(TARGET)
