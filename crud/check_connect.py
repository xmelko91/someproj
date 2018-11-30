import pymysql
db = pymysql.connect('sql2.freemysqlhosting.net', 'sql2267143', 'bL8%tF2*', db='sql2267143')


def namepass(b, a):
    cr = db.cursor()
    st = "SELECT * FROM idbase WHERE ID = '" +b +"' AND passw = '"+ a +"';"
    cr.execute(st)
    if cr.fetchone() != None:
        cr.close()
        return True
    cr.close()

def getName(b, a):
    cr = db.cursor()
    st = "SELECT name FROM idbase WHERE ID = '" + b + "' AND passw = '" + a + "';"
    cr.execute(st)
    back = cr.fetchone()
    cr.close()
    return (back[0])


def regUserCheck(name):
    cr = db.cursor()
    st = "SELECT * FROM idbase WHERE ID = '"+ name +"';"
    cr.execute(st)
    if cr.fetchone() != None:
        cr.close()
        return False
    cr.close()
    return True

def regNewUser(ID, passw, name):
    cr = db.cursor()
    st = ("INSERT INTO idbase VALUES('" + ID + "'"+",'" + name + "'"+",'" + passw + "');")
    cr.execute(st)
    cr.close()
    db.commit()
    return

def getNewLink(name, link):
    cr = db.cursor()
    st = ("INSERT INTO linkBase VALUES ('"+name+"', '"+link+"');")
    cr.execute(st)
    cr.close()
    db.commit()
    return

def getAllLinks(name):
    cr = db.cursor()
    st = "SELECT link FROM linkBase WHERE id = '" + name + "';"
    cr.execute(st)
    ret = []
    for r in cr:
        ret.append(r[0])
    cr.close()
    return (ret)


def removeLink(name, link):
    cr = db.cursor()
    st = "DELETE FROM linkBase WHERE link = '" + link + "' AND id = '" + name + "';"
    cr.execute(st)
    cr.close()
    db.commit()
    return
