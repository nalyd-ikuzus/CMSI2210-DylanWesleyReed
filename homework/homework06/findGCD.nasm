; -----------------------------------------------------------------------------
;  findGCD program in 'nasm'
;     to assemble:   nasm -f macho64 findGCD.nasm
; -----------------------------------------------------------------------------

           global  _main
           default rel
           extern _printf
           extern _scanf
           extern _atoi


                segment .text

_main:     push   rbx            ; we have to push this to keep the os happy


prompt1:   xor    rax, rax       ; print out first prompt
           mov    rdi, str_form
           mov    rsi, input1str
           call   _printf

input1:    xor    rax, rax
           mov    rdi, scan_str
           push   qword 0
           push   qword 0
           mov    rsi, rsp
           call   _scanf
           mov    r8, [rsp]
           add    rsp, 16

           push   r8

prompt2:   xor    rax, rax
           mov    rdi, str_form
           mov    rsi, input2str
           sub    rsp, 8
           call   _printf
           add    rsp, 8

input2:    xor    rax, rax
           mov    rdi, scan_str
           push   qword 0
           push   qword 0
           mov    rsi, rsp
           sub    rsp, 8
           call   _scanf
           add    rsp, 8
           mov    r9, [rsp]
           add    rsp, 16

           pop    r8

afterRead:

           ;mov    r8, 3113041662 ; initialize the values for testing division and such
           ;mov    r9, 11570925   ; ^
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

print:     mov    rsi, r8 ; we're done, so let's print stuff
           lea    rdi, [format]
           ;sub    rsp, 8
           call   _printf
           ;add    rsp, 8


end:       pop    rbx
           ret


               segment .data
format:    db   "%20d", 0x0A, 0x00
scan_str   db   "%d", 0
str_form:  db   "%s", 0x00
input1str: db   0x0A, "Enter your first number: ", 0x00
input2str: db   0x0A, "Enter your second number: ", 0x00

               segment .bss
num:       resb 8