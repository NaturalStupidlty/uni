import re
from managed_attribute import ManagedAttribute
from structure_fixer import StructureFixer
from logging_managed_attribute import attr_change_logger


def validate_name(x):
    if not isinstance(x, str):
        raise ValueError("Name must be a string.")
    if not x.strip():
        raise ValueError("Name cannot be empty or just whitespace.")
    return True


def validate_age(x):
    if not isinstance(x, int):
        raise ValueError("Age must be an integer.")
    if x < 0 or x > 120:
        raise ValueError("Age must be between 0 and 120.")
    return True


def validate_email(x):
    if not isinstance(x, str):
        raise ValueError("Email must be a string.")
    # Simple regex for basic email validation
    email_regex = r'^[\w\.-]+@[\w\.-]+\.\w+$'
    if not re.match(email_regex, x):
        raise ValueError("Email format is invalid.")
    return True


def validate_password(x):
    if not isinstance(x, str):
        raise ValueError("Password must be a string.")
    if len(x) < 8:
        raise ValueError("Password must be at least 8 characters long.")
    # Check for at least one digit, one uppercase letter, and one lowercase letter
    if not re.search(r"[0-9]", x):
        raise ValueError("Password must include at least one digit.")
    if not re.search(r"[A-Z]", x):
        raise ValueError("Password must include at least one uppercase letter.")
    if not re.search(r"[a-z]", x):
        raise ValueError("Password must include at least one lowercase letter.")
    return True


def validate_personal_code(x):
    if not isinstance(x, str):
        raise ValueError("Personal code must be a string.")
    # Expecting a 10-character alphanumeric string
    if len(x) != 10 or not x.isalnum():
        raise ValueError("Personal code must be a 10-character alphanumeric string.")
    return True


@attr_change_logger
class UserProfile(metaclass=StructureFixer):
    __allow_dynamic_changes__ = False

    name = ManagedAttribute(validation_function=validate_name)
    age = ManagedAttribute(validation_function=validate_age)
    email = ManagedAttribute(validation_function=validate_email)
    password = ManagedAttribute(validation_function=validate_password)
    personal_code = ManagedAttribute(validation_function=validate_personal_code)

    def __init__(self, name, age, email, password, personal_code):
        self.name = name
        self.age = age
        self.email = email
        self.password = password
        self.personal_code = personal_code
