from geometry import Vector


def get_players(team):
    players = []
    for i in xrange(10):
        x, y = map(float, raw_input().split(' '))
        if team == 0:
            x *= -1
            y *= -1
        players.append(Vector(x, y))
    return players


def get_ballpos(team):
        ballpos = Vector(*map(float, raw_input().split(' ')))
        if team == 0:
            ballpos.x *= -1
            ballpos.y *= -1
