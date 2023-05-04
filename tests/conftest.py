from pathlib import Path
import subprocess
import logging

log = logging.getLogger("Tests")

# download test dataset
if not Path("tests-data").exists():
    log.info("Downloading test dataset")
    try:
        subprocess.run(["git", "clone", "ttps://github.com/chemfiles/tests-data.git"], check=True)
    except subprocess.CalledProcessError as e:
        log.error("Failed to download test dataset")
        raise e
    
