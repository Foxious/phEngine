import random as r

class Room():
    def __init__(self,name=None):
        self.doors = self.numRooms()
        self.usedDoors = 0
        self.neighbors = []
        if name != None:
            self.name = name
    def numRooms(self,num = 2 , maxConnections=3):
        if num > maxConnections:
            num = maxConnections
        number =  r.randint(num,maxConnections)
        return number
    
def generateDungeon(numberOfRooms = 5):
    roomsToGenerate = numberOfRooms
    rooms = []
    while roomsToGenerate > 0:
        rooms.append(Room(name=str(numberOfRooms - roomsToGenerate)))
        roomsToGenerate -= 1
    for room in rooms:   
        if len(room.neighbors) < room.doors:
            _room = pickUnusedRoom(room,rooms)
            room.neighbors.append(_room)
            if _room != None:
                if room not in _room.neighbors and room.doors > len(room.neighbors):
                    _room.neighbors.append(room)
        #print len(room.neighbors)
    return rooms
def pickUnusedRoom(_Room = None,rooms = None):
    #expects an instance of the Room object and a list of rooms
    #otherwise it fails
    #randomly selects form the list of rooms not in use
    if _Room != None and rooms != None:
        avalableRooms = []
        for _room in rooms:
            if _room not in _Room.neighbors:
                if _room is not _Room:
                    if len(_room.neighbors) < _room.doors:
                       avalableRooms.append(_room)
        if len(avalableRooms) > 0:
            returnRoom = avalableRooms[r.randint(0,len(avalableRooms)-1)]
            return returnRoom
        else:
            newRoom = Room(name = 'deadend')
            print newRoom
            return newRoom
    else:
        return none
def testWalker(dungeon):
  for room in dungeon:
      neighbors = []
      for connection in room.neighbors:
          if room != None and connection != None:
              neighbors.append(connection.name)
      print room.name,room.doors,neighbors
if __name__ =='__main__':
    testWalker(generateDungeon(10))
    '''
    generate pool of rooms
    create room connections
    remove unused doors
    pick a room with one door as an entrace
    random room some distance away as an exist
    '''
