// Dalio, Brian A.
// dalioba
// 2020-03-30

#if !defined( __VERTEX_H__ )
#define __VERTEX_H__

//----------------------------------------------------------
typedef struct _Vertex {
  double x;
  double y;
  double z;
} Vertex;

//----------------------------------------------------------
void   dumpVertex( Vertex *vertex );

//----------------------------------------------------------
#endif

