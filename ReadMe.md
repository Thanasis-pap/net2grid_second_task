# 24-bit Integer Conversion in POSIX C

This project provides an interface to convert between standard native integer types (1, 2, 4, 8 bytes) and 24-bit integers.

## Features

- Supports signed and unsigned conversions.
- Uses 2’s complement for signed 24-bit numbers.
- Generic function for arbitrary X-byte to Y-byte conversion.

## Build Instructions

```sh
mkdir build && cd build
cmake ..
make
```
