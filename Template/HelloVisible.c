// Dalio, Brian A.
// dalioba
// 2020-05-04

//----------------------------------------------------------
// This is an incredibly simple test of isVisible() using a
//   PARALLEL projected camera position.
//
// The intent is to demonstrate that if the calculations in
//   isVisible() are done correctly, even having INFINITY as one
//   of the coordinates of the Camera Position causes no
//   computation difficulties.
//
// In particular, you should NOT encounter any "Not a Number"
//   ("nan") results and you do NOT need any operations other than
//   add, subtract, multiply, negate, and a relation.
//
// We define a camera position that has an "infinite" z and three
//   vertices (A, B, and C).  For ease of visualization, these
//   three vertices have all been placed on the XY plane.
//
// By considering the vertices in one order (A, B, C) then in the
//   opposite order (A, C, B), we should have one of the triangles
//   FACING the camera position and the other triangle facing AWAY
//   from the camera position.
//----------------------------------------------------------

// All we use from <math.h> is the INFINITY macro.  We
//   specifically do NOT require any trigonometric, power, or
//   root routines.
#include <math.h>

// All we use from <stdio.h> is the printf() routine.
#include <stdio.h>

//----------------------------------------------------------

#include "vertex.h"    // for the Vertex structure definition.
#include "visible.h"   // for the isVisible() routine.

//----------------------------------------------------------
int main()
{
  // This camera position represents the location of the viewer
  //   when the projection is PARALLEL.
  //
  // INFINITY is used to represent a viewer who is "very far"
  //   away, which makes PERSPECTIVE projection look just like
  //   PARALLEL projection.
  Vertex cp = { 0, 0, INFINITY };

  // The three vertices that we will use to make up our triangles.
  //
  // These three vertices are all on the XY plane for simplicity's
  //   sake.  (Their z coordinates are all 0.)
  Vertex vA = { 1, 2, 0 };
  Vertex vB = { 3, 4, 0 };
  Vertex vC = { 5, 2, 0 };

  // Display our camera position.
  //
  // This should print with "inf" (or something like that) in the
  //   place of the z coordinate, indicating that z is as large
  //   as we can make it.
  printf( "\n#-------------------\n" );
  printf( "cp ( %13.8f, %13.8f, %13.8f )\n", cp.x, cp.y, cp.z );

  // We will first consider the vertices in the order vA, vB, and
  //   then vC.
  //
  // After displaying the vertices in this order, we make a call
  //   to isVisible() and announce the visibility result.
  //
  // (FYI:  This triangle should be NOT visible from the given
  //        camera position.)
  printf( "\n#-------------------\n" );
  printf( "vA ( %13.8f, %13.8f, %13.8f )\n", vA.x, vA.y, vA.z );
  printf( "vB ( %13.8f, %13.8f, %13.8f )\n", vB.x, vB.y, vB.z );
  printf( "vC ( %13.8f, %13.8f, %13.8f )\n", vC.x, vC.y, vC.z );
  printf( "\n  --> This △ %s visible.\n", isVisible( &cp, &vA, &vB, &vC ) ? "IS" : "is NOT" );

  // We now consider the vertices in the order vA, vC, vB.  Note
  //   that this is the REVERSE of the order considered in the
  //   first triangle.
  //
  // Therefore, if the first triangle were visible, this triangle
  //   should be invisible, and vice-versa.
  //
  // (FYI:  This triangle SHOULD be visible from the given camera
  //        position.)
  printf( "\n#-------------------\n" );
  printf( "vA ( %13.8f, %13.8f, %13.8f )\n", vA.x, vA.y, vA.z );
  printf( "vC ( %13.8f, %13.8f, %13.8f )\n", vC.x, vC.y, vC.z );
  printf( "vB ( %13.8f, %13.8f, %13.8f )\n", vB.x, vB.y, vB.z );
  printf( "\n  --> This △ %s visible.\n", isVisible( &cp, &vA, &vC, &vB ) ? "IS" : "is NOT" );

  printf( "\n#-------------------\n" );

  // All done and no errors!
  return 0;
}

//----------------------------------------------------------
