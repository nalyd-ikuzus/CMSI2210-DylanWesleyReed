   ;----------------------------------------------------------------------------
   ; makeNBO.nasm
   ;
   ; This is a Win32 console progam tests the correctness of makeNBO.c
   ;
   ;  to assemble for windows:         nasm -f win32 makeNBO.nasm
   ;  to link for win32 under win64:   gcc -m32 makeNBO.obj -o makeNBO.exe
   ;  to link for gdb for win32:       gcc -gdb -m32 makeNBO.obj -o makeNBO.exe
   ;----------------------------------------------------------------------------

               global   _main
               extern   _printf
               extern   _makeNBO

               section  .text

   _main:
               push     ebx                 ; Save ebx

   test1:
               mov      ebx, 0x000000F0     ; Set input of makeNBO to 0x000000F0 
               push     ebx                 ; Push ebx to makeNBO
               call     _makeNBO            ; Calls makeNBO to convert 0x000000F0 -> 0xF0000000
               cmp      eax, 0xF0000000     ; Test to see if the bytes at the end switch properly 
               jne      fail                ; Jump if assertion fails
   
   test2:
               mov      ebx, 0xF0000000     ; Set input of makeNBO to 0xF0000000
               push     ebx                 ; Push ebx to makeNBO 
               call     _makeNBO            ; Calls makeNBO to convert 0xF0000000 -> 0x000000F0
               cmp      eax, 0x000000F0     ; Test to see if the bytes at the end switch properly
               jne      fail                ; Jump if assertion fails

   test3:
               mov      ebx, 0xDDDDDDDD     ; Set input of makeNBO to 0xDDDDDDDD
               push     ebx                 ; Push ebx to makeNBO 
               call     _makeNBO            ; Calls makeNBO to convert 0xDDDDDDDD -> 0xDDDDDDDD
               cmp      eax, 0xDDDDDDDD     ; Test to see if number does not change for palindromatic bytes
               jne      fail                ; Jump if assertion fail
   
   test4:
               mov      ebx, 0x49B2B249     ; Set input of makeNBO to 0x49B2B249
               push     ebx                 ; Push ebx to makeNBO 
               call     _makeNBO            ; Calls makeNBO to convert 0x49B2B249 -> 0x49B2B249
               cmp      eax, 0x49B2B249     ; Test to see if number does not change for palindromatic bytes
               jne      fail                ; Jump if assertion fails 
   
   test5:
               mov      ebx, 0x00889900     ; Set input of makeNBO to 0x00889900
               push     ebx                 ; Push ebx to makeNBO 
               call      _makeNBO           ; Calls makeNBO to convert 0x00889900 -> 0x00998800
               cmp      eax, 0x00998800     ; Test to see if the middle bytes switch
               jne      fail                ; Jump if assertion fails
   
   test6:
               mov      ebx, 0x00998800     ; Set input of makeNBO to 0x00998800
               push     ebx                 ; Push ebx to makeNBO 
               call     _makeNBO            ; Calls makeNBO to convert 0x00998800 -> 0x00889900
               cmp      eax, 0x00889900     ; Test to see if the middle bytes switch
               jne      fail                ; Jump if assertion fails

   complete:
               push     eax                 ; Push eax to printf
               push     ebx                 ; Push ebx to printf
               push     done                ; Pushes the congrats message to printf
               call     _printf             ; Prints the congrats message
               add      esp, 12             ; Add 12 bytes back to stack       
               jmp      end                 ; Jump to end the program

   fail:       
               push     failure             ; Pushes the failure message to printf
               call     _printf             ; Prints the failure message
               add      esp, 4              ; Add 4 bytes back to stack  

   end:        
               pop      ebx                 ; Pop all variables
               ret                          ; End program
               

               section  .data
   failure:    db       "Test Failed! %d is not a reverse byte of %d!", 0x0A, 0x00
   done:       db       "Congrats! All tests passed!", 0x0A, 0x00