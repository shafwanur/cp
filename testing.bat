@echo off

set i=0
:loop
    gen %i% > in
    code < in > out

    echo. 
    echo INPUT
    type in
    echo OUTPUT
    type out
    pause

    set /a i=%i%+1
    goto loop

:fail 
    echo FAILED %i%
    gen %i%
    pause
    goto loop
