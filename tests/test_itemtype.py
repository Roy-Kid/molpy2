import molpy2 as mp
import numpy as np

class TestAtomProperty:

    def test_default_constructor(self):

        ap1 = mp.AtomProperty()
        ap2 = mp.AtomProperty(1)
        ap3 = mp.AtomProperty(1.23)
        ap4 = mp.AtomProperty("abc")
        ap5 = mp.AtomProperty([1, 2, 3])
        ap6 = mp.AtomProperty(np.ones(3, ))

    def test_set_get(self):

        ap = mp.AtomProperty(1)
        ap = 1.23
        ap = "abc"
        ap = [1, 2, 3]
        ap = np.ones(3, )

    def test_equality(self):
            
        ap1 = mp.AtomProperty(1)
        ap2 = mp.AtomProperty(1)
        ap3 = mp.AtomProperty(2)
        assert ap1 == ap2
        assert ap1 != ap3

class TestAtomType:

    def test_default_constructor(self):
        at = mp.AtomType("at")
        at["k1"] = 1
        at["k2"] = 1.23
        at["k3"] = "abc"
        at["k4"] = [1, 2, 3]

    def test_equality(self):

        at1 = mp.AtomType("at1")
        at2 = mp.AtomType("at2")

        assert at1 == at1
