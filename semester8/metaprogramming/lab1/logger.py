from datetime import datetime


def safe_log(filename, message):
    """Helper function to safely log messages with a timestamp."""
    try:
        with open(filename, "a") as log_file:
            timestamp = datetime.now().isoformat()
            log_file.write(f"[{timestamp}] {message}\n")
    except Exception as e:
        print(f"Logging failed for {filename}: {e}")
