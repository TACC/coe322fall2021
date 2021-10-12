int main() {

  
  // this is nice C++, memory gets taken care of for you
  for (int i=..... ) {
    vector<double> x(bignumber);
    // do something with x

    // at the end of the iteration, everything nicely goes away (RAII)
  }

  // this is C. don't do that. even if it's legal, strictly speaking
  for (int i=.... ) {
    // pascal stuff starts here
    double *x;
    x = (double*) malloc( bignumber * sizeof(double) );
    // do something with x
    // => without this you have a leak: free(x);
  }

}
