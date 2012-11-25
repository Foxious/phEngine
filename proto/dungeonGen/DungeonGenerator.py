# -*- coding: utf-8 -*-
"""
Spyder Editor

This temporary script file is located here:
C:\Users\Drachis\.spyder2\.temp.py
"""
import random
import math

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
        room = select(roomlist)
        if room not in placed:
            placed.append(room)
    return placed


def select(rooms):
    return rooms[int(random.random()*len(rooms))]

if __name__ == '__main__':
    rooms = [
    'a',
    'b',
    'c',
    'd',
    'e',
    ]
    print selectRoom(rooms)
    '''
    for row in makeRoom(8):
        hor = ''
        for cell in row:
            hor += cell + ' '
        print hor
    '''
