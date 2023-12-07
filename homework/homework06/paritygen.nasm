; -----------------------------------------------------------------------------
;  paritygen program in 'nasm' -> essentially simulates the parity flag
;     to assemble:   nasm -f macho64 paritygen.nasm
;     to link: gcc paritygen.o -o paritygen
; -----------------------------------------------------------------------------

; Plan:
; AND the bitstring against 0x01, check to see if that digit was a one, if it is then increment the 'one' counter
; bitshift the bitstring to the right, decrement the loop counter, then repeat if the loop counter hasn't reached 0
; once the loop has finished, use idiv to essentially mod the 'one' counter and then return the correct response


           global  _paritygen
           default rel

                segment .text

_paritygen:   push   rbx            ; we have to push this to keep the os happy
              mov    r8, rdi        ; grab the function argument and put it into r8
              xor    r10, r10       ; initialize 'one' counter 
              mov    r9, r8         ; make a copy of r8 so that we can AND r8
              mov    r11, 8         ; initialize loop counter
anding:       dec    r11            ; START OF ANDING LOOP: update counter
              cmp    r11, 0x00      ; check counter status
              je     checkP         ; if the loop counter is zero, we're done
              mov    r8, r9         ; reset r8 to the current bitstring
              and    r8, 0x01       ; isolate the least significant digit
              shr    r9, 1          ; bitshift r9 to queue up the next digit
              cmp    r8, 0x01       ; compare our ANDed number to 1
              je     increment      ; if the current digit is a 1, jump to increment
              jne    anding         ; if not, move on to the next iteration

increment:    inc    r10            ; increment the 'one' counter
              jmp    anding         ; jump back into the loop

checkP:       xor    rdx, rdx       ; clear rdx (just kinda needs to happen for idiv-ing)
              mov    rax, r10       ; move 'one' counter into rax so we can idiv it
              mov    r8,  2         ; move the value of 2 into r8
              idiv   r8             ; idiv 'one' counter by 2
afterDiv:     cmp    rdx, 0x00      ; check the remainder
              je     even           ; if 'one' counter mod 2 is 0: there are an even number of ones
              jne    odd            ; otherwise there are an odd number of ones

even:         mov    rax, 0x01      ; if there are an even number of ones, we return a one
jumping:      jmp    end            ; jump to end

odd:          mov    rax, 0x00      ; if there are an odd number of ones, we return a zero

end:          pop    rbx            ; restore the base pointer
              ret                   ; return and we're done