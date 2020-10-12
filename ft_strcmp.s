BITS 64

section .text

global ft_strcmp

ft_strcmp:
    push    r8          ;variable tmp
    push    r9          ;variable tmp
    push    rcx         ;compteur
    mov     r8, rdi     ;string 1
    mov     r9, rsi     ;string 2
    mov     rcx, 0      ;compteur mit a 0

_loop:
    cmp     byte [r9 + rcx], 0  ;compare la string 1 a \0
    je      _ret                ;si == => return
    mov     dl, [r8 + rcx]      ;stock le caractere de string 1 dans dl (repertoire tmp)
    cmp     dl, [r9 + rcx]      ;copare les 2 caracs
    ja      _ret                ;si != return
    jb      _ret1
    inc     rcx                 ;incrementation du compteur
    jmp     _loop               ;je boucle

_ret:
    mov     rax, 0              ;mettre la veleur de retour a 0
    mov     al, [r8 + rcx]      ;la mettre a la valeur du caractere ascii de s1
    sub     al, [r9 + rcx]      ;soustraire la valeur du caractere ascii de s2
    pop     rcx                 ;supprimer compteur
    pop     r9
    pop     r8
    ret                         ;return

_ret1:
    mov     rax, -1             ;mettre la veleur de retour a -1 pour avoir un octet signe
    mov     al, [r8 + rcx]      ;la mettre a la valeur du caractere ascii de s1
    sub     al, [r9 + rcx]      ;soustraire la valeur du caractere ascii de s2
    pop     rcx                 ;supprimer compteur
    pop     r9
    pop     r8
    ret                         ;return