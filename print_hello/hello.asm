section .data     ; 초기화된 데이터 섹션
    ; 변수 선언
    message db "Hello, World!", 10
    len equ $ - message

section .text     ; 코드 섹션
    global _start ; 프로그램 시작점

_start:
    ; 코드 작성
    mov rax, 1      ; sys_write (1)
    mov rdi, 1      ; stdout (1)
    mov rsi, message
    mov rdx, len
    syscall         ; 시스템 콜 호출

    ; 프로그램 종료
    mov rax, 60     ; exit(60) 시스템 콜
    xor rdi, rdi    ; 인자 0
    syscall
