#!/bin/python3

import serial
import string
import random
import time

s = serial.Serial('/dev/ttyACM0', 1000000, timeout=1)

length = 240000
rand_str = ''.join(random.choice(string.ascii_uppercase)
                   for i in range(length))

write_start_t = time.time()
s.write(rand_str.encode() + b'\0')
write_end_t = time.time()

print('Write time is {:.3f}ms'.format(1e3 * (write_end_t - write_start_t)))
print('Write speed is {:.3f}kB/s'.format(length / (1e3 * (write_end_t - write_start_t))))

read_start_t = time.time()
resp = ''
while len(resp) < length:
    resp += s.read(length - len(resp)).decode()
read_end_t = time.time()

print('Read time is {:.3f}ms'.format((1e3 * (read_end_t - read_start_t))))
print('Read speed is {:.3f}kB/s'.format(length / (1e3 * (read_end_t - read_start_t))))

s.close()

# Check response is correct
if resp.upper() == rand_str:
    print('Response matches')
else:
    print('Response matches not')
