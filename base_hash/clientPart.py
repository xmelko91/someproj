# -*- coding: utf-8 -*-
import os
import socket


def Upload(path, port):
    host = '127.0.0.1'

    sock = socket.socket()
    sock.connect((host, port))
    data = 0
    with open(path, 'rb') as f:
        while True:
            l = f.read(1024)
            if len(l) < 1:
                break
            sock.send(l)

            data = sock.recv(1024)

    sock.close()

    #back hash of file
    return (data)

def Download(hash, port):
    host = '127.0.0.1'

    sock = socket.socket()
    sock.connect((host, port))
    if not os.path.exists('temp'):
        os.makedirs('temp')
    dir = 'temp/'
    namefile = hash
    with open(dir + namefile, 'wb') as f:
        while True:
            data = sock.recv(1024)
            if not data:
                break
            f.write(data)
    sock.close()
    return '0'
