from pyop3 import *
from pyop3.extras.viz import view_axes


mesh_axis = Axis(
  [
    AxisComponent(2, "cells"),
    AxisComponent(3, "verts"),
  ],
  "mesh",
)

axes = AxisTree(
    mesh_axis,
    {
        mesh_axis.id: [
            Axis([AxisComponent(3), AxisComponent(4)], permutation=[1, 3, 5, 0, 2, 4, 6]),
            Axis([AxisComponent(3), AxisComponent(4)], permutation=[1, 3, 5, 0, 2, 4, 6])
        ]
    }
)
view_axes(axes, name="extruded_layout")
