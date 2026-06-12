#include "LevelLoder.h"
#include <fstream>
#include <stdexcept>

using json = nlohmann::json;

js::LevelData LevelLoder::load(const std::string& filepath)
{
	std::ifstream file(filepath);

	if (!file.is_open())
		throw std::runtime_error("Level nicht gefunden: " + filepath);

	json j;
	file >> j;

	js::LevelData level;
	level.name = j["name"];
	level.player_start = { j["player_start"][0], j["player_start"][1] };

	level.background.image = j["background"]["image"];

	for (auto& b : j["borders"])
	{
		js::Border border;
		border.position = { b["position"][0], b["position"][1] };
		border.size = { b["size"][0], b["size"][1] };
		level.borders.push_back(border);
	}

	return level;
}


void loadInLevel(js::LevelData LevelDatas)
{
	js::LevelData level = LevelLoder::load("Level\\.json");
}