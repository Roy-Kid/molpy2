import molpy2 as mp


class TestTrajectory:

    def test_load_single_frames(self, TEST_DATA_DIR):
        
        traj = mp.Trajectory(TEST_DATA_DIR / "xyz/methane.xyz")
        assert traj.nsteps == 1

    def test_load_multiple_frames(self, TEST_DATA_DIR):

        traj = mp.Trajectory(TEST_DATA_DIR / "lammps/polymer.lammpstrj")
        frame = traj.read()
        assert frame.nstep == 42

    def test_write_single_frame(self):

        pass