import sys
from PyQt4 import QtGui, QtCore

def DrawLine(qp, start, end, color=QtCore.Qt.black):
    pen = QtGui.QPen(color, 2, QtCore.Qt.SolidLine)
    qp.setPen(pen)
    x, y = start
    w, h = end
    qp.drawLine(x, y, w, h)

# Do I really need this as its own function?
def MakeLine(start, end):
    return (start, end)

class NodeHeader(QtGui.QWidget):
    def __init__(self, size):
        super(NodeHeader, self).__init__()
        w, h = size
        self.setGeometry(0, 0, w, h)

    def paintEvents(self, e):
        x, y = self.position
        w, h = self.size

def DrawRect(qp, position, size, color=QtCore.Qt.white):
    x, y = position
    w, h = size
    brush = QtGui.QBrush(color)
    qp.fillRect(x, y, w, h, brush)
    qp.drawRect(x, y, w, y)

def setGeometry(widget, position, size):
    x, y = position
    w, h = size
    widget.setGeometry(x-1, y-1, w+x+1, y+h+1)

class Param(QtGui.QWidget):
    def __init__(self, size):
        super(Param, self).__init__()
        w, h = size
        print ("passing into setGeometry: " + str(h))
        self.setGeometry(0, 0, w, h)
        print ('internal height after setGeo: ' + str(self.height()))

    def paintEvent(self, e):
        qp = QtGui.QPainter()
        qp.begin(self)
        print ('height: ' + str(self.height()))
        DrawRect(qp, (self.x(), self.y()), (self.width(), self.height()))
        qp.end()

class ConnectPoint(QtGui.QWidget):
    def __init__(self):
        super(ConnectPoint, self).__init__()
        self.position = (0, 0)
        self._size = (5, 5)

    def paintEvent(self, e):
        setGeometry(self, self.position, self._size)
        qp = QtGui.QPainter()
        qp.begin(self)
        DrawRect(qp, self.position, self._size, QtCore.Qt.black)

    
def MakeParam(x, y, w, h):
    param = Param((w, h))
    param.move(x, y)
    return param

class NodeControl(QtGui.QWidget):
    def __init__(self):
        super(NodeControl, self).__init__()
        self.lines = []
        self.initUI()
        self.param = MakeParam(10, 10, 50, 10)
        self.layout = QtGui.QVBoxLayout(self)
        self.layout.addWidget(self.param)
        print('height after layout: ' + str(self.param.height()))
        
    def initUI(self):
        self.setGeometry(300, 300, 280, 270)
        self.setWindowTitle("Drawing Lines")
        self.show()
        
    def paintEvent(self, e):
        qp = QtGui.QPainter()
        qp.begin(self)
        self.drawLines(qp)
        qp.end()
        
    def mousePressEvent(self, event):
        mousePos = (event.x(), event.y())
        self.lines.append(MakeLine(mousePos, mousePos))
        
    def drawLines(self, qp):
        [l.draw(qp) for l in self.lines]
                    
def main():
    app = QtGui.QApplication(sys.argv)
    ex = NodeControl()
    sys.exit( app.exec_() )


if __name__ == '__main__':
    main()
