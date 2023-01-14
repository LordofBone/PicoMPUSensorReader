### Hardware
This can be done on Windows, but it is advisable to use a Raspberry Pi with RPi OS on.

### Setting up Pico SDK
Follow the instructions for setting up pre-requisites and the Pico SDK [here](https://circuitdigest.com/microcontroller-projects/how-to-program-raspberry-pi-pico-using-c)

### Compiling and flashing
To compile the code, navigate into the build folder and run the following commands:

```cmake ..```

```make```

(can optionally add -j4 to the end of the second command to speed up compilation - changing the number to the number of cores you have)

There should now be a SensorReader.uf2 file in the build folder.

Plug in a Raspberry Pi Pico to your computer while holding the boot button, then let go, the Pico should mount a folder
simply copy the SensorReader.uf2 file to the Pico folder and wait for it to reboot.

Once running you can install and use screen to check it is working and reporting the sensor data.

```sudo apt install screen```

```screen /dev/ttyACM0```