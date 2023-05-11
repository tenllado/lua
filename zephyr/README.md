# Lua Zephyr Module

This project is fork of the lua github mirror, that incorporate the files
required by Zephyr to incorporate lua as a scripting library.

## Status

The Module is still unofficial. Some issues with the libc and posix layers in
Zephyr have to be solved to integrate this as an official lua module.

Currently it has been updated to support the Zephyr-v3.3.0 version by using
PICOLIBC instead of NEWLIB_LIBC, as this introduces less symbol-missing link
errors. At the moment it still requires the user to provide an implementation of
the ``times()`` function, required by the ``clock()`` implementation of the
picolib library.

## Future plans

- Integrate the module in zephyr as an official module for lua library
- Optionally add a lua interpreter for the SHELL module or indpendent of it.
- Add te possibility to compile lua sources and add them to the binary or leave
  them for download to the on-chip file system.
