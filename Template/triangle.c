// Ghale, Sudip
// sxg7881
// 2020-05-06
//----------------------------------------------------------
#include <stdio.h>

#include "line.h"
#include "triangle.h"

//----------------------------------------------------------
void dumpTriangle( View *view, Vertex *v1, Vertex *v2, Vertex *v3 )
{
  //         Using a Line structure and calling clipLine(), check
  //         each of the three lines v1->v2, v2->v3, v3->v1 for
  //         clipping status and print an 'l' line for those that
  //         are not rejected.  Do the lines in that order!
  Line l1, l2, l3;
  l1.p1X = v1->x;
  l1.p1Y = v1->y;
  l1.p2X = v2->x;
  l1.p2Y = v2->y;

  l2.p1X = v2->x;
  l2.p1Y = v2->y;
  l2.p2X = v3->x;
  l2.p2Y = v3->y;

  l3.p1X = v3->x;
  l3.p1Y = v3->y;
  l3.p2X = v1->x;
  l3.p2Y = v1->y;


  if(clipLine(&l1,view->m_portalXMin, view->m_portalYMin, view->m_portalXMax, view->m_portalYMax))
  {
    printf("l %8.1f %8.1f %8.1f %8.1f\n" ,l1.p1X, l1.p1Y, l1.p2X, l1.p2Y);
  }
  
  if(clipLine(&l2,view->m_portalXMin, view->m_portalYMin, view->m_portalXMax, view->m_portalYMax))
  {
    printf("l %8.1f %8.1f %8.1f %8.1f\n" ,l2.p1X, l2.p1Y, l2.p2X, l2.p2Y);
  }

  if(clipLine(&l3,view->m_portalXMin, view->m_portalYMin, view->m_portalXMax, view->m_portalYMax))
  {
    printf("l %8.1f %8.1f %8.1f %8.1f\n" ,l3.p1X, l3.p1Y, l3.p2X, l3.p2Y);
  }


}

//----------------------------------------------------------

