BITS 64

extern  malloc
extern  ft_strlen
extern  ft_strcpy

section .text

global ft_strdup

ft_strdup:
    cmp     rdi, 0x0
    jz      _error_null
    call    ft_strlen       ;appelle de strlen sur rdi qui contient la string et stock sa longueur dans rax
    inc     rax             ;rax + 1 pour pouvoir malloc le \0
    push    rdi             ;creation d une tmp sur la stack
    mov     rdi, rax        ;mise de la taille dans rdi pour pouvoir appeler malloc
    call    malloc          ;malloc de rax a la bonne taille
    cmp     rax, 0
    je      _error_malloc
    pop     rsi             ;recuperation de la tmp sur la stack
    mov     rdi, rax        ;deplacement de la string malloc pour pouvoir appeler strcpy
    call    ft_strcpy       ;cpie rsi dans rdi et la stock dans rax
    ret                     ;return

_error_malloc:
    mov     rax, 0
    pop     rsi             ;recuperation de la tmp sur la stack
    ret

_error_null:
    mov     rax, 0
    ret