@echo off

set BUILD_TYPE=%1

if "%BUILD_TYPE%"=="" (
    set BUILD_TYPE=Debug
)

rmdir /s /q tmp 2>nul
mkdir tmp
cd tmp

:: install oatpp module

call :install_module %BUILD_TYPE% oatpp
call :install_module %BUILD_TYPE% oatpp-swagger
call :install_module %BUILD_TYPE% oatpp-sqlite

git clone --depth=1 https://github.com/oatpp/oatpp
cd oatpp
git fetch --tags
git checkout 1.3.0-latest --
mkdir build
cd build
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
cmake --build .   --target install


git clone --depth=1 https://github.com/oatpp/oatpp-swagger
cd oatpp-swagger
git fetch --tags
git checkout 1.3.0-latest --
mkdir build
cd build
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
cmake --build .   --target install

:: cd oatpp-postgresql
git clone --depth=1 https://github.com/oatpp/oatpp-postgresql
cd oatpp-postgresql
git fetch --tags
git checkout 1.3.0 --
mkdir build
cd build
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
cmake --build .   --target install
cd ..

:rmdir /s /q tmp
exit /b

:install_module
set BUILD_TYPE=%1
set MODULE_NAME=%2`

set NPROC=1
for /f "delims=" %%i in ('echo %NUMBER_OF_PROCESSORS%') do set NPROC=%%i

echo.
echo INSTALLING MODULE '%MODULE_NAME%' (%BUILD_TYPE%) using %NPROC% threads ...
echo.

git clone --depth=1 https://github.com/oatpp/%MODULE_NAME%

cd %MODULE_NAME%
mkdir build
cd build

:: Flag '-DOATPP_SQLITE_AMALGAMATION=ON' used by oatpp-sqlite module only
cmake -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DOATPP_BUILD_TESTS=OFF -DOATPP_SQLITE_AMALGAMATION=ON ..
cmake --build . --config %BUILD_TYPE% --target install -j %NPROC%

cd ..
cd ..
exit /b



