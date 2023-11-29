; -----------------------------------------------------------------------------
;  findGCD function in 'nasm' for use in a C file.
;     to assemble:   nasm -f macho64 findGCD.nasm
; -----------------------------------------------------------------------------

           global  _findGCD
           default rel

                segment .text

_findGCD:   push   rbx          ; we have to push this to keep the os happy
           mov    r8, rdi       ; initialize the values for GCD finding
           mov    r9, rsi       ; ^
           cmp    r8, r9        ; compare the two values so that we can ensure r8 is the greater value
           je     end           ; if the values happen to be the same, they are each other's GCD
           jg     switch        ; if r9 is the greater value, we must switch them for euclid's

euclid:    xor    rdx, rdx      ; clear rdx so that idiv works
           mov    rax, r8       ; r8 is the greater value, so get ready to idiv it
           idiv   r9            ; idiv r8 by r9
           mov    r8, r9        ; r9's value becomes the larger of the values
           mov    r9, rdx       ; remainder of the idiv becomes the lesser of the values
           cmp    rdx, 0        ; compare the remainder to zero
           je     end           ; if it is zero, we're done
           jne    euclid        ; otherwise, repeat euclid's

switch:    mov    r10, r8      ; r9 is the greater value, so switch them using r10 as a temp value
           mov    r8, r9       ; ^
           mov    r9, r10      ; ^
           jmp    euclid       ; with the values flipped, we can start euclid's

end:       mov    rax, r8      ; get ready to return r8
           pop    rbx          ; restore base pointer
           ret                 ; we're done


               segment .data
format:    db   "%20d", 0x0A, 0x00