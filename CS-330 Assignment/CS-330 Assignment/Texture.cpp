#include <Texture.h>
#include <stb_image.h>
#include <iostream>

Texture::Texture(const filesystem::path& path)
{

	//load texture
	stbi_set_flip_vertically_on_load(true); //flip image

	auto texturePath = path.string(); //set path to image
	int width, height, numChannels;
	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &numChannels, STBI_rgb_alpha);

	glGenTextures(3, &_textureHandle);
	glBindTexture(GL_TEXTURE_2D, _textureHandle);

	if (data) {

		glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);

		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		cerr << "Failed to load texure at: " << texturePath << endl;
	}
	stbi_image_free(data);

}

void Texture::Bind()
{

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, _textureHandle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

}
