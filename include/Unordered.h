#include"Polinom.h"
#include<vector>
#include<algorithm>
template<typename Tkey, typename Tvalue>
class unordered_table {
private:
	std::vector<std::pair<Tkey, Tvalue>> table;
public:
	using iterator = typename vector<pair<Tkey, Tvalue>>::iterator;
	unordered_table(const std::pair<Tkey, Tvalue>& para)
	{
		table.push_back(para);
	}
	unordered_table(const std::initializer_list<std::pair<Tkey, Tvalue>>& l)
	{
		for (auto it = l.begin(); it != l.end(); it++)
		{
			insert(*it);
		}
	}

	void push(Tkey key, Tvalue value)
	{
		if (find(key))
		{
			for (auto it = table.begin(); it != table.end(); it++)
			{
				if (key == (*it).first)
				{
					(*it).second = value;
				}
			}
		}
		else
		{
			table.push_back(std::make_pair(key, value));
		}
	}

	bool find(const Tkey& key)
	{
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if (key == (*it).first) return true;
		}
		return false;
	}

	void erase(const Tkey& key)
	{
		if (find(key))
		{
			for (auto it = table.begin(); it != table.end(); it++)
			{
				if (key == (*it).first)
				{

					if ((*it) != table[table.size() - 1])
					{
						std::swap((*it), table[table.size() - 1]);
					}
					table.pop_back();
					return;
				}
			}
		}
	}

	Tvalue operator[](const Tkey& key)
	{
		if (find(key))
		{
			for (auto it = table.begin(); it != table.end(); it++)
			{
				if (key == (*it).first)
				{
					return (*it).second;
				}
			}
		}
		else return NULL;
	}

	void print()
	{
		for (auto it = table.begin(); it != table.end(); it++)
		{
			std::cout << (*it).second;
		}

	}
};