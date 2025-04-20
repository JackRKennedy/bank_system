# Bank System

This project is a simple C-based bank system implementation. It provides basic functionality for managing bank accounts, including:

* **Account Creation:**  Allows users to create new bank accounts.
* **Deposit:** Allows users to deposit funds into their accounts.
* **Withdrawal:** Allows users to withdraw funds from their accounts.
* **Balance Inquiry:** Allows users to check their account balance.
* **Account Closure:** Allows user to close existing bank accounts.

## Getting Started

**Prerequisites:**

* A C compiler (e.g., GCC, Clang)
* Make (for building the project)
* CMake (for managing the build process)

**Building:**

1. Clone the repository: `git clone <repository_url>`
2. Create a build directory `mkdir build && cd build`
3. Run cmake to configure the build:  `cmake ..`
4. Build the project: `make`

**Running:**

1. Open the terminal inside the build directory and type this command to run the compiled program: `./bank_system`

## Usage

The bank system provides a simple command-line interface for interacting with accounts. Upon running the program, you will be presented with a menu of options. Follow the on-screen prompts to perform operations.

## Future Enhancements

* **Persistent Storage:** Currently, account data is stored in memory and is lost when the program exits. Future development will focus on adding persistent storage (e.g., using files or a database) to retain account information between sessions.
* **Transaction History:**  Implementing a transaction history feature to keep track of all account activities.
* **User Authentication:**  Adding a user authentication system to secure accounts and prevent unauthorized access.
* **Improved User Interface:**  Improving the user interface to make it more user-friendly.  Possibly adding a GUI in the future.
* **More Features:** Adding features like transfer between accounts, loan management, and other banking operations.

## Contributing

Contributions are welcome! Please feel free to submit pull requests for bug fixes, new features, or other improvements.

## License

This project is licensed under the [MIT License](LICENSE).
