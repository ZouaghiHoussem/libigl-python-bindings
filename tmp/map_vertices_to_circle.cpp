//TODO: libigl is not templated...
#include <common.h>
#include <npe.h>
#include <typedefs.h>
#include <igl/map_vertices_to_circle.h>

const char* ds_map_vertices_to_circle = R"igl_Qu8mg5v7(
Map the vertices whose indices are in a given boundary loop (bnd) on the unit circle with spacing proportional to the original boundary edge lengths.

Parameters
----------
v : #v by dim array of mesh vertex positions
b : #w list of vertex ids

Returns
-------
uv : #w by 2 list of 2D positions on the unit circle for the vertices in b

See also
--------
None

Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(map_vertices_to_circle)
npe_doc(ds_map_vertices_to_circle)
npe_arg(v, dense_f32, dense_f64)
npe_arg(bnd, dense_i32, dense_i64)
npe_begin_code()

  EigenDenseLike<npe_Matrix_v> uv;
  igl::map_vertices_to_circle(v, bnd, uv);
  return npe::move(uv);

npe_end_code()


