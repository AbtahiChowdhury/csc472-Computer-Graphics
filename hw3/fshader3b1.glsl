#version 330

// PUT YOUR CODE HERE

// inputs
in vec2 v_TexCoord;

// outputs
out vec4 fragColor;

// uniforms
uniform sampler2D u_Sampler;

void main() 
{
	// PUT YOUR CODE HERE
	fragColor = vec4(texture(u_Sampler, v_TexCoord).xyz, 1);
}
