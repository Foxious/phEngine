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
    seed = math.floor(random.random()*3)
    options = {
       0:'F',
       1:'W',
       2:'P'
    }
    return options[seed]
        

def generateRow(size):
    dungeon = list()
    for each in range(0,size+1):
        dungeon.append(generateCell())
    return dungeon
        
    
for row in makeRoom(8):
    hor = ''
    for cell in row:
        hor += cell + ' '
    print hor