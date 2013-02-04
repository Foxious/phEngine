'''
Created on Jan 27, 2013

@author: Foxious
'''

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

class NodeConnector(QtGui.QWidget):
    def __init__(self, parent=None):
        super(NodeConnector, self).__init__(parent)
        self.resize(7, 7)

    def paintEvent(self, e):
        qp = QtGui.QPainter()
        qp.begin(self)
        brush = QtGui.QBrush(QtCore.Qt.black)
        qp.fillRect(0, 0, self.width(), self.height(), brush)
        qp.end()

class Node(QtGui.QWidget):
    def __init__(self, parent = None):
        super(Node, self).__init__(parent)
        self._clickPos = None
        title = Param( color = QtGui.QColor(255, 0, 0) )
        title.text = 'Node Title'
        title.mousePressOverride = self.mousePressOverride
        title.mouseMoveOverride = self.mouseMoveOverride
        self.titleHeight = 18
        title.resize(1, self.titleHeight)
        self.resize(self.width(), 1)
        self.addParam(title)
        
        self.inConnection = NodeConnector(self)
        self.inConnection.move(0, 4)
        
    def setWidth(self, width):
        self.resize(width, self.height())
        children = self.findChildren(Param)
        [c.resize(width-16, c.height()) for c in children]
                
    def paintEvent(self, event):
        qp = QtGui.QPainter()
        qp.begin(self)
        pen = QtGui.QPen(QtGui.QColor.black)
        qp.setPen(pen)
        qp.drawRect(6, 0, self.width()-15, self.height()-1)
        qp.drawRect(6, 0, self.width()-15, self.titleHeight-1)
        qp.end()

    def mousePressOverride(self, event):
        self._clickPos = event.globalPos()
        
    def mouseMoveOverride(self, event):
        currPos = self.mapToGlobal(self.pos())
        globalPos = event.globalPos()
        diff = globalPos - self._clickPos
        newPos = self.mapFromGlobal(currPos + diff)
        self.move(newPos)
        self._clickPos = globalPos
            
    def addParam(self, param):
        param.resize(self.width()-16, param.height())
        param.setParent(self)
        param.move(7, self.height())
        self.resize(self.width(), self.height() + param.height()+1)

class Param(QtGui.QWidget):
    def __init__(self, parent = None, color = QtCore.Qt.white):
        QtGui.QWidget.__init__(self, parent)
        self.fillColor = color
        self.text = 'Param Text'
        self.mousePressOverride = None
        self.mouseMoveOverride = None

    def paintEvent(self, e):
        qp = QtGui.QPainter()
        qp.begin(self)
        brush = QtGui.QBrush(self.fillColor)
        qp.fillRect(0, 0, self.width(), self.height(), brush)
        qp.setPen(QtCore.Qt.black)
        qp.setFont(QtGui.QFont('Decorative', 8))
        qp.drawText(e.rect(), QtCore.Qt.AlignCenter, self.text)
        qp.end()

    def mousePressEvent(self, event):
        if(self.mousePressOverride):
            self.mousePressOverride(event)

    def mouseMoveEvent(self, event):
        if(self.mouseMoveOverride):
            self.mouseMoveOverride(event)

class NodeControl(QtGui.QWidget):
    def __init__(self):
        super(NodeControl, self).__init__()
        self.lines = []
        self.node = Node(self)
        self.node.move(10, 10)
        self.node.setWidth(100)
        p = Param()
        p.resize(12, 15)
        self.node.addParam(p) 
        
    def paintEvent(self, e):
        qp = QtGui.QPainter()
        qp.begin(self)
        self.drawLines(qp)
        qp.end()
        
    def mousePressEvent(self, event):
        mousePos = (event.x(), event.y())
        self.lines.append(MakeLine(mousePos, mousePos))
        
    def drawLines(self, qp):
        [DrawLine(qp, l[0], l[1]) for l in self.lines]
        
    def run(self):
        self.setGeometry(300, 300, 280, 270)
        self.setWindowTitle("Drawing Lines")
        self.show()
                    
def main():
    app = QtGui.QApplication(sys.argv)
    ex = NodeControl()
    ex.run()
    return app.exec_()
    #sys.exit( app.exec_() )


if __name__ == '__main__':
    main()
