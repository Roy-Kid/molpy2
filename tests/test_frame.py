import molpy2 as mp

class TestFrame:

    def test_init(self):
        traj = mp.Trajectory("multi.xyz")
        frame = traj.read()