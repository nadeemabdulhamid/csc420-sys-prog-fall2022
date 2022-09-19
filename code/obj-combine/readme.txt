One of the most commonly used file formats to store graphics data is 
the .obj format; the file format is widely used in both research and 
industry applications.

In this exercise, we look at the most basic form of the .obj format, 
which contains a list of vertices and a list of triangular faces that
together specify the geometry of a 3D model. The coordinate space in 
which the vertices are specified is called world space. For now, we 
can simply imagine the 3D model described by the .obj file as a 
collection of vertices and triangular faces, positioned in some 
sort of arbitrary coordinate space.

The structure of a basic .obj file is shown below:

v x1 y1 z1  
v x2 y2 z2  
v x3 y3 z3  
...  
v xm ym zm  
f face0v1 face0v2 face0v3  
f face1v1 face1v2 face1v3  
f face2v1 face2v2 face2v3  
...  
f face_n_v1 face_n_v2 face_n_v3

The lines that begin with a v contain vertex data, whereas the lines 
that begin with a f contain face data. Each “vertex line” starts with 
a v and follows the v with three floating point numbers: the x, y, 
and z coordinates (in that order) of a vertex in the described 3D model. 
Each “face line” starts with a f and follows the f with three integers 
specifying the three vertices that make up a triangular face in the 3D 
model. For example, the following line:

f 1 8 37

specifies a face that is made up of the first, eighth, and thirty-seventh 
specified vertices in the file. Note that this means the vertices are 
1-indexed; i.e. the first specified vertex in the file is referred to as 
the first vertex, rather than the zeroth vertex. This is simply due to 
convention in the computer graphics world.
