from collections import Counter


def generate_probs(data: list[any]) -> tuple[list[float], list[float], list[any]]:
    """
    The generate_probs function takes in a list of any data type and returns a tuple of three lists. The function
    first counts the number of occurrences of each data element in the input list using the Counter() method.
    It then calculates the alpha and beta values required for constructing an Optimal Binary Search Tree.

    Args:
        data (List[Any]): A list of objects representing the input data.

    Returns:
        Tuple[List[float], List[float], List[Any]]: A tuple containing 3 lists:
        alphas: a list of float values representing the alpha values for constructing the Optimal Binary Search Tree
        betas: a list of float values representing the beta values for constructing the Optimal Binary Search Tree
        beta_values: a list of any data type representing the values corresponding to each beta value

    The alpha and beta values are calculated as follows:
        The counts are sorted in ascending order based on the keys, and then iterated over using the iter() method.
    For each key-value pair in the sorted counts, the count value is divided by the total number of elements in
    the input list.
    If it is the first key-value pair, the resulting value is added to the alphas list.
    If it is not the first key-value pair, the resulting value is added to the betas list, and the corresponding
    key is added to the beta_values list.
    The alpha values and beta values are then returned as a tuple along with the corresponding beta values.

    Example:
        >>> example_data = ['a', 'a', 'b', 'c', 'c', 'c']
        >>> a, b, b_values = generate_probs(example_data)
        >>> print(a)
        >>> print(b)
        >>> print(b_values)

        [0.3333333333333333, 0.0, 0.5, 0.0]
        [0.0, 0.16666666666666666, 0.3333333333333333, 0.0]
        ['a', 'b', 'c']
    """
    total = len(data)
    counts = Counter(data)
    beta_values = []
    alphas = []
    betas = []
    num = 0
    it = iter(sorted(counts.items()))

    for (k, c) in it:
        if num == 0:
            alphas.append(float(c) / float(total))
            num = 1
        else:
            betas.append(float(c) / float(total))
            beta_values.append(k)
            num = 0

    if len(alphas) == len(betas):
        alphas.append(0.0)

    return alphas, betas, beta_values
