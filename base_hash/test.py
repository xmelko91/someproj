import requests

path = '/home/serge/PycharmProjects/patt/base_hash/123.jpg'
hh = '7206f89133daa9cdebdbf0ca4efdc480f235a682'

#реквест на загрузку, получает хэш
hh = requests.get(('http://127.0.0.1:5000'), data='Upload '+path)
#реквест на выгрузку
b = requests.get(('http://127.0.0.1:5000'), data='Download '+hh)
#
b = requests.get(('http://127.0.0.1:5000'), data='Delete '+hh)
