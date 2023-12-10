import numpy as np


def number_to_letter(n):
    if 0 <= n <= 26:
        return chr(ord('A') + n)
    else:
        return None


def letter_to_number(letter):
    # Ensure the input is a single uppercase letter
    if len(letter) == 1 and 'A' <= letter <= 'Z':
        return ord(letter) - ord('A')
    else:
        return None


def bipartite_encrypt(text: str, matrix: np.ndarray, alphabet_size: int = 26):
    # Remove whitespaces, punctuation, \n and convert to uppercase
    text = "".join([letter.upper() for letter in text if letter.isalpha()])

    if len(text) % 2 != 0:
        text = text[:-1]

    encrypted_text = ""

    for i in range(0, len(text), 2):
        block = text[i: i + 2]
        vector = [letter_to_number(block[0]), letter_to_number(block[1])]

        vector_array, matrix_array = np.array(vector), np.array(matrix)
        encrypted_vector = np.dot(matrix_array, vector_array)
        encrypted_block = "".join([number_to_letter(int(val) % alphabet_size) for val in encrypted_vector])
        encrypted_text += encrypted_block

    return encrypted_text


def bipartite_decrypt(text: str, matrix: np.ndarray, alphabet_size: int = 26):
    decrypted_text = ""
    inverse_matrix = np.linalg.inv(matrix)

    for i in range(0, len(text), 2):
        block = text[i:i+2]
        vector = [letter_to_number(block[0]), letter_to_number(block[1])]

        vector_array = np.array(vector)
        decrypted_vector = np.round(np.dot(inverse_matrix, vector_array))
        decrypted_block = ''.join([str(number_to_letter(int(val % alphabet_size))) for val in decrypted_vector])

        decrypted_text += decrypted_block

    return decrypted_text


if __name__ == '__main__':
    matrix = np.array([[1, 2], [3, 4]])
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
    encrypted_message = bipartite_encrypt(message, matrix)
    print("Encrypted text:", encrypted_message)

    # write to file as UTF-8
    with open("encrypted.txt", "w", encoding="utf-8") as file:
        file.write(encrypted_message)

    decrypted_message = bipartite_decrypt(encrypted_message, matrix)
    print("Decrypted text:", decrypted_message)

    # write to file as UTF-8
    with open("decrypted.txt", "w", encoding="utf-8") as file:
        file.write(decrypted_message)
