import molpy2 as mp
import numpy as np

class TestTopology:

    def test_constructor(self):

        top = mp.Topology()

    def test_atom_manage(self):
            
        topo = mp.Topology()
        atom1 = topo.create_atom()
        assert topo.has_atom(atom1)
        assert topo.get_natoms() == 1

        atom2 = topo.create_atom()
        assert topo.has_atom(atom2)
        assert topo.get_natoms() == 2

        topo.del_atom(atom1)
        assert not topo.has_atom(atom1)
        assert topo.get_natoms() == 1
        topo.del_atom(atom2)
        assert not topo.has_atom(atom2)
        assert topo.get_natoms() == 0

    def test_bond_manage(self):

        topo = mp.Topology()
        atom1 = topo.create_atom()
        atom2 = topo.create_atom()
        bond1 = topo.create_bond(atom1, atom2)
        assert topo.has_bond(bond1)
        assert topo.get_nbonds() == 1

        atom3 = topo.create_atom()
        atom4 = topo.create_atom()
        bond2 = topo.create_bond(atom3, atom4)
        assert topo.has_bond(bond2)
        assert topo.get_nbonds() == 2

        topo.del_bond(bond1)
        assert not topo.has_bond(bond1)
        assert topo.get_nbonds() == 0
        topo.del_bond(bond2)
        assert not topo.has_bond(bond2)
        assert topo.get_nbonds() == 0

class TestSubTopo:

    def test_atom_manage(self):

        topology = mp.Topology()
        subtopo = topology.create_topology()
        atom1 = topology.create_atom()
        assert topology.has_atom(atom1)
        assert topology.get_natoms() == 1

        atom2 = subtopo.create_atom()
        assert subtopo.has_atom(atom2)
        assert subtopo.get_natoms() == 1
        assert topology.get_natoms() == 2

    def test_bond_manage(self):

        topology = mp.Topology()
        subtopo = topology.create_topology()
        atom1 = topology.create_atom()
        atom2 = topology.create_atom()
        bond1 = topology.create_bond(atom1, atom2)
        assert topology.has_bond(bond1)
        assert topology.get_nbonds() == 1

        atom3 = subtopo.create_atom()
        atom4 = subtopo.create_atom()
        bond2 = subtopo.create_bond(atom3, atom4)
        assert subtopo.has_bond(bond2)
        assert subtopo.get_nbonds() == 1
        assert topology.get_nbonds() == 2

        bond3 = topology.create_bond(atom1, atom3)
        assert topology.has_bond(bond3)
        assert topology.get_nbonds() == 3
        assert subtopo.get_nbonds() == 1

        topology.del_bond(bond1)
        assert not topology.has_bond(bond1)
        assert topology.get_nbonds() == 2

    def test_topo_manage(self):

        # 1 \       / 5
        # |   3 - 4   |
        # 2 /       \ 6        

        topology = mp.Topology()
        subtopo1 = topology.create_topology()
        subtopo2 = topology.create_topology()
        atom1 = subtopo1.create_atom()
        atom2 = subtopo1.create_atom()
        atom3 = subtopo1.create_atom()
        atom4 = subtopo2.create_atom()
        atom5 = subtopo2.create_atom()
        atom6 = subtopo2.create_atom()

        bond1 = subtopo1.create_bond(atom1, atom2)
        bond2 = subtopo1.create_bond(atom2, atom3)
        bond3 = subtopo1.create_bond(atom3, atom1)

        bond4 = subtopo2.create_bond(atom4, atom5)
        bond5 = subtopo2.create_bond(atom5, atom6)
        bond6 = subtopo2.create_bond(atom6, atom4)

        topology.add_topology(subtopo1)
        topology.add_topology(subtopo2)

        bond7 = topology.create_bond(atom3, atom4)

        assert topology.get_natoms() == 7