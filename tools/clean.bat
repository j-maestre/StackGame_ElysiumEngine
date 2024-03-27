@echo off

set "build_dir=..\build"
set "exclude_folder=deps"

del /Q "%build_dir%\*.vcxproj"
del /Q "%build_dir%\*.vcxproj.filters"
del /Q "%build_dir%\*.vcxproj.user"
del /Q "%build_dir%\*.ini"
del /Q "%build_dir%\*.sln"

for /d %%i in ("%build_dir%\*") do (
    if /i not "%%~nxi"=="%exclude_folder%" (
        echo Eliminando carpeta: "%%i"
        rmdir /s /q "%%i"
    ) else (
        echo Se omitió la carpeta: "%%i"
    )
)

echo Archivos eliminados exitosamente.

pause