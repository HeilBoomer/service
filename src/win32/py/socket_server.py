import socket

port = 42069
ip = "127.0.0.1"
if __name__ == "__main__":
    s = socket.socket()

    s.bind((ip,port))
    s.listen(1)
    while True:
        c,addr = s.accept()
        data = c.recv(1024).decode()
        if not data:
            continue
        print(data)
