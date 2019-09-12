/*
 * Created by: Lugsole
 * What: This is a prime finding function
 * When: 2017 - Curent
 * Where: 
 * Why: This was made for fun
 */
#include <iostream>
#include <math.h>
#include <fstream>
#include <chrono>
#include <vector> 
#undef DEBUG
using namespace std;         // Including the C++ Standard Library.
using namespace std::chrono; // Include chrono standard library

int main()
{
  /* Log out an explanation of the max it can do */
  cout << "Max can find " << (unsigned long)pow((unsigned long)2,(unsigned long) 32) - 1 << endl;
  cout << "Finding primes version v3" << endl
       << "Input the maximum number it will test." << endl;
  unsigned int max_count;
  /* Read the largest number it will be allowed to test against */
  cin >> max_count;
  vector<unsigned int> Prime_Numbers; 
  /* Start with two prime numbers */
  Prime_Numbers.push_back(2);
  Prime_Numbers.push_back(3);
  /* Set the last number tested */
  unsigned int spot = 4;

  /* Get starting time to measure time taken */
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  /* Run through all  */
  while (spot <= max_count && spot > 0)
  {
    /* Declare number as prime (change latter is not true) */
    bool is_prime = true;
    /* Set the largest number to try the square root  */
    unsigned int max_try = sqrt(spot); // TODO replace function with uint64_t varent
    /* check against all the known prime numbers to see if it is prime or not */
    for (unsigned int j = 0; j < Prime_Numbers.size() && max_try >= Prime_Numbers[j]; ++j)
    {

      /* if we are logging then print what index we are testing against */
      #ifdef DEBUG
        cout << "letter j:" << j << '=' << Prime_Numbers[j] << endl;
      #endif
      /* Get the number to test against */
      unsigned int i = Prime_Numbers[j];
      unsigned int n = spot;
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
      #ifdef DEBUG
        /* log as prime */
        cout << "Found prime: " << spot << endl;
      #endif
      /* add to list of prime */
      Prime_Numbers.push_back(spot);
    }
    #ifdef DEBUG
    /* if not prime */
    else
    {
      /* Print Found not prime */
      cout << "Found not prime: " << spot << endl;
    }
    #endif
    /* increase spot checking */
    spot++;
  }
  /* Create a second time to determine time taken */
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double, std::milli> time_span = t2 - t1;
  /* Prints the time it took to the console */
  cout << "Time used: " << time_span.count() << " ms"<< endl;
  /* Crates a file stream */
  ofstream myfile;
  /* opens the file to write data to it */
  myfile.open("example.txt");
  /* Crates a file stream */
  ofstream Uint_File;
  /* opens the file to write data to it */
  Uint_File.open("example.bin");
  cout << "Writing prime numbers to files" << endl;
  /* for all of the numbers print to file */
  for (unsigned int j = 0; j < Prime_Numbers.size(); j++)
  {
    #ifdef DEBUG
      cout << "prime:" << Prime_Numbers[j] << endl;
    #endif
    /* Prints to the file */
    myfile << Prime_Numbers[j] << '\n';
    Uint_File << (uint8_t)((Prime_Numbers[j])>>24);
    Uint_File << (uint8_t)((Prime_Numbers[j])>>16);
    Uint_File << (uint8_t)((Prime_Numbers[j])>>8);
    Uint_File << (uint8_t)(Prime_Numbers[j]);
  }
  /* prints the number of prime numbers to the file */
  myfile << "Found " << Prime_Numbers.size() << " primes" << endl;
  /* prints amount of time consumed to the file */
  myfile << "Total time consumed: " << time_span.count() << " ms" << endl;
  /* close the file and save the file */
  myfile.close();
  Uint_File.close();
  /* Lets the window remain open */
  cout << "Press enter to continue...";
  getchar();
  return 0;
}
