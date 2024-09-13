# Tên của chương trình đầu ra
TARGET = sensor_program

# Thư mục chứa các file nguồn và file đối tượng
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Các file nguồn
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/Sensor.c
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Sensor.o

# Các cờ biên dịch
CFLAGS = -Wall -Wextra -std=c99 -I$(INCLUDE_DIR)

# Mục tiêu mặc định
all: $(TARGET)

# Cách biên dịch các file nguồn thành file đối tượng
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) -c $< -o $@

# Mục tiêu liên kết các file đối tượng thành chương trình thực thi
$(TARGET): $(OBJS)
	gcc -o $(TARGET) $(OBJS)

# Mục tiêu chạy chương trình
run: $(TARGET)
	./$(TARGET)

# Mục tiêu dọn dẹp các file đối tượng và chương trình thực thi
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

# Mục tiêu dọn dẹp tất cả, bao gồm cả thư mục build
distclean: clean
	rm -rf $(BUILD_DIR)
