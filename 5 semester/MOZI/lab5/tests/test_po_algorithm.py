from lab5.source.po_algorithm import po_algorithm

def test_po_algorithm():
    assert po_algorithm(3) == None  # Просте число
    assert po_algorithm(4) == None  # Складене число, але дільник = 2
    assert po_algorithm(15) == 3    # 3 - дільник 15
    assert po_algorithm(17) == None  # Просте число
    assert po_algorithm(561) == 3   # 3 - дільник числа Кармайкла 561

    assert po_algorithm(8051) == 97  # 31 - дільник числа 8051

    # Перевірка на великому простому числі
    large_prime = 104723
    assert po_algorithm(large_prime) == None  # Просте число

    print("All tests passed")

if __name__ == "__main__":
    test_po_algorithm()
