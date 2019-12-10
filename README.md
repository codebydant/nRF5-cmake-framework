# nRF5 CMake Framework
This is a CMake project to program a **nRF52832 board** using CMake 3.16.0, JLink, NRFJProgrammer and NRF5 SDK 16.0. The CMake files are taken from: https://github.com/Polidea/cmake-nRF5x and https://github.com/JF002/nrf52-baseproject for reference.

## How to compile
1. Download:
	
	* gcc arm none eabi toolchain x86-64-linux: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
	* SDK for the nRF52 16.0: https://www.nordicsemi.com/Software-and-tools/Software/nRF5-SDK/Download#infotabs
	* Programmer NRFJPROG: https://www.nordicsemi.com/Software-and-tools/Development-Tools/nRF-Command-Line-Tools/Download#infotabs

2. Create a folder in /opt to unzip files, e.g. */opt/SEGGER/*
3. Change lines **19**,**20**,**21** and **22** in the *CMakeLists.txt* file at the root project with the path for each one (toolchain,SDK and Programmer) and save it.
	e.g. 

		set(NRF_TARGET 	"nrf52")							  # nrf51 or nrf52
		set(ARM_NONE_EABI_TOOLCHAIN_PATH "/opt/SEGGER/gcc-arm-none-eabi-9-2019-q4-major") # Path to root folder 
		set(NRF5_SDK_PATH "/opt/SEGGER/nRF5SDK"	)					  # Path to root folder
		set(NRFJPROG "/opt/SEGGER/Toolchain/nrfjprog/nrfjprog")				  # Path to .bin file

4. Create a *build* folder and,
	
		$ cd build/	
		$ cmake ../	

	If everything is good, you should see something like this, e.g.

		-- The C compiler identification is GNU 5.4.0
		-- The CXX compiler identification is GNU 5.4.0
		-- The ASM compiler identification is GNU
		-- Found assembler: /usr/bin/cc
		-- Check for working C compiler: /usr/bin/cc
		-- Check for working C compiler: /usr/bin/cc -- works
		-- Detecting C compiler ABI info
		-- Detecting C compiler ABI info - done
		-- Detecting C compile features
		-- Detecting C compile features - done
		-- Check for working CXX compiler: /usr/bin/c++
		-- Check for working CXX compiler: /usr/bin/c++ -- works
		-- Detecting CXX compiler ABI info
		-- Detecting CXX compiler ABI info - done
		-- Detecting CXX compile features
		-- Detecting CXX compile features - done
		-- Configuring done
		-- Generating done
		-- Build files have been written to: /home/xXx/Downloads/nRF5-cmake-framework-master/build

5. Compile with make:
	
		$ make

	e.g.

		[ 91%] Linking C executable application-example.out
		post build steps for application-example
		   text	   data	    bss	    dec	    hex	filename
		   8800	    172	    884	   9856	   2680	application-example.out
		[ 91%] Built target application-example
		Scanning dependencies of target FLASH_application-example
		[ 93%] flashing application-example.hex
		Parsing hex file.
		Erasing page at address 0x0.
		Erasing page at address 0x1000.
		Erasing page at address 0x2000.
		Applying system reset.
		Checking that the area to write is not protected.
		Programming device.
		Applying system reset.
		Run.
		[ 93%] Built target FLASH_application-example
		Scanning dependencies of target FLASH_SOFTDEVICE
		[ 95%] flashing SoftDevice
		Parsing hex file.
		Erasing page at address 0x0.
		Erasing page at address 0x1000.
		.
		.
		.
		Erasing page at address 0x24000.
		Erasing page at address 0x25000.
		Applying system reset.
		Checking that the area to write is not protected.
		Programming device.
		Applying system reset.
		Run.
		[ 95%] Built target FLASH_SOFTDEVICE
		Scanning dependencies of target FLASH_ERASE
		[ 97%] erasing flashing
		Erasing user available code and UICR flash areas.
		Applying system reset.
		[ 97%] Built target FLASH_ERASE
		Scanning dependencies of target START_JLINK
		[100%] started JLink commands
		[100%] Built target START_JLINK

## How to run monitor
At the root folder run,

		$ ./monitor
		
This assume that the JLink binaries are on */opt/SEGGER/JLink/* if not, you should modify the *runJLinkEXE-nrf52* on the *RTT* folder.

## How to use as your own project
Just modify the *main.c* file with your own code. In case you need specify more SDK libraries you have to modify the *nrF5x.cmake* file on the *cmake* folder.

