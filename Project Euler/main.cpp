#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include <ctime>
using std::cout;
using std::endl;
using std::string;

int multiples(int max_number);
int fibonacci(int);
// Finds the sum of all fibonacci numbers lower than int

long long largest_prime_factor(long long int);
int palindromic_number();
long long least_common_multiple(int);
// Finds the least common multiple of the range 1, int

std::vector<int> prime_range(int);
// Finds all primes ranging from 2 to int

int nth_prime(int);
// Finds prime n

int square_sum(int);

long long int largest_series_product(int);

int pythagorean_triplet();

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
			std::vector<int> i = prime_range(stoi(string(argv[2])));
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
				i = 2;
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
	}
	return prime_array;
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
	cout << primes_product << endl;
	cout << lcm << endl;
	return 0;
}

int square_sum(int range) {
	int num_sum = 0, sqr_sum = 0;
	for (int i = 1; i <= range; i++) {
		num_sum += pow(i, 2);
		sqr_sum += i;
	}
	cout << num_sum << ", " << sqr_sum << endl;
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
	int a, b, c = 998;
	while (c >= 1) {
		b = 999 - c;
		a = 1000 - b - c;

		if (a + b + c != 1000)
			cout << "YOu dun fucked up" << endl;
		c--;
	}

	return 0;
}