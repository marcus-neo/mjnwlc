#define _USE_MATH_DEFINES
#include <vector>
#include <iostream>
#include <complex>
#include <cmath>
#include <sstream>


using namespace std;

// TODO: Provide a definition for this function
vector<complex<float>> dft(vector<complex<float>> x, int m){
vector<complex<float>> y;
int n = x.size();
complex <float> i = (0.0,1.0);
float test;
for (int a = 0; a < m; a++){
    y.push_back(0);
    for (int b = 0; b < n; b++) {
        test = -2*a*b/n*M_PI;
        y[a] += x[b] * exp<float>(i*test);
    }
}
return y;
}

////////////////////////////////////////////
// Don't modify things below this line

void print_spectrum(vector<complex<float>> f)
{
    vector<float> levels;

    string gray{" .:-=+*#%@"};

    float max_level=1.0;

    for(int i=1; i<(int)f.size(); i=i+1){
        float acc=abs(f[i]);
        levels.push_back(acc*acc);
        max_level=max(max_level, levels.back());
    }
    

    for(int i=0; i<levels.size(); i=i+1){
        float l=(int)(levels[i] * 10 / max_level);
        if(l>9){
            l=9;
        }
        cout << gray.at(l);
    }

    cout << "|" << endl;
}


int main()
{
    int WINDOW_LEN=1;
    int MAX_F=100; // Increase to get higher frequencies (will get slower)

    // Skip over sox data header
    string header1, header2;
    getline(cin, header1);
    getline(cin, header2);

    vector<complex<float>> x;
    float t, s;
    while(cin >> t >> s) // Loop while there is more input
    {
        x.push_back(s);

        // Check if the buffer is full
        if(x.size() == WINDOW_LEN){
            // Apply the dft transform
            vector<complex<float>> y=dft(x, MAX_F);

            // Print out the results
            print_spectrum(y);

            // Clear the buffer so we can start building again
            x.clear();
        }
    }
}
