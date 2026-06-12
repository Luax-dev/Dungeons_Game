#pragma once
#include <string>
#include <vector>
#include <array>
#include "json.hpp"

namespace js
{
	struct Border
	{
		std::array<int, 2> position;
		std::array<int, 2> size;
	};

	struct Background
	{
		std::string image;
	};

	struct LevelData
	{
		std::string name;
		std::array<int, 2> player_start;
		Background background;
		std::vector<Border> borders;
	};
}




class LevelLoder
{
public:
	static js::LevelData load(const std::string& filepath);
	
	void loadInLevel(js::LevelData LevelDatas);
};

