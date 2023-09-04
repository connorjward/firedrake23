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
view_axes(mesh_axes, name="two_cell_mesh")
