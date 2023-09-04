from pyrsistent import pmap
import loopy as lp
from pyop3 import *
from pyop3.codegen import LOOPY_LANG_VERSION, LOOPY_TARGET
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
axes = (
    mesh_axes
    .add_subaxis(Axis(2), mesh_axis.id, "cells")
    .add_subaxis(Axis(1), mesh_axis.id, "verts")
)

func0 = MultiArray(axes, name="func0", dtype=ScalarType)
func1 = MultiArray(axes, name="func1", dtype=ScalarType)

cells_axes = AxisTree(Axis([AxisComponent(3, "cells")], "mesh"))

map_axes0 = cells_axes.add_subaxis(Axis(1), *cells_axes.leaf)
map_axes1 = cells_axes.add_subaxis(Axis(2), *cells_axes.leaf)
map_array0 = MultiArray(map_axes0, name="map0", dtype=IntType)
map_array1 = MultiArray(map_axes1, name="map1", dtype=IntType)

closure = Map(
        {
            pmap({"mesh": "cells"}): [
                TabulatedMapComponent("mesh", "cells", map_array0),
                TabulatedMapComponent("mesh", "verts", map_array1),
            ],
        },
        "closure",
    )

lpy_kernel = lp.make_kernel(
    "{ [i]: 0 <= i < 4 }",
    "y[i] = x[i] + y[i]",
    [lp.GlobalArg("x", ScalarType, (4,), is_input=True, is_output=False),
    lp.GlobalArg("y", ScalarType, (4,), is_input=True, is_output=True)],
    name="dummy_kernel",
    target=LOOPY_TARGET,
    lang_version=LOOPY_LANG_VERSION,
)
dummy_kernel = LoopyKernel(lpy_kernel, [READ, INC])

# l = loop(c := mesh.cells, kernel(func0[closure(c)], ...))
l = loop(
    # c := mesh_axes[Slice("mesh", [SliceComponent("cells")])].index(),
    c := cells_axes.index(),
    dummy_kernel(func0[closure(c), :], func1[closure(c), :])
)

with open("residual_assembly.c", "w") as f:
    f.write(l.c_code)
