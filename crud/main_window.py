
# -*- coding: utf-8 -*-
import sys
import webbrowser

from check_connect import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *


#основное окно


q = 0
class mWindow(QWidget):

    def mStats(self, ID,  name):
        grid = QGridLayout()
        grid.setSpacing(10)
        self.ID = ID
        self.name = name + "'s LikeToHaveBase"
        self.index = 0

        self.adress = QLineEdit()
        self.addLink = QPushButton("Add WishLlink.")
        self.removeLink = QPushButton("Delete.")
        self.editLink = QPushButton("Edit.")
        self.addLink.clicked.connect(self.newLink)
        self.removeLink.clicked.connect(self.editDialog)
        self.editLink.clicked.connect(self.editLinkF)

        self.mW = QListWidget()
        self.links = getAllLinks(self.ID)

        if self.links != None:
            for r in self.links:
                self.mW.addItem(r)
        self.mW.doubleClicked.connect(self.openBrowser)
        self.mW.clicked.connect(self.getIndex)


        grid.addWidget(self.removeLink, 2, 10, 1, 1)
        grid.addWidget(self.editLink, 1, 10, 1, 1)
        grid.addWidget(self.addLink, 0, 10, 1, 1)
        grid.addWidget(self.adress, 0, 0, 1, 10)
        grid.addWidget(self.mW, 1, 0, 9, 10)
        self.setGeometry(0, 0, 800, 600)
        self.setWindowTitle(self.name)
        self.setLayout(grid)

    def __init__(self):
        super().__init__()

        self.initUI()
    def initUI(self):
        self.show()

    def closeEvent(self, event):

        reply = QMessageBox.question(self, 'Message',
                                     "Are you sure to quit?", QMessageBox.Yes |
                                     QMessageBox.No, QMessageBox.No)

        if reply == QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()

    def newLink(self):
        if self.adress.text() not in self.links:
            self.mW.addItem(self.adress.text())
            self.links.append(self.adress.text())
            getNewLink(self.ID, self.adress.text())
        self.adress.clear()

    def editDialog(self):
        removeLink(self.ID, self.mW.currentItem().text())
        self.mW.takeItem(self.mW.row(self.mW.currentItem()))

    def openBrowser(self):
        webbrowser.open(self.mW.currentItem().text())

    def getIndex(self):
        self.index = self.mW.currentRow()

    def editLinkF(self):

        self.nw = editWindow()
        link = self.mW.item(self.index).text()
        self.nw.mEditWindow(link, self.ID, self.mW.item(self.index))
        self.nw.show()




    def keyPressEvent(self, e):

        if e.key() == Qt.Key_Escape:

            self.close()

        if e.key() == Qt.Key_Enter:
            self.newLink()

        if e.key() == Qt.Key_Delete:

            self.editDialog()

#
#запрос пароля
class enterWindow(QDialog):

    def __init__(self):
        super().__init__()

        self.initUI()

    #проверка пароля
    def pasw(self):
        name = self.nameEdit.text()
        pas = self.passwEdit.text()
        if namepass(name, pas):

            self.ex = mWindow()
            self.ex.mStats(name, getName(name, pas))
            self.close()
            self.ex.show()
        else:
            self.close()
            self.ex = make_choose()
            self.ex.show()


    def initUI(self):

        grid = QGridLayout()
        grid.setSpacing(10)


        name = QLabel("ID")
        passw = QLabel("password")
        self.enter = QPushButton('Enter')

        self.nameEdit = QLineEdit()
        self.passwEdit = QLineEdit()
        self.enter.clicked.connect(self.pasw)

        grid.addWidget(self.enter,3,0,1,2)

        grid.addWidget(name, 1, 0)
        grid.addWidget(self.nameEdit,1,1)

        grid.addWidget(passw,2, 0)
        grid.addWidget(self.passwEdit,2,1)

        self.setLayout(grid)

        self.setGeometry(0,0,400,300)
        self.setWindowTitle('Enter to base')
        self.show()


    def keyPressEvent(self, e):

        if e.key() == Qt.Key_Escape:

            self.close()

        if e.key() == Qt.Key_Enter:
            self.pasw()

#возврат-регистрация
class make_choose(QDialog):
    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        grid = QGridLayout()
        grid.setSpacing(10)

        self.chooseBack = QPushButton("Try again")
        self.chooseNew = QPushButton("New User")

        self.chooseBack.clicked.connect(self.bWindow)
        self.chooseNew.clicked.connect(self.regWindow)

        grid.addWidget(self.chooseNew,1,0)
        grid.addWidget(self.chooseBack, 1, 1)

        self.setLayout(grid)



    def bWindow(self):
        self.close()
        self.nw = enterWindow()
        self.nw.show()

    def regWindow(self):
        self.close()
        self.nw = register()
        self.nw.show()

#Регистрация
class register(QDialog):

    def __init__(self):
        super().__init__()

        self.initUI()


    def initUI(self):

        grid = QGridLayout()
        grid.setSpacing(10)


        newID = QLabel("Login")
        newName = QLabel("Your Name")
        passw = QLabel("Password")
        self.enter = QPushButton('Enter')

        self.newNameEdit = QLineEdit()
        self.newIDEdit = QLineEdit()
        self.passwEdit = QLineEdit()
        self.enter.clicked.connect(self.check_username)

        grid.addWidget(self.enter,4,0,1,2)

        grid.addWidget(newID, 1, 0)
        grid.addWidget(self.newIDEdit,1,1)

        grid.addWidget(newName,2, 0)
        grid.addWidget(self.newNameEdit, 2, 1)

        grid.addWidget(passw,3, 0)
        grid.addWidget(self.passwEdit,3,1)

        self.setLayout(grid)

        #self.setGeometry(0,0,400,300)
        self.setWindowTitle('Register new user')
        self.show()


    def check_username(self):
        if self.newIDEdit.text() == '' or self.newNameEdit.text() == '' or self.passwEdit.text() == '':
            QMessageBox.question(self, 'Ошибка.', "Не все поля заполнены.", QMessageBox.Ok)
            return
        name = self.newNameEdit.text()
        ID = self.newIDEdit.text()
        passw = self.passwEdit.text()

        if regUserCheck(ID):
            regNewUser(ID, passw, name)
            QMessageBox.question(self, 'Ура!', "Вы успешно зарегистрировались!", QMessageBox.Ok)
            self.close()
            self.nw = enterWindow()
            self.nw.show()
        else:
            QMessageBox.question(self, 'Ошибка.', "Такой пользователь уже существует.", QMessageBox.Ok)

class editWindow(QDialog):

    def mEditWindow(self, link, ID, it):

        grid = QGridLayout()
        grid.setSpacing(10)
        self.link = link
        self.ID = ID
        self.it = it

        name = QLabel("Link:")
        self.enter = QPushButton('Edit.')

        self.nameEdit = QLineEdit(self.link)
        self.enter.clicked.connect(self.edit)

        grid.addWidget(self.enter,3,0,1,2)

        grid.addWidget(name, 1, 0)
        grid.addWidget(self.nameEdit,1,1)

        self.setLayout(grid)

        self.setGeometry(0,0,400,300)
        self.setWindowTitle('Enter to base')

    def __init__(self):
        super().__init__()

        self.initUI()

    def edit(self):
        removeLink(self.ID, self.link)
        getNewLink(self.ID, self.nameEdit.text())
        self.ret(self.it)
        self.close()


    def initUI(self):

        self.show()


    def keyPressEvent(self, e):

        if e.key() == Qt.Key_Escape:

            self.close()

        if e.key() == Qt.Key_Enter:
            self.edit()

    def rett(self):
        return (self.nameEdit.text())

    def ret(self, it):
        it.setText(self.nameEdit.text())

