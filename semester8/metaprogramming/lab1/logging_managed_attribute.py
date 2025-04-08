from logger import safe_log
from managed_attribute import ManagedAttribute


class LoggingManagedAttribute(ManagedAttribute):
    def __set__(self, instance, value):
        if isinstance(value, str):
            old_value = getattr(instance, self.name, None)
            if old_value != value:
                log_filename = f"{self.name}_log.txt"
                safe_log(
                    log_filename, f"{self.name} changed from {old_value} to {value}"
                )
        # Call the original __set__ to actually set the value.
        super().__set__(instance, value)


def attr_change_logger(cls):
    for attr_name, attr in cls.__dict__.items():
        if isinstance(attr, ManagedAttribute):
            # Replace with a logging descriptor.
            setattr(cls, attr_name, LoggingManagedAttribute(attr.name, attr.validation_function))
    return cls
