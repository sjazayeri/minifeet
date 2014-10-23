from geometry import Vector, epsilon


def get_players(team):
    players = []
    for i in xrange(10):
        x, y = map(float, raw_input().split(' '))
        if team == 1:
            x *= -1
            y *= -1
        players.append(Vector(x, y))
