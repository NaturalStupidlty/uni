## Implementation of the 5th laboratory work on the subject of "Mathematical basics of information security"

## Running

```
# 1. Copy an empty repo
git clone --no-checkout https://github.com/NaturalStupldity/uni

# 2. Move into the empty repo
cd uni

# 3. Initialize sparse-checkout
git sparse-checkout init --cone

#4. Checkout the folder with the project
git sparse-checkout set semester5/MOZI/lab5
```


## Structure

* `README.md` - This file
* `demo.py` - Main file demonstrating program functionality
* `source/` - Directory with source files
  * `modular_exponentiation.py` - Modular exponentiation function
  * `pohlig_hellman.py` - Pohlig-Hellman algorithm
  * `rho_algorithm.py` - Pollard's-Rho algorithm
  * `utils.py` - Auxiliary functions
* `tests/` - Directory with tests
  * `test_modular_exponentiation.py` - Tests for modular exponentiation function
  * `test_pohlig_hellman.py` - Tests for Pohlig-Hellman algorithm
  * `test_rho_algorithm.py` - Tests for Pollard's-Rho algorithm

## Requirements
`python3.8` or higher

## Usage

Run `demo.py` to see the program in action

## Testing

Run `pytest` to run all tests

## Authors

* **[Ihor Olkhovatyi](https://github.com/NaturalStupldity/uni)** 
* **[Artem Volyk](https://github.com/LuckyMan26)**
* **[Oleksandr Tsilynko](https://github.com/Dio-Stesso)**
* **[Volodymyr Kovalov](https://github.com/volodymyrkovalov)**
* **[Bondar Yulia](https://github.com/Bondar-Yulia)**
* **[Triasko Sofia]()**
