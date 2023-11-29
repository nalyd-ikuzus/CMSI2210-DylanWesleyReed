; -----------------------------------------------------------------------------
;  paritygen program in 'nasm' -> essentially simulates the parity flag
;     to assemble:   nasm -f macho64 paritygen.nasm
; -----------------------------------------------------------------------------

; Plan:
; AND the bitstring against 0x01, check to see if that digit was a one, if it is then increment the 'one' counter
; bitshift the bitstring to the right, decrement the loop counter, then repeat if the loop counter hasn't reached 0
; once the loop has finished, use idiv to essentially mod the 'one' counter and then return the correct response


           global  _paritygen
           default rel

                segment .text

_paritygen:   push   rbx            ; we have to push this to keep the os happy
              mov    r8, rdi
              xor    r10, r10
              ;mov    r8, 0x0F
              mov    r9, r8
              mov    r11, 8
anding:       dec    r11
              cmp    r11, 0x00
              je     checkP
              mov    r8, r9
              and    r8, 0x01
              shr    r9, 1
              cmp    r8, 0x01
              je     increment
              jne    anding

increment:    inc    r10
              jmp    anding

checkP:       xor    rdx, rdx
              mov    rax, r10
              mov    r8,  2
              idiv   r8
afterDiv:     cmp    rdx, 0x00
              je     even
              jne    odd

even:         mov    rax, 0x01
jumping:      jmp    end

odd:          mov    rax, 0x00

end:          pop    rbx
              ret