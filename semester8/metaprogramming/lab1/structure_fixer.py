from logger import safe_log


class StructureFixer(type):
    def __new__(mcls, name, bases, namespace):
        cls_obj = super().__new__(mcls, name, bases, namespace)
        # Only freeze the instance structure if explicitly disabled.
        if getattr(cls_obj, "__allow_dynamic_changes__", True) is False:
            # Build a set of allowed attribute names from the class and its bases.
            allowed_keys = set()
            for base in cls_obj.__mro__:
                allowed_keys.update(base.__dict__.keys())

            # Save any existing __setattr__ (likely object.__setattr__).
            original_setattr = cls_obj.__setattr__

            def fixed_setattr(self, key, value):
                # If the key is not one of the allowed names, log and block the assignment.
                if key not in allowed_keys:
                    log_filename = "structure_changes_log.txt"
                    safe_log(
                        log_filename,
                        f"Attempted to add dynamic attribute '{key}' with value '{value}' to instance of {type(self).__name__}",
                    )
                    raise AttributeError(
                        f"Dynamic attribute addition not allowed for {type(self).__name__}"
                    )
                # If the attribute is defined as a descriptor, let it handle the assignment.
                attr = None
                for base in type(self).__mro__:
                    if key in base.__dict__:
                        attr = base.__dict__[key]
                        break
                if attr is not None and hasattr(attr, "__set__"):
                    attr.__set__(self, value)
                else:
                    # Otherwise, perform a normal assignment.
                    original_setattr(self, key, value)

            cls_obj.__setattr__ = fixed_setattr
        return cls_obj
