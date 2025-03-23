#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

class DataFrame
{
	// TODO: catch errors
private:
	size_t n_rows;
	size_t n_columns;
	vector<vector<double>> data;
	vector<string> column_names;
	bool is_column_names;

public:
	DataFrame(size_t num_rows, size_t num_columns)
	{
		data.resize(num_rows, vector<double>(num_columns));
		n_rows = num_rows;
		n_columns = num_columns;
		is_column_names = false;
	}

	size_t set_column_names(vector<string> names)
	{
		/*
		 * Example,
		 * vector<string> names = {"Col 1", "Col 2", "Col 3"};
		 */
		for (const auto &str : names)
		{
			column_names.push_back(str);
		}
		is_column_names = true;
		return 0;
	}

	size_t at(double value, size_t row, size_t column)
	{
		data[row][column] = value;
		return 0;
	}

	size_t get_num_rows(void)
	{
		return n_rows;
	}

	size_t get_num_columns(void)
	{
		return n_columns;
	}

	size_t print_dataframe(size_t column_width = 16, size_t val_precision = 8)
	{
		// TODO: print in range (slice)
		// cout << fixed;

		if (is_column_names)
		{
			for (size_t j = 0; j != n_columns; j++)
				cout << left << setw(column_width) << column_names[j];
			cout << endl;
		}
		// cout << ios::scientific;
		cout << fixed;
		for (size_t i = 0; i != n_rows; i++)
		{
			for (size_t j = 0; j != n_columns; j++)
				cout << left << setw(column_width) << setprecision(val_precision) << data[i][j];
			cout << endl;
		}
		cout.unsetf(ios::fixed | ios::scientific);
		return 0;
	}

	size_t to_csv(const string &fileName, size_t precision = 8)
	{
		ofstream file(fileName);

		// Check if the file was successfully opened
		if (!file.is_open())
		{
			cerr << "Error: Could not open file " << fileName << " for writing." << endl;
			return 1;
		}

		if (is_column_names)
		{
			for (size_t j = 0; j != n_columns; j++)
			{
				file << column_names[j];
				if (j < (n_columns - 1))
					file << ",";
			}
			file << "\n";
		}

		file.precision(precision);
		file.setf(ios::scientific);
		for (size_t i = 0; i != n_rows; i++)
		{
			for (size_t j = 0; j != n_columns; j++)
			{
				file << data[i][j];
				if (j < (n_columns - 1))
					file << ",";
			}
			if (i < (n_rows - 1))
				file << "\n";
		}
		file.close();
		cout << "Data saved to " << fileName << " successfully!" << endl;
		return 0;
	}
};