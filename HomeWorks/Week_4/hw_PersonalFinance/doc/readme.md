* @brief Implement a personal budgeting system. You need to process requests of the following types:

ComputeIncome from to: Compute the net income for the given date range.

Earn from to value: take into account that for the specified period (evenly over the days) the amount value was earned.

Notes:

In all from to ranges, both from and to dates are included.

Input Format
The first line enters the number of requests Q, then the requests themselves are entered in the format described above,
one per line.

Output Format
For each ComputeIncome query, on a separate line print a real number — profit for the specified date range.

Note:

use std::cout.precision(25) in your code for uniform output of real numbers

Restrictions
The number of requests Q is a natural number not exceeding 50.

All dates are entered in YYYY-MM-DD format. The dates are correct (including leap years) and belong to the interval from
2000 to 2099.

value are positive integers not exceeding 1000000.

1 second to process all requests.

Clue
Use std::accumulate to calculate sums.
