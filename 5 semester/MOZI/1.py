encoding = {
    "A": "X",
    "B": "E",
    "C": "I",
    "D": "K",
    "E": "H",
    "F": "F",
    "G": "J",
    "H": "G",
    "I": "O",
    "J": "M",
    "K": "V",
    "L": "L",
    "M": "R",
    "N": "Q",
    "O": "P",
    "P": "S",
    "Q": "T",
    "R": "U",
    "S": "N",
    "T": "W",
    "U": "D",
    "V": "Y",
    "W": "C",
    "X": "Z",
    "Y": "B",
    "Z": "A",
    " ": "",
    ".": "",
    ",": "",
    ":": "",
    ";": "",
    "!": "",
    "?": "",
    "(": "",
    ")": "",
    "\n": "",
}


def encode(message):
    encoded_message = ""
    for letter in message:
        encoded_message += encoding[letter.upper()]
    return encoded_message


if __name__ == '__main__':
    message = """The material given in this work is considered there due to the fact
that last time the idea that science has exhausted itself and its role is
decreasing every day, appears in the media and among specialists. This
situation is especially surprising when a person who graduated from
some University has access to the Internet, believes that everything he
needs is in the Internet and there is no need for scientific research.
Various pandemics demonstrates us the absurdity of such a thought.
It is obvious that the progress in virology is absolutely important and
necessary. But achievement in other areas of science, in particular in
computer science, is very important also (may be less obvious). The
relationship between algebra, computer science and programming is
considers in this work; moreover we made an attempt to describe a
certain influence of algebra on computer science and on the contrary
computer science on algebra and other fields.
We do not pretend on completeness of the material, however it is
almost impossible to give a full description of algebra applications in
computer science and programming."""
    print(encode(message))
