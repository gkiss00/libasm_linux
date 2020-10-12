BITS 64

extern __errno_location

section .text

global  ft_write

ft_write:
    mov     rax, 1
    syscall                     ;appelle system qui ecrit
    jc      _err
    ret

_err:
    push    rbx
    mov     rbx, rax
    call    __errno_location
    mov     [rax], rbx
    pop     rbx
    mov     rax, -1
    ret