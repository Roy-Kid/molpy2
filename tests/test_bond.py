import molpy2 as mp
import numpy as np

class TestBond:

    def test_init(self):

        atom1 = mp.Atom()
        atom2 = mp.Atom()
        bond = mp.Bond(atom1, atom2)
