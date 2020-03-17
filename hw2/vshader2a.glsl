#version 330 //open gl 3.3

in	vec2	a_Position;	// attribute variable
uniform	mat4	u_Projection;	// uniform variable for passing projection matrix
void main() 
{
	// PUT YOUR CODE HERE
    gl_PointSize = 3.0;
	gl_Position = u_Projection * vec4(a_Position, 0, 1);
}
