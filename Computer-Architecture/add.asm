section .data
    num1 db 1
    num2 db 2
    result db 0
    fmt db "Result: %d", 10, 0  ; printf 포맷 문자열

section .bss
    res resb 1

section .text
    global _start
    extern printf

_start:
    mov al, [num1]     ; AL 레지스터에 num1(1) 로드
    add al, [num2]     ; AL에 num2(2) 더함
    mov [res], al      ; 결과를 res에 저장

    ; printf 호출
    mov rdi, fmt       ; 첫 번째 인자 (출력 포맷 문자열)
    movzx rsi, byte [res] ; 두 번째 인자 (연산 결과)
    call printf

    ; 종료
    mov eax, 60        ; exit(60) 시스템 콜
    xor edi, edi
    syscall
