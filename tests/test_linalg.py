import molpy2 as mp

class TestLinalg:

    def test_init_Vector3D(self):

        mp.Vector3D(1, 2, 3)

    def test_set_get_Vector3D(self):

        v = mp.Vector3D(1, 2, 3)
        assert v[0] == 1
        assert v[1] == 2
        assert v[2] == 3
        v[0] = 4
        v[1] = 5
        v[2] = 6
        assert v[0] == 4
        assert v[1] == 5
        assert v[2] == 6
