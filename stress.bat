@echo off

set i=0
:loop
    echo %i%

    gen > in
    code < in > wa-out
    test < in > ac-out

    fc /w /c ac-out wa-out
    if errorlevel 1 goto fail

    set /a i=%i%+1
    goto loop

:fail 
    echo FAILED %i%
    type in

    pause
    
    set /a i=%i%+1
    goto loop
