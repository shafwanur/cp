@echo off

set i=0
:loop
    echo %i%

    gen > in

    code < in > wa-out
    test < in > ac-out
     
    if NOT [%1]==[] (
      checker < ac-out > ac-check
      checker < wa-out > wa-check
    )
    
    if [%1]==[] (
     fc /w ac-out wa-out
    ) else (
      fc /w ac-check wa-check
    ) 
    if errorlevel 1 goto fail

    set /a i=%i%+1
    goto loop

:fail 
    echo FAILED %i%
    type in

    pause
    
    set /a i=%i%+1
    goto loop
