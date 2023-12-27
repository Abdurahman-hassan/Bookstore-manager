template <size_t MAX_COLS>
void writeCSV(const std::string& filename, const std::string data[][MAX_COLS], int rowCount, int colCount) {
    std::ofstream fileOut(filename);
    if (!fileOut.is_open()) {
        throw std::runtime_error("Error opening file for writing");
    }

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            fileOut << data[i][j];
            if (j < colCount - 1) fileOut << ",";
        }
        fileOut << "\n";
    }

    fileOut.close();
}


template <size_t MAX_COLS>
void readCSV(const std::string& filename, std::string data[][MAX_COLS], int& rowCount, int& colCount) {
    std::ifstream fileIn(filename);
    if (!fileIn.is_open()) {
        throw std::runtime_error("Error opening file for reading");
    }

    std::string line;
    rowCount = 0;

    while (std::getline(fileIn, line) && rowCount < 100) { // Assuming max 100 rows
        std::istringstream ss(line);
        std::string cell;
        int col = 0;

        while (std::getline(ss, cell, ',') && col < MAX_COLS) {
            data[rowCount][col++] = cell;
        }

        if (col > 0) { // Ensure we have at least one column
            rowCount++;
        }
    }

    colCount = (rowCount > 0) ? MAX_COLS : 0; // Set colCount to MAX_COLS if we have at least one row
    fileIn.close();
}
