# author: Roy Kid
# contact: lijichen365@126.com
# date: 2023-06-10
# version: 0.0.1

import molpy2 as mp

class TestAtom:

    def test_constructor(self):

        a0 = mp.Atom("a0")
        assert a0["name"] == "a0"

    # def test_copy_constructor(self):

    #     a0 = mp.Atom("a0")
    #     a1 = mp.Atom(a0)
    #     assert a1['name'] == "a0"

    # def test_has(self):

    #     a0 = mp.Atom("a0")
    #     a0.set("k1", "v1")
    #     assert a0.has("k1")
    #     a0["k2"] = "v2"
    #     assert a0.has("k2")
    #     assert "k2" in a0

    # def test_set_get(self):

    #     a0 = mp.Atom("a0")
    #     a0.set("k1", "v1")
    #     assert a0.get("k1") == "v1"
    #     a0["k2"] = "v2"
    #     assert a0["k2"] == "v2"

    # def test_equality(self):
            
    #     a0 = mp.Atom("a0")
    #     a1 = mp.Atom("a1")
    #     assert a0 == a0
    #     assert a0 != a1

    # def test_hash(self):
            
    #     a0 = mp.Atom("a0")
    #     a1 = mp.Atom("a1")
    #     assert hash(a0) == hash(a0)
    #     assert hash(a0) != hash(a1)
