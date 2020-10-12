BITS 64

extern __errno_location

section .text

global  ft_read

ft_read:
    mov     rax, 0
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