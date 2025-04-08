import os

from user_profile import UserProfile

if __name__ == "__main__":
    # Remove old log files for a clean test (if they exist)
    for file in [
        "name_log.txt",
        "email_log.txt",
        "password_log.txt",
        "personal_code_log.txt",
        "structure_changes_log.txt",
    ]:
        if os.path.exists(file):
            os.remove(file)

    # Create a user profile.
    user = UserProfile("Alice", 30, "alice@example.com", "Secret123", "IPCA001007")

    # Change a string attribute to trigger logging in the attribute descriptor.
    user.name = "Alice Cooper"  # This change is logged in name_log.txt.
    user.email = "alice.cooper@example.com"  # This change is logged in email_log.txt.

    # Changing a non-string attribute (like age) won’t trigger logging by LoggingManagedAttribute.
    user.age = 31

    # Attempting to add a new attribute dynamically will be blocked.
    try:
        user.new_attribute = "This should fail"
    except AttributeError as e:
        print("Caught exception:", e)

    print("Testing complete. Check the log files for recorded changes.")
