// Ghale, Sudip
// sxg7881
// 2020-05-06
//----------------------------------------------------------
#include <stdio.h>

#include "visible.h"

//----------------------------------------------------------
int isVisible( Vertex *cameraPosition, Vertex *v1, Vertex *v2, Vertex *v3 )
{
  //          Purpose:  Determine if the triangle represented by
  //          vertices v1, v2, and v3 is visible from the given
  //          camera position.
  //
  //        Compute the toTriangle vector from the camera position
  //          to v1 of the triangle.
  //
  //        Derive the surface normal for the triangle by
  //          computing the cross product of the vector from v1
  //          to v2 with the vector from v1 to v3.
  //
  //        Compute the angle between the toTriangle vector and
  //          the surface normal vector.
  //
  //        Return 1 if this angle indicates the triangle is
  //          visible from the camera position, 0 otherwise.
  Vertex toTriangle, vec_A, vec_B, sn;
  double angleValue = 0;

  toTriangle.x = v1->x - cameraPosition->x;
  toTriangle.y = v1->y - cameraPosition->y;
  toTriangle.z = v1->z - cameraPosition->z;

  vec_A.x = v2->x - v1->x;  // todo , handle - Ve ???
  vec_A.y = v2->y - v1->y;
  vec_A.z = v2->z - v1->z;

  vec_B.x = v3->x - v1->x;
  vec_B.y = v3->y - v1->y;
  vec_B.z = v3->z - v1->z;

  sn.x = vec_A.y*vec_B.z - vec_A.z*vec_B.y;
  sn.y = vec_A.z*vec_B.x - vec_A.x*vec_B.z;
  sn.z = vec_A.x*vec_B.y - vec_A.y*vec_B.x;

  angleValue = toTriangle.x*sn.x + toTriangle.y*sn.y + toTriangle.z*sn.z;
  if(angleValue < 0) return 1;
  else return 0;
  
  










}

//----------------------------------------------------------
