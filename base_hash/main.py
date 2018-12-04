import os
import random
from flask import Flask, request
from base_hash import socks
from base_hash.clientPart import Upload, Download

app = Flask(__name__)


@app.route('/')
def hello_world():
    s = request.data
    st = s.decode()
    st = str(st).split(' ')
    if st[0] == 'Upload':
        return UploadS(st[1])
    if st[0] == 'Download':
        return DownloadS(st[1])
    if st[0] == 'Delete':
        return DeleteS(st[1])
    return '0'



def UploadS(path):
    r = random.randrange(2000, 45000)
    pid = os.fork()
    if pid > 0:
        scks(r)
    elif pid == 0:
        return Upload(path, r)
    else:
        print('Error')
    return '0'


def DownloadS(hash):
    r = random.randrange(2000, 45000)
    pid = os.fork()
    if pid > 0:
        dscks(r, hash)
    elif pid == 0:
        return Download(hash, r)
    else:
        print('Error')
    return '0'


def DeleteS(hash):
    socks.delSock(hash)
    return '0'


def scks(r):
    socks.newSock(r)

def dscks(r, hash):
    socks.dwnSock(r, hash)

