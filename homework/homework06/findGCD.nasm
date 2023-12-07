; -----------------------------------------------------------------------------
;  findGCD program in 'nasm' Presumably only runs on intel-based macOS
;     to assemble:   nasm -f macho64 findGCD.nasm
;     to link:  gcc findGCD.o -o findGCD
; -----------------------------------------------------------------------------

           global  _main
           default rel
           extern _printf
           extern _scanf
           extern _atoi


                segment .text

_main:     push   rbx            ; we have to push this to keep the os happy


prompt1:   xor    rax, rax          ; clear rax to keep printf happy
           mov    rdi, str_form     ; move the format into rdi
           mov    rsi, input1str    ; move the first prompt into rsi
           call   _printf           ; print out first prompt

input1:    xor    rax, rax          ; clear rax to keep scanf happy
           mov    rdi, scan_str     ; move scanning format into rdi
           push   qword 0           ; setup space on the stack
           push   qword 0           ; ^
           mov    rsi, rsp          ; set rsi to be the stack pointer for scanf
           call   _scanf            ; scan for the input
           mov    r8, [rsp]         ; move what's at the address of the stack pointer into r8
           add    rsp, 16           ; update the stack pointer to clear that space we made

           push   r8                ; preserve r8 through the next input

prompt2:   xor    rax, rax          ; clear rax to keep printf happy
           mov    rdi, str_form     ; move the format into rdi
           mov    rsi, input2str    ; move the second prompt into rsi
           sub    rsp, 8            ; since we have r8 in the stack, we have to move the stack pointer to keep printf happy
           call   _printf           ; print second prompt
           add    rsp, 8            ; reset stack pointer so we can access r8 later

input2:    xor    rax, rax          ; clear rax to keep scanf happy
           mov    rdi, scan_str     ; move scanning format into rdi
           push   qword 0           ; make space on the stack
           push   qword 0           ; ^
           mov    rsi, rsp          ; move stack pointer into rsi for scanf
           sub    rsp, 8            ; move the stack pointer to keep scanf happy
           call   _scanf            ; scan for the input
           add    rsp, 8            ; reset stack pointer
           mov    r9, [rsp]         ; move what's at the address of the stack pointer into r9
           add    rsp, 16           ; update the stack pointer to clear the space we made

           pop    r8                ; restore r8

afterRead:
           cmp    r8, r9            ; compare the two inputs
           je     print             ; if they're equal, skip to print
           jg     switch            ; if r9 is greater, switch them

euclid:    xor    rdx, rdx          ; clear rdx to keep idiv happy
           mov    rax, r8           ; r8 is the greater value, so get ready to idiv it
           idiv   r9                ; idiv r8 by r9
           mov    r8, r9            ; r9 becomes the greater value
           mov    r9, rdx           ; remainder becomes lesser value
           cmp    rdx, 0            ; compare the remainder to zero
           je     print             ; if the remainder is zero, time to print
           jne    euclid            ; otherwise, keep going with euclid's

switch:    mov    r10, r8           ; r9 is the greater value, so switch them using r10 as a temp value
           mov    r8, r9            ; ^
           mov    r9, r10           ; ^
           jmp    euclid            ; r8 holds the greater value, so ready for euclid's

print:     mov    rsi, r8           ; we're done, so let's print r8 (GCD)
           lea    rdi, [format]     ; load in the format
           call   _printf           ; print


end:       pop    rbx               ; restore base pointer
           ret                      ; we're done


               segment .data
format:    db   "%20d", 0x0A, 0x00 ; number-printing format
scan_str   db   "%d", 0 ; input-scanning format
str_form:  db   "%s", 0x00 ; string-printing format
input1str: db   0x0A, "Enter your first number: ", 0x00 ; first prompt
input2str: db   0x0A, "Enter your second number: ", 0x00 ; second prompt
