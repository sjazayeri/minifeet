#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int team, number;

class Vector{
public:
    float x, y;
    Vector (float x = 0, float y = 0):x(x), y(y){}

    float dist(Vector other)
    {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
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

vector<Vector> gplayers;
Vector last_cycle_dest(0, 0);

vector<Vector> get_players()
{
    vector <Vector> res;
    for (int i = 0; i < 10; i++)
    {
        float a, b;
        cin >> a >> b;
        if (team == 0)
        {
            a *= -1;
            b *= -1;
        }
        res.push_back(Vector(a, b));
    }
    return res;
}

Vector get_ballpos()
{
	Vector ballpos;
	cin >> ballpos.x >> ballpos.y;
	if (team == 0)
	{
		ballpos.x *= -1;
		ballpos.y *= -1;
	}
	return ballpos;
}

Vector get_target_position(int number, Vector ballpos)
{
    Vector pos(0, 0);
    if (number == 0)
    {
        pos = Vector(0, -40);
    }
    else if (number == 1)
    {
        pos = Vector(-20, -33);
    }
    else if (number == 2)
    {
        pos = Vector(20, -33);
    }
    else if (number == 3)
    {
        pos = Vector(-10, -10);
    }
    else if (number == 4)
    {
        pos = Vector(10, 0);
    }
//    if (ballpos.y > 0)
//        pos.y += ballpos.y * 3 / 4;

    return pos;
}

int get_ball_receiver(vector<Vector> players, Vector ballpos)
{
	vector<Vector> positions;
	float min_dist = 10e4;
	int receiver = 0;
	for (int i = 0; i <= 4; i++)
	{
		Vector pos = get_target_position(i, ballpos);
		if (pos.dist(ballpos) < min_dist)
		{
			min_dist = pos.dist(ballpos);
			receiver = i;
		}
	}
	return receiver;
}


float get_closest_op_dist(){
    //int other = 1-team;
    //cerr<<'heh'<<endl;
    float cmindist = 10e4;
    for(int i = 0; i <10; i++){
        cmindist = min(cmindist, (gplayers[team*5+number]-gplayers[i]).len());
    }
    return cmindist;
}

void move(Vector pos)
{
    if (team == 0)
    {
        pos.x *= -1;
        pos.y *= -1;
    }
    if((pos-last_cycle_dest).len() < 0.3 && get_closest_op_dist() < 3){
        pos = pos+Vector((rand()%2)*(-rand()%2), (rand()%2)*(-rand()%2));
        cerr<<"stuck"<<" "<<team<<" "<<number<<endl;    
    }
    last_cycle_dest = pos;
    cout << "move " << pos.x << " " << pos.y << endl;
    cout.flush();
}

void kick(Vector target, float power)
{
    if (team == 0)
    {
        target.x *= -1;
        target.y *= -1;
    }
    cout << "kick " << target.x << " " << target.y << " " << power << endl;
    cout.flush();
}

void kick_action()
{
    int a = rand() % 40 - 20;
    kick(Vector(10, 60), 1);
}


int main()
{
    srand(time(NULL));
    int game_state;
    cin >> team >> number;
    while (true)
    {
        vector <Vector> players = get_players();
        gplayers.clear();
        gplayers = players;
        //cerr<<get_closest_op_dist(players, team, number)<<endl;
        Vector selfpos = players[5*team+number];
        Vector ballpos = get_ballpos();
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
            Vector position = get_target_position(number, ballpos);
            if (selfpos.dist(position) > 2)
            	move(position);
        }
    }
    return 0;
}
