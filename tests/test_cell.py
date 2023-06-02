import molpy2 as mp
import numpy as np
import numpy.testing as npt

class TestCell:

    def test_default_constructor(self):

        cell = mp.Cell()
        npt.assert_allclose(cell.get_lengths(), np.ones(3, ))
        npt.assert_allclose(cell.get_tilts(), np.zeros(3, ))
        npt.assert_allclose(cell.get_angles(), np.ones(3, ) * 90.0)
        assert cell.get_volume() == 1.0

    def test_orthogonal(self):

        cell = mp.Cell(np.array([1, 2, 3]), np.ones(3, )*90)
        npt.assert_allclose(cell.get_lengths(), (1, 2, 3))
        npt.assert_allclose(cell.get_tilts(), np.zeros(3, ))
        npt.assert_allclose(cell.get_angles(), np.ones(3, ) * 90.0)
        assert cell.get_volume() == 6.0

    def test_triclinic(self):

        cell = mp.Cell(np.array([1, 1, 1]), np.array([45, 45, 45]))
        npt.assert_allclose(cell.get_lengths(), (1, 1, 1))
        npt.assert_allclose(cell.get_tilts(), (0.707, 0.707, 0.293), 1e-03)
        npt.assert_allclose(cell.get_angles(), np.ones(3, ) * 45.0)
        assert cell.get_volume() == 0.45508987

