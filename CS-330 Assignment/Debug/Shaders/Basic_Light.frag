#version 330 core
	
	out vec4 FragColor;
	in vec4 vertexColor;
	in vec2 texCoord;

	uniform sampler2D tex0; //gl_texture0
//	uniform sampler2D tex1; //gl_texture1
//	uniform sampler2D tex2; //gl_texture2

	void main(){

	float ambientStrength = 0.3;
	vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
	vec3 ambient = ambientStrength * lightColor;

	vec3 objectColor = vertexColor.xyz;

	vec3 finalColor = objectColor * ambient;

	

		//FragColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.5) * vertexColor; //mix two textures
		//FragColor = texture(tex0, texCoord) * vertexColor; //call one texture 
		//FragColor = texture(tex1, texCoord) * vertexColor; //call one texture 

		FragColor = vec4(finalColor, 1.0); //simple color only call

	}