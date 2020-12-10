<p align="center">
  <h1 align="center">Sahito Service</h1>
  <h4 align="center">A Service to Handle the Operations of Sahito Project.</h4>
</p>

## Installation

### GNU/Linux

Only available as source for now.

#### Building From Source
Make sure you have `gcc` installed.

```bash
$ git clone https://github.com/sahito-org/service.git
$ cd service
$ make build
$ sudo make install
```

You can then uninstall with following command in the same directory.

```bash
$ sudo make uninstall
```
### Windows

#### Building From Source

You can install the service directly with startup auto if you want:

```cmd
> git clone https://github.com/sahito-org/service.git
> cd service
> python src/win32/py/main.py install --startup auto
```

## Usage

### GNU/Linux

You can start the service by using the following command.

```bash
$ systemctl start sahito
```

You can set script to run at startup using the following command.

```bash
$ systemctl enable sahito
```

### Windows

Windows service will start automatically if you installed it using the code above.
