#!/usr/bin/env python3
from SMWinservice import SMWinservice


class SahitoService(SMWinservice):
    _svc_name_ = 'sahito'
    _svc_display_name_ = 'Sahito Service'
    _svc_description_ = 'Sahito Operation Handler'

    def start(self):
        self.is_running = True

    def stop(self):
        self.is_running = False

    def main(self):
        pass


if __name__ == '__main__':
    SahitoService.parse_command_line()
