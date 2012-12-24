import random as r

class Room():
    def __init__(self):
        self.doors = self.numRooms(1,4)
        self.usedDoors = 0
        self.neighbors = []
    def numRooms(self,num = 2 , maxConnections=4):
        if num > maxConnections:
            num = maxConnections
        number =  r.randint(num,maxConnections)
        return number
def generateDungeon(numberOfRooms = 5):
    roomsToGenerate = numberOfRooms
    rooms = []
    while roomsToGenerate > 0:
        rooms.append(Room())
        roomsToGenerate -= 1
    for room in rooms:   
        for index in range(room.doors):
            if room.usedDoors <= room.doors:
                _room = pickUnusedRoom(room,rooms)
                room.neighbors.append(_room)
                room.usedDoors += 1
        print len(room.neighbors)
def pickUnusedRoom(room = None,rooms = None):
    #expects a room object and a list of rooms
    #otherwise it fails
    if room != None and rooms != None:
        avalableRooms = []
        for _room in rooms:
            if _room not in room.neighbors:
                avalableRooms.append(_room)
        return avalableRooms[r.randint(0,len(avalableRooms)-1)]
    else:
        return none
if __name__ =='__main__':
    test = generateDungeon(5)
    print test
    '''
    generate pool of rooms
    create room connections
    remove unused doors
    pick a room with one door as an entrace
    random room some distance away as an exist
    '''
