@echo off
setlocal

set CC=C:\Toolchain\arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-gcc
set CXX=C:\Toolchain\arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-g++


rem Definiere den Pfad zum Build-Ordner
set "BUILD_DIR=CmakeBuild"

rem Überprüfen, ob der Build-Ordner existiert und löschen, wenn ja
if exist "%BUILD_DIR%" (
    echo Lösche den vorhandenen Build-Ordner...
    rmdir /s /q "%BUILD_DIR%"
)

rem Neuen Build-Ordner erstellen
echo Erstelle neuen Build-Ordner...
mkdir "%BUILD_DIR%"

rem In den Build-Ordner wechseln
cd "%BUILD_DIR%"

rem Build starten
echo Starte den Build...
cmake -G Ninja ..

rem Build starten
echo Starte den Build mit Ninja...
ninja

echo Build abgeschlossen.
endlocal
