#include<bits/stdc++.h>

using namespace std;

constexpr int MAX_SIZE = 10;

class Stack
{
private:
	int arr[MAX_SIZE];
	int sz;
public:
	void reset()
	{
		sz = 0;
	}

	bool push(const int a)
	{
		if(sz < MAX_SIZE)
		{
			arr[sz] = a;
			sz++;
			return true;
		}
		return false;
	}

	int pop()
	{
		assert(sz > 0);
		int ans = arr[sz];
		sz--;
		return (ans);
	}

	void print()
	{
		cout << "( ";
		for(int i = 0; i < sz; i++)
		{
			cout << arr[i] << ' ';
		}		
		cout << " )" << endl;
	}
};

class Ball
{
private:
	string m_color{};
	double radius{};

public:
	Ball(double radius) : m_color("black"), radius(radius) {};
	Ball(string color="black", double radius=10.0) : m_color(color), radius(radius) {};

	void print()
	{
		cout << "color: " << m_color << ", radius: " << radius << endl;
	}
};


class Point2d
{
private:
	double m_x;
	double m_y;

public:
	Point2d(double x=0.0, double y=0.0) : m_x(x),m_y(y){};

	void print()
	{
		cout << "Point2d(" << m_x << ", " << m_y << ")" << endl;
	}

	friend double distanceFrom(const Point2d& point1, const Point2d& point2);
};

double distanceFrom(const Point2d& point1, const Point2d& point2)
{
	double dist = (point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) + (point1.m_y - point2.m_y) * (point1.m_y - point2.m_y);
	dist = sqrt(dist);

	return dist;
}


class Monster
{
public:
	enum class Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

private:
	Type type;
	string name;
	string roar;
	int hit_points;

public:
	Monster(Monster::Type type, string name, string roar, int hit_points) :
	type(type),
	name(name),
	roar(roar),
	hit_points(hit_points)
	{};

	void print()
	{
		cout << name << " the ";
		switch(type)
		{
			case Monster::Type::dragon:
			{
				cout << "dragon";
				break;
			}

			case Monster::Type::goblin:
			{
				cout << "goblin";
				break;
			}

			case Monster::Type::ogre:
			{
				cout << "ogre";
				break;
			}

			case Monster::Type::orc:
			{
				cout << "orc";
				break;
			}

			case Monster::Type::skeleton:
			{
				cout << "skeleton";
				break;
			}

			case Monster::Type::troll:
			{
				cout << "troll";
				break;
			}

			case Monster::Type::vampire:
			{
				cout << "vampire";
				break;
			}

			case Monster::Type::zombie:
			{
				cout << "zombie";
				break;
			}

			default:
			{
				cout << "monster";
				break;
			}
		}

		cout << " has " << hit_points << " hit points and says " << roar << "\n";
	}
};


class Card
{
public:
	enum class Suit
	{
	    club,
	    diamond,
	    heart,
	    spade,

	    max_suits
	};

	enum class Rank
	{
	    rank_2,
	    rank_3,
	    rank_4,
	    rank_5,
	    rank_6,
	    rank_7,
	    rank_8,
	    rank_9,
	    rank_10,
	    rank_jack,
	    rank_queen,
	    rank_king,
	    rank_ace,

	    max_ranks
	};

private:
    Rank rank{};
    Suit suit{};

public:
	Card() : rank(Rank::rank_2), suit(Suit::club)
	{};
	Card(Rank r, Suit s) : rank(r), suit(s)
	{};

	void print() const
	{
	    switch(rank)
	    {
	    case Rank::rank_2:      std::cout << '2';   break;
	    case Rank::rank_3:      std::cout << '3';   break;
	    case Rank::rank_4:      std::cout << '4';   break;
	    case Rank::rank_5:      std::cout << '5';   break;
	    case Rank::rank_6:      std::cout << '6';   break;
	    case Rank::rank_7:      std::cout << '7';   break;
	    case Rank::rank_8:      std::cout << '8';   break;
	    case Rank::rank_9:      std::cout << '9';   break;
	    case Rank::rank_10:     std::cout << 'T';   break;
	    case Rank::rank_jack:   std::cout << 'J';   break;
	    case Rank::rank_queen:  std::cout << 'Q';   break;
	    case Rank::rank_king:   std::cout << 'K';   break;
	    case Rank::rank_ace:    std::cout << 'A';   break;
	    default:
	        std::cout << '?';
	        break;
	    }

	    switch(suit)
	    {
	    case Suit::club:       std::cout << 'C';   break;
	    case Suit::diamond:    std::cout << 'D';   break;
	    case Suit::heart:      std::cout << 'H';   break;
	    case Suit::spade:      std::cout << 'S';   break;
	    default:
	        std::cout << '?';
	        break;
	    }
	}

	int value() const
	{
	  switch(rank)
	  {
	  case Rank::rank_2:        return 2;
	  case Rank::rank_3:        return 3;
	  case Rank::rank_4:        return 4;
	  case Rank::rank_5:        return 5;
	  case Rank::rank_6:        return 6;
	  case Rank::rank_7:        return 7;
	  case Rank::rank_8:        return 8;
	  case Rank::rank_9:        return 9;
	  case Rank::rank_10:       return 10;
	  case Rank::rank_jack:     return 10;
	  case Rank::rank_queen:    return 10;
	  case Rank::rank_king:     return 10;
	  case Rank::rank_ace:      return 11;
	  default:
	    assert(false && "should never happen");
	    return 0;
	  }
	}
};

int main()
{
	const Card cardQueenHearts{ Card::Rank::rank_queen, Card::Suit::heart };
	cardQueenHearts.print();
	std::cout << " has the value " << cardQueenHearts.value() << '\n';
	
	return 0;
}