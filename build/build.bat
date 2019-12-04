@echo off
echo game is building 
cd ..
cd src
mingw32-make PLATFORM=PLATFORM_DESKTOP BUILD_MODE=DEBUG
echo Done!
cd ..
cd build
