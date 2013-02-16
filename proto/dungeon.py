import random
import math
class cell():
    def __init__(self):
        self.content = ' '
    def genValue(self):
        wall = random.randint(0,3)
        if wall == 0:
            self.content = '#'
        elif wall == 1:
            self.content = ' '
    def setValue(self,value):
        self.content = value
    def getContents(self):
        return self
class room():
    def __init__(self,height,width):
        self.height = height
        self.width = width
        self.contents = [[]]
        self.generate()
    def display(self):
        for row in self.contents:
            out = ''
            for cell in row:
                out +=  cell.content
            print out,'\n'
    def generate(self):
        for i,val in enumerate(range(int(self.height)+1)):
            self.contents.append(list())
            for j , value in enumerate(range(int(self.width)+1)):
                c = cell()
                if i == self.height or j == self.width or i == 0 or j == 0:
                    c.setValue('#')
                else:
                    c.genValue()
                #print i,j
                self.contents[i].append(c)

if __name__ == '__main__':
    r = room(8,3e0)
    r.display()
