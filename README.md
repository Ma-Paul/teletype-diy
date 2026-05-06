Command to prepare device:
`sudo stty -F /dev/ttyUSB0 19200 raw -echo -ixon -ixoff -crtscts -hupcl`

Command to start tty:
`sudo agetty -L -8 --noclear --autologin jj --delay 2 19200 ttyUSB0 vt100`

