"""
  Compute nearest pair of points using two algorithms
 
  First algorithm is 'brute force' comparison of every possible pair.
  Second, 'divide and conquer', is based on:
    www.cs.iupui.edu/~xkzou/teaching/CS580/Divide-and-conquer-closestPair.ppt 
  Adapted by Jaime Cohen
"""
 
from random import randint 
from random import randrange
from operator import itemgetter, attrgetter

infinity = float('inf')
instances = []

class Point:
    def __init__(self, xCoord, yCoord):
        self.xCoord = xCoord
        self.yCoord = yCoord
    def __repr__(self):
        return repr((self.xCoord,self.yCoord))
    # because we will only compare distances
    # there is no need to compute the square below
    def distance(self, p):
        return ((self.xCoord - p.xCoord)**2 + (self.yCoord - p.yCoord)**2)

def bruteForceClosestPair(point):
    numPoints = len(point)
    if numPoints < 2:
        return infinity, (None, None)
    return min( ((point[i].distance(point[j]), (point[i], point[j]))
                 for i in range(numPoints-1)
                 for j in range(i+1,numPoints)),
                key=itemgetter(0))
 
def closestPair(point):
    xP = sorted(point, key= attrgetter('xCoord'))
    yP = sorted(point, key= attrgetter('yCoord'))
    return _closestPair(xP, yP)
 
def _closestPair(xP, yP):
    numPoints = len(xP)
    if numPoints <= 3:
        return bruteForceClosestPair(xP)
    Pl = xP[:numPoints//2]
    Pr = xP[numPoints//2:]
    Yl, Yr = [], []
    xDivider = Pl[-1].xCoord
    for p in yP:
        if p.xCoord <= xDivider:
            Yl.append(p)
        else:
            Yr.append(p)
    dl, pairl = _closestPair(Pl, Yl)
    dr, pairr = _closestPair(Pr, Yr)
    dm, pairm = (dl, pairl) if dl < dr else (dr, pairr)
    # Points within dm of xDivider sorted by Y coord
    closeY = [p for p in yP if abs(p.xCoord - xDivider) < dm]
    numCloseY = len(closeY)
    if numCloseY > 1:
        # There is a proof that you only need compare a max of 7 next points
        closestY = min( ((closeY[i].distance(closeY[j]), (closeY[i], closeY[j]))
                         for i in range(numCloseY-1)
                         for j in range(i+1,min(i+8, numCloseY))),
                        key=itemgetter(0))
        return (dm, pairm) if dm <= closestY[0] else closestY
    else:
        return dm, pairm

def times():
    ''' Time the different functions
    '''
    import timeit
 
    functions = [bruteForceClosestPair, closestPair]
    for f in functions:
        print('   Time for', f.__name__, timeit.Timer('%s(pointList)' % f.__name__,
                                                   'from closestpair import %s, pointList' % f.__name__).timeit(number=1))

pointList = [ Point(randint(0,1000),randint(0,1000)) for i in range(2000)]
        
if __name__ == '__main__':
    print('Exemplo:\n')
    points = [(7, 2), (9, 2), (3, 2), (5, 8), (5, 10), (5, 5), (7, 10), (10, 10), (6, 8), (8, 8)]
    print('  ', points)
    pointList = [Point(p[0],p[1]) for p in points]
    print('   bruteForceClosestPair:', bruteForceClosestPair(pointList))
    print('   closestPair          :', closestPair(pointList))

    # measure execution times
    print('\nTempos para 2000 pontos: \n')
    for i in range(3):
        times()

# Código desenvolvido pelo professor
