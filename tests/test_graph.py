import molpy2 as mp
import numpy as np

class TestGraph:
    
    def test_constructor(self):

        g = mp.Graph()

    def test_node(self):

        g = mp.Graph()
        g.add_node(0)
        assert g.has_node(0)
        assert not g.has_node(1)
        g.del_node(0)
        assert not g.has_node(0)

    def test_edge(self):

        g = mp.Graph()
        g.add_edge(0, 1)
        assert g.has_edge(0, 1)
        assert g.has_edge(1, 0)
        g.del_edge(0, 1)
        assert not g.has_edge(0, 1)

    def test_get_bonds(self):

        g = mp.Graph()
        g.add_edge(0, 1)
        g.add_edge(1, 2)
        g.add_edge(2, 0)
        bonds = g.get_bonds()
        assert len(bonds) == 3
        assert (0, 1) in bonds
        assert (1, 2) in bonds
        assert (2, 0) in bonds

    def test_angles(self):

        g = mp.Graph()
        g.add_edge(0, 1)
        g.add_edge(1, 2)
        g.add_edge(2, 0)
        angles = g.get_angles()
        assert len(angles) == 3
        assert (1, 0, 2) in angles
        assert (0, 1, 2) in angles
        assert (0, 2, 1) in angles

    def test_dihedrals(self):

        g = mp.Graph()
        g.add_edge(0, 1)
        g.add_edge(1, 2)
        g.add_edge(2, 3)
        g.add_edge(3, 0)
        dihedrals = g.get_dihedrals()
        assert len(dihedrals) == 4
        assert (0, 1, 2, 3) in dihedrals
        assert (3, 0, 2, 1) in dihedrals
        assert (1, 0, 3, 2) in dihedrals
        assert (1, 2, 3, 0) in dihedrals