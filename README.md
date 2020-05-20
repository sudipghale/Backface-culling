# Backface-culling
backface cull triangles



#-------------------
QUESTIONS:
when do we use project vertices ???


#----------------------------------------------------------------------
Purpose:

  * Demonstrate ability to backface cull triangles using the
    method discussed in class.

  * Demonstrate ability to write some additional (simple) C code.
#-----------------------------------------------------------------------

To Compile:
$cd Template
$ gcc -o hmwk_04 hmwk_04.c face.c line.c model.c projection.c triangle.c vertex.c view.c visible.c -lm
$ ./hmwk_04 ../Tests/pyramid.svfm ../Tests/pyramid_setting_01.view