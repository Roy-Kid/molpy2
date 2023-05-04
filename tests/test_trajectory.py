import molpy2 as mp


class TestTrajectory:

    def test_single_frame(self):

        traj = mp.Trajectory("test.xyz")
        assert traj.nsteps == 1

    def test_multiple_frames(self):
        
        traj = mp.Trajectory("test.xyz")
        assert traj.nsteps == 5

    def test_get_frame(self):

        traj = mp.Trajectory("multi.xyz")
        frame = traj.read()
        assert frame.nstep == 0

        frame = traj.read_step(2)
        assert frame.nstep == 2

    