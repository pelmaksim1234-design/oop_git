$ErrorActionPreference = "Stop"

$mingwBin = "C:\Users\pohil\AppData\Local\Programs\CLion\bin\mingw\bin"
$cmakeExe = "C:\Users\pohil\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe"
$buildDir = Join-Path $PSScriptRoot "cmake-build-debug"
$fso = New-Object -ComObject Scripting.FileSystemObject
$shortRoot = $fso.GetFolder($PSScriptRoot).ShortPath
$shortBuildDir = $fso.BuildPath($shortRoot, "cmake-build-debug")

$env:PATH = "$mingwBin;$env:PATH"

& $cmakeExe -S $shortRoot -B $shortBuildDir -G "MinGW Makefiles" `
    -DCMAKE_MAKE_PROGRAM="$mingwBin\mingw32-make.exe" `
    -DCMAKE_C_COMPILER="$mingwBin\gcc.exe" `
    -DCMAKE_CXX_COMPILER="$mingwBin\g++.exe"
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

& $cmakeExe --build $shortBuildDir --target lab2
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

& (Join-Path $buildDir "lab2.exe")
exit $LASTEXITCODE
