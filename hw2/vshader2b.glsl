#version 330

in	vec2	a_Position;	// attribute variable: position vector
in	vec3	a_Color;	// attribute variable: color vector

out	vec4	v_Color;	// varying variable for passing color to fragment shader

uniform	mat4	u_Modelview;	// uniform variable for passing modelview  matrix
uniform	mat4	u_Projection;	// uniform variable for passing projection matrix
uniform	float	u_Theta;		// Theta parameter
uniform	int		u_Twist;		// Twist flag

void main() 
{
	// PUT YOUR CODE HERE
	if (u_Twist == 1)
	{
		float d = sqrt(a_Position[0]*a_Position[0] + a_Position[1]*a_Position[1]);
		float sinTheta = sin(d*u_Theta);
		float cosTheta = cos(d*u_Theta);
		gl_Position = u_Projection * vec4(a_Position[0]*cosTheta - a_Position[1]*sinTheta, a_Position[0]*sinTheta + a_Position[1]*cosTheta, 0, 1);
	}
	else
	{
		gl_Position = u_Projection * u_Modelview * vec4(a_Position, 0, 1);
	}

	v_Color = vec4(a_Color, 1);
}
