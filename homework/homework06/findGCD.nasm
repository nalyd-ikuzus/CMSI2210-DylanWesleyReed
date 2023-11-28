; -----------------------------------------------------------------------------
;  findGCD function in 'nasm'
;     to assemble:   nasm -f macho64 findGCD.nasm
; -----------------------------------------------------------------------------

           global  _main
           default rel
           extern _printf


                segment .text

_main:     push   rbx            ; we have to push this to keep the os happy
           
           mov    r8, 3113041662 ; initialize the values for division and such
           mov    r9, 11570925   ; ^
           cmp    r8, r9
           je     print
           jg     switch

euclid:    xor    rdx, rdx
           mov    rax, r8       ; r8 is the greater value
           idiv   r9
           mov    r8, r9
           mov    r9, rdx
           cmp    rdx, 0
           je     print
           jne    euclid

switch:    mov    r10, r8      ; r9 is the greater value, so switch them using r10 as a temp value
           mov    r8, r9
           mov    r9, r10
           jmp    euclid

print:     mov    rsi, r8 ; we're done
           lea    rdi, [format]
           ;sub    rsp, 8
           call   _printf
           ;add    rsp, 8


end:       pop    rbx
           ret


               segment .data
format:    db   "%20d", 0x0A, 0x00
;buffer:    
;BUFSIZE: