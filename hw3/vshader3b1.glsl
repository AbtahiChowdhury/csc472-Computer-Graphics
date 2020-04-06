#version 330

// PUT YOUR CODE HERE

// inputs
in vec3 a_Position;
in vec2 a_TexCoord;
in vec3 a_Color;
in vec3 a_Normal;

// outputs
out vec2 v_TexCoord;

// uniforms
uniform mat4 u_Projection;
uniform mat4 u_View;

void main() 
{
	// PUT YOUR CODE HERE
	gl_Position = u_Projection * u_View * vec4(a_Position, 1);
	v_TexCoord = a_TexCoord;
}
