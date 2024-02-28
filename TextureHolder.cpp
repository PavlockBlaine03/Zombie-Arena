#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;
TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}
Texture& TextureHolder::GetTexture(string const& filename)
{
	// Get reference to m_Texture using m_s_Instance
	auto& m = m_s_Instance->m_Textures;
	// auto is equivalent of map<string, Texture>

	// create an iterator to hold a key value pair and search for required kvp
	// using passed in file name
	auto keyValuePair = m.find(filename);

	// Did we find a match?
	if (keyValuePair != m.end())
	{
		// Yes return texture the second part of the key value pair
		return keyValuePair->second;
	}
	else
	{
		// File name not found
		// Create new key value pair using filename
		auto& texture = m[filename];

		// load texture from file usual way
		texture.loadFromFile(filename);
		return texture;
	}

}