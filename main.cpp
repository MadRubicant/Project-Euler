#include <array>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "latticepath.cpp"
using std::cout;
using std::endl;
using std::string;

int multiples(int max_number);
int fibonacci(int);
// Finds the sum of all fibonacci numbers lower than int

long long largest_prime_factor(long long int);
// Finds the largest prime factor of a number

int palindromic_number();
// Finds a number that's also a palindrome that's the product of two 3 digit numbers

long long least_common_multiple(int);
// Finds the least common multiple of the range 1, int

std::vector<int> prime_range(int);
// Finds all primes ranging from 2 to int, sorted from least to greatest

std::vector<int> prime_sieve(int);
int nth_prime(int);
// Finds prime n

int square_sum(int);
// Finds the difference between the sum of the squares and the square of the sum of (1, int)

long long int largest_series_product(int);
// Finds the largest product of adjacent digits in a 1000 digit number

int pythagorean_triplet();
// Finds the product of the pythagorean triplet whose sum = 1000

long long prime_sum(int);
// Finds the sum of all primes less than int

int number_grid();
// Finds the greatest product of 4 numbers in a grid

int triangle_numbers(int);
// Finds the triangle number with a number of factors greater than int

unsigned long long large_sum();

int longest_collatz(int);

int lattice_paths(int);

int power_digit_sum();

int number_letter_counts(int);

int max_path_sum1();

int counting_sundays();

int amicable_numbers(int);

long long names_score();

int nonabundent_sums();

int main(int argc, char* argv[]) {
	switch (argc) {
	case 1:
	case 2:
		if (argc == 1 || !(strcmp(argv[1], "/h") || (strcmp(argv[1], "/H") || strcmp(argv[1], "help")))) {
			cout << "Usage: Euler.exe --[arg] [input]\n";
			cout << "Possible arguments: --multiples [int], --fibonacci [int], --largest_prime_factor [int], --palindromic_number [void], --least_common_multiple [int]\n";
			cout << "Example: Euler.exe --largest_prime_factor 600\n";
			cout << "Give each argument the specified type. Void means don't give it an input.\n";
			cout << "Warning: Giving a type other than the one specified is undefined behavior. Floats in place of ints and vice versa are probably fine" << endl;
			break;
		}
		else if (!(strcmp(argv[1], "--palindromic_number"))) {
			cout << palindromic_number() << endl;
		}
		else if (!(strcmp(argv[1], "--pythagorean_triplet"))) {
			cout << pythagorean_triplet() << endl;
		}
		else if (!strcmp(argv[1], "--grid_product")) {
			cout << number_grid() << endl;
		}
		else if (!strcmp(argv[1], "--large_sum")) {
			large_sum();
		}
		else if (!strcmp(argv[1], "--power_digit_sum"))
			power_digit_sum();

		else if (!strcmp(argv[1], "--number_letter_counts")){
			cout << number_letter_counts(1000) << endl;
		}
		else if (!strcmp(argv[1], "--max_path_sum_one")) {
			cout << max_path_sum1() << endl;
		}
		else if (!strcmp(argv[1], "--counting_sundays")) {
			cout << counting_sundays() << endl;
		}
		else if (!strcmp(argv[1], "--factorial_sum")) {
			system("python factorial_digits.py");
		}
		else if (!strcmp(argv[1], "--names_score")) {
			cout << names_score() << endl;
		}
		else if (!strcmp(argv[1], "--nonabundent_sums")) {
			cout << nonabundent_sums() << endl;
		}
		break;
	case 3:
		if (!strcmp(argv[1], "--multiples")) {
			cout << multiples(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--fibonacci")) {
			cout << fibonacci(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--largest_prime_factor")) {
			cout << largest_prime_factor(stoll(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--least_common_multiple")) {
			cout << least_common_multiple(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--primes")) {			
			std::vector<int> i = prime_sieve(stoi(string(argv[2])));
			int newline = 0;
			for (auto it : i) {
				cout << it << ", ";
				newline += 1;
				if (newline == 10)
					cout << endl;
			}
			cout << endl;
		}
		else if (!strcmp(argv[1], "--square_sum")) {
			cout << square_sum(stoi(string(argv[2]))) << endl;;
		}
		else if (!strcmp(argv[1], "--nth_prime")) {
			cout << nth_prime(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--largest_series_product")) {
			cout << largest_series_product(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--prime_sum")) {
			cout << prime_sum(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--triangle_numbers")) {
			cout << triangle_numbers(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--longest_collatz")) {
			cout << longest_collatz(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--lattice_paths")) {
			cout << lattice_paths(stoi(string(argv[2]))) << endl;
		}
		else if (!strcmp(argv[1], "--amicable_numbers")) {
			cout << amicable_numbers(stoi(string(argv[2]))) << endl;
		}
		break;
	}
	cout << clock() << " MS" << endl;
	return EXIT_SUCCESS;
}


//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.
int multiples(int max_number) {
	int total = 0;
	for (int i = 0; i < max_number; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			total += i;
		}
	}
	return total;
}

int fibonacci(int max_number) {
	int first = 2, second = 3;
	int total = 2;
	int tmp = 0;
	while (second < max_number) {
		tmp = second;
		second += first;
		cout << first << ", " << tmp << ", " << second << endl;
		first = tmp;
		if (second % 2 == 0) {
			total += second;
		}
		
	}
	return total;
}

long long largest_prime_factor(long long int number) {
	using std::list;
	list<long long int> factor_list = { number };
	bool not_factored = true;
	while (not_factored) {
		long long working_number = factor_list.back();
		factor_list.pop_back();
		for (long long i = 2; i < working_number / 2; i++) {
			if (working_number % i == 0) {
				factor_list.push_back(i);
				working_number /= i;
				i = 1;
			}
		}
		factor_list.push_back(working_number);
		not_factored = false;
		for (long long i = 2; i <= working_number / 2; i++) {
			if (working_number % i == 0) {
				not_factored = true;
				break;
			}
			if (working_number == 2 && i == 2) {
				factor_list.pop_back();
				factor_list.push_back(i);
				factor_list.push_back(working_number / i);
				break;
			}
		}
	}
	factor_list.sort();
	for (auto x : factor_list) {
		cout << x << ", ";
	}
	cout << endl;
	return factor_list.back();
}

int palindromic_number() {
	std::list<int> palindrome_list;
	int first = 999, second = 999, product = 0;
	string str, half_one, half_two;
	bool str_found = false;
	while (!str_found && first >= 100) {
		while (!str_found && second >= 100) {
			product = first * second;
			str = std::to_string(product); // Get the product, make it a string

			if (str.length() % 2 == 0) {
				half_one = str.substr(0, str.size() / 2);
				half_two = str.substr(str.size() / 2, str.size());
				// Create two strings to compare

				str_found = true;
				for (int i = 0; i < half_one.length(); i++) {
					if (half_one.at(i) != half_two.at(half_two.size() - 1 - i)) {
						str_found = false;
						break; // If a character doesn't match, we're back up to 
					}
				}
			} // HERE

			else { // Odd length string. This time we get the middle character and ignore it
				half_one = str.substr(0, str.size() / 2);
				half_two = str.substr(str.size() / 2 + 1, str.size());
				// Loop
				str_found = true;
				for (int i = 0; i < half_one.length(); i++) {
					if (half_one.at(i) != half_two.at(half_two.length() - 1 - i)) {
						str_found = false;
						break;
					}
				}
			}
			second--;
			if (str_found) {
				palindrome_list.push_back(product);
				str_found = false;
			}
		}
		first--;
		second = 999;
	}
	palindrome_list.sort();
	return palindrome_list.back();
}

std::vector<int> prime_range(int range) {
	std::vector<int> prime_array = { 2 };
	for (int i = 2; i <= range; i++) {
		bool prime = true;

		for (int x : prime_array) {
			if (i % x == 0) { // If it's divisible by a prime already found, into the trash it goes
				prime = false;
				break;
			}
		}
		/*if (prime) {
			for (int j = prime_array.back(); j < i / 2; j++) {
				if (i % j == 0) { // If it divides even, into the trash it goes
					prime = false;
					break;
				}
			}
		}*/

		if (prime)
			prime_array.push_back(i);
	}
	return prime_array;
}

std::vector<int> prime_sieve(int range) {
	std::set<int> primes;
	//std::list<int> return_list;
	std::vector<int> return_vec;
	int p = 3;
	primes.insert(2);
	for (int i = 3; i < range; i += 2){
		primes.insert(i);
	}
	while (p * p < range) {
		int mult = p;
		while (mult < range) {
			mult += p;
			primes.erase(mult);
		}
		p = *primes.lower_bound(p + 1);
		cout << p << endl;
	}
	for (auto x : primes) {
		return_vec.push_back(x);
	}
	return return_vec;
}

long long least_common_multiple(int range) {
	long long primes_product = 1, lcm;
	bool not_found = true;
	// Find the product of the prime numbers in our range since this is guaranteed to be an intermediate factor
	for (auto x : prime_range(range)) {
		primes_product *= x;
	}
	lcm = primes_product;
	// What we're doing is checking all the multiples of our prime product. Eventually we'll hit the lcm.
	while (not_found) {
		lcm += primes_product;
		not_found = false;
		for (int i = range; i > 1; i--) {
			if (lcm % i != 0) {
				not_found = true;
				break;
			}
		}
	}
	//cout << primes_product << endl;
	cout << lcm << endl;
	return 0;
}

int square_sum(int range) {
	int num_sum = 0, sqr_sum = 0;
	for (int i = 1; i <= range; i++) {
		num_sum += pow(i, 2);
		sqr_sum += i;
	}
	//cout << num_sum << ", " << sqr_sum << endl;
	sqr_sum *= sqr_sum;
	return (sqr_sum - num_sum);
}

int nth_prime(int n) {
	std::vector<int> prime_array = { 2 };
	int i = 2;
	while (prime_array.size() < n) {
		bool prime = true;

		for (int x : prime_array) {
			if (i % x == 0) { // If it's divisible by a prime already found, into the trash it goes
				prime = false;
				break;
			}
		}
		if (prime) {
			for (int j = prime_array.back(); j < i / 2; j++) {
				if (i % j == 0) { // If it divides even, into the trash it goes
					prime = false;
					break;
				}
			}
		}

		if (prime)
			prime_array.push_back(i);
		i++;
	}
	return prime_array.back();
}

long long int largest_series_product(int num_digits) { // Look at this. What the fuck is this.
	string thousand_digit = "73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";
	long long int highest_product = 0;
	long long int temp;
	for (int i = 0; i < 1000 - num_digits; i++) {
		temp = 1;
		for (char c : thousand_digit.substr(i, num_digits)) {
			int j = stoi(string(&c));
			if (j == 0) {
				temp = 0;
				break;
			}
			temp *= j;
		}
		if (temp > highest_product)
			highest_product = temp;
	}

	return highest_product;
}

int pythagorean_triplet() {
	int a, b = 1, c = 998;
	while (c >= 1) {
		a = 1000 - b - c;
		if ((int) pow(a, 2) + (int) pow(b, 2) == (int) pow(c, 2)) {
			return (a * b * c);
		}
		c--;
		if (c == 1) {
			b++;
			c = 998 - b;
		}
	}

	return 0;
}

long long prime_sum(int max) {
	auto vec = prime_sieve(max);
	long long sum = 0, i = 0;
	for (int x : vec) {
		i++;
		sum += x;
	}
	cout << i << endl;
	return sum;
}

int number_grid() {
	std::array<std::array<int, 20>, 20> grid;
	std::ifstream file;
	string line;
	file.open("numbers.txt");
	int p = 0;
	// Parse the grid and put it in a 2d array
	while (std::getline(file, line)) {
		int i = 0;
		string str;
		for (char c : line) {
			if (c == ' ') {
				grid[p][i] = stoi(str);
				str.clear();
				i++;
			}
			else {
				str.push_back(c);
			}
		}
		p++;
	}
	int number = 1;
	int highest = 0;
	for (int x = 0; x < 17; x++) {
		for (int y = 0; y < 17; y++) {
			int count = 0;

			// Try going right first
			while (count < 4) {
				number *= grid[x][y + count];
				count++;
			}
			if (number > highest)
				highest = number;
			number = 1;
			count = 0;

			// Next try going down
			while (count < 4) {
				number *= grid[x + count][y];
				count++;
			}
			if (number > highest)
				highest = number;
			number = 1;
			count = 0;

			// Diagonal right
			while (count < 4) {
				number *= grid[x + count][y + count];
				count++;
			}
			if (number > highest)
				highest = number;
			number = 1;
			count = 0;
			if (y > 3) {
				for (y; y < 20; y++) {
					// Diagonal left, this is sort of tacked on
					while (count < 4) {
						number *= grid[x + count][y - count];
						count++;
					}
					if (number > highest)
						highest = number;
					number = 1;
					count = 0;
				}
			}
		}
	}
	//for (auto x : grid) {
	//	for (auto y : x) {
	//		cout << y << " ";
	//	}
	//	cout << endl;
	//}
	file.close();	
	return highest;
}

int triangle_numbers(int total_factors) {
	std::list<int> factors;
	bool found = false;
	int it = 0, total = 0;
	while (!found) {
		// Find the factors of the current number
		total += it;
		it++;
		//cout << total << endl;
		for (int i = 1; i <= total / 2; i++) {
			if (total % i == 0) {
				factors.push_back(i);
			}
		}
		if (factors.size() >= total_factors)
			return total;

		factors.clear();
	}
}

unsigned long long large_sum() {
	/*std::fstream file;
	std::array<string, 50> numbers;
	file.open("50 digit numbers.txt");
	for (int num = 0; num < 50; num++) {
		std::getline(file, numbers[num]);
	}
	int total_offset = 37;
	unsigned long long rough_total;	
	for (auto str : numbers) {
		unsigned long long operand = std::stoull(string(str.substr(0, 10)));
	}
	return 0;*/
	string script_command = "python large_sum.py";
	system(script_command.c_str());
	return 0;
}

int longest_collatz(int range) {
	int count = 0, longest_count = 0, longest_number = 0;
	std::vector<int> cache = {0};
	long long num;
	for (int i = 2; i < range; i++) {
		num = i;
		count = 0;
		while (num != 1 && num >= i) {
			if (num % 2 == 0)
				num /= 2;
			else
				num = num * 3 + 1;

			count++;
			}
		count += cache.at(num - 1);
		num = 1;
		cache.push_back(count);
		if (count > longest_count) {
			longest_number = i;
			longest_count = count;
		}
	}
	return longest_number;
}

int lattice_paths(int dimensions) {
	vector<vector<bool>> paths;
	// Paths are stored as an array of bools. False means move right, True means move down.
	vector<bool> cur_path, last_path;
	for (int i = 0; i < dimensions * 2; i++)
		cur_path.push_back(false);
	paths.push_back(cur_path);
	last_path = cur_path;
	cur_path.clear();
	bool finished = false;
	while (!finished) {
		int pos = 0; // We're at node 0
		int movsum = 0;
		while (pos < dimensions * 2) {
			bool direction = 0;
			if (last_path.at(pos) == direction)
				direction = 1;
			movsum += direction;
			cur_path.push_back(direction);
			cout << "Pos: " << pos << "\n" << "Direction: " << direction << endl;
			if (pos == dimensions && movsum == dimensions) {
				finished = true;
			}
			pos++;
		}
		paths.push_back(cur_path);
		last_path = cur_path;
		cur_path.clear();
	}
	return paths.size();
}

int power_digit_sum() {
	system("python digit_sum.py");
	return 1;
}

string digit_word(int digit) {
	switch (digit) {
	case 0:
		return "";
		break;
	case 1:
		return "one";
		break;
	case 2:
		return "two";
		break;
	case 3:
		return "three";
		break;
	case 4:
		return "four";
		break;
	case 5:
		return "five";
		break;
	case 6:
		return "six";
		break;
	case 7:
		return "seven";
		break;
	case 8:
		return "eight";
		break;
	case 9:
		return "nine";
		break;
	}
}

int get_digit(int number, int digit) {
	return static_cast<int>(number / pow(10, digit - 1)) % 10;
}

string get_word(int num) {
	string phrase = "";
	if (num == 1000) {
		phrase.append("onethousand");
		return phrase;
		}
	if (num > 99 && num < 1000) {
		auto var = digit_word(get_digit(num, 3));
		phrase.append(var);//digit_word(get_digit(num, 3)));
		phrase.append("hundred");
		if (!(get_digit(num, 2) == 0 && get_digit(num, 1) == 0))
			phrase.append("and");
	}
	if (num > 0) {
		auto var = get_digit(num, 2);
		auto varb = get_digit(num, 1);
		switch (var){//get_digit(num, 2)) {
		case 0:
			phrase.append(digit_word(varb));
			break;
		case 1:
			switch (varb) {//get_digit(num, 1)) {
			case 0:
				phrase.append("ten");
				break;
			case 1:
				phrase.append("eleven");
				break;
			case 2:
				phrase.append("twelve");
				break;
			case 3:
				phrase.append("thirteen");
				break;
			case 4:
				phrase.append("fourteen");
				break;
			case 5:
				phrase.append("fifteen");
				break;
			case 6:
				phrase.append("sixteen");
				break;
			case 7:
				phrase.append("seventeen");
				break;
			case 8:
				phrase.append("eighteen");
				break;
			case 9:
				phrase.append("nineteen");
				break;
			}
			break;
		case 2:
			phrase.append("twenty");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		case 3:
			phrase.append("thirty");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		case 4:
			phrase.append("forty");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		case 5:
			phrase.append("fifty");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		case 6:
			phrase.append("sixty");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		case 7:
			phrase.append("seventy");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		case 8:
			phrase.append("eighty");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		case 9:
			phrase.append("ninety");
			phrase.append(digit_word(get_digit(num, 1)));
			break;
		}
	}
	/*if (num > 0 && num < 10) {
		phrase.append(digit_word(num));
	}*/
	if (num == 0) {
		phrase.append("zero");
	}
	return phrase;
}

int number_letter_counts(int range) {
	string fnl = "";
	for (int i = 1000; i > 0; i--) {
		cout << i << " " << get_word(i) << endl;
		fnl.append(get_word(i));
	}
	int count = 0;
	for (char c : fnl) {
		if (c >= 'a' && c <= 'z')
			count++;
	}
	//cout << fnl;
	return fnl.size();
}

int max_path_sum1() {
	std::fstream file;
	string line, num = "";
	int x = 0;
	std::vector < std::vector<int> > triangle, sums;
	file.open("triangle.txt");
	char c;
	std::vector<int> tri_line = {}, sum_line = {};
	while (file.get(c)){
		if (c == '\n') {
			//cout << num;
			tri_line.push_back(stoi(num));
			sum_line.push_back(0);
			triangle.push_back(tri_line);
			sums.push_back(sum_line);
			num = "";
			tri_line.clear();
			sum_line.clear();
		}
		else if (c == ' ') {
			//cout << num;
			tri_line.push_back(stoi(num));
			sum_line.push_back(0);
			num = "";
		}
		else{
			num.append(1, c);
		}
	}
	tri_line.push_back(stoi(num));
	sum_line.push_back(0);
	triangle.push_back(tri_line);
	sums.push_back(sum_line);
	/*while (std::getline(file, line)) {
		triangle.push_back({});
		sums.push_back({});
		for (char c : line){
			cout << c;
			if (c == ' ' || c == '\n') {
				triangle.at(x).push_back(stoi(num));
				sums.at(x).push_back(0);
				num = "";
			}
			else
				num.append(1, c);
		}
		cout << endl;
			x++;
	}*/
	sum_line.push_back(0);
	sums.push_back(sum_line);
	/*for (auto x : triangle) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	for (auto x : sums) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}*/
	auto it = triangle.rbegin(), it_sum = sums.rbegin(), it_sum_up = sums.rbegin();
	it_sum_up++;
	while (it != triangle.rend()) {
		auto it_b = it->begin(), it_sum_b = it_sum->begin(), it_sum_up_b = it_sum_up->begin();
		while (it_b != it->end()) {
			//cout << *it_b << " ";
			int sum = std::max(*it_b + *(it_sum_b), *it_b + it_sum_b[1]);
			it_sum_up_b[0] = sum;
			//cout << *it_b + *(it_sum_b) << ", " << *it_b + it_sum_b[1] << "; ";
			it_b++;
			it_sum_b++;
			it_sum_up_b++;
		}
		//cout << endl;
		it++;
		it_sum++;
		it_sum_up++;
	}
	
	return sums.front().front();
}

int counting_sundays() {
	int weekday = 2;
	int month = 1;
	int year = 1901;
	int sundays = 0;
	while (year <= 2000) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			weekday += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			weekday += 30;
			break;
		case 2:
			if (year % 4 == 0) { // Leap year
				weekday += 29;
			}
			else
				weekday += 28;
			break;
		}
		if (weekday % 7 == 0) {
			sundays++;
		}
		month++;
		if (month > 12) {
			year++;
			month = 1;
		}
	}
	return sundays;
}

int d(int n, vector<int> &sums) {
	if (n > sums.size())
		return 0;
	else
		return sums.at(n);
}

int amicable_numbers(int range) {
	std::vector<std::vector<int>> factors;
	std::vector<int> sums;
	std::vector<int> short_list = {};
	factors.push_back({ 0 });
	factors.push_back({ 1 });
	factors.push_back({ 2, 1 });
	int it = 3;
	for (it; it < range; it++) {
		for (int div = static_cast<int>(it / 2); div > 0; div--) {
			if (it % div == 0) {
				short_list.push_back(div);
			}
		}
		factors.push_back(short_list);
		short_list.clear();
	}
	for (auto x : factors) {
		int sum = 0;
		for (auto y : x) {
			sum += y;
		}
		sums.push_back(sum);
		//cout << endl;
	}
	int sum = 0;
	int x = 0;
	for (x; x < sums.size(); x++) {
		for (int y = 0; y < sums.size(); y++) {
			if (d(y, sums) == 1)
				continue;
			else if (d(y, sums) == d(x, sums) && y != x) {
				sum += x;
				break;
			}
		}
	}
	return sum;
}

long long names_score() {
	std::fstream file;
	string name;
	std::list<string> all_names;
	file.open("names.txt");
	while (!file.eof()) {
		char c = file.get();
		if (c == ',') {
			all_names.push_back(name);
			name.clear();
			// We've got a full name, add the character to our list
		}
		else if (c == '"') {
			// Discard this character
		}
		else {
			name += c;
			// Continue building our name
		}
	}
	name.erase(name.length() - 1);
	all_names.push_back(name);
	all_names.sort();
	long long total_sum = 0, it = 1;
	for (string name : all_names) {
		long long sum = 0;
		for (char c : name) {
			sum += c - 'A' + 1;
		}
		sum *= it++;
		cout << it << " " << name << ": " << sum << endl;
		total_sum += sum;
	}
	return total_sum;
}

int nonabundent_sums() {
	vector<int> sums;
	vector<bool> abundancy;
	sums.push_back(0);
	abundancy.push_back(0);
	for (int i = 1; i <= 28123; i++) {
		abundancy.push_back(false);
		int sum = 1;
		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) // If it perfectly divides
				sum += j;
		}
		sums.push_back(sum);
	}
	for (int i : sums) {
		for (int j : sums) {
			if (i + j < 28123 && sums.at(i) == i && sums.at(j) == j){
				abundancy.at(i + j) = true;
				break;
			}
		}
	}
	int fin_sum = 0;
	for (int i = 0; i < abundancy.size(); i++){
		if (!abundancy.at(i))
			fin_sum += i;
	}
	return fin_sum;
}