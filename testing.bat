@echo off

set i=0
:loop
    gen > in
    code < in > out

    echo. 
    echo INPUT
    type in
    echo.

    echo OUTPUT
    type out
    echo.

    if NOT [%1]==[] (
      echo CHECKER
      checker < out
      echo.
    )
    pause

    set /a i=%i%+1
    goto loop
