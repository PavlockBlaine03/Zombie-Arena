#pragma once

#include <SFML/Graphics.hpp>
#include <map>
using namespace std;
using namespace sf;

class TextureHolder
{
private:
	// A map container from STL that holds pairs of strings and textures
	map<string, Texture> m_Textures;

	// pointer of same type as the class
	static TextureHolder* m_s_Instance;
public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);
};

