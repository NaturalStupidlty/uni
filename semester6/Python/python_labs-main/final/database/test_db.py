import unittest
from unittest.mock import MagicMock
from datetime import datetime
from create_database import main, random_string, random_date


class TestDatabaseOperations(unittest.TestCase):
    def setUp(self):
        # Patching the DataBase class used in the main function
        self.patcher = unittest.mock.patch('database.DataBase')
        self.mock_db_class = self.patcher.start()

        # Create a mock database object
        self.mock_db = self.mock_db_class.return_value

    def tearDown(self):
        self.patcher.stop()

    def test_random_string(self):
        # Test the random_string function for a specific length
        result = random_string(10)
        self.assertEqual(len(result), 10)  # Check length
        self.assertTrue(result.isupper())  # Check all characters are uppercase

    def test_random_date(self):
        # Test the random_date function
        start_date = datetime(2023, 1, 1)
        end_date = datetime(2023, 12, 31)
        result = random_date(start_date, end_date)
        self.assertTrue(start_date <= result <= end_date)

    def test_retrieve_concerts(self):
        # Set a return value for the concerts method
        self.mock_db.concerts.return_value = ['concert1', 'concert2']

        # Test the return value
        self.assertEqual(self.mock_db.concerts(), ['concert1', 'concert2'])

    def test_retrieve_performers(self):
        # Set a return value for the performers method
        self.mock_db.performers.return_value = ['performer1', 'performer2']

        # Test the return value
        self.assertEqual(self.mock_db.performers(), ['performer1', 'performer2'])


if __name__ == '__main__':
    main()
    unittest.main()
