#version 330 core
	
	out vec4 FragColor;
	in vec4 vertexColor;
	in vec2 texCoord;

	uniform sampler2D tex0; //gl_texture0
	uniform sampler2D tex1; //gl_texture1
//	uniform sampler2D tex2; //gl_texture2

	void main(){


	//FragColor = vec4(1.0);


		//FragColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.5) * vertexColor; //mix two textures
	FragColor = texture(tex0, texCoord) * vertexColor; //call one texture 
	FragColor = texture(tex1, texCoord) *   vertexColor; //call second texture 
		//FragColor = vertexColor; //simple color only call

	}