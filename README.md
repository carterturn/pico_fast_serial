Pico Fast Serial
================

The built-in serial over USB library for the Raspberry Pi Pico has a speed limited to ~100kbits/s, significantly below the 12Mbits/s expected for USB 1.1 Full-Speed.
To improve on this speed, this library uses TinyUSB directly to perform optimized serial over USB transfers.

The speed of this library was tested using the `test.py` Python script. The results so far are
- 3.6Mbits/s to a Pi Pico and 2.4Mbits/s from a Pi Pico with a Linux 6.6 host
- 1.0Mbits/s to a Pi Pico and 2.0Mbits/s from a Pi Pico with a Windows 10 host

To use this library, copy `fast_serial.c`, `fast_serial.h`, and `tusb_config.h`. Then add `fast_serial.c` to the `target_sources` for your Pico project.
The `fast_serial_init()` function must be called to setup TinyUSB. `fast_serial_task()` should be called periodically in the main loop of the program.
`fast_serial_read`, `fast_serial_read_until`, and `fast_serial_write` should be used to read data and write data in an optimized manner. `fast_serial_read` requires that the number of bytes to be received is known in advance, but is about 4x faster than `fast_serial_read_until` as it does not have to check for a terminating character.
