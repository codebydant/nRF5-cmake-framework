# nRF5 CMake Framework
This is a CMake project to program a nRF52832 board using CMake, JLink programmer, and NRF5 SDK. The CMake files are taken from: https://github.com/Polidea/cmake-nRF5x and https://github.com/JF002/nrf52-baseproject for reference.

## How to compile
1. Download:
	
	* toolchain gcc arm x86-64-linux: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
	* SDK for nRF5: https://www.nordicsemi.com/Software-and-tools/Software/nRF5-SDK/Download#infotabs
	* Programmer: https://www.nordicsemi.com/Software-and-tools/Development-Tools/nRF-Command-Line-Tools/Download#infotabs

2. Create a folder in /opt to unzip files, e.g. */opt/nrf52*
3. Change lines 5,6 and 7 in the CMakeLists.txt at the root project with the path for each (toolchain,SDK and Programmer)
	e.g. 

		set(ARM_NONE_EABI_TOOLCHAIN_PATH "/opt/nrf52/gcc-arm-none-eabi-9-2019-q4-major")
		set(NRF5_SDK_PATH "/opt/nrf52/nRF5SDK160098a08e2")
		set(NRFJPROG "/opt/nrf52/nRF-Command-Line-Tools_10_5_0_Linux-amd64/nrfjprog/nrfjprog")
4. Save it.
5. Create a build folder
6. Create compilation files with CMake:
	
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
		-- Build files have been written to: /home/imar-itt/Desktop/ses_test/build

7. Compile with make:
	
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



