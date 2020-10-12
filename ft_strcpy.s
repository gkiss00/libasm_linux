BITS 64

section .text

global ft_strcpy

ft_strcpy:
    push    r8          ;cre le registre r8
    push    r9          ;cre le registre r8
    push    rax         ;cre le registre rax
    mov     rax, 0      ;initialise le compteur rax a 0
    mov     r8, rdi     ;backup de la dest dans r8
    mov     r9, rsi     ;placement de la src dans r9


_loop:
    cmp     byte [r9 + rax], 0      ;check si le caractere est un \0
    je      _ret                    ;si oui, quitte la boucle
    mov     dl, [r9 + rax]          ;copie chaque caract dans une tmp
    mov     [r8 + rax], dl          ;copie la tmp dans dest
    inc     rax                     ;incremente rax
    jmp     _loop                   ;iteration suivante

_ret:
    mov byte [r8 + rax], 0  ;met le \0
    pop rax                 ;delete rax
    mov rax, r8             ;stock la dest dans le return (rax)
    pop r8                  ;delete r8
    pop r9                  ;delete r9
    ret                     ;return