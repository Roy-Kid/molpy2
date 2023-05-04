import molpy2 as mp
import numpy as np
import numpy.testing as npt

class TestAtom:

    def test_init(self):

        atom = mp.Atom()

    def test_get_set(self):

        atom = mp.Atom()
        atom['int'] = 42
        atom['double'] = 3.14
        atom['string'] = "test"
        atom['positions'] = np.array([1.0, 2.0, 3.0])
        atom['vel'] = [1.0, 2.0, 3.0]

        assert atom['int'] == 42
        assert atom['double'] == 3.14
        assert atom['string'] == 'test'
        npt.assert_allclose(atom['positions'], np.array([1.0, 2.0, 3.0]))
        npt.assert_allclose(atom['vel'], np.array([1.0, 2.0, 3.0]))
