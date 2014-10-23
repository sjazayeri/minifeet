#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vector{
public:
    float x, y;
    Vector (float x = 0, float y = 0):x(x), y(y){}

    float dist(Vector other)
    {
        return sqrt((x - other.x) * (x - other.x) - (y - other.y) * (y - other.y));
    }

    float len()
    {
        return sqrt(x * x + y * y);
    }

    float angle()
    {
        float res;
        if (x == 0)
        {
            res = 3.1415/2;
            if (x < 0)
                res += 3.1415;
        }
        else
        {
            res = atan(1.0*y/x);
        }
        if (x < 0)
            res += 3.1415;
        return res;
    }
    Vector operator-(Vector other)
    {
        return Vector(x-other.x, y-other.y);
    }
    Vector operator+(Vector other)
    {
        return Vector(x+other.x, y+other.y);
    }
    Vector operator*(float num)
    {
        return Vector(x*num, y*num);
    }
};

int team;

vector<Vector> get_players()
{
    vector <Vector> res;
    for (int i = 0; i < 10; i++)
    {
        float a, b;
        cin >> a >> b;
        if (team == 1)
        {
            a *= -1;
            b *= -1;
        }
        res.push_back(Vector(a, b));
    }
    return res;
}

Vector get_position(int number, Vector ballpos)
{
    Vector pos(0, 0);
    if (number == 0)
    {
        pos = Vector(0, -43);
    }
    else if (number == 1)
    {
        pos = Vector(-25, -35);
    }
    else if (number == 2)
    {
        pos = Vector(25, -35);
    }
    else if (number == 3)
    {
        pos = Vector(-10, -10);
    }
    else if (number == 4)
    {
        pos = Vector(10, 0);
    }
    if (ballpos.y > 0)
        pos.y += ballpos.y * 3 / 4;
    if (team == 1)
        pos.y = pos.y - 1;

    return pos;
}

int get_ball_receiver(vector<Vector> players, Vector ballpos)
{
	vector<Vector> positions;
	float min_dist = 10e4;
	int receiver = 0;
	for (int i = 0; i <= 4; i++)
	{
		Vector pos = get_position(i, ballpos);
		if (pos.dist(ballpos) < min_dist)
		{
			min_dist = pos.dist(ballpos);
			receiver = i;
		}
	}
	return receiver;
}

void move(Vector pos)
{
    if (team == 1)
    {
        pos.x *= -1;
        pos.y *= -1;
    }
    cout << "move " << pos.x << " " << pos.y << endl;
    cout.flush();
}

void kick(Vector target, float power)
{
    if (team == 1)
    {
        target.x *= -1;
        target.y *= -1;
    }
    cout << "kick " << target.x << " " << target.y << " " << power << endl;
    cout.flush();
}

void kick_action()
{
    kick(Vector(0, 45), 1);
}

int main()
{
    int number, game_state;
    cin >> team >> number;
    while (true)
    {
        vector <Vector> players = get_players();
        Vector selfpos = players[5*team+number];
        Vector ballpos;
        cin >> ballpos.x >> ballpos.y;
        cin >> game_state;

        int ball_reveiver = get_ball_receiver(players, ballpos);
        if (number == ball_reveiver)
        {
            if (selfpos.dist(ballpos) < 2)
            {
                kick_action();
            }
            else
                move(ballpos);
        }
        else
        {
            Vector position = get_position(number, ballpos);
            move(position);
        }
    }
    return 0;
}
