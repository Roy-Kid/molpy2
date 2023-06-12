import molpy2 as mp
import numpy as np

class TestAtomType:

    def test_default_constructor(self):
        at = mp.AtomType("at")
        at["k1"] = 1
        at["k2"] = 1.23
        at["k3"] = "abc"
        at["k4"] = np.array([1, 2, 3])

    def test_equality(self):

        at1 = mp.AtomType("at1")
        at2 = mp.AtomType("at2")

        assert at1 == at1
