from pathlib import Path
import subprocess
import logging

log = logging.getLogger("Tests")

# download test dataset
if not Path("tests-data").exists():
    log.info("Downloading test dataset")
    try:
        subprocess.run(["git", "clone", "https://github.com/chemfiles/tests-data.git"], check=True)
    except subprocess.CalledProcessError as e:
        log.error("Failed to download test dataset")
        raise e
    
TEST_DATA_DIR = Path("tests-data")