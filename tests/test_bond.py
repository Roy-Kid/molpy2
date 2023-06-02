import molpy2 as mp
import numpy as np

class TestBond:

    def test_init(self):

        atom1 = mp.Atom()
        atom2 = mp.Atom()
        bond = mp.Bond(atom1, atom2)

    def test_get_ends(self):

        atom1 = mp.Atom()
        atom2 = mp.Atom()
        bond = mp.Bond(atom1, atom2)
        assert bond.get_itom() == atom1
        assert bond.get_jtom() == atom2

    def test_equlity(self):

        atom1 = mp.Atom()
        atom2 = mp.Atom()
        bond1 = mp.Bond(atom1, atom2)
        bond2 = mp.Bond(atom2, atom1)
        assert bond1 == bond2

    def test_set_get(self):

        atom1 = mp.Atom()
        atom2 = mp.Atom()
        bond = mp.Bond(atom1, atom2)
        bond.set("k1", "v1")
        assert bond.get("k1") == "v1"
        bond["k2"] = "v2"
        assert bond["k2"] == "v2"

        assert bond.has("k1")
