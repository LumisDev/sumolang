# SumoLang

SumoLang is a programming language that looks sometimes like VB.NET
Here's a little example: 
```
Public Class App
    Public Function Main(Argc: Int, Argv: Array(String)):Void
        Println("Hello!")
    End Function
End Class
```

## How to build
To build, configure and rebuild, I put a little CLI script in the repo. Just run:
```shell
# For Mac and Linux
sh ./sumo.sh cfg
sh ./sumo.sh build
```
```batch
rem For windows do this. 'sumo' is for ''.\sumo.bat'
sumo cfg
sumo build
```
> Note: These programs ***are required***: CMake >= 3.5, LLVM (with Clang), Ninja >= 1.5
