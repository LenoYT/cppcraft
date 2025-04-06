@echo off

cls
del minecraft.exe

echo #############################################################################################################
echo #                                                                                                           #
echo #                                            Minecraft Launcher (cpp)                                       #  
echo #                                                                                                           #
echo #############################################################################################################

echo Wybierz wersję Minecrafta:
echo 1. Wersja 0.0.1b
set /p version=Wybierz numer wersji (1-1): 

if "%version%"=="1" (
    set source_file="cpp/v0.0.1/minecraft.cpp"
) else (
    echo Nieznana wersja. Domyślnie wybieram wersję 0.0.1b.
    set source_file="cpp/v0.0.1/minecraft.cpp"
)    

g++ %source_file% -o minecraft.exe

minecraft.exe
