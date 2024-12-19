# 获取当前目录
DIR := $(shell pwd)

# 查找所有 .c 文件
CSRCS := $(shell find . -name "*.c")
CSRCS += $(shell find ../ds-common -name "*.c")

# 定义编译标志
CFLAGS := -g -O2 -Wall
CFLAGS += -I./include
CFLAGS += -I../ds-common/include

# 生成目录
BUILD_DIR := build

# 最终生成的可执行文件名称
TARGET := interpreter

# 将 .c 文件转换为对应的 .o 文件
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(CSRCS))

# 编译器
CC := gcc

# 默认目标
all: $(BUILD_DIR) $(TARGET)

# 生成目标文件
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "+cc $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	@echo "+link $@"
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm

run: all
	./$(TARGET)

# 清理编译生成的文件
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# 建立编译目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 显示的伪目标
.PHONY: all clean
