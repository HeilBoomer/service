#!/usr/bin/env python3
from SMWinservice import SMWinservice
import socket
port = 42069
ip = "127.0.0.1"

class SahitoService(SMWinservice):
    _svc_name_ = 'sahito'
    _svc_display_name_ = 'Sahito Service'
    _svc_description_ = 'Sahito Operation Handler'

    def start(self):
        self.is_running = True

    def stop(self):
        self.is_running = False

    def main(self):
        s = socket.socket()

        s.bind((ip,port))
        s.listen(1)
        while self.is_running:
            c,addr = s.accept()
            data = c.recv(1024).decode()
            if not data:
                continue
            print(" \x1b[1;32m=> \x1b[1;37mReceived message: \x1b[;m", str(data))

if __name__ == '__main__':
    SahitoService.parse_command_line()
