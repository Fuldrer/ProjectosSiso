    .global _syscall_readFile
    .global _syscall_readSector
    .global _syscall_printString
    .global _syscall_readString
    .global _syscall_executeProgram
    .global _syscall_terminate
    .global _syscall_clearScreen
    
;syscall_readFile(char *name, char* buffer)
_syscall_readFile:
    push bp
    mov bp, sp
    mov ax, #3
    mov bx, [bp+4]  
    mov cx, [bp+6]  
    int #0x21
    leave
    ret
;syscall_readSector(char *buffer, int sector)
_syscall_readSector:
    push bp
    mov bp, sp
    mov ax, #2
    mov bx, [bp+4]  ;str
    mov cx, [bp+6]  ;sector
    int #0x21
    leave
    ret


;syscall_printString(char *str)
_syscall_printString:
    push bp
    mov bp, sp
    mov ax, #0
    mov bx, [bp+4]  ;str
    int #0x21
    leave
    ret


;syscall_readString(char *str)
_syscall_readString:
    push bp
    mov bp, sp
    mov ax, #1
    mov bx, [bp+4]  ;str
    int #0x21
    leave
    ret


;void syscall_executeProgram(char *name, int segment)
_syscall_executeProgram:
    push bp
    mov bp, sp
    mov ax, #4
    mov bx, [bp+4] ;name
    mov cx, [bp+6] ;segment
    int #0x21
    leave
    ret

;void syscall_terminate()
_syscall_terminate:
    push bp
    mov bp, sp
    mov ax, #5
    int #0x21
    leave
    ret

;void syscall_clearScreen()
_syscall_clearScreen:
    push bp
    mov bp, sp
    mov ax, #6
    int #0x21
    leave
    ret
