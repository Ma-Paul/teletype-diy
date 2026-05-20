# teletype-diy

A DIY teletype-style terminal built from a PS/2 keyboard and an Epson dot-matrix printer.

The goal of this project is to turn old input/output hardware into a usable serial terminal for a modern Linux computer. With the finished setup, you can log into a Linux machine over a serial connection and use it like a classic teletype: type on the PS/2 keyboard, and receive terminal output on the printer.

The repository is split into several development stages, including printer control, PS/2 keyboard handling, chat/testing, and the final TTY setup.

## Project Structure
```
01_Printer   Printer experiments and output handling
02_PS2       PS/2 keyboard input handling
03-Chat      Serial/chat-style experiments
04-TTY       Final teletype/TTY implementation
```
## Starting a Linux TTY

To start a TTY on a Linux computer connected through /dev/ttyUSB0, use:
```
sudo agetty -L -8 --noclear --delay 2 19200 ttyUSB0 vt100
```
## Arduino Libraries

Search for Arduino libraries:
```
arduino-cli lib search Package
```
Command to install library
```
arduino-cli lib install Package
```
Replace Package with the name of the library you want to install.

## Hardware Idea

This project combines:

* a PS/2 keyboard for input
* an Epson dot-matrix printer for output
* an Arduino or compatible microcontroller
* a serial connection to a Linux computer

The result behaves like a simple physical terminal.
