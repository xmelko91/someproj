import os
import socket
import hashlib


def newSock(port):
    sock = socket.socket()
    sock.bind(("", port))
    sock.listen(2)
    conn, addr = sock.accept()
    crDir = False
    if not os.path.exists('temp'):
        os.makedirs('temp')
        crDir = True
    dir = 'temp'
    namefile = 'temp'
    sha1 = hashlib.sha1()

    f = open(dir + '/' + namefile, 'wb')

#цикл обработки
    while True:
        data = conn.recv(1024)
        if not data:
            break
        f.write(data)
        sha1.update(data)
    #возврат
        send = sha1.hexdigest()
        conn.send(bytes(send, 'utf-8'))

    newname = sha1.hexdigest()

    if not os.path.exists('store'):
        os.makedirs('store')
    if not os.path.exists('store/'+newname[:2]):
        os.makedirs('store/'+newname[:2])

    old = os.path.join(dir, namefile)
    new = os.path.join('store/'+newname[:2], newname)
    os.rename(old, new)
    if crDir:
        os.removedirs(dir)
    print(sha1.hexdigest())
    conn.close()

def dwnSock(port, hash):
    sock = socket.socket()
    sock.bind(("", port))
    sock.listen(2)
    conn, addr = sock.accept()
    dir = hash[:2]
    with open('store/' + dir + '/' + hash, 'rb') as f:
        while True:
            l = f.read(1024)
            if len(l) < 1:
                break
            conn.send(l)

    sock.close()

def delSock(hash):

    dir = hash[:2]
    os.remove('store/' + dir + '/' + hash)