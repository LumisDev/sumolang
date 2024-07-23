case "$1" in
    "cfg")
        cmake -S "$2" -B "$2/build" -DCMAKE_TOOLCHAIN_FILE="$2/toolchain/compile.cmake" -G Ninja
        ;;
    "build")
        cmake --build "$2/build"
        ;;
    "rebuild")
        rm -rf "$2/build"
        cmake -S "$2" -B "$2/build" -DCMAKE_TOOLCHAIN_FILE="$2/toolchain/compile.cmake" -G Ninja
        cmake --build "$2/build"
        ;;
    "recfg")
        rm -rf "$2/build"
        cmake -S "$2" -B "$2/build" -DCMAKE_TOOLCHAIN_FILE="$2/toolchain/compile.cmake" -G Ninja
        ;;
    "reset")
        rm -rf "$2/build"
        ;;
    *)
        echo "The only used commands are cfg, rebuild, recfg, reset, and build!"
        ;;
esac
