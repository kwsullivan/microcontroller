all: compile upload

compile:
	arduino-cli compile --fqbn esp32:esp32:esp32 --libraries ./lib --build-path ./build sketch

upload:
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 ./sketch

probe:
	sudo modprobe ch341

board:
	arduino-cli board list

mon:
	arduino-cli monitor -p /dev/ttyUSB0 -b esp32:esp32:esp32
