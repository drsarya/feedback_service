#!/bin/sh

BUILD_TYPE=$1

if [ -z "$BUILD_TYPE" ]; then
    BUILD_TYPE="Debug"
fi

rm -rf tmp

mkdir tmp
cd tmp

##########################################################
## install oatpp module

function install_module () {

BUILD_TYPE=$1
MODULE_NAME=$2



echo "\n\nINSTALLING MODULE '$MODULE_NAME' ($BUILD_TYPE)  \n\n"

git clone --depth=1 https://github.com/oatpp/$MODULE_NAME
cd $MODULE_NAME
git fetch --tags
git checkout 1.3.0-latest --

mkdir build
cd build

cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
make install -j 1

cd ../../

}




##########################################################

function install_module_oatpp_postgresql () {

BUILD_TYPE=$1
MODULE_NAME=$2


echo "\n\nINSTALLING MODULE '$MODULE_NAME' ($BUILD_TYPE)  \n\n"

git clone --depth=1 https://github.com/oatpp/oatpp-postgresql
cd $MODULE_NAME
git fetch --tags
git checkout 1.3.0 --


mkdir build
cd build

############################################################################
## Flag '-DOATPP_SQLITE_AMALGAMATION=ON' used by oatpp-postgresql module only ##
############################################################################
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
make install -j 1
cd ../../

}

##########################################################

install_module $BUILD_TYPE oatpp
install_module $BUILD_TYPE oatpp-swagger
install_module_oatpp_postgresql $BUILD_TYPE oatpp-postgresql


cd ../
