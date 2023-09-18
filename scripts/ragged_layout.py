import numpy as np

from pyop3 import *
from pyop3.extras.viz import view_axes


axis0 = Axis([AxisComponent(5, "pt0")], "ax0")
nnz = MultiArray(axis0, data=np.asarray([1, 2, 4, 3, 2], dtype=int))
axis1 = Axis(nnz)

axes = AxisTree(axis0, {axis0.id: axis1})
view_axes(axes, name="ragged_layout")
