#include <iostream>
#include <string>
#include <string_view>
#include "Random.h"

class Monster
{
public:
	enum Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monsters,
	};

private:
	Type m_type{};
	std::string m_name{ "???" };
	std::string m_roar{ "???" };
	int m_HP{};

public:
	Monster(Type type, std::string_view name, std::string_view roar, int HP)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_HP{ HP }
	{
	}

	std::string_view getTypeString();
	void print();
};

std::string_view Monster::getTypeString()
{
	switch (m_type)
	{
	case Type::dragon: return "dragon";
	case Type::goblin: return "goblin";
	case Type::ogre: return "ogre";
	case Type::orc: return "orc";
	case Type::skeleton: return "skeleton";
	case Type::troll: return "troll";
	case Type::vampire: return "vampire";
	case Type::zombie: return "zombie";
	default: return "???";
	}
}

void Monster::print()
{
	std::cout << m_name << " the " << this->getTypeString() << " has " << m_HP << " hit points and says " << m_roar << '\n';
}

namespace MonsterGenerator
{
	std::string_view getName(int name)
	{
		switch (name)
		{
		case(0): return "sardior";
		case(1): return "asgorath";
		case(2): return "bahamut";
		case(3): return "tiamat";
		case(4): return "garyx";
		case(5): return "kereska";
		default: return "???";
		}
	}

	std::string_view getRoar(int roar)
	{
		switch (roar)
		{
		case(0): return "skree";
		case(1): return "*rawr*";
		case(2): return "*growl*";
		case(3): return "*bree*";
		case(4): return "*blegh*";
		case(5): return "*buagh*";
		default: return "???";
		}
	}

	Monster generate()
	{
		return Monster{ static_cast<Monster::Type>(Random::get(0, Monster::max_monsters -1)),
			getName(Random::get(0, 5)),
			getRoar(Random::get(0, 5)),
			Random::get(0, 100)};
	}
}

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}