### About


### To compile your coin on Ubuntu 16.04

```
1. sudo apt-get -y install build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev librocksdb-dev libgflags-dev libsnappy-dev zlib1g-dev libbz2-dev liblz4-dev libzstd-dev
2. rm -rf build; mkdir -p build/release; cd build/release
3. cmake -D STATIC=ON -D ARCH="default" -D CMAKE_BUILD_TYPE=Release ../..
4. PORTABLE=1 make
```
### To compile your coin on Windows 10

```
1. You need to have the following dependencies installed:
	1. Windows 10
	2. Boost 1.59
	3. Visual Studio 2017
2. mkdir build
3. cd build
4. cmake.exe -DBOOST_ROOT=C:\boost_1_59_0 -DBOOST_LIBRARYDIR=C:\boost_1_59_0\libs -G "Visual Studio 15 Win64" ..
5. Open Bytecoin.snl in Visual Studio 2017 and change target to "Release" "x64"
6. From the Solution explorer, build "external" and then build "ALL_BUILD"
7. You will find your compiled files at build/src/Release (npcoind.exe, miner.exe, npcoinwallet.exe and walletd.exe)
```
### Dependencies
* GCC 4.7.3 or later     (http://gcc.gnu.org/)
* CMake 2.8.6 or later   (http://www.cmake.org/)
* Boost 1.55 or later    (http://www.boost.org/)
* MSVC 2013 (Windows only)

### Usage
1. Download or compile the binaries
2. Start the daemon:
```
./npcoind --config-file PATH_TO_YOUR_CONFIG
```
This code is generated by Cryptonote generator - https://github.com/forknote/cryptonote-generator
Seed source - https://github.com/amjuarez/bytecoin
