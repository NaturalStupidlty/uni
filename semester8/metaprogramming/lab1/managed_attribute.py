class ManagedAttribute:
    def __init__(self, name=None, validation_function=None):
        self.name = name  # Optional; set in __set_name__ if not provided.
        self.validation_function = validation_function

    def __set_name__(self, owner, name):
        if self.name is None:
            self.name = name

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return instance.__dict__.get(self.name)

    def __set__(self, instance, value):
        if self.validation_function:
            result = self.validation_function(value)
            if not result:
                raise ValueError(f"Validation failed for {self.name} with value {value}")
        instance.__dict__[self.name] = value

    def __delete__(self, instance):
        if self.name in instance.__dict__:
            del instance.__dict__[self.name]
