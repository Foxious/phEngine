# -*- coding: utf-8 -*-
"""
Spyder Editor

This temporary script file is located here:
C:\Users\Drachis\.spyder2\.temp.py
"""
import random
import math
class point():
    def __init__(self,position = (0,0)):
        self.position = position

class room():
    def __init__(self):
        #generate a room that will conect to a number of other rooms based on the number of exits it has
        self.exits = self.numberOfExits()
        self.neighbors = []
    def numberOfExits(self,maximum=4):
        #sugessted maximum of 8
        self.exits = random.randint(1,maximum)
        
        
class dungeon():
    def __init__(self):
        self.roomNum= self.numberOfRooms()
        self.rooms = []
        self.fillDungeon()
        
    def numberOfRooms(self,max=13):
        return random.randint(5,max)
    def fillDungeon(self):
        i = 0 
        while  i < self.roomNum:
            i += 1
            cell = room()
            if cell.exits >= 2:
                neighbors = 0
                while neighbors < cell.exits:
                    neighbors += 1
                    i += 1
                    cell.neighbors.append(room())
            self.rooms.append(cell)
    def placeRoom(self, cell):
        while self.roomNum < len(self.rooms) and len(cell.neighbors) < cell.exits:
            pass
        cell = room()
        if cell.exits >= 2:
            neighbors = 0
            while neighbors < cell.exits:
                neighbors += 1
                i += 1
                cell.neighbors.append(room())
        self.rooms.append(cell)        
            

def makeRoom(size):
    room = list()
    iterator = 0
    while iterator <= size:
        room.append(generateRow(size))
        iterator +=1
    return room

def generateCell():
    value = [
       'F',
       'W',
       'P',
    ][int(random.random()*3)]
    return value

def generateRow(size):
    dungeon = list()
    for each in range(0,size+1):
        dungeon.append(generateCell())
    return dungeon

def selectRoom(roomlist):
    placed = []
    while len(placed) <= len(roomlist):
        room = selectRoom(roomList)
        if room not in placed:
            placed.append(room)
    return placed


def selectRoom(rooms):
    return rooms[int(random.random()*len(rooms))]

class floor():
    def __init__(self,size = (3,3)):
        
        for i, value in size:
            #size should only be holding a set of integers each greater than 3
            if 3 > value :
                size[i] = 3
        self.size = size
        #initial spawn is in the center of the floor
        self.entrance = point(
            position=(
                random.randint(0, size[0]-1),
                random.randint(0, size[1]-1)
            )
        )