; demo.stpn
; program to output the powers of 2 up to 1,000,000
; output goes to port 100  [hex 0x64]
; copied from cmsi 284/2210 web pages

            global      _main   
            global      _loop
            global      _end
            extern      _printf    

            section     .text


; Initial variables
_main:
            push        ecx
            mov         ecx, 0x1         
            mov         ebx, 0xA

; Main loop
_loop:      
            push        ecx
            push        format
            call        _printf
            add         esp, 0x8
            add         ecx, 0x1
            cmp         ecx, ebx
            jle         _loop       

; Terminate program
_end:
            pop         ecx
            ret

format: db "%d", 0xA, 0x00