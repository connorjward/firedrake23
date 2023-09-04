from pyop3 import *
from pyop3.extras.viz import view_axes


numbering = [3, 0, 5, 2, 1, 6, 4]
permutation = numbering
# permutation = [0] * 7
# for i, n in enumerate(numbering):
#     permutation[n] = i

# breakpoint()


mesh_axis = Axis(
  [
    AxisComponent(3, "cells"),
    AxisComponent(4, "verts"),
  ],
  "mesh",
  permutation=permutation,
)

mesh_axes = AxisTree(mesh_axis)
view_axes(mesh_axes, name="interval_mesh_layout", format="png")
