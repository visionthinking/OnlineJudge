@echo off  
:loop  
    rand.exe > rand.in
    std.exe < rand.in > std.out
    my.exe < rand.in > my.out
    fc my.out std.out  
if not errorlevel 1 goto loop  
pause  
goto loop