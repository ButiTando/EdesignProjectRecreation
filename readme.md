# Solar efficiency checker


# Attiny85
## design choice 
The esp32c3-dev-kit has 18 general input output (GPIO) pin, which limits the number of devices we can connect to the device. To add more functionality to the project an attiny micro-controller is added to vitually increase the number of GPIO pin available. The attiny will communicate with the main micro-controller, in this case the esp32 board, via I2c or SPI dependending on how many more attiny boards will be used.