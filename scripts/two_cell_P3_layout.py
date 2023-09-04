from pyop3 import *
from pyop3.extras.viz import view_axes


mesh_axis = Axis(
  [
    AxisComponent(2, "cells"),
    AxisComponent(5, "edges"),
    AxisComponent(4, "verts"),
  ],
  "mesh",
  permutation=[3, 7, 0, 10, 5, 9, 2, 1, 6, 4, 8],
)

mesh_axes = AxisTree(mesh_axis)
axes = (
    mesh_axes
    .add_subaxis(Axis(1), mesh_axis.id, "cells")
    .add_subaxis(Axis(2), mesh_axis.id, "edges")
    .add_subaxis(Axis(1), mesh_axis.id, "verts")
)


view_axes(axes, name="two_cell_P3_layout")
