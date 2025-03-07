# 실행 파일 이름
TARGET = calculator

# NASM 컴파일 옵션
NASM = nasm
NASM_FLAGS = -f elf64 -g -F dwarf

# 링커 옵션 (GCC 사용)
CC = gcc
LDFLAGS = -no-pie -nostartfiles

# 빌드할 소스 파일
SRC = $(TARGET).asm
OBJ = $(TARGET).o

# 빌드 규칙
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ): $(SRC)
	$(NASM) $(NASM_FLAGS) -o $@ $<

# 실행 규칙
run: $(TARGET)
	./$(TARGET)

# 디버깅 (GDB 실행)
debug: $(TARGET)
	gdb ./$(TARGET)

# 정리 (빌드된 파일 삭제)
clean:
	rm -f $(OBJ) $(TARGET)
