// PrimFinder.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <math.h>
#include <fstream>
#include <chrono>
#include <ctime>
#include <ratio>
using namespace std;         // Including the C++ Standard Library.
using namespace std::chrono; // Include chrono standard library

int main()
{
  /* Log out an explanation of the max it can do */
  cout << "Max can find" << pow(2, 31) - 1 << endl;
  cout << "Finding primes version v3" << endl
       << "Input the maximum number it will test." << endl;
  int max_count;
  /* Read the largest number it will be allowed to test against */
  cin >> max_count;
  int *prime = new int[max_count];
  /* Start with two prime numbers */
  prime[0] = 2;
  prime[1] = 3;
  /* Tells the position latter to start saving numbers too */
  int position = 2;
  /* Set the last number tested */
  int spot = 4;
  bool log = false;

  /* Get starting time to measure time taken */
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  /* Run through all  */
  while (spot <= max_count && spot > 0)
  {
    /* Declare number as prime (change latter is not true) */
    bool is_prime = true;
    /* Set the largest number to try the square root  */
    int max_try = sqrt(spot);
    /* check against all the known prime numbers to see if it is prime or not */
    for (int j = 0; j < position && max_try >= prime[j]; j++)
    {
      /* if we are logging then print what index we are testing against */
      if (log)
        cout << "letter j:" << j << endl;
      /* Get the number to test against */
      int i = prime[j];
      int n = spot;
      /* see if not evenly divisible */
      if (n % i == 0)
      {
        /* declare ads not prime and leave loop */
        is_prime = false;
        break;
      }
    }
    /* check if the number is prime */
    if (is_prime)
    {
      /* log as prime */
      cout << "Found prime: " << spot << endl;
      /* add to list of prime */
      prime[position] = spot;
      /* increase data save counter */
      position++;
    }
    /* if not prime */
    else
    {
      /* and logging enabled */
      if (log)
      /* Print Found not prime */
        cout << "Found not prime: " << spot << endl;
      }
      /* increase spot checking */
    spot++;
  }
  /* Create a second time to determine time taken */
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double, std::milli> time_span = t2 - t1;
  /* Prints the time it took to the console */
  cout << "Time difference: " << time_span.count() << " ms" << endl;
  /* Crates a file stream */
  ofstream myfile;
  /* opens the file to write data to it */
  myfile.open("example.txt");
  cout << "List of prime numbers: " << endl;
  /* for all of the numbers print to file */
  for (int j = 0; j < position; j++)
  {
    cout << "prime:" << prime[j] << endl;
    /* Prints to the file */
    myfile << "prime:" << prime[j] << endl;
  }
  /* prints the number of prime numbers to the file */
  myfile << "Found " << position << " primes" << endl;
  /* prints amount of time consumed to the file */
  myfile << "Total time consumed: " << time_span.count() << " ms" << endl;
  /* close the file and save the file */
  myfile.close();
  /* Lets the window remain open */
  cout << "Press enter to continue...";
  getchar();
  return 0;
}
