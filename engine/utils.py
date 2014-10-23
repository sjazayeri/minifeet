from geometry import Vector, epsilon


def get_players():
    players = []
    for i in xrange(10):
        x, y = map(float, raw_input().split(' '))
        players.append(Vector(x, y))
