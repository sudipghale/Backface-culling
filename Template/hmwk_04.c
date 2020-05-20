// Ghale, Sudip
// sxg7881
// 2020-05-06
//----------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "model.h"
#include "projection.h"
#include "triangle.h"
#include "vertex.h"
#include "view.h"
#include "visible.h"

//----------------------------------------------------------
int main( int argc, char *argv[] )
{
  if ( argc != 3 ) {
    fprintf( stderr, "Usage: %s <modelFileName> <viewFileName>\n", argv[0] );
    exit( 1 );
  }

  //--------------------------------------
  // Load the desired model and view.
  Model *m = loadModel( argv[1] );
  View *v = loadView( argv[2] );

  // Compute the projection corresponding to the view.
  Projection *p = computeProjection( v );

  //--------------------------------------
  // Dump all of these data structures as a check.
  dumpModel( m );
  dumpView( v );
  dumpProjection( p );

  //--------------------------------------
  // Allocate a place for the projected versions of the vertices
  // to go.
  Vertex *v_projected = (Vertex *) calloc(m->m_numVertices, sizeof(Vertex));
  if(v_projected == NULL)
  {
    fprintf(stderr, "malloc error: for allocating the num vertices\n");
    exit(0);
  }


  // And now project the vertices into that space ...
  projectVertexList2(p, m->m_vertex, m->m_numVertices, v_projected);


  //--------------------------------------
  // Print the canvas size for the SDF file.
  printf( "c %4d %4d\n", v->m_width, v->m_height );

  //--------------------------------------
  // Draw lines corresponding to the viewport region.
  printf( "l %6d %8d %8d %8d\n", v->m_portalXMin, v->m_portalYMin, v->m_portalXMax, v->m_portalYMin ); 
  printf( "l %6d %8d %8d %8d\n", v->m_portalXMax, v->m_portalYMin, v->m_portalXMax, v->m_portalYMax );
  printf( "l %6d %8d %8d %8d\n", v->m_portalXMax, v->m_portalYMax, v->m_portalXMin, v->m_portalYMax );
  printf( "l %6d %8d %8d %8d\n", v->m_portalXMin, v->m_portalYMax, v->m_portalXMin, v->m_portalYMin );

  //--------------------------------------
  //       Construct a Vertex holding the worldspace position of
  //       the camera.  If the projection is PARALLEL, remember
  //       that the camera's z coordinate should be at effectively
  //       "infinity".
  Vertex v_cam;
  v_cam.x = 0;
  v_cam.y =0;
  if(v->m_cameraDistance == 0) v_cam.z = INFINITY;
  else v_cam.z = v->m_cameraDistance;



  //--------------------------------------
  //       For each face of the model, draw the triangle
  //       represented by its three vertices using the enhanced
  //       version of dumpTriangle().  Draw the triangle ONLY IF
  //       the triangle is visible (use isVisible() to determine
  //       this).
  for( int i =0; i < m->m_numFaces; i ++)
  {
    if( isVisible(&v_cam, &m->m_vertex[m->m_face[i].v1], &m->m_vertex[m->m_face[i].v2], &m->m_vertex[m->m_face[i].v3]))
    {
      dumpTriangle(v, &v_projected[m->m_face[i].v1], &v_projected[m->m_face[i].v2], &v_projected[m->m_face[i].v3]);
    }

  }

  //--------------------------------------
  // Free all of our allocated resources ...
  if(m != NULL)
  {
    free(m);
  }
  if(v != NULL)
  {
    free(v);
  }
  if(p != NULL)
  {
    free(p);
  }
  if(v_projected != NULL)
  {
    free(v_projected);
  }


  // ... and exit with no error.
  return 0;
}

//----------------------------------------------------------

