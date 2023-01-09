primecount 7.6
December 07, 2022
Kim Walisch, <kim.walisch@gmail.com>

About primecount
================

  primecount is a command-line program that counts the number of
  primes below an integer x <= 10^31 using fast implementations of the
  prime counting function pi(x).

  Homepage: https://github.com/kimwalisch/primecount

Usage examples
==============

  Open a terminal and run:

  # Count the primes below 10^14
  ./primecount 1e14

  # Print progress and status information during computation
  ./primecount 1e20 --status

  # Count primes using Meissel's algorithm
  ./primecount 2**32 --meissel

  # Find the 10^14th prime using 4 threads
  ./primecount 1e14 --nth-prime --threads=4 --time

Command-line options
====================

  Usage: primecount x [options]
  Count the number of primes less than or equal to x (<= 10^31).

  Options:

    -d, --deleglise-rivat  Count primes using the Deleglise-Rivat algorithm
    -g, --gourdon          Count primes using Xavier Gourdon's algorithm.
                           This is the default algorithm.
    -l, --legendre         Count primes using Legendre's formula
        --lehmer           Count primes using Lehmer's formula
        --lmo              Count primes using Lagarias-Miller-Odlyzko
    -m, --meissel          Count primes using Meissel's formula
        --Li               Approximate pi(x) using the logarithmic integral
        --Li-inverse       Approximate the nth prime using Li^-1(x)
    -n, --nth-prime        Calculate the nth prime
    -p, --primesieve       Count primes using the sieve of Eratosthenes
        --phi <X> <A>      phi(x, a) counts the numbers <= x that are not
                           divisible by any of the first a primes
        --Ri               Approximate pi(x) using Riemann R
        --Ri-inverse       Approximate the nth prime using Ri^-1(x)
    -s, --status[=NUM]     Show computation progress 1%, 2%, 3%, ...
                           Set digits after decimal point: -s1 prints 99.9%
        --test             Run various correctness tests and exit
        --time             Print the time elapsed in seconds
    -t, --threads=NUM      Set the number of threads, 1 <= NUM <= CPU cores.
                           By default primecount uses all available CPU cores.
    -v, --version          Print version and license information
    -h, --help             Print this help menu

  Advanced options for the Deleglise-Rivat algorithm:

    -a, --alpha=NUM        Set tuning factor: y = x^(1/3) * alpha
        --P2               Compute the 2nd partial sieve function
        --S1               Compute the ordinary leaves
        --S2-trivial       Compute the trivial special leaves
        --S2-easy          Compute the easy special leaves
        --S2-hard          Compute the hard special leaves

  Advanced options for Xavier Gourdon's algorithm:

        --alpha-y=NUM      Set tuning factor: y = x^(1/3) * alpha_y
        --alpha-z=NUM      Set tuning factor: z = y * alpha_z
        --AC               Compute the A + C formulas
        --B                Compute the B formula
        --D                Compute the D formula
        --Phi0             Compute the Phi0 formula
        --Sigma            Compute the 7 Sigma formulas
