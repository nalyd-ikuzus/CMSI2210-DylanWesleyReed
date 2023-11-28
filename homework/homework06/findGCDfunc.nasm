; -----------------------------------------------------------------------------
;  findGCD function in 'nasm' for use in a C file.
;     to assemble:   nasm -f macho64 findGCD.nasm
; -----------------------------------------------------------------------------

           global  _findGCD
           default rel

                segment .text

_findGCD:   push   rbx            ; we have to push this to keep the os happy
           mov    r8, rdi ; initialize the values for testing division and such
           mov    r9, rsi ; ^
           cmp    r8, r9
           je     end
           jg     switch

euclid:    xor    rdx, rdx
           mov    rax, r8       ; r8 is the greater value
           idiv   r9
           mov    r8, r9
           mov    r9, rdx
           cmp    rdx, 0
           je     end
           jne    euclid

switch:    mov    r10, r8      ; r9 is the greater value, so switch them using r10 as a temp value
           mov    r8, r9
           mov    r9, r10
           jmp    euclid

end:       mov    rax, r8
           pop    rbx
           ret


               segment .data
format:    db   "%20d", 0x0A, 0x00
scan_str   db   "%d", 0
str_form:  db   "%s", 0x00
input1str: db   0x0A, "Enter your first number: ", 0x00
input2str: db   0x0A, "Enter your second number: ", 0x00

               segment .bss
num:       resb 8