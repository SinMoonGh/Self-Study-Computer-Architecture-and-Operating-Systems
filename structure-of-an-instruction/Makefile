# 컴파일러 설정
CC=gcc
CFLAGS=-g -Wall

# 타겟 프로그램들
TARGETS=ImmediateAddressing DirectAddressing RegisterAddressing stack linked_stack

# 각 타겟의 소스 파일들
SRCS=$(wildcard *.c)

# 오브젝트 파일들
OBJS=$(SRCS:.c=.o)

# 기본 타겟 - 모든 프로그램 빌드
all: $(TARGETS)

# 각각의 타겟을 위한 컴파일 규칙
%: %.o
	$(CC) $(CFLAGS) -o $@ $<

# .c 파일을 .o 파일로 컴파일
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 모든 프로그램 실행
run: $(TARGETS)
	@for target in $(TARGETS); do \
		echo "Running $$target:"; \
		./$$target; \
		echo ""; \
	done

# 청소
clean:
	rm -f $(TARGETS) $(OBJS)

.PHONY: all run clean $(addprefix run-,$(TARGETS)) $(addprefix debug-,$(TARGETS))
