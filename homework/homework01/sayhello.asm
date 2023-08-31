         global      _main                   ; declares the starting entry point
         extern      _printf                 ; we'll use the "C" library for now

         section .text                       ; code starts here
_main:
         push        ebx
         push        message                 ; put the message on the stack
         call        _printf                 ; call "printf()" to display it
         add         esp, 4                  ; set up the exit
         pop         ebx
         ret                                 ; return to Windows

message: db  "Hello, World!", 10, 0
                    