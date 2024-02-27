#pragma once
#include <glm/glm.hpp>
#include <vector>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Color;
	glm::vec3 Normal{ 0.0f, 0.0f, 0.0f };
	glm::vec2 Uv{ 1.0f, 1.0f };
};


struct Shapes {

	static inline std::vector<Vertex>cubeVertices{
	//front face
	{.Position = { -0.25f, 0.25f, 0.25f },//vertex 1
		.Color = { 1.0f, 1.0f, 1.0f }},
	{ .Position = {-0.25f, -0.25f, 0.25f},//vertex 2
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, -0.25f, 0.25f},//vertex 3
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, 0.25f, 0.25f},//vertex 4
	.Color = {1.0f, 1.0f, 1.0f } },

		//right side
	{ .Position = {0.25f, 0.25f, 0.25f},//vertex 5
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, -0.25f, 0.25f},//vertex 6
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, -0.25f, -0.25f},//vertex 7
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, 0.25f, -0.25f},//vertex 8
	.Color = {1.0f, 1.0f, 1.0f } },

		//back side
	{ .Position = {0.25f, 0.25f, -0.25f},//vertex 9
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, -0.25f, -0.25f},//vertex 10
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, -0.25f, -0.25f},//vertex 11
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, 0.25f, -0.25f},//vertex 12
	.Color = {1.0f, 1.0f, 1.0f } },

		//left side
	{ .Position = {-0.25f, 0.25f, -0.25f},//vertex 13
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, -0.25f, -0.25f},//vertex 14
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, -0.25f, 0.25f},//vertex 15
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, 0.25f, 0.25f},//vertex 16
	.Color = {1.0f, 1.0f, 1.0f } },

		//top side
	{ .Position = {-0.25f, 0.25f, -0.25f},//vertex 17
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, 0.25f, 0.25f},//vertex 18
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, 0.25f, 0.25f},//vertex 19
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, 0.25f, -0.25f},//vertex 20
	.Color = {1.0f, 1.0f, 1.0f } },

		//bottom side
	{ .Position = {0.25f, -0.25f, 0.25f},//vertex 21
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {0.25f, -0.25f, -0.25f},//vertex 22
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, -0.25f, -0.25f},//vertex 23
	.Color = {1.0f, 1.0f, 1.0f } },
	{ .Position = {-0.25f, -0.25f, 0.25f},//vertex 24
	.Color = {1.0f, 1.0f, 1.0f } }

};



static inline std::vector<uint32_t>cubeElements{
	0, 1, 3, 1, 2, 3, //front face
	4, 5, 7, 5, 6, 7, //right face
	8, 9, 11, 9, 10, 11, //back face
	12, 13, 15, 13, 14, 15, //left face
	16, 17, 19, 17, 18, 19, //top face
	20, 21, 23, 21, 22, 23 //bottom face
};

static inline std::vector<Vertex>shapeVertices{
		//front face x
		{.Position = {0.5f, -0.5f, -0.5f},//vertex 0
		.Color = {0.400f, 0.804f, 0.667f},
		.Uv {0.0f, 0.0f}
		},
		{.Position = {-0.5f, -0.5f, -0.5f},//vertex 1
		.Color = {0.400f, 0.804f, 0.667f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {0.0f, 0.25f, 0.0f},//vertex 2
		.Color = {0.400f, 0.804f, 0.667f},
		.Uv {0.0f, 0.0f}
	},

		//right side x
		{.Position = {-0.5f, -0.5f, -0.5f},//vertex 3
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {-0.5f, -0.5f, 0.5f},//vertex 4
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {0.0f, 0.25f, 0.0f},//vertex 5
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},

		//back side x
		{.Position = {-0.5f, -0.5f, 0.5f},//vertex 6
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {0.5f, -0.5f, 0.5f},//vertex 7
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {0.0f, 0.25f, 0.0f},//vertex 8
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},

		//left side x
		{.Position = {0.5f, -0.5f, 0.5f},//vertex 9
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {0.5f, -0.5f, -0.5f},//vertex 10
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {0.0f, 0.25f, 0.0f},//vertex 11
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},

		//bottom side x
		{.Position = {0.5f, -0.5f, 0.5f},//vertex 12
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {0.5f, -0.5f, -0.5f},//vertex 13
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {-0.5f, -0.5f, -0.5f},//vertex 14
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	},
		{.Position = {-0.5f, -0.5f, 0.5f},//vertex 15
		.Color = {0.5f, 0.5f, 0.5f},
		.Uv {0.0f, 0.0f}
	}

	};


	static inline std::vector<uint32_t>shapeElements{
	0, 1, 2, //front face
	3, 4, 5, //right face
	6, 7, 8, //back face
	9, 10, 11,  //left face
	14, 13, 15, 13, 12, 15 //bottom face

	};


	static inline std::vector<Vertex>planeVertices{
		//Floor Plane
	{.Position = {0.0f, -2.0f, 1.0f},//vertex 0
	.Color = {0.961f, 0.871f, 0.702f},
	.Uv {0.0f, 1.0f} },
	{.Position = {0.0f, -2.0f, -1.0f},//vertex 1
	.Color = {0.961f, 0.871f, 0.702f},
	.Uv {0.0f, 0.0f} },
	{.Position = {-2.0f, -2.0f, -1.0f},//vertex 2 
	.Color = {0.961f, 0.871f, 0.702f},
	.Uv {1.0f, 0.0f} },
	{.Position = {-2.0f, -2.0f, 1.0f},//vertex 3
	.Color = {0.961f, 0.871f, 0.702f},
	.Uv {1.0f, 1.0f} },

	//left wall Plane
	{.Position = {0.0f, 0.0f, -1.0f},//vertex 4
	.Color = {0.420f, 0.557f, 0.137f},
	.Uv {} },
	{.Position = {0.0f, 0.0f, 1.0f},//vertex 5
	.Color = {0.420f, 0.557f, 0.137f},
	.Uv {} },
	{.Position = {0.0f, -2.0f, 1.0f},//vertex 6 
	.Color = {0.420f, 0.557f, 0.137f},
	.Uv {} },
	{.Position = {0.0f, -2.0f, -1.0f},//vertex 7
	.Color = {0.420f, 0.557f, 0.137f},
	.Uv {} },

	//right wall Plane 
	{.Position = {0.0f, 0.0f, 1.0f},//vertex 8
	.Color = {0.604f, 0.804f, 0.196f},
	.Uv {} },
	{.Position = {-2.0f, 0.0f, 1.0f},//vertex 9
	.Color = {0.604f, 0.804f, 0.196f},
	.Uv {} },
	{.Position = {-2.0f, -2.0f, 1.0f},//vertex 10 
	.Color = {0.604f, 0.804f, 0.196f},
	.Uv {} },
	{.Position = {0.0f, -2.0f, 1.0f},//vertex 11
	.Color = {0.604f, 0.804f, 0.196f},
	.Uv {} },
	};

	static inline std::vector<uint32_t>planeElements{
	2, 1, 3, 1, 0, 3, //floor plane
	7, 4, 5, 7, 5, 6, //left wall plane
	8, 9, 10, 8, 11, 10, //right wall plane
	};


	static inline std::vector<Vertex>deskVertices{


		//left side desk 
		{.Position = {0.9f, -0.3f, 0.2f},//vertex 0
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 1.0f} },
		{.Position = {0.9f, -1.0f, 0.2f},//vertex 1
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.9f, -1.0f, 0.9f},//vertex2  
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 0.0f} },
		{.Position = {0.9f, -0.3f, 0.9f},//vertex 3
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 1.0f} },
		{.Position = {0.8f, -0.3f, 0.2f},//vertex 4
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 1.0f} },
		{.Position = {0.8f, -1.0f, 0.2f},//vertex 5
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.8f, -1.0f, 0.9f},//vertex 6  
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 0.0f} },
		{.Position = {0.8f, -0.3f, 0.9f},//vertex 7
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 1.0f} },

		//right side of desk
		{.Position = {-0.2f, -0.3f, 0.2f},//vertex 8
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 1.0f} },
		{.Position = {-0.2f, -1.0f, 0.2f},//vertex 9
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 0.0f} },
		{.Position = {-0.2f, -1.0f, 0.9f},//vertex 10
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 0.0f} },
		{.Position = {-0.2f, -0.3f, 0.9f},//vertex 11
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 1.0f} },
		{.Position = {-0.3f, -0.3f, 0.2f},//vertex 12
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 1.0f} },
		{.Position = {-0.3f, -1.0f, 0.2f},//vertex 13
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 0.0f} },
		{.Position = {-0.3f, -1.0f, 0.9f},//vertex 14
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 0.0f} },
		{.Position = {-0.3f, -0.3f, 0.9f},//vertex 15
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 1.0f} },

		//top desk shape
		{.Position = {0.9f, -0.1f, 0.2f},//vertex 16
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 1.0f} },
		{.Position = {0.9f, -0.3f, 0.2f},//vertex 17
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {} },
		{.Position = {0.9f ,-0.3f, 0.9f},//vertex 18
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {} },
		{.Position = {0.9f, -0.1f, 0.9f},//vertex 19
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {0.0f, 0.0f} },
		{.Position = {-0.3f ,-0.1f, 0.2f},//vertex 20
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 0.0f} },
		{.Position = {-0.3f, -0.3f, 0.2f},//vertex 21
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {} },
		{.Position = {-0.3f, -0.3f, 0.9f},//vertex 22
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {}},
		{.Position = {-0.3f, -0.1f, 0.9f},//vertex 23
		.Color = {0.824f, 0.706f, 0.549f},
		.Uv {1.0f, 1.0f} },

		//desk drawer
		{.Position = {0.6f ,-0.15f, 0.195f},//vertex 24
		.Color = {0.961f, 0.871f, 0.702f},
		.Uv {0.0f, 1.0f} },
		{.Position = {0.6f, -0.25f, 0.195f},//vertex 25
		.Color = {0.961f, 0.871f, 0.702f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.0f, -0.25f, 0.195f},//vertex 26
		.Color = {0.961f, 0.871f, 0.702f},
		.Uv {1.0f, 0.0f}},
		{.Position = {0.0f, -0.15f, 0.195f},//vertex 27
		.Color = {0.961f, 0.871f, 0.702f},
		.Uv {1.0f, 1.0f} },

	};



	static inline std::vector<uint32_t>deskElements{
		1, 5, 4, 4, 0, 1, //front left side desk
		4, 5, 7, 5, 6, 7, //right left side desk
		0, 1, 2, 0, 2, 3, //left left side desk
		0, 4, 7, 7, 3, 0, //top left side desk
		2, 5, 7, 6, 7, 2, //back left side desk
		8, 9, 13, 8, 13, 12, //front right side desk
		12, 13, 14, 12, 14, 15, //right right side desk
		8, 12, 15, 8, 15, 11, //top right side desk
		8, 9, 10, 8, 10, 11, //left right side desk
		11, 10, 14, 11, 14, 15, //back right side desk
		16, 17, 18, 16, 18, 19, //left side top of desk
		16, 17, 21, 16, 21, 20, //front top of desk
		20, 21, 22, 20, 22, 23, //right top of desk
		17, 21, 22, 17, 22, 18, //bottom top of desk
		19, 18, 22, 19, 22, 23, //back top of desk
		16, 20, 23, 16, 23, 19, //top top of desk
		24, 25, 26, 24, 26, 27 //desk drawer



	};



	static inline std::vector<Vertex>lampVertices{
		//Lamp Base
		{.Position = {0.75f, -0.05f, 0.55f},//vertex 0
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.75f, -0.15f, 0.55f},//vertex 1
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.75f, -0.15f, 0.7f},//vertex 2 
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.75f, -0.05f, 0.7f},//vertex 3
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.6f, -0.05f, 0.55f},//vertex 4
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.6f, -0.15f, 0.55f},//vertex 5
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.6f, -0.15f, 0.7f},//vertex 6 
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.6f, -0.05f, 0.7f},//vertex 7
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },

		//lamp neck
		{.Position = {0.64f, -0.05f, 0.59f},//vertex 8
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.65f, -0.05f, 0.61f},//vertex 9
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.66f, -0.05f, 0.59f},//vertex 10 
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.64f, 0.25f, 0.59f},//vertex 11
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.65f, 0.25f, 0.61f},//vertex 12
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.66f, 0.25f, 0.59f},//vertex 13
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		
		//lamp light top
		{.Position = {0.7f, 0.25f, 0.65f},//vertex 14
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.7f, 0.25f, 0.55f},//vertex 15
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.7f, 0.3f, 0.6f},//vertex 16 
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.4f, 0.25f, 0.65f},//vertex 17
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.4f, 0.25f, 0.55f},//vertex 18
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.4f, 0.3f, 0.6f},//vertex 19
		.Color = {0.294f, 0.000f, 0.510f},
		.Uv {0.0f, 0.0f} },

		//light bulb
		{.Position = {0.65f, 0.25f, 0.55f},//vertex 20
		.Color = {1.0f, 1.0f, 1.0f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.65f, 0.25f, 0.65f},//vertex 21
		.Color = {1.0f, 1.0f, 1.0f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.4f, 0.25f, 0.65f},//vertex 22
		.Color = {1.0f, 1.0f, 1.0f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.4f, 0.25f, 0.55f},//vertex 23
		.Color = {1.0f, 1.0f, 1.0f},
		.Uv {0.0f, 0.0f} },


	};

	static inline std::vector<uint32_t>lampElements{
	//lamp base
	0, 1, 4, 1, 4, 5,
	0, 1, 2, 0, 2, 3,
	4, 5, 6, 4, 6, 7, 
	3, 2, 6, 3, 6, 7, 
	0 ,4, 7, 0, 7, 3,
	//lamp neck
	8, 9, 12, 8, 12, 11,
	8, 10, 13, 8, 13, 11,
	9, 10, 13, 9, 13, 12,
	11, 12, 13,
	//lamp light
	14, 15, 16, 
	15, 16, 19, 15, 19, 18,
	14, 16, 19, 14, 17, 19,
	18, 19, 17,
	20, 21, 22, 20, 22, 23,

	};

	static inline std::vector<Vertex>stoolVertices{
		//stool bottom verts
		{.Position = {0.45f, -1.0f, 0.35f},//vertex 0
		.Color = {1.0f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.35f, -1.0f, 0.25f},//vertex 1
		.Color = {0.690f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.25f, -1.0f, 0.25f},//vertex 2
		.Color = {1.0f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.15f, -1.0f, 0.35f},//vertex 3
		.Color = {1.0f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.15f, -1.0f, 0.45f},//vertex 4
		.Color = {0.690f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.25f, -1.0f, 0.55f},//vertex 5
		.Color = {1.0f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.35f, -1.0f, 0.55f},//vertex 6 
		.Color = {0.690f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.45f, -1.0f, 0.45f},//vertex 7
		.Color = {1.0f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },

		//stool top
		{.Position = {0.45f, -0.5f, 0.35f},//vertex 8
		.Color = {0.0f, 0.0f, 1.0f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.35f, -0.5f, 0.25f},//vertex 9
		.Color = {0.0f, 0.0, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.25f, -0.5f, 0.25f},//vertex 10
		.Color = {0.0f, 0.0f, 1.0f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.15f, -0.5f, 0.35f},//vertex 11
		.Color = {0.690f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.15f, -0.5f, 0.45f},//vertex 12
		.Color = {0.0f, 0.0f, 1.0f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.25f, -0.5f, 0.55f},//vertex 13
		.Color = {0.690f, 0.769f, 0.871f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.35f, -0.5f, 0.55f},//vertex 14
		.Color = {0.0f, 0.0f, 1.0f},
		.Uv {0.0f, 0.0f} },
		{.Position = {0.45f, -0.5f, 0.45f},//vertex 15
		.Color = {0.0f, 0.0f, 1.0f},
		.Uv {0.0f, 0.0f} },


	};

	static inline std::vector<uint32_t>stoolElements{
	//stool sides
	0, 1, 9, 0, 8, 9,
	1, 2, 10, 1, 9, 10, 
	2, 3, 11, 2, 10, 11,
	3, 4, 12, 3, 11, 12, 
	4, 5, 13, 4, 13, 12,
	5, 6, 14, 5, 13, 14, 
	6, 7, 15, 6, 14, 15, 
	7, 0, 8, 7, 8, 15, 
	//stool top
	8, 15, 14,
	15, 14, 13,
	14, 13, 12, 
	13, 12, 11, 
	12, 11, 10,
	11, 10, 9, 
	10, 9, 8, 
	9, 8, 15, 
	8, 14, 12, 
	15, 13, 11,
	13, 11, 9,
	12, 10, 8, 
	14, 11, 9,

	};
};