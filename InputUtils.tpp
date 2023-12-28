// function to get a valid number (int or float)
template <typename T>
T getValidNumber(const string& prompt) {
    T number;
    string input;
    bool isValid = false;

    while (!isValid) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);

        if (ss >> number && !(ss >> input)) { // Check if input is a number and nothing follows
            isValid = true;
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
        }
    }
    return number;
}
