@echo off
if "%1" == "cfg" (
    cmake -S "%2" -B "%2/build" -DCMAKE_TOOLCHAIN_FILE="%2/toolchain/compile.cmake" -G Ninja
) else if "%1" == "build" (
    cmake --build "%2/build"
) else if "%1" == "rebuild" (
    rmdir /s /q %2\build
    cmake -S "%2" -B "%2/build" -DCMAKE_TOOLCHAIN_FILE="%2/toolchain/compile.cmake" -G Ninja
    cmake --build "%2/build"
) else if "%1" == "recfg" (
    rmdir /s /q %2\build
    cmake -S "%2" -B "%2/build" -DCMAKE_TOOLCHAIN_FILE="%2/toolchain/compile.cmake" -G Ninja
) else if "%1" == "reset" (
    rmdir /s /q %2\build
) else (
    echo The only used commands are cfg, rebuild, recfg, reset and build!
)
